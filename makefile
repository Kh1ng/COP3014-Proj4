SHELL=/bin/bash
CXX=g++
CXXFLAGS=-std=c++11 -Wall -g
RM=rm -rf

.PHONY: clean

# Target rules
main: main.o grade.o text-menu-app.o gradebook.o
	$(CXX) -o $@ $^

test-all: test.o grade.o gradebook.o
	$(CXX) -o $@ $^
	./$@

# General compilation rules
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Rule to test run your code with the exact same input used in the sample run
test-run: main
	./main < input.txt

clean:
	$(RM) *.o main test-all *.gc* *.dSYM out.txt test_output.txt
