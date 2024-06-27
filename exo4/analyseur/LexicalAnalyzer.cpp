#include "LexicalAnalyzer.h"

void LexicalAnalyzer::tokenizeArithmeticExpression(const std::string& expression) {
    state = START;
    std::string token;
    size_t index = 0;

    while (state != END && index < expression.size()) {
        char currentChar = expression[index];
        switch (state) {
            case START:
                if (isdigit(currentChar)) {
                    state = INTEGER;
                    token += currentChar;
                } else if (currentChar == '+' || currentChar == '*') {
                    state = OPERATOR;
                    token += currentChar;
                } else {
                    state = ERROR;
                }
                break;

            case INTEGER:
                if (isdigit(currentChar)) {
                    token += currentChar;
                } else if (currentChar == '+' || currentChar == '*') {
                    outputToken("<int:" + token + ">");
                    token = "";
                    state = OPERATOR;
                    token += currentChar;
                } else {
                    state = ERROR;
                }
                break;

            case OPERATOR:
                outputToken("<operator:" + token + ">");
                token = "";
                if (isdigit(currentChar)) {
                    state = INTEGER;
                    token += currentChar;
                } else {
                    state = ERROR;
                }
                break;

            case ERROR:
                std::cerr << "Parse error at position " << index << std::endl;
                return;

            default:
                state = ERROR;
                break;
        }
        index++;
    }

    if (state == INTEGER) {
        outputToken("<int:" + token + ">");
    } else if (state == OPERATOR) {
        outputToken("<operator:" + token + ">");
    } else if (state == ERROR) {
        std::cerr << "Parse error at position " << index << std::endl;
    }
    std::cout << std::endl;
}

void LexicalAnalyzer::parseFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: File '" << filename << "' not found." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        tokenizeArithmeticExpression(line);
    }

    file.close();
}

void LexicalAnalyzer::outputToken(const std::string& token) {
    std::cout << token;
}
