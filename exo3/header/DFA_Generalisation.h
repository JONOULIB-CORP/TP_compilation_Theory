//
// Created by noutcheu on 6/27/24.
//

#ifndef COMPILATION_TP_1_5_DFA_GENERALISATION_H
#define COMPILATION_TP_1_5_DFA_GENERALISATION_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class GeneralizedDFA {
    public:
        GeneralizedDFA(const std::string& word);

        void reset();

        void process(char character) ;

        bool isFinalState() const;

    private:
        std::string word;
        int currentState;
        std::vector<std::pair<char, int>> transitions;

};



// DFA_Generalisation

#endif //COMPILATION_TP_1_5_DFA_GENERALISATION_H
