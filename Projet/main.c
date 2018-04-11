#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "constantes.h"
#include "joueur.h"

int main()
{
    Joueurs* tableauJoueurs = NULL;
    chargerJoueurs(tableauJoueurs);
    printf("%d", sizeof(int));
    printf("%s",tableauJoueurs[0].exp);



    free(tableauJoueurs);
    return 0;
}
