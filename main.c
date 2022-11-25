#include <stdio.h>
#include "moteur.h"


int main() {
  //test moteur
    /*
     *Création de 5 avions pour le test ! 
     */
    avion* elmAvion1=initAvion();
    avion* elmAvion2=initAvion();
    avion* elmAvion3=initAvion();
    avion* elmAvion4=initAvion();
    avion* elmAvion5=initAvion();

    elmAvion1=creerAvion("azerty-uiop",AVIONLEGER,0,15);
    elmAvion2=creerAvion("Bouffon_AirLine",AVIONLIGNE,1,300);
    elmAvion3=creerAvion("L'ASILE",AVIONAFFAIRE,0,10);
    elmAvion4=creerAvion("OMG",AVIONLEGER,0,30);
    elmAvion5=creerAvion("CONSOLE.LOG(CANNARD!)",AVIONLIGNE,0,200);

    elmAvion1=empile(elmAvion1,elmAvion2);
    elmAvion1=empile(elmAvion1,elmAvion3);
    elmAvion1=empile(elmAvion1,elmAvion4);
    elmAvion1=empile(elmAvion1,elmAvion5);

    /*
     * Commande d'affichage de test 
     */
    afficheListe(elmAvion1);
    printf("\nelm crééééééé : %s\n",elmAvion1->identifiant);
//fin test moteur
    return 0;
}