#ifndef EXO14_H
#define EXO14_H

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yylval;
void yyerror(const char *s);

#define INT 1001
#define PLUS 1002
#define TIMES 1003
#define DIVIDE 1004

typedef enum { S_INIT, S_EXPR, S_OP_PLUS, S_OP_TIMES } State;
extern int yylval;  // Declaration of yylval as extern
extern State currentState;  // Declaration of currentState as extern
extern StackNode *stack;  // Declaration of stack as extern


void pushState(State state);
State popState();

#endif
