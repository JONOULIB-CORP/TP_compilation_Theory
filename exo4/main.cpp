#include <iostream>
#include <fstream>
#include <string>
#include "analyseur/LexicalAnalyzer.h"


int main(int argc, char* argv[])  {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    
    LexicalAnalyzer lexer;
    lexer.parseFile(argv[1]);

    return 0;
}



