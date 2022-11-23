#ifndef ALGO_ASILISEN_S3_MOTEUR_H
#define ALGO_ASILISEN_S3_MOTEUR_H



typedef enum TypeAvion{
    AVIONLIGNE,
    AVIONAFFAIRE,
    AVIONLEGER,
    UNDEFINED
}TypeAvion;

typedef enum TypePiste {
    PETITE,
    MOYENNE,
    GRANDE
}TypePiste;

 
typedef struct avion {
    char identifiant[20];
    TypeAvion avionType;
    int etat;
    int nbPassagers;
    struct avion* prec;
    struct avion* suiv;
}avion;

typedef struct piste{
    int numPiste;
    int longueur;
    TypePiste pisteType;
    int nbAvionsMax;
    avion* listeAvion;
}piste;

avion* initAvion();
avion* creerAvion(char* id,TypeAvion avionType,int etat,int nbPassagers);


#endif
