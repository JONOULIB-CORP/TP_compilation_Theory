//
// Created by noutcheu on 6/27/24.
//
#include "../header/exo3-2.h"

void countWordOccurrences(const std::string& filename, const std::string& word) {
    GeneralizedDFA dfa(word);
    int occurrenceCount = 0;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: File '" << filename << "' not found." << std::endl;
        return;
    }

    char character;
    while (file.get(character)) {
        dfa.process(character);
        if (dfa.isFinalState()) {
            occurrenceCount++;
            dfa.reset();
        }
    }

    file.close();
    std::cout << "Le nombre d'occurrences de '" << word << "' est: " << occurrenceCount << std::endl;
}