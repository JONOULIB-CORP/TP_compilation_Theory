%{
#include "parser.tab.h"
%}

%% 
[0-9]+  { yylval = atoi(yytext); return NUMBER; }
[ \t]   ;  // ignore whitespace
\+      { return PLUS; }
\*      { return TIMES; }
\n      { return 0; }
.       { return yytext[0]; }  // return any other character as itself

%%
