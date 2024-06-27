// DFA.cpp

#include "../header/DFA.h"


DFA::DFA() : currentState(0) {
    currentState = 0;
}

void DFA::reset() {
    currentState = 0;
}

void DFA::process(char character) {
    switch (currentState) {
        case 0:
//            std::cout <<character <<std::endl;
            if (character == 'm') currentState = 1;
            else currentState = 0;
            break;
        case 1:
//            std::cout <<character <<std::endl;
            if (character == 'u') currentState = 2;
            else if  (character == 'm') currentState = 1;
            else currentState = 0;
            break;
        case 2:
//            std::cout <<character <<std::endl;
            if (character == 'r') currentState = 3;
            else if  (character == 'm') currentState = 1;
            else currentState = 0;
            break;
        case 3:
//            std::cout <<character <<std::endl;
            if (character == 'm') currentState = 1;
            else currentState = 0;
            break;
        default:
            currentState = 0;
            break;
    }
}

bool DFA::isFinalState() const {
    return currentState == 3;
}

