#include "moteur.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

avion* empile(avion* liste,avion* elm){
    avion* parcours=malloc(sizeof(avion));
    parcours=liste;
    while(parcours->suiv != NULL){
        parcours=parcours->suiv;
    }
    parcours->suiv=elm;
    elm->prec=parcours;
    return liste;
}

void afficheListe(avion* liste){
    printf("|       NOM       |   ETAT   |   AVIONTYPE  |\n");
    while(liste != NULL){
        printf("|%8s|",liste->identifiant);
        printf("%8d|",liste->etat);
        printf("%9d|\n",liste->avionType);
        liste=liste->suiv;
    }
}

int verifPiste(avion* avion,piste* piste){
    //piste petite/moy 
    if(piste->pisteType>0 && piste->pisteType <3) {
        if(avion->avionType == 1 || avion->avionType == 3){
            printf("peut atterir");
            return 0;
        }
        return 1;
    }
    //grandes pistes
    if(piste->pisteType==3){
        if(avion->avionType == 3 || avion->avionType == 2){
            return 0;
        }
        return 1;
    }
    printf("\n------------problème de piste------------\n");
    return 1;
}

