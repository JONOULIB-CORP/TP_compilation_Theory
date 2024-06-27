//
// Created by noutcheu on 6/27/24.
//

#include "../header/exo3_2.h"

void countWordOccurrences(const char* filename, const char* word) {
    GeneralizedDFA* dfa = createGeneralizedDFA(word);
    int occurrenceCount = 0;
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error: File '%s' not found.\n", filename);
        return;
    }

    char character;
    while ((character = fgetc(file)) != EOF) {
        process(dfa, character);
        if (isFinalState(dfa)) {
            occurrenceCount++;
            reset(dfa);
        }
    }

    fclose(file);
    freeGeneralizedDFA(dfa);
    printf("Le nombre d'occurrences de '%s' est: %d\n", word, occurrenceCount);
}
