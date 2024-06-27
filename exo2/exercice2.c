// Importation des librairis
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tailleMax 100

// Fonction principale Main
int main(int argc, char** argv)
{

    // Déclaration des variables
    FILE* file;

    char* key = (char *)malloc(sizeof(char) * tailleMax); // Mot à rechercher
    key = argv[2];
    int length = strlen(key);

    int counter = 0;
    char buffer[1024]; // Tampon pour lire les lignes du fichier

    // Ouverture du fichier en mode lecture
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Une erreur est survenue lors de l'ouverture du fichier");
        return 1;
    }

    // Lecture du fichier ligne par ligne
    while (fgets(buffer, sizeof(buffer), file))
    {
        char *position = buffer;

        while ((position = strstr(position, key)) != NULL)
        {
            counter++;
            position += length;
        }
    }

    fclose(file);
    printf("Le nombre d'occurences du mot est : %d .\n", counter);

    return 0;
}