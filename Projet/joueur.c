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
    fseek(fichierJoueur, 13, SEEK_SET); //replacer le curseur apr�s le titre
    return nbJoueur;
}

Joueurs* chargerJoueurs(int* nbJoueur)
{
    FILE* fichier = NULL;
    fichier = fopen("donnees\\joueur.txt", "r");
    if(fichier == NULL){
        printf("ERREUR DANS LA LECTURE DU FICHIER \"Joueur\" :(");
        exit(0);
    }

    (*nbJoueur) = nbJoueurs(fichier);
    Joueurs* tableauJoueurs = NULL;
    tableauJoueurs = malloc(*nbJoueur * sizeof(Joueurs));
    if (tableauJoueurs == NULL){
        printf("ACCES A LA MEMOIRE REFUSE");
         exit(0);
    }

    for(int i = 0; i < *nbJoueur; i++)
    {
        fscanf(fichier,"%s %s %d\n", tableauJoueurs[i].nom, tableauJoueurs[i].mdp, &tableauJoueurs[i].exp);
    }

    fclose(fichier);
    return tableauJoueurs;
}

void calcNiveau(int experience, char niveau[], char expManquante[])
{
    int i = 25, intNiveau = 0, sommeExp = 25;
    while (sommeExp <= experience)
    {
        i += (int)(i/4);
        sommeExp += i;
        intNiveau++;
    }
    sprintf(niveau, "%d", intNiveau);
    sprintf(expManquante, "%d", sommeExp - experience);
}



