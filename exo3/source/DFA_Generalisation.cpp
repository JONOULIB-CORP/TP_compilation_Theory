//
// Created by noutcheu on 6/27/24.
//

#include "../header/DFA_Generalisation.h"


GeneralizedDFA::GeneralizedDFA(const std::string& word) : word(word), currentState(0) {
    transitions.reserve(word.size());
    for (size_t i = 0; i < word.size(); ++i) {
        transitions.emplace_back(word[i], i + 1);
    }
}


void GeneralizedDFA::reset() {
    currentState = 0;
}

void GeneralizedDFA::process(char character) {
    if (currentState < transitions.size() &&
        transitions[currentState].first == character) {
        currentState = transitions[currentState].second;
    } else {
        currentState = 0;
        if (transitions[0].first == character) { // handle immediate reset case
            currentState = 1;
        }
    }
}


bool GeneralizedDFA::isFinalState() const {
    return currentState == word.size();
}
