%{
#include "analyser.h"
%}

%%

[0-9]+      { yylval.intval = atoi(yytext); return INT; }
[ \t\n]+    { /* ignorer les espaces blancs */ }
"+"         { return '+'; }
"*"         { return '*'; }
.           { return yytext[0]; }

%%

int yywrap(void) {
    return 1;
}
