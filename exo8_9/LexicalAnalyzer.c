#include "LexicalAnalyzer.h"



void tokenizeArithmeticExpression(const char* expression) {
    State state = START;
    char token[MAX_TOKEN_SIZE] = "";
    size_t index = 0;
    size_t tokenIndex = 0;

    while (state != END && index < strlen(expression)) {
        char currentChar = expression[index];
        switch (state) {
            case START:
                if (isdigit(currentChar)) {
                    state = INTEGER;
                    token[tokenIndex++] = currentChar;
                } else if (currentChar == '+' || currentChar == '*') {
                    state = OPERATOR;
                    token[tokenIndex++] = currentChar;
                } else {
                    state = ERROR;
                }
                break;

            case INTEGER:
                if (isdigit(currentChar)) {
                    token[tokenIndex++] = currentChar;
                } else if (currentChar == '+' || currentChar == '*') {
                    token[tokenIndex] = '\0';
                    char output[OUTPUT_SIZE];
                    snprintf(output, sizeof(output), "<int:%s>", token);
                    outputToken(output);
                    tokenIndex = 0;
                    memset(token, 0, sizeof(token));
                    state = OPERATOR;
                    token[tokenIndex++] = currentChar;
                } else {
                    state = ERROR;
                }
                break;

            case OPERATOR:
                token[tokenIndex] = '\0';
                char output[OUTPUT_SIZE];
                snprintf(output, sizeof(output), "<operator:%s>", token);
                outputToken(output);
                tokenIndex = 0;
                memset(token, 0, sizeof(token));
                if (isdigit(currentChar)) {
                    state = INTEGER;
                    token[tokenIndex++] = currentChar;
                } else {
                    state = ERROR;
                }
                break;

            case ERROR:
                fprintf(stderr, "Parse error at position %zu\n", index);
                return;

            default:
                state = ERROR;
                break;
        }
        index++;
    }

    if (state == INTEGER) {
        token[tokenIndex] = '\0';
        char output[OUTPUT_SIZE];
        snprintf(output, sizeof(output), "<int:%s>", token);
        outputToken(output);
    } else if (state == OPERATOR) {
        token[tokenIndex] = '\0';
        char output[OUTPUT_SIZE];
        snprintf(output, sizeof(output), "<operator:%s>", token);
        outputToken(output);
    } else if (state == ERROR) {
        fprintf(stderr, "Parse error at position %zu\n", index);
    }
    printf("\n");
}

void parseFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: File '%s' not found.\n", filename);
        return;
    }

    char line[MAX_TOKEN_SIZE];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';  // Remove newline character
        tokenizeArithmeticExpression(line);
    }

    fclose(file);
}

void outputToken(const char* token) {
    printf("%s", token);
}