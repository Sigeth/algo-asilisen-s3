# Logiciel de gestion d'un aéroport - Asil'ISEN

Projet du semestre 3 d'Algorithmie réalisé à l'ISEN Méditerranée. Projet du groupe Asil'ISEN.

## Manuel d'utilisation

### Utilisation et première compilation

Le programme est écrit en C et nécessite quelques étapes pour être correctement lancé :
- Ouvrir un terminal
- Importer le programme : `git clone https://github.com/Sigeth/algo-asilisen-s3.git`
- Entrer dans le fichier créé : `cd algo-asilisen-s3`
- Si vous le souhaitez, générer une nouvelle base de données
- - `make bdd`
- - `./generateBdd`
- Compiler le programme avec `make`
- Lancer le programme avec `./main`

## Architecture et répartition des tâches
Pour ce projet, nous avons choisi de séparer le programme en 4 grandes parties.<br>
Le tableau ci-dessous décrit les objectifs de chaque partie, ainsi que les personnes s'en étant occupées.

| Partie     | Responsable          | Fonctionnement                                                                                                                                                                                                                                                                                     |
|------------|----------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Moteur     | SCHNEIDER Bastient   | Crée toutes les fonctions permettant au programme de fonctionner correctement. Il crée les structures, les énumérations, ainsi que les fonctions permettant de décoller et atterrir, et toutes les fonctions que l'on ne voit pas qui sont néanmoins nécessaires au bon fonctionnement du logiciel |
| Affichage  | SOLA Maxime          | Permet à l'utilisateur de visualiser les données que le moteur utilise. Il permet notamment d'afficher les pistes et les avions, ainsi que de rendre le décollage et l'atterrissage des avions agréable visuellement pour l'utilisateur                                                            |
| Menu       | SERVET-BOUDOU Isaure | Unifie chaque partie. Le menu permet de récupérer toutes les informations que l'utilisateur veut communiquer au logiciel, et permet à chaque partie d'être appelée et utilisée au bon moment, uniquement quand l'utilisateur le demande.                                                           |
| Sauvegarde | SEIGNOUR Thomas      | Crée une base de données utilisable par les autres parties. Cette partie permet à chaque utilisateur de sauvegarder l'état actuel lorsqu'ils quittent le programme, ou à charger l'état dans lequel ils se trouvaient avant de fermer le logiciel.                                                 |

## Informations complémentaires
- Groupe Asil'ISEN composé de 
- - Thomas SEIGNOUR (chef de projet)
- - Bastient SCHNEIDER
- - SERVET-BOUDOU Isaure
- - SOLA Maxime
- Projet rendu le 06/12/2022


