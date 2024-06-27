#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

#define MAX_TOKEN_SIZE 247
#define OUTPUT_SIZE 247

typedef enum {
    START,
    INTEGER,
    OPERATOR,
    ERROR,
    END
} State;

void tokenizeArithmeticExpression(const char* expression);
void parseFile(const char* filename);
void outputToken(const char* token);

#endif // LEXICALANALYZER_H
