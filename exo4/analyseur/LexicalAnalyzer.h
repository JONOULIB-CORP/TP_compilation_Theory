#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <iostream>
#include <fstream>
#include <string>

class LexicalAnalyzer {
public:
    void tokenizeArithmeticExpression(const std::string& expression);
    void parseFile(const std::string& filename);

private:
    enum State {
        START,
        INTEGER,
        OPERATOR,
        ERROR,
        END
    };

    State state;

    void outputToken(const std::string& token);
};

#endif // LEXICALANALYZER_H
