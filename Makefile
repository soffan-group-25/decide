CXX := g++
CXXFLAGS := -I.
objects := decide/lics.o decide/decide.o
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



### Testing
%.test: %.test.cpp %.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS)

# Compile all test files together w/ normal file and run them
# use @ for silent running
test_runner: $(testfiles)
	@$< || (echo "Test failed for $<" && exit 1)

test: test_runner
	@echo "Ran tests for:"
	@echo "$(testfiles)"
	@echo "Tests OK."


### Cleanup
# Declare as phony to assure target is run even if there's a "clean" file
.PHONY: clean
clean:
	rm -f decide/*.o DECIDE decide/*.test
