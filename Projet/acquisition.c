#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int choixMenu(int nbChoix)
{
    char touche = 0;
    do
    {
        touche = getch();
    }
    while(touche < '1' || touche >= '1' + nbChoix);

    return(touche - 64);

}


int lireTexte (char chaine[],int longueur, int type) //type normal, code, maj, min
{
    char touche = 0;
    int indice = 0;
    do
    {
        touche = getch();
        if(indice < longueur &&((touche == ' ')||(touche >= 'a' && touche <= 'z')||(touche >= 'A' && touche <= 'Z'))) //||(touche>='0' && touche <= '9')) //pour inclure les chiffres
        {
            //printf("\nboucle avec n = %d \n",indice);
            switch(type)
            {
            case 1:
                chaine[indice] = (char)touche;
                printf("%c",chaine[indice]);
                break;
            case 2:
                chaine[indice] = touche;
                printf("*");
                break;
            case 3:
                chaine[indice] = toupper(touche);
                printf("%c",chaine[indice]);
                break;
            case 4:
                chaine[indice] = tolower(touche);
                printf("%c",chaine[indice]);
                break;
            }
            indice++;
        }else
        {
            switch(touche)
            {
            case 8: //touche supr
                if (indice > 0)
                    {
                        printf("\b \b");
                        indice--;
                        chaine[indice] = 0;
                    }
                break;
            }
        }
    }
    while(touche != 13);
    chaine[indice] = '\0';
    return(indice);
}



int lireEntier(int longueur, int min, int max)
{
    int valeur = 0;
    char touche;
    char* chaine = NULL;
    chaine = malloc(longueur*sizeof(char));
    if (chaine == NULL){
        printf("ACCES A LA MEMOIRE REFUSE");
        exit(0);
    }
    int signe = 1;
    int indice = 0;

    do //attente touche entrer
    {
        touche = getch();
        printf("              \b\b\b\b\b\b\b\b\b\b\b\b\b\b"); //reinitialisation du message d'erreur
        if(indice < longueur &&(touche >= '0' && touche <= '9'))
        {
            chaine[indice] = touche-48;
            printf("%d",chaine[indice]);
            indice++;
        }else
        {
            switch(touche)
            {
            case 8: //touche supr
                if (indice > 0 || signe == -1) //conditions a ameliorer
                {
                    printf("\b \b");
                    if(indice != 0 || signe == 1)//si on n'a pas effacer le signe -
                    {
                        indice--;
                    }else
                    {
                        signe = 1;
                    }
                    chaine[indice] = 0;
                }
                break;
            case '-':
                if(indice == 0)
                {
                    signe = -1;
                    printf("-");
                }
                break;
            }
        }
        valeur = signe * charToInt(chaine,indice);

        if(valeur > max && (touche == 13 || signe == 1))
        {
            printf("  Trop grand !\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        }
        if(valeur < min && (touche == 13 || signe == -1))
        {
            printf("  Trop petit !\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        }
    }
    while( !((touche == 13) && valeur >= min && valeur <= max)); //touche entrer

    free(chaine);
    return(valeur);
}

int puissance10(int valeur) //prefferable a pow car defini en 0 et ne nécésite pas de cast en double/int
{
    int resultat = 1;
    for(int j = 0; j<valeur;j++)
    {
        resultat *= 10;
    }
    return(resultat);
}

int charToInt(char* chaine, int longueur)
{
    int resultat =0;

    for(int i=0;i<longueur;i++)
    {
        resultat = resultat +chaine[i] * puissance10(longueur - i-1);
    }
    return(resultat);
}
