#include "menu.h"
#include "moteur.h"
#include "affichage.h"
#include "couleursAffichage.h"
#include <stdio.h>
#include <stdlib.h>


/*function menu, print the principal menu in the terminal
 *@param avion* liste, the list of the planes
 *@param piste* pisteTEST, the liste of the runways
 */
void menu(listeAvion* liste, piste* PisteTEST){

	int menuPrincipal = 1;
	int choixMenu;
	char* choixAvion = malloc(sizeof(char)*20);
	int choixPistes;
	int quitter = 0;

	while(menuPrincipal == 1){

		quitter = 0;
		//Marche bien pour $COLUMNS = 135
		couleur("1;35");
		printf("=========================================================== MENU PRINCIPAL ===========================================================\n");
		printf("|                                                         1 : Afficher avions                                                        |\n");
		printf("|                                                         2 : Afficher pistes                                                        |\n");
		printf("|                                                         3 : Quitter                                                                |\n");
		printf("======================================================================================================================================\n");
		printf("\n");
		printf("Que voulez-vous faire ? ");
		scanf("%d", &choixMenu);
		printf("\n");
		printf("\n");

		switch(choixMenu)
		{
			case 1:
				//Afficher avions
				clrscr();
				printf("---------------------------------------------------------- Liste des avions ----------------------------------------------------------\n");
				afficheListeAvion(liste);
				printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("Quel avions voulez-vous afficher ? ");
				scanf("%s", choixAvion);
				printf("\n");
				printf("\n");
				while(quitter != 1){
					avion* avionAAfficher = getAvionWithName(choixAvion, liste);
					if(avionAAfficher == NULL){
						printf("Cet avion n'existe pas.\n");
					}
					else{
						afficheAvion(avionAAfficher);
					}
					printf("\n");
					printf("Appuyer sur 1 pour quitter et retourner au menu principal");
					printf("\n");
					scanf("%d", &quitter);
					clrscr();
				}
				clrscr();
				break;

			case 2:
				//Afficher pistes
				clrscr();
				printf("---------------------------------------------------------- Liste des pistes ----------------------------------------------------------\n");
				affichePisteAvion(PisteTEST);
				printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("Quelle piste voulez-vous afficher ? ");
				scanf("%d", &choixPistes);
				printf("\n");
				printf("\n");
				while(quitter != 1){
					piste* pisteAAfficher = getPisteWithName(choixPistes, PisteTEST);
					affichePisteAvion(pisteAAfficher);
					printf("\n");
					printf("Appuyer sur 1 pour quitter et retourner au menu principal");
					printf("\n");
					scanf("%d", &quitter);
					clrscr();
				}
				clrscr();
				break;
				
			case 3:
				menuPrincipal = 0;
				break;
		}

	}

	printf("FIN\n");
	couleur("0");
}