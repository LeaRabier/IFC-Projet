#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

int nbJoueurs(FILE* fichierJoueur)
{
    int nbJoueur = 0;
    char c;
        while((c=fgetc(fichierJoueur)) != EOF)
        {
            if(c=='\n')
                nbJoueur++;
        }
        return nbJoueur;
}

int chargerJoueurs(Joueurs* tableauJoueurs)
{
    FILE* fichier = NULL;
    fichier = fopen("donnees/joueur.csv", "r+");

    if(fichier != NULL)
    {
        //Joueurs* tableauJoueurs = NULL;
        tableauJoueurs = malloc(nbJoueurs(fichier) * sizeof(Joueurs));
        if (tableauJoueurs == NULL) exit(0);

        fseek(fichier, 1, SEEK_SET);

        fscanf(fichier,"%s;%s;%d", tableauJoueurs[0].nom, tableauJoueurs[0].mdp, &tableauJoueurs[0].exp);

        fclose(fichier);
        return 1;
    }
    return 0;

    //printf("val 1 : %d\nval 2 : %d", valeurl, valeur2);

}
