#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#include "utilitaire.h"
#include "LexicalAnalyzer.h"
#include "ExpressionEvaluation.h"
#define MAX_EXPRESSION_SIZE 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <nom_fichier>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char expression[MAX_EXPRESSION_SIZE];
    if (fgets(expression, sizeof(expression), file) == NULL) {
        perror("Erreur lors de la lecture de l'expression depuis le fichier");
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("Expression lue : %s\n", expression);
    printf("Expression Analyse :");
    parseFile(argv[1]);
    
    char result_avec_prio[MAX_EXPRESSION_SIZE];
    char result_sans_prio[MAX_EXPRESSION_SIZE];

    // Convertir l'expression en postfixe avec priorité
    exp_post_fixe_avec_prio(expression, result_avec_prio);
    printf("Expression postfixe avec priorité : %s\n", result_avec_prio);

    int eval_prio = evaluate_postfix(result_avec_prio);
    printf("Résultat de l'évaluation avec priorité : %d\n", eval_prio);

    // Convertir l'expression en postfixe sans priorité
    exp_post_fixe_sans_prio(expression, result_sans_prio);
    printf("Expression postfixe sans priorité : %s\n", result_sans_prio);

    int eval_sans_prio = eval_expr_sans_prio(result_sans_prio);
    printf("Résultat de l'évaluation sans priorité : %d\n", eval_sans_prio);

    return 0;
}
