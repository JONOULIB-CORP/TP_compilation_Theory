// DFA.h

#ifndef COMPILATION_TP_1_5_DFA_H
#define COMPILATION_TP_1_5_DFA_H
#include <iostream>
#include <fstream>
#include <string>
class DFA {
    public:
        DFA(); // Constructor
        void reset(); // Method to reset the DFA
        void process(char character); // Method to process input characters
        bool isFinalState() const; // Method to check if the DFA is in a final state

    private:
        int currentState; // Private member variable to track the current state

};

#endif // COMPILATION_TP_1_5_DFA_H
