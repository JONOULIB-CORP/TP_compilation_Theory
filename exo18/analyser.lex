%{

#include <stdio.h>

#include "analyser.h"
%}

%%

[0-9]+      { yylval.intval = atoi(yytext); return INT; }
[ \t\n]+    { /* ignore whitespace */ }
[a-d]       { yylval.var = yytext[0]; return VAR; }
"print"     { return PRINT; }
"="         { return '='; }
";"         { return ';'; }
"+"         { return '+'; }
"*"         { return '*'; }
.           { return yytext[0]; }

%%

int yywrap(void) {
    return 1;
}
