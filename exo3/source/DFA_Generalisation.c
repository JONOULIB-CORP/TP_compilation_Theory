//
// Created by noutcheu on 6/27/24.
//

#include "../header/DFA_Generalisation.h"

GeneralizedDFA* createGeneralizedDFA(const char* word) {
    GeneralizedDFA* dfa = (GeneralizedDFA*)malloc(sizeof(GeneralizedDFA));
    dfa->word = strdup(word);
    dfa->currentState = 0;
    dfa->transitionCount = strlen(word);
    dfa->transitions = (Transition*)malloc(dfa->transitionCount * sizeof(Transition));

    for (int i = 0; i < dfa->transitionCount; ++i) {
        dfa->transitions[i].character = word[i];
        dfa->transitions[i].nextState = i + 1;
    }

    return dfa;
}

void reset(GeneralizedDFA* dfa) {
    dfa->currentState = 0;
}

void process(GeneralizedDFA* dfa, char character) {
    if (dfa->currentState < dfa->transitionCount &&
        dfa->transitions[dfa->currentState].character == character) {
        dfa->currentState = dfa->transitions[dfa->currentState].nextState;
    } else {
        dfa->currentState = 0;
        if (dfa->transitions[0].character == character) { // handle immediate reset case
            dfa->currentState = 1;
        }
    }
}

int isFinalState(const GeneralizedDFA* dfa) {
    return dfa->currentState == dfa->transitionCount;
}

void freeGeneralizedDFA(GeneralizedDFA* dfa) {
    free(dfa->word);
    free(dfa->transitions);
    free(dfa);
}
