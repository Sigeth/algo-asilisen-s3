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
    return elmAvion;
}


/*function initAvion
 * return an struct avion type elemnt with default value
 */
piste* initPiste(){
    piste* elmPiste=malloc(sizeof(piste));
    elmPiste->pisteType=UNDEFINED;
    elmPiste->liste=initListe();
    elmPiste->longueur=-1;
    elmPiste->numPiste=-1;
    elmPiste->prec=NULL;
    elmPiste->suiv=NULL;
    return elmPiste;
}




listeAvion* initListe(){
    listeAvion* listeInit=malloc(sizeof(listeAvion));
    listeInit->Elm=malloc(sizeof(avion));
    listeInit->Elm=initAvion();
    return listeInit;
}

listeAvion* creerListe(avion* AvionC){
    listeAvion* listeInit=malloc(sizeof(listeAvion));
    listeInit->Elm=malloc(sizeof(avion));
    listeInit->Elm=AvionC;
    listeInit->prec=NULL;
    listeInit->suiv=NULL;
    return listeInit;
}

/*function creerAvion
 *@param char* id, the id name of the "avion"
 *@param TypeAvion avionType, the type of the "avion"
 *@param int etat, the status of the "avion" (on the ground or in the air)
 *@param int nbPassagers, the number of the passengers
 *return an struct avion type elemnt with value passed in parameter;
 */
piste* creerPiste(int numPiste,int longueur,TypePiste pisteType,int nbAvionMax,avion* elm){
    piste* elmPiste=malloc(sizeof(piste));
    elmPiste->liste=initListe(elm);
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
listeAvion* enfile(listeAvion* liste,avion* elm){
    listeAvion* parcour=malloc(sizeof(listeAvion));
    parcour=liste;
    while(parcour->suiv->Elm != NULL){
        parcour=parcour->suiv;
    }
    parcour->suiv->Elm=elm;
    return parcour;
}


/*function afficheListe,debug function
 *@param avion* liste, the first element of the linked-list
 */
void afficheListe(listeAvion* liste){
    printf("|       NOM       |   ETAT   |   AVIONTYPE  |\n");
    while(liste != NULL){
        printf("|%8s|",liste->Elm->identifiant);
        printf("%8d|",liste->Elm->etat);
        printf("%9d|\n",liste->Elm->avionType);
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






int decolle(avion* avionD,piste* pisteD){
    if( pisteD->liste->Elm== avionD) {
        if(avionD->etat==0){
        if(verifPiste(avionD,pisteD)==0){
            avionD->etat=1;
            pisteD->liste->suiv=NULL;
            pisteD->liste=pisteD->liste->suiv;
            printf("décollage réussi !\n");
            return 0;
        }
    }
    }
    return 1;
}
