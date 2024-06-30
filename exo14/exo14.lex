%{
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

extern int yylex();

void yyerror(const char *s);

#define INT 1001
#define PLUS 1002
#define TIMES 1003
#define DIVIDE 1004

typedef enum { S_INIT, S_EXPR, S_OP_PLUS, S_OP_TIMES } State;
int yylval;
State currentState;
StackNode *stack = NULL;

void pushState(State state);
State popState();


%}

%option noyywrap

%%
[0-9]+      { yylval = atoi(yytext); return INT; }
"+"         { return PLUS; }
"*"         { return TIMES; }
"/"         { return DIVIDE; }
[ \t\n]+    { /* Ignore whitespace */ }
.           { yyerror("Unrecognized character"); }
%%


void pushState(State state) {
    push(&stack, (int)state);
}

State popState() {
    return (State)pop(&stack);
}

void parseExpression() {
    currentState = S_INIT;
    pushState(S_INIT);

    int token;
    while ((token = yylex()) != 0) {
        printf("token: %d (lexeme: %s)\n", token, yytext);
        switch (currentState) {
            case S_INIT:
                if (token == INT) {
                    printf("E -> int\n");
                    currentState = S_EXPR;
                } else {
                    yyerror("Syntax error in state S_INIT");
                }
                break;
            case S_EXPR:
                if (token == PLUS) {
                    printf("E -> E + E (start)\n");
                    pushState(S_OP_PLUS);
                    currentState = S_INIT;
                } else if (token == TIMES) {
                    printf("E -> E * E (start)\n");
                    pushState(S_OP_TIMES);
                    currentState = S_INIT;
                } else {
                    yyerror("Syntax error in state S_EXPR");
                }
                break;
            case S_OP_PLUS:
                if (token == INT) {
                    printf("E -> E + E (end)\n");
                    currentState = popState();
                } else {
                    yyerror("Syntax error in state S_OP_PLUS");
                }
                break;
            case S_OP_TIMES:
                if (token == INT) {
                    printf("E -> E * E (end)\n");
                    currentState = popState();
                } else {
                    yyerror("Syntax error in state S_OP_TIMES");
                }
                break;
            default:
                yyerror("Unexpected state");
        }
    }

     while (stack != NULL) {
        State op = popState();
        printf("E -> E %s E (end)\n", op == S_OP_PLUS ? "+" : "*");
    }

    if (currentState == S_EXPR) {
        printf("Valid expression\n");
    } else {
        yyerror("Syntax error: invalid expression");
    }
}

int main() {
    stack = NULL;
    parseExpression();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    exit(1);
}
