#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "constantes.h"
#include "joueur.h"

int main()
{
    Joueurs* joueurs = NULL;
    int indiceJoueur = 0; //l'indice du joueur connecté, dans le tableau joueurs
    connexion(joueurs, &indiceJoueur); //avec joueurs mis a jour en cas de nouveau compte

    //Joueurs* joueurs = chargerJoueurs(); pris en charge par "connexion"

    menu(joueurs[indiceJoueur], joueurs);

    /* test affichage joueurs : ok
    for(int i = 0; i<4;i++)
    {
        printf("%s | %s | %d\n",joueurs[i].nom, joueurs[i].mdp, joueurs[i].exp);
    }
    /**/


    free(joueurs); //Libérer la place prise en mémoire pour les joueurs

    return 0;
}
