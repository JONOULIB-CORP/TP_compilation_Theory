// DFA.c

#include "../header/DFA.h"

DFA* createDFA() {
    DFA* dfa = (DFA*)malloc(sizeof(DFA));
    if (dfa == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    dfa->currentState = 0;
    return dfa;
}

void resetDFA(DFA* dfa) {
    dfa->currentState = 0;
}

void processDFA(DFA* dfa, char character) {
    switch (dfa->currentState) {
        case 0:
            // printf("%c\n", character);
            if (character == 'm') {
                dfa->currentState = 1;
            } else {
                dfa->currentState = 0;
            }
            break;
        case 1:
            // printf("%c\n", character);
            if (character == 'u') {
                dfa->currentState = 2;
            } else if (character == 'm') {
                dfa->currentState = 1;
            } else {
                dfa->currentState = 0;
            }
            break;
        case 2:
            // printf("%c\n", character);
            if (character == 'r') {
                dfa->currentState = 3;
            } else if (character == 'm') {
                dfa->currentState = 1;
            } else {
                dfa->currentState = 0;
            }
            break;
        case 3:
            // printf("%c\n", character);
            if (character == 'm') {
                dfa->currentState = 1;
            } else {
                dfa->currentState = 0;
            }
            break;
        default:
            dfa->currentState = 0;
            break;
    }
}

int isFinalStateDFA(const DFA* dfa) {
    return dfa->currentState == 3;
}

void freeDFA(DFA* dfa) {
    free(dfa);
}
