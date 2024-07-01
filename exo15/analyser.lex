%{
#include "parser.tab.h"
%}

%%

[0-9]+      { yylval.intval = atoi(yytext); return INT; }
[ \t\n]+    { /* ignore whitespace */ }
"+"         { return '+'; }
"*"         { return '*'; }
.           { return yytext[0]; }

%%

int yywrap(void) {
    return 1;
}
