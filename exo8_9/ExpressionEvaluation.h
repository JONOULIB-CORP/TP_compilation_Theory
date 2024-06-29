// ExpressionEvaluation.h
#ifndef EXPRESSIONEVALUATION_H
#define EXPRESSIONEVALUATION_H

#define MAX_TOKEN_SIZE 263
#include "utilitaire.h"

int eval_expr_sans_prio(char *expression);
void exp_post_fixe_sans_prio(const char* expr, char* result);
void exp_post_fixe_avec_prio(const char* expr, char* result);
int evaluate_postfix(const char* expr);

#endif // EXPRESSIONEVALUATION_H
