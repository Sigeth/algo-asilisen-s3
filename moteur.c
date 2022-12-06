#include "moteur.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*function initAvion
 * return an struct avion type element with default value
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
    strncpy(elmAvion->identifiant,id,20);
    elmAvion->avionType=avionType;
    elmAvion->etat=etat;
    elmAvion->nbPassagers=nbPassagers;
    return elmAvion;
}


/*function initPiste
 * return a struct piste type element with default value
 */
piste* initPiste(){
    piste* elmPiste=malloc(sizeof(piste));
    elmPiste->pisteType=PARKING;
    elmPiste->liste=initListe();
    elmPiste->longueur=-1;
    elmPiste->numPiste=-1;
    elmPiste->prec=NULL;
    elmPiste->suiv=NULL;
    return elmPiste;
}


/*function compteurElm
 * return the nuber of 'avion'in a struct piste
 */
int cptElement(piste* PisteCpt){
    int cpt=0;
    listeAvion* tmp = PisteCpt->liste;
    while(tmp != NULL) {
        tmp=tmp->suiv;
        cpt++;
    }
    return cpt;
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
piste* creerPiste(int numPiste,int longueur,TypePiste pisteType,int nbAvionMax,listeAvion* elm){
    piste* elmPiste=malloc(sizeof(piste));
    elmPiste->liste=initListe(elm);
    elmPiste->numPiste=numPiste;
    elmPiste->liste=elm;
    elmPiste->longueur=longueur;
    elmPiste->pisteType=pisteType;
    elmPiste->nbAvionsMax = nbAvionMax;
    elmPiste->prec=NULL;
    elmPiste->suiv=NULL;
    return elmPiste;
}


/*function enfile, add an element "avion" in the queue 
 *@param avion* liste, the first element of the linked-list
 *@param avion* elm, the element to add to the queue
 *return the liste with the new element at the end
 */
listeAvion* enfile(listeAvion* liste,avion* elm){
    listeAvion* tmp=malloc(sizeof(listeAvion));
    tmp=liste;
    if (tmp == NULL) {
        tmp=creerListe(elm);
        return tmp;
    } else {
        if(tmp->suiv != NULL){
            while(tmp->suiv != NULL){
                tmp=tmp->suiv;
            }
            tmp->suiv=creerListe(elm);
            tmp->suiv->prec=tmp;
        }
        else {
            tmp->suiv=creerListe(elm);
            tmp->suiv->prec=tmp;
        }
    }
      return liste ;
}

/*function verifPiste, function to test if an element "avion" can take of or land
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
    if(piste->numPiste==3){
        if(avion->avionType ==  || avion->avionType == 2){
            return 0;
        }
        return 1;
    }
    printf("\n------------problème de piste------------\n");
    return 1;
}   


avion* getAvionWithName(char* name,listeAvion* listeAvion) {
    while(listeAvion->Elm != NULL ){
        if(strcmp(listeAvion->Elm->identifiant,name)==0){
            return listeAvion->Elm;
        }
        listeAvion=listeAvion->suiv;
    }
    return NULL;
}

piste* getPisteWithName(int name,piste* listePiste) {
    while(listePiste != NULL ){
        if(listePiste->numPiste == name){
            return listePiste;
        }
        listePiste=listePiste->suiv;
    }
    return NULL;
}

/*function atterir who serve to land an element "plane"
 *@param avion* avion, the plane concerned
 *@param piste* piste, the piste concenrned
 *return 0 if it's true or 1 else;
 */
int atterir(avion* avionA,piste* pisteA){
    printf("%d",avionA->etat);
    if(avionA->etat==1){
        if(verifPiste(avionA,pisteA)==0){
            avionA->etat=0;
            while(pisteA->pisteType != PARKING || pisteA->prec != NULL) {
                pisteA=pisteA->prec;
            }
            enfile(pisteA->liste,avionA);
            return 0;
        }
    }
    return 1;
}


int decolle(avion* avionD,piste* pisteD){
    if( strcmp(pisteD->liste->Elm->identifiant,avionD->identifiant)==0) {
    if(avionD->etat==0){
       if(verifPiste(avionD,pisteD)==0){
            avionD->etat=1;
            pisteD->liste=pisteD->liste->suiv;
            return 0;
    }
    }}
    return 1;
}


int deplace(avion* avionDplc,piste* pisteDepart, piste* pisteDplc){
      if(pisteDepart != pisteDplc && verifPiste(avionDplc,pisteDplc)==0){
        if(AvionInListe(pisteDepart,avionDplc)==0){
            enfile(pisteDplc->liste,avionDplc);
            pisteDepart->liste=supprElm(pisteDepart->liste,avionDplc);
            return 0;
            }
      }
      return 1;
    }

listeAvion* supprElm(listeAvion* liste, avion* Elm){
    listeAvion* tmp = liste;
    while(tmp->suiv != NULL ){
        if(strcmp(tmp->Elm->identifiant, Elm->identifiant) == 0){
            if(tmp->prec == NULL){
                tmp = tmp -> suiv;
                tmp -> prec = NULL;
                return tmp;
        }
            tmp->prec->suiv=tmp->suiv;
    }
        tmp=tmp->suiv;
    }
    return liste;
}


int AvionInListe(piste* pisteRecherche , avion * avionRecherche){
   listeAvion* tmp = pisteRecherche -> liste;
    while(tmp -> suiv != NULL) {
       if( strcmp(tmp->Elm->identifiant, avionRecherche->identifiant) == 0) {
            return 0 ;
        }
        tmp=tmp -> suiv;
    }
    return 1;
}

piste* RecherchePiste(piste* pisteR , avion* AvionR){
    printf("nom de l'avion : %s",AvionR->identifiant);
    printf("avion état : %d",AvionR->etat);
    while(pisteR ->suiv != NULL ){
        if(AvionInListe(pisteR,AvionR)== 0 ){
            return pisteR;
        }
        pisteR = pisteR -> suiv ;
    }
    if(AvionInListe(pisteR,AvionR)== 0 ){
            return pisteR;
        }
    return NULL;
}