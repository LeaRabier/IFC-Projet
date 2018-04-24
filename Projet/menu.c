#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "acquisition.h"
#include "outilMenu.h"
#include "constantes.h"

void menu(int indiceJoueur, Joueurs* listeJoueurs)
{
    system("title Menu");
    system("mode con lines=32 cols=120"); //attention, n'est pas en fonction du define

    char ecran[(LARGEUR +1)*HAUTEUR-1];
    initialiserEcran(ecran);
    graphismesMenu(ecran);

    //affichage de l'en tête
    int niveau[4]={0}, expManquante[5] = {0};
    calcNiveau(listeJoueurs[indiceJoueur].exp, &niveau, &expManquante);
    ecrireEcran(5,1,listeJoueurs[indiceJoueur].nom,ecran,20);
    ecrireEcran(65,1,"Niveau :",ecran,8);
    ecrireEcran(74,1,niveau,ecran,3);
    ecrireEcran(84,1,"Exp pour niveau suivant :",ecran,25);
    ecrireEcran(110,1,expManquante,ecran,5);

    //affichage des emilleurs joueurs
    ecrireEcran(XTOP3,YTOP3,"1er  :",ecran,6);
    ecrireEcran(XTOP3,YTOP3+2,"2eme :",ecran,6);
    ecrireEcran(XTOP3,YTOP3+4,"3eme :",ecran,6);
    for(int i = 0; i<3; i++)
    {
        ecrireEcran(XTOP3 + 7, YTOP3 + i * 2, listeJoueurs[i].nom,ecran,LONGUEURNOMMAX);
    }


    printf("%s",ecran);
    //afficher le menu, avec le top 3 des joueurs


   switch(choixMenu(3))
    {
    case 1:
//        menuJouer(joueur);
        break;
    case 2:
//        menuCour();
        break;
    case 3:
//        menuCredits();
        printf("e");
    }

}
