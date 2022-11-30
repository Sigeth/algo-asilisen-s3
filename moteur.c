#include "moteur.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*function initAvion
 * return an struct avion type elemnt with default value
 */
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


/*function creerAvion
 *@param char* id, the id name of the "avion"
 *@param TypeAvion avionType, the type of the "avion"
 *@param int etat, the status of the "avion" (on the ground or in the air)
 *@param int nbPassagers, the number of the passengers
 *return an struct avion type elemnt with value passed in parameter;
 */
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


/*function initAvion
 * return an struct avion type elemnt with default value
 */
piste* initPiste(){
    piste* elmPiste=malloc(sizeof(avion));
    elmPiste->pisteType=UNDEFINED;
    elmPiste->longueur=-1;
    elmPiste->numPiste=-1;
    elmPiste->prec=NULL;
    elmPiste->suiv=NULL;
    for(int i=0;i<30;i++){
        strcpy(elmPiste->liste[i],"XXX-XXX-XXX");
    }
    return elmPiste;
}



/*function creerAvion
 *@param char* id, the id name of the "avion"
 *@param TypeAvion avionType, the type of the "avion"
 *@param int etat, the status of the "avion" (on the ground or in the air)
 *@param int nbPassagers, the number of the passengers
 *return an struct avion type elemnt with value passed in parameter;
 */
piste* creerPiste(int numPiste,int longueur,TypePiste pisteType,int nbAvionMax,char * liste){
    piste* elmPiste=malloc(sizeof(piste));
    for(int i=0;i<30;i++){
        if(strcmp(elmPiste->liste[i],"XXX-XXX-XXX")!=1){
            strcpy(elmPiste->liste[i],liste);
            break;
        }
        if(i==29){
            strcpy(elmPiste->liste[i],liste);
        }
    }
    elmPiste->numPiste=numPiste;
    elmPiste->longueur=longueur;
    elmPiste->pisteType=pisteType;
    elmPiste->prec=NULL;
    elmPiste->suiv=NULL;
    return elmPiste;
}


/*function enfile, add an element "avion" in the queue 
 *@param avion* liste, the first element of the linked-list
 *@param avion* elm ,the element to add to the queue
 *return the liste with the new element at the end
 */
avion* enfile(avion* liste,avion* elm){
    avion* parcours=malloc(sizeof(avion));
    parcours=liste;
    elm->suiv=NULL;
    elm->prec=NULL;
    while(parcours->suiv != NULL){
        parcours=parcours->suiv;
    }
    parcours->suiv=elm;
    elm->prec=parcours;
    return liste;
}

/*function afficheListe,debug function
 *@param avion* liste, the first element of the linked-list
 */
void afficheListe(avion* liste){
    printf("|       NOM       |   ETAT   |   AVIONTYPE  |\n");
    while(liste != NULL){
        printf("|%8s|",liste->identifiant);
        printf("%8d|",liste->etat);
        printf("%9d|\n",liste->avionType);
        liste=liste->suiv;
    }
}

void affichePiste(piste* piste){
    printf("|      NumPiste      |   Longueur   |   PISTETYPE  |\n");
    while(piste != NULL){
        printf("|%15d|",piste->numPiste);
        printf("%8d|",piste->longueur);
        printf("%9d|\n",piste->pisteType);
        piste=piste->suiv;
    }
}

/*function verifPiste , function to test if an element "avion" can take of or land
 *@param avion* avion, the plane concerned
 *@param piste* piste, the piste concenrned
 *return 0 if it's true or 1 else;
 */
int verifPiste(avion* avion,piste* piste){
    //small or medium runway 
    if(piste->pisteType!=PARKING && piste->pisteType <3) {
        if(avion->avionType == 1 || avion->avionType == 3){
            printf("peut atterir");
            return 0;
        }
        return 1;
    }
    //large runway
    if(piste->pisteType==3){
        if(avion->avionType == 3 || avion->avionType == 2){
            return 0;
        }
        return 1;
    }
    printf("\n------------problème de piste------------\n");
    return 1;
}   


/*function atterir who serve to land an element "plane"
 *@param avion* avion, the plane concerned
 *@param piste* piste, the piste concenrned
 *return 0 if it's true or 1 else;
 */
int atterir(avion* avionA,piste* pisteA){
    if(avionA->etat==1){
        if(verifPiste(avionA,pisteA)==0){
            avionA->etat=0;
            printf("atterissage réussi !\n");
            return 0;
        }
    }
    return 1;
}


/*function decole who serve to take of an element "plane"
 *@param avion* avion, the plane concerned (the first of the queue)
 *@param piste* piste, the piste concenrned
 *return 0 if it's true or 1 else;
 */
avion* rechercheParNom(avion* liste, char* nom){
      while(liste != NULL){
        if(strcmp(liste->identifiant,nom)){
            return liste;
        }
        liste=liste->suiv;
    }
    return NULL;
}



int decolle(avion* avionD,piste* pisteD){
    if(rechercheParNom(avionD,pisteD->liste[0])== avionD) {
        if(avionD->etat==0){
        if(verifPiste(avionD,pisteD)==0){
            avionD->etat=1;
            for(int i=1;i<30;i++){
                strcpy(pisteD->liste[i-1],pisteD->liste[i]);
            }
            printf("décollage réussi !\n");
            return 0;
        }
    }
    }
    return 1;
}
