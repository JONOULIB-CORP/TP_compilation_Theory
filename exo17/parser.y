%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);

int vars[4];  // Variables prédéfinies a, b, c, d

%}

%union {
    int intval;
    int var;
}

%token <intval> INT
%token <var> VAR
%token PRINT

%type <intval> E T F

%%

S : L
  ;

L : L STMT
  | STMT
  ;

STMT : VAR '=' E ';' { 
            vars[$1] = $3;
            printf("Affectation: %c = %d\n", 'a' + $1, $3); 
        }
     | PRINT VAR ';' { 
            printf("Impression: %c = %d\n", 'a' + $2, vars[$2]); 
        }
     ;

E : E '+' T { $$ = $1 + $3; }
  | T { $$ = $1; }
  ;

T : T '*' F { $$ = $1 * $3; }
  | F { $$ = $1; }
  ;

F : INT { $$ = $1; }
  | VAR { $$ = vars[$1]; }
  ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erreur: %s\n", s);
}

int main(void) {
    if (yyparse() == 0) {
        printf("Analyse terminée avec succès.\n");
    }
    return 0;
}
