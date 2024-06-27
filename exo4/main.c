#include <stdio.h>
#include <stdlib.h>
#include "analyseur/LexicalAnalyzer.h"


int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    parseFile(argv[1]);

    return 0;
}



