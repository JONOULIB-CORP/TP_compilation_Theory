// Importation des librairis
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction principale Main
int main()
{
    // Déclaration des variables
    FILE *file;
    char key[] = "mur"; // Mot à rechercher
    int length = strlen(key);
    int counter = 0;
    char buffer[1024]; // Tampon pour lire les lignes du fichier

    // Ouverture du fichier en mode lecture
    file = fopen("input.txt", "r");
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
