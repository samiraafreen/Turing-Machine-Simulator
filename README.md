# Turing Machine Simulator

This C++ program simulates a TM. For each input string, it prints "Input accepted" if the input string is in the language of the TM. If the input string is not in the language, then it prints "Input rejected".

## Running the Program

Compile the tm.cpp file using the makefile. Run ./tm with the input file name and the input string.

## Code Structure

The main function reads in a file one line at a time, stores number of states, stores the alphabet, stores the final states in a vector, and then transitions are stored in a struct inside a vector. Then we read the input, and check if the current state is an accepting state. if it is, then we halt and print "Input accepted". if it is not, then the program goes through the rest of the input, checking every time if current state is an accept state. if the program has gone through the entire string and was not in an accept state, it prints "Input rejected".

## Known Discrepancies

* Accepts the empty string if turing machine accepts empty string
* Must have placeholder spaces when writing or reading blanks

## Authors

* Eura Choi
* Samira Afreen

