CXX := g++
CXXFLAGS := -I.
objects = decide/lics.o decide/decide.o

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

# Declare as phony to assure target is run even if there's a "clean" file
.PHONY: clean
clean:
	rm decide/*.o DECIDE
