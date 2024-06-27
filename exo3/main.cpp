#include <iostream>
#include <fstream>
#include <string>
#include "header/exo3-1.h"
#include "header/exo3-2.h"


int main(int argc, char* argv[])  {
     if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename> [word]" << std::endl;
        return 1;
    }

    std::string filename = argv[1];

    if (argc == 2) {
        countMurOccurrences(filename);
    } else if (argc == 3) {
        std::string word = argv[2];
        countWordOccurrences(filename, word);
    } else {
        std::cerr << "Usage: " << argv[0] << " <filename> [word]" << std::endl;
        return 1;
    }

    return 0;
}



