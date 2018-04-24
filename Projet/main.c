#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include "joueur.h"
#include "menu.h"

int main()
{
    system("color F0");
    //Joueurs* joueurs = NULL;
    int nbJoueurs =0; //necesaire pour faire des states
    int indiceJoueur = 0; //l'indice du joueur connecté, dans le tableau joueurs
    //connexion(joueurs, &indiceJoueur, nbJoueur); //avec joueurs mis a jour en cas de nouveau compte

    //pris en charge par "connexion" : debuging :
    Joueurs* joueurs = chargerJoueurs(&nbJoueurs);
    indiceJoueur = 0; //pour test

    menu(indiceJoueur, joueurs);

    /* test affichage joueurs : ok
    for(int i = 0; i<4;i++)
    {
        printf("%s | %s | %d\n",joueurs[i].nom, joueurs[i].mdp, joueurs[i].exp);
    }
    */


    free(joueurs); //Libérer la place prise en mémoire pour les joueurs

    return 0;
}
