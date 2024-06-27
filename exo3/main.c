#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/exo3_1.h"
#include "header/exo3_2.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage:  ./exo3  <filename> or \n  ./exo3  <filename> [word] ", argv[0]);
        return 1;
    }

    char* filename = argv[1];

    if (argc == 2) {
        countMurOccurrences(filename);
    } else if (argc == 3) {
        char* word = argv[2];
        countWordOccurrences(filename, word);
    } else {
        printf("Usage: ./exo3  <filename> [word] \n");
        return 1;
    }

    return 0;
}
