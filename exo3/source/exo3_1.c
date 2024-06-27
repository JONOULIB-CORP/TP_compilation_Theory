//
// Created by noutcheu on 6/27/24.
//

#include "../header/exo3_1.h"

void countMurOccurrences(const char* filename) {
    DFA* murDfa = createDFA();
    int occurrenceCount = 0;
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error: File '%s' not found.\n", filename);
        return;
    }

    char character;
    while ((character = fgetc(file)) != EOF) {
        processDFA(murDfa, character);

        if (isFinalStateDFA(murDfa)) {
            occurrenceCount++;
            resetDFA(murDfa);
        }
    }

    fclose(file);
    freeDFA(murDfa);
    printf("Le nombre d'occurrences de 'mur' est: %d\n", occurrenceCount);
}
