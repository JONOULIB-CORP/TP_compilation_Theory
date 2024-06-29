%{
#include <stdio.h>
#include "LexicalAnalyzer.h"
%}

%%

[0-9]+          { printf("<nombre:%s>\n", yytext); }
[\+\-\*/]       { printf("<operateur:%c>\n", *yytext); }
[ \t\n]         ; // Ignorer les espaces, tabulations et sauts de ligne
.               { printf("<caractere:%c>\n", *yytext); }

%%

void parseFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }

    yyin = file;
    yylex();
    fclose(file);
}
