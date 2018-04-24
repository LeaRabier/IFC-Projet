#include "constantes.h"
#include "structure.h"

void initialiserEcran(char ecran[])
{
    for(int y =0; y < HAUTEUR; y++)
    {
        for(int x = 0; x < LARGEUR; x++)
        {
            ecran[y*(LARGEUR +1 ) + x] = ' ';
        }
        ecran[(y + 1)*(LARGEUR +1 ) - 1] = '\n';
    }
    ecran[(LARGEUR +1)*HAUTEUR-1] = '\0';
}

void ecrireEcran(int x, int y, char mot[], char ecran[], int tailleMax)
{
    int longueurMot = strlen(mot);
    if(longueurMot < tailleMax) tailleMax = longueurMot;

    for(int i = 0; i < tailleMax; i++)
    {
        ecran[y*(LARGEUR +1 ) + x + i] = mot[i];
    }
}

void afficherTop3(Joueurs listeJoueur[])
{




}




