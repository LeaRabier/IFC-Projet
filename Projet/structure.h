
typedef struct Joueurs Joueurs;
struct Joueurs
    {
        char nom[20];
        char mdp[20];
        int exp;
        Joueurs* JoueurSuivant;
    };
