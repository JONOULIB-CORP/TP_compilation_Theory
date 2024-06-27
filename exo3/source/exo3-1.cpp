//
// Created by noutcheu on 6/27/24.
//

#include "../header/exo3-1.h"


void countMurOccurrences(const std::string& filename) {
    DFA murDfa;
    int occurrenceCount = 0;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: File '" << filename << "' not found." << std::endl;
        return;
    }

    char character;
    while (file.get(character)) {
        murDfa.process(character);

        if (murDfa.isFinalState()) {
            occurrenceCount++;
            murDfa.reset();
        }
    }

    file.close();
    std::cout << "Le nombre d'occurrences de 'mur' est: " << occurrenceCount << std::endl;

} // DFA
