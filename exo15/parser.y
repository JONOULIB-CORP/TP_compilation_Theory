%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);

int result;  // Variable pour stocker le résultat de l'expression
%}

%union {
    int intval;  // Ajouter cette ligne pour définir un type de valeur entier
}

%token <intval> INT

%type <intval> E T F

%%

S : E { printf("Reduce S -> E    Fin!!!\n"); }
  ;

E : E '+' T { 
        printf("Reduce E -> E + T    $1=%d    $2='%c'    $3=%d    $$=%d\n", $1, '+', $3, $1 + $3); 
        $$ = $1 + $3; 
         
    }
  | T { 
        printf("Reduce E -> T    $1=%d    $$=%d\n", $1, $1); 
        $$ = $1; 
         
    }
  ;

T : T '*' F { 
        printf("Reduce T -> T * F    $1=%d    $2='%c'    $3=%d    $$=%d\n", $1, '*', $3, $1 * $3); 
        $$ = $1 * $3; 
    }
  | F { 
        printf("Reduce T -> F    $1=%d    $$=%d\n", $1, $1); 
        $$ = $1; 
    }
  ;

F : INT { 
        printf("Reduce F -> int    $1=%d    $$=%d\n", $1, $1); 
        $$ = $1; 
    }
  ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    if (yyparse() == 0) {
        printf("okay see you thank you Tp3: -> 30/30  \n");
    }
    return 0;
}
