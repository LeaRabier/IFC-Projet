
#include "constantes.h"
#include "outilMenu.h"

void graphismesMenu(char ecran[])
{

    ecrireEcran(XCHOIXMENU, YCHOIXMENU, " ", 45);


    //En tête
    for(int i = 1; i< LARGEUR-2; i++)
    {
        ecrireEcran(i,2,"_",ecran,1);
    }

    //cadre top 3
    ecrireEcran(XTOP3-2,YTOP3-2,"#",ecran,1);
    ecrireEcran(XTOP3-2,YTOP3+6,"#",ecran,1);
    for(int i = 0; i< 9 + LONGUEURNOMMAX; i++)
    {
        ecrireEcran(XTOP3-1 + i,YTOP3-2,"-",ecran,1);
        ecrireEcran(XTOP3-1 + i,YTOP3 + 6,"-",ecran,1);
    }
    ecrireEcran(XTOP3+8+LONGUEURNOMMAX,YTOP3-2,"#",ecran,1);
    ecrireEcran(XTOP3+8+LONGUEURNOMMAX,YTOP3+6,"#",ecran,1);
    for(int i = 0; i<7; i++)
    {
        ecrireEcran(XTOP3-2,YTOP3-1 + i,"|",ecran,1);
        ecrireEcran(XTOP3+8+LONGUEURNOMMAX,YTOP3-1 + i,"|",ecran,1);
    }





}
