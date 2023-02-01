CXX := g++
CXXFLAGS := -I. -std=c++2a
objects := $(addsuffix .o, $(filter-out decide/main, $(basename $(filter-out $(wildcard decide/*.test.cpp), $(wildcard decide/*.cpp)))))
# Testfiles to make/compile (e.g. decide.test). Ignore example.test.cpp.
testfiles = $(filter-out decide/example.test, $(basename $(wildcard decide/*.test.cpp)))
# Colouring
col_failed=$(shell echo -e "\033[0;33m")
col_success=$(shell echo -e "\033[0;32m")
col_revert=$(shell echo -e "\033[0m")

### Main program
decide: decide_binary

# $^ = all prereqs (i.e. all *.o-files)
decide_binary: $(objects) decide/main.o
	$(CXX) $^ -o $@ $(CXXFLAGS)

# Separate rule for main.o as it has no main.hpp
%/main.o: %/main.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

# $@ = target, $< = first prereq (catch all != main.o)
%.o: %.cpp %.hpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)


### Formatting
format: $(wildcard decide/*.?pp)
	clang-format -i $^ --style=file


### Testing
#Special case for decide.test as it uses all LICs
decide/decide.test: $(objects) decide/decide.test.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS)

%.test: %.test.cpp %.cpp decide/utils.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS)

# Compile all test files together w/ normal file and run them
# use @ for silent running
test_runner: $(testfiles)
	@err=0; \
	for f in $^; do \
	./$$f && continue || err=$$? && echo "$(col_failed)Warning: Test failed for $$f$(col_revert)"; \
	done; \
	[ $$err -eq 0 ] || exit $$err

test: test_runner
	@echo "Ran tests for:"
	@echo "$(testfiles)"
	@echo "$(col_success)Tests OK.$(col_revert)"


### Cleanup
# Declare as phony to assure target is run even if there's a "clean" file
.PHONY: clean
clean:
	rm -f decide/*.o DECIDE decide/*.test
