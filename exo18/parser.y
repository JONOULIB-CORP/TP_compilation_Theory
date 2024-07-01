%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);

int variables[4] = {0, 0, 0, 0};  // Variables prédéfinies : a, b, c, d
%}

%union {
    int intval;
    char var;
}

%token <intval> INT
%token <var> VAR
%token PRINT

%type <intval> expr

%%

program:
    program statement
  | /* empty */
  ;

statement:
    assignment
  | print_stmt
  ;

assignment:
    VAR '=' expr ';' {
        int index = $1 - 'a';  // Conversion du caractère en index (0 pour 'a', 1 pour 'b', etc.)
        variables[index] = $3;
        printf("Affectation: %c = %d\n", $1, $3);
    }
  ;

print_stmt:
    PRINT VAR ';' {
        int index = $2 - 'a';
        printf("Impression: %c = %d\n", $2, variables[index]);
    }
  ;

expr:
    expr '+' expr {
        $$ = $1 + $3;
    }
  | expr '*' expr {
        $$ = $1 * $3;
    }
  | INT {
        $$ = $1;
    }
  | VAR {
        int index = $1 - 'a';
        $$ = variables[index];
    }
  ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    if (yyparse() == 0) {
        printf("Analyse terminée avec succès.\n");
    }
    return 0;
}
