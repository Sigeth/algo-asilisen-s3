#include "menu.h"
#include "moteur.h"
#include "affichage.h"
#include "couleursAffichage.h"
#include <stdio.h>
#include <stdlib.h>

void menu(avion* liste,piste* PisteTEST){

	int menuPrincipal = 1;
	int choixMenu, choixAvion, choixPistes;
	int quitter = 0;

	while(menuPrincipal == 1){
		couleur("1;35");
		printf("==================================================================================================== MENU PRINCIPAL =====================================================================================================\n");
		printf("1 : Afficher avions\n");
		printf("2 : Afficher pistes\n");
		printf("3 : Quitter\n");
		printf("=========================================================================================================================================================================================================================\n");
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
				printf("------------------------------------------------------------------------------- Liste des avions -------------------------------------------------------------------------------\n");
				printf("Quel avions voulez-vous afficher ? ");
				scanf("%d", &choixAvion);
				printf("\n");
				printf("\n");
				switch(choixAvion)
				{
					case 1:
						while(quitter != 1){
							clrscr();
							printf("TEST 1\n");
							printf("\n");
							//couleur("41");
							printf("Appuyer sur 1 pour quitter et retourner au menu principal");
							//couleur("0");
							printf("\n");
							scanf("%d", &quitter);
							clrscr();
						}
						quitter = 0;
						clrscr();
						break;

					case 2:
						while(quitter != 1){
							clrscr();
							printf("TEST 2\n");
							printf("\n");
							//couleur("41");
							printf("Appuyer sur 1 pour quitter et retourner au menu principal");
							//couleur("0");
							printf("\n");
							scanf("%d", &quitter);
							clrscr();
						}
						quitter = 0;
						clrscr();
						break;

					case 3:
						clrscr();
						break;
				}
				break;

			case 2:
				//Afficher pistes
				//couleur("35");
				printf("------------------------------------------------------------------------------- Liste des pistes : -------------------------------------------------------------------------------\n");
				printf("Quel avions voulez-vous afficher ? ");
				//couleur("0");
				scanf("%d", &choixPistes);
				printf("\n");
				printf("\n");
				switch(choixPistes)
				{
					case 1:
						while(quitter != 1){
							clrscr();
							printf("TEST 1\n");
							printf("\n");
							//couleur("41");
							printf("Appuyer sur 1 pour quitter et retourner au menu principal");
							//couleur("0");
							printf("\n");
							scanf("%d", &quitter);
							clrscr();
						}
						quitter = 0;
						clrscr();
						break;

					case 2:
						while(quitter != 1){
							clrscr();
							printf("TEST 2\n");
							printf("\n");
							//couleur("41");
							printf("Appuyer sur 1 pour quitter et retourner au menu principal");
							//couleur("0");
							printf("\n");
							scanf("%d", &quitter);
							clrscr();
						}
						quitter = 0;
						clrscr();
						break;

					case 3:
						clrscr();
						break;
				}
				break;
				
			case 3:
				menuPrincipal = 0;
				break;
		}

	}

	printf("FIN\n");
	couleur("0");
}