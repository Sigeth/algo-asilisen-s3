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
    struct avion* prec;
    struct avion* suiv;
}avion;

typedef struct piste{
    int numPiste;
    int longueur;
    TypePiste pisteType;
    int nbAvionsMax;
    char liste[20][30];//décolage
    struct piste* prec;
    struct piste* suiv;
}piste;

piste* initPiste();
void affichePiste(piste* piste);
piste* creerPiste(int numPiste,int longueur,TypePiste pisteType,int nbAvionMax,char * liste);
avion* initAvion();
avion* creerAvion(char* id,TypeAvion avionType,int etat,int nbPassagers);
avion* enfile(avion* liste,avion* elm);
void afficheListe(avion* liste);
int verifPiste(avion* avion,piste* piste);
int atterir(avion* avion,piste* piste);
int decolle(avion* avion,piste* piste);

#endif
