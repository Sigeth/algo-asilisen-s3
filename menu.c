#include "menu.h"
#include "moteur.h"
#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>

void menu(avion* liste,piste* PisteTEST){

	int menuPrincipal = 1;
	int choixMenu, choixAvion, choixPistes;
	int quitter = 0;

	while(menuPrincipal == 1){

		printf("========== MENU PRINCIPAL ==========\n");
		printf("1 : Afficher avions\n");
		printf("2 : Afficher pistes\n");
		printf("3 : Quitter\n");
		printf("====================================\n");
		printf("\n");
		printf("Que voulez-vous faire ? ");
		scanf("%d", &choixMenu);
		printf("\n");
		printf("\n");

		switch(choixMenu)
		{
			case 1:
				//Afficher avions
				printf("----- Liste des avions : -----\n");
				printf("Quel avions voulez-vous afficher ? ");
				scanf("%d", &choixAvion);
				printf("\n");
				printf("\n");
				switch(choixAvion)
				{
					case 1:
						while(quitter != 1){
							printf("TEST 1\n");
							printf("Appuyer sur 1 pour quitter et retourner au menu principal\n");
							scanf("%d", &quitter);
							system("clear");
						}
						quitter = 0;
						system("clear");
						break;

					case 2:
						while(quitter != 1){
							printf("TEST 2\n");
							printf("Appuyer sur 1 pour quitter et retourner au menu principal\n");
							scanf("%d", &quitter);
							system("clear");
						}
						quitter = 0;
						system("clear");
						break;

					case 3:
						system("clear");
						break;
				}
				break;

			case 2:
				//Afficher pistes
				printf("----- Liste des pistes : -----\n");
				printf("Quel avions voulez-vous afficher ? ");
				scanf("%d", &choixPistes);
				printf("\n");
				printf("\n");
				switch(choixPistes)
				{
					case 1:
						while(quitter != 1){
							printf("TEST 1\n");
							printf("Appuyer sur 1 pour quitter et retourner au menu principal\n");
							scanf("%d", &quitter);
							system("clear");
						}
						quitter = 0;
						system("clear");
						break;

					case 2:
						while(quitter != 1){
							printf("TEST 2\n");
							printf("Appuyer sur 1 pour quitter et retourner au menu principal\n");
							scanf("%d", &quitter);
							system("clear");
						}
						quitter = 0;
						system("clear");
						break;

					case 3:
						system("clear");
						break;
				}
				break;
				
			case 3:
				menuPrincipal = 0;
				break;
		}

	}

	printf("FIN\n");
}