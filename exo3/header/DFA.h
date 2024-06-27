// DFA.h

#ifndef COMPILATION_TP_1_5_DFA_H
#define COMPILATION_TP_1_5_DFA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int currentState; // Variable privée pour suivre l'état actuel
} DFA;

// Constructeur
DFA* createDFA();

// Méthode pour réinitialiser le DFA
void resetDFA(DFA* dfa);

// Méthode pour traiter les caractères d'entrée
void processDFA(DFA* dfa, char character);

// Méthode pour vérifier si le DFA est dans un état final
int isFinalStateDFA(const DFA* dfa);

// Méthode pour libérer la mémoire allouée pour le DFA
void freeDFA(DFA* dfa);

#endif // COMPILATION_TP_1_5_DFA_H
