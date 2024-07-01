%{

#include <stdio.h>
#include "analyser.h"
%}
%%

[a-d]       { yylval.var = yytext[0] - 'a'; return VAR; }
print       { return PRINT; }
[0-9]+      { yylval.intval = atoi(yytext); return INT; }
[ \t\n]+    { /* ignorer les espaces blancs */ }
";"         { return ';'; }
"="         { return '='; }
"+"         { return '+'; }
"*"         { return '*'; }
.           { return yytext[0]; }

%%

int yywrap(void) {
    return 1;
}