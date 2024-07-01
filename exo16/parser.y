%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(const char *s);
int yylex(void);
%}

%token NUMBER
%token PLUS TIMES

%left PLUS
%left TIMES

%%
expr: 
    expr PLUS expr   { printf("%d\n", $1 + $3); }
  | expr TIMES expr  { printf("%d\n", $1 * $3); }
  | NUMBER           { $$ = $1; }
  ;

%%

void yyerror(const char *s) {
  fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
  return yyparse();
}
