%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);

int result;  // Variable pour stocker le resule ofde l'expression
%}

%union {
    int intval;  // Ajouter cette ligne pour define ofn type de valeur entier
}

%token <intval> INT

%type <intval> E T F

%%

S : E { printf("Reduce of S -> E    Fin de l'analyse !!!\n"); }
  ;

E : E '+' T { 
        printf("Reduce of E -> E + T    $1=%d    $2='%c'    $3=%d    $$=%d\n", $1, '+', $3, $1 + $3); 
        $$ = $1 + $3; 
        result = $$; 
    }
  | T { 
        printf("Reduce of E -> T    $1=%d    $$=%d\n", $1, $1); 
        $$ = $1; 
        result = $$; 
    }
  ;

T : T '*' F { 
        printf("Reduce of T -> T * F    $1=%d    $2='%c'    $3=%d    $$=%d\n", $1, '*', $3, $1 * $3); 
        $$ = $1 * $3; 
    }
  | F { 
        printf("Reduce of T -> F    $1=%d    $$=%d\n", $1, $1); 
        $$ = $1; 
    }
  ;

F : INT { 
        printf("Reduce of F -> int    $1=%d    $$=%d\n", $1, $1); 
        $$ = $1; 
    }
  ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    if (yyparse() == 0) {
        printf("okay see you thank you Tp3: -> 30/30   \n");
    }
    return 0;
}
