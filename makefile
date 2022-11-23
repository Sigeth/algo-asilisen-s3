main: main.o affichage.o moteur.o sauvegarde.o menu.o
	gcc -Wall main.o -o main affichage.o moteur.o sauvegarde.o menu.o

main.o: main.c
	gcc -Wall -c main.c

affichage.o: affichage.c affichage.h
	gcc -Wall -c affichage.c

menu.o: menu.c menu.h
	gcc -Wall -c menu.c

moteur.o: moteur.c moteur.h
	gcc -Wall -c moteur.c

sauvegarde.o: sauvegarde.c sauvegarde.h
	gcc -Wall -c sauvegarde.c

clean:
	rm -f *~ *.o