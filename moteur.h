#ifndef ALGO_ASILISEN_S3_MOTEUR_H
#define ALGO_ASILISEN_S3_MOTEUR_H



typedef enum TypeAvion{
    UNDEFINED,
    AVIONLEGER,
    AVIONLIGNE,
   AVIONAFFAIRE 
}TypeAvion;

typedef enum TypePiste {
    PARKING,
    PETITE,
    MOYENNE,
    GRANDE,
}TypePiste;

 
typedef struct avion {
    char identifiant[20];
    TypeAvion avionType;
    int etat; //0 au sol ; 1 en vol
    int nbPassagers;
}avion;

typedef struct piste{
    int numPiste;
    int longueur;
    TypePiste pisteType;
    int nbAvionsMax;
    struct listeAvion* liste;
    struct piste* prec;
    struct piste* suiv;
}piste;

typedef struct listeAvion{
    avion* Elm;
    struct listeAvion* prec;
    struct listeAvion* suiv;
}listeAvion;

piste* initPiste();
void affichePiste(piste* piste);
piste* creerPiste(int numPiste,int longueur,TypePiste pisteType,int nbAvionMax,avion* elm);
avion* initAvion();
piste* ajoutePiste(avion* avionAjout, piste* PisteAjout);
avion* creerAvion(char* id,TypeAvion avionType,int etat,int nbPassagers);
listeAvion* enfile(listeAvion* liste,avion* elm);
void afficheListe(listeAvion* liste);
int verifPiste(avion* avion,piste* piste);
int atterir(avion* avion,piste* piste);
int decolle(avion* avion,piste* piste);
int cptElement(piste* pisteR);
listeAvion* initListe();

#endif
