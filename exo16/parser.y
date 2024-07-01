%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);

int result;  // Variable pour stocker le résultat de l'expression
%}

%union {
    int intval;  // Type union pour les valeurs entières
}

%token <intval> INT  // Définir le type de token pour les entiers

%type <intval> E T F  // Définir les types pour les symboles non-terminaux

%%

S : E { 
        printf("Réduction de S -> E    Fin de l'analyse !!!\n");
        result = $1;  // Stocker le résultat final
    }
  ;

E : E '+' T { 
        printf("Réduction de E -> E + T    $1=%d    $2='%c'    $3=%d    $$=%d\n", $1, '+', $3, $1 + $3); 
        $$ = $1 + $3; 
    }
  | T { 
        printf("Réduction de E -> T    $1=%d    $$=%d\n", $1, $1); 
        $$ = $1; 
    }
  ;

T : T '*' F { 
        printf("Réduction de T -> T * F    $1=%d    $2='%c'    $3=%d    $$=%d\n", $1, '*', $3, $1 * $3); 
        $$ = $1 * $3; 
    }
  | F { 
        printf("Réduction de T -> F    $1=%d    $$=%d\n", $1, $1); 
        $$ = $1; 
    }
  ;

F : INT { 
        printf("Réduction de F -> int    $1=%d    $$=%d\n", $1, $1); 
        $$ = $1; 
    }
  ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erreur: %s\n", s);
}

int main(void) {
    if (yyparse() == 0) {
        printf("Résultat de l'expression : %d\n", result);
        printf("okay see you thank you Tp3: -> 30/30  \n");
    }
    return 0;
}
