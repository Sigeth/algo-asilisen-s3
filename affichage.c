#include "affichage.h"
#include "moteur.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

/*function affiche_avion
 * print a fast animation of a flying plane
 */

void animationAvion(int etat)
{
char temp[800] = "";
char espace [200]= " ";
char retour_ligne [61]= " \n\n\n\n\n\n\n";
char ligne1  [61] = "                       ___                                 \n";
char ligne2  [61] = "                       \\\\ \\                             \n";
char ligne3  [61] = "                        \\\\ `\\                           \n";
char ligne4  [61] = "     ___                 \\\\  \\                          \n";
char ligne5  [61] = "    |   \\                 \\\\  `\\                       \n";
char ligne6  [61] = "    |    \\                 \\\\  `\\                      \n";
char ligne7  [61] = "    |______\\                \\    `\\                     \n";
char ligne8  [61] = "    |       \\                \\     \\                    \n";
char ligne9  [61] = "    |      __\\__---------------------------------._.      \n";
char ligne10 [61] = "  __|---~~~__o_o_o_o_o_o_o_o_o_o_o_o_o_o_o_o_o_o_[][\\__   \n";
char ligne11 [61] = " |___                         /~      )                \\__\n";
char ligne12 [61] = "     ~~~---..._______________/      ,/_________________/   \n";
char ligne13 [61] = "                            /      /                       \n";
char ligne14 [61] = "                           /     ,/                        \n";
char ligne15 [61] = "                         /     ,/                          \n";
char ligne16 [61] = "                        /     /                            \n";
char ligne17 [61] = "                       /    ,/                             \n";
char ligne18 [61] = "                      /    /                               \n";
char ligne19 [61] = "                     //  ,/                                \n";
char ligne20 [61] = "                    //  /                                  \n";
char ligne21 [61] = "                   // ,/                                   \n";
char ligne22 [61] = "                  //_/                                     \n";


for(int i = 0; i<60;i++)
{
    system("clear"); 
    if(etat == 1)
    {
        printf("%s",retour_ligne);
    }
    for(int j = i; j>0;j--)
        {
            printf("%c",ligne1[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne2[60-j]);
        }
            
        
        for(int j = i; j>0;j--)
        {
            printf("%c",ligne3[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne4[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne5[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne6[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne7[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne8[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne9[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne10[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne11[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne12[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne13[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne14[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne15[60-j]);
        }


        for(int j = i; j>0;j--)
        {
            printf("%c",ligne16[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne17[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne18[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne19[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne20[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne21[60-j]);
        }

        for(int j = i; j>0;j--)
        {
            printf("%c",ligne22[60-j]);
        }


        tempo(10000000);
        

}

int cpt=strlen(retour_ligne);

for(int s = 0; s<73;s++)
{
    system("clear");

if(etat == 1)
{
for(int i = 0; i<cpt; i++)
{
    printf("%c",retour_ligne[i]);
}
}



strcpy(temp,espace);
strcat(temp,ligne1);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne2);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne3);
printf("%s",temp);



strcpy(temp,espace);
strcat(temp,ligne4);
printf("%s",temp);


strcpy(temp,espace);
strcat(temp,ligne5);
printf("%s",temp);


strcpy(temp,espace);
strcat(temp,ligne6);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne7);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne8);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne9);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne10);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne11);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne12);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne13);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne14);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne15);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne16);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne17);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne18);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne19);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne20);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne21);
printf("%s",temp);

strcpy(temp,espace);
strcat(temp,ligne22);
printf("%s",temp);

if(s%10 == 0 && etat == 1)
{
    cpt-=1;
}



strcat(espace," ");
tempo(10000000);
}

strcpy( ligne1   , "                       ___                                 ");
strcpy( ligne2   , "                       \\\\ \\                             ");
strcpy( ligne3   , "                        \\\\ `\\                           ");
strcpy( ligne4   , "     ___                 \\\\  \\                          ");
strcpy( ligne5   , "    |   \\                 \\\\  `\\                       ");
strcpy( ligne6   , "    |    \\                 \\\\  `\\                      ");
strcpy( ligne7   , "    |______\\                \\    `\\                     ");
strcpy( ligne8   , "    |       \\                \\     \\                    ");
strcpy( ligne9   , "    |      __\\__---------------------------------._.      ");
strcpy( ligne10  , "  __|---~~~__o_o_o_o_o_o_o_o_o_o_o_o_o_o_o_o_o_o_[][\\__   ");
strcpy( ligne11  , " |___                         /~      )                \\__");
strcpy( ligne12  , "     ~~~---..._______________/      ,/_________________/   ");
strcpy( ligne13  , "                            /      /                       ");
strcpy( ligne14  , "                           /     ,/                        ");
strcpy( ligne15  , "                         /     ,/                          ");
strcpy( ligne16  , "                        /     /                            ");
strcpy( ligne17  , "                       /    ,/                             ");
strcpy( ligne18  , "                      /    /                               ");
strcpy( ligne19  , "                     //  ,/                                ");
strcpy( ligne20  , "                    //  /                                  ");
strcpy( ligne21  , "                   // ,/                                   ");
strcpy( ligne22  , "                  //_/                                     ");
system("clear");

    for(int i = 0; i<61;i++)
    {   system("clear");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne1[j]);
        }
        
        printf("\n");
        
        
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne2[j]);

        }
        printf("\n");
        printf("%s",espace);

        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne3[j]);
        }
        printf("\n");

        printf("%s",espace);

        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne4[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne5[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne6[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne7[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne8[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne9[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne10[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne11[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne12[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne13[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne14[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne15[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne16[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne17[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne18[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne19[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne20[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne21[j]);
        }
        printf("\n");
        printf("%s",espace);
        for(int j = 0; j<60-i;j++)
        {
            printf("%c",ligne22[j]);
        }
        printf("\n");
        
            strcat(espace," ");
    
        tempo(10000000);
        system("clear");
        

}

if(etat == 1)
        {
            animationAvion(0);
        }
        

}

/*function tempo
 * allows you to delay
 */

void tempo(int temp)
{
    double cpt = 0;
    while(cpt != temp)
    {
        cpt+=1;
    }
}



/*function afficheListeAvion
 * Print the list of the planes
 */

void afficheListeAvion(listeAvion* liste){
    printf("                            _________________________________________________________________________________\n");
    printf("                            |    NOM    |      ETAT     |       AVIONTYPE      |     nombre de passagers    |\n");
    printf("                            ---------------------------------------------------------------------------------\n");
    while(liste != NULL){
        printf("                            |%6s     |",liste->Elm->identifiant);
        if(liste->Elm->etat == 0){
            printf("     au sol    |");
        }
        else{
            printf("     en vol    |");
        }

        switch (liste->Elm->avionType)
        {
        case UNDEFINED:
            printf("       Indéfinie      |");
            break;
        case AVIONLEGER: 
            printf("     Avion léger      |");
            break;
        
        case AVIONAFFAIRE: 
            printf("    Avion d'affaire   |");
            break;
        
        case AVIONLIGNE: 
            printf("     Avion de ligne   |");

        default:

            break;
        }
        printf("%15d%14s\n",liste->Elm->nbPassagers,"|");
        liste=liste->suiv;
    }
    printf("                            ---------------------------------------------------------------------------------\n");
}


void afficheAvion(avion* avion){
    printf("                            _________________________________________________________________________________\n");
    printf("                            |    NOM    |      ETAT     |       AVIONTYPE      |     nombre de passagers    |\n");
    printf("                            ---------------------------------------------------------------------------------\n");
    printf("                            |%6s     |",avion->identifiant);
        if(avion->etat == 0){
            printf("     au sol    |");
        }
        else{
            printf("     en vol    |");
        }

        switch (avion->avionType)
        {
        case UNDEFINED:
            printf("       Indéfinie      |");
            break;
        case AVIONLEGER: 
            printf("     Avion léger      |");
            break;
        
        case AVIONAFFAIRE: 
            printf("    Avion d'affaire   |");
            break;
        
        case AVIONLIGNE: 
            printf("     Avion de ligne   |");

        default:

            break;
        }
        printf("%15d%14s\n",avion->nbPassagers,"|");
        printf("                            ---------------------------------------------------------------------------------\n");
}



/*function affichePisteAvion
 * Print the list of piste
 */

void affichePisteAvion(piste* piste){
    printf("                                    ________________________________________________________________\n");
    printf("                                    |      NumPiste      |   Longueur   |   PISTETYPE  |  NBAvion  |\n");
    printf("                                    ----------------------------------------------------------------\n");
    while(piste != NULL){
        printf("                                    |%11d%10s",piste->numPiste,"|");
        printf("%9d%6s",piste->longueur,"|");
        switch (piste->pisteType)
        {
        case PARKING:
            printf("   parking    |\n");
            break;
        case PETITE:
            printf("    petite    |\n");
            break;
        
        case MOYENNE:
            printf("   moyenne    |\n");
            break;
        case GRANDE:
            printf("   grande     |\n");
            break;
        default:
            break;
        }

        piste=piste->suiv;
    }
    printf("                                    ----------------------------------------------------------------\n");
    
}

void affichePiste(piste* piste){
    printf("                                    ________________________________________________________________\n");
    printf("                                    |      NumPiste      |   Longueur   |   PISTETYPE  |  NBAvion  |\n");
    printf("                                    ----------------------------------------------------------------\n");
    printf("                                    |%11d%10s",piste->numPiste,"|");
    printf("%9d%6s",piste->longueur,"|");
    switch (piste->pisteType)
    {
    case PARKING:
        printf("   parking    |\n");
        break;
    case PETITE:
        printf("    petite    |\n");
        break;
        
    case MOYENNE:
        printf("   moyenne    |\n");
        break;
    case GRANDE:
        printf("   grande     |\n");
        break;
    default:
        break;
    }
    printf("                                    ----------------------------------------------------------------\n");
    
}





