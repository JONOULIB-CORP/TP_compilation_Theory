//
// Created by noutcheu on 6/27/24.
//

#ifndef COMPILATION_TP_1_5_DFA_GENERALISATION_H
#define COMPILATION_TP_1_5_DFA_GENERALISATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char character;
    int nextState;
} Transition;

typedef struct {
    char* word;
    int currentState;
    Transition* transitions;
    int transitionCount;
} GeneralizedDFA;

GeneralizedDFA* createGeneralizedDFA(const char* word);

void reset(GeneralizedDFA* dfa);

void process(GeneralizedDFA* dfa, char character);

int isFinalState(const GeneralizedDFA* dfa);
void freeGeneralizedDFA(GeneralizedDFA* dfa);
#endif // COMPILATION_TP_1_5_DFA_GENERALISATION_H
