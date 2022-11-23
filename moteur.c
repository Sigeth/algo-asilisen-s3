#include "moteur.h"
#include <string.h>

avion* initAvion(){
    avion* elmAvion=malloc(sizeof(avion));
    elmAvion->avionType=UNDEFINED;
    elmAvion->etat=-1;
    strcpy(elmAvion->identifiant,"XXX-XXX-XXX");
    elmAvion->nbPassagers=-1;
    elmAvion->prec=NULL;
    elmAvion->suiv=NULL;
    return elmAvion;
}

avion* creerAvion(char* id,TypeAvion avionType,int etat,int nbPassagers){
    avion* elmAvion=malloc(sizeof(avion));
    strcpy(elmAvion->identifiant,id);
    elmAvion->avionType=avionType;
    elmAvion->etat=etat;
    elmAvion->nbPassagers=nbPassagers;
    elmAvion->prec=NULL;
    elmAvion->suiv=NULL;
    return elmAvion;
}


