CXX := g++
CXXFLAGS := -I. -std=c++2a
objects := $(addsuffix .o, $(filter-out decide/main, $(basename $(filter-out $(wildcard decide/*.test.cpp), $(wildcard decide/*.cpp)))))
# Testfiles to make/compile (e.g. decide.test). Ignore example.test.cpp.
testfiles = $(filter-out decide/example.test, $(basename $(wildcard decide/*.test.cpp)))

### Main program
decide: DECIDE

# $^ = all prereqs (i.e. all *.o-files)
DECIDE: $(objects) decide/main.o
	$(CXX) $^ -o $@ $(CXXFLAGS)

# Separate rule for main.o as it has no main.hpp
%/main.o: %/main.cpp
	$(CXX) -o $@ -c $<

# $@ = target, $< = first prereq (catch all != main.o)
%.o: %.cpp %.hpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)


### Formatting
format: $(wildcard decide/*.?pp)
	clang-format -i $< --style=file


### Testing
# Special case for utils file as it is only a header
decide/utils.test: decide/utils.test.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS)

%.test: %.test.cpp %.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS)

# Compile all test files together w/ normal file and run them
# use @ for silent running
test_runner: $(testfiles)
	@for f in $^; do eval $${f} || (echo "Test failed for $${f}" && exit 1); done

test: test_runner
	@echo "Ran tests for:"
	@echo "$(testfiles)"
	@echo "Tests OK."


### Cleanup
# Declare as phony to assure target is run even if there's a "clean" file
.PHONY: clean
clean:
	rm -f decide/*.o DECIDE decide/*.test
