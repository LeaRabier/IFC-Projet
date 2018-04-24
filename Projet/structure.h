#include "constantes.h"

typedef struct Joueurs Joueurs;
struct Joueurs
    {
        char nom[LONGUEURNOMMAX + 1];
        char mdp[20];
        int exp;
    };
