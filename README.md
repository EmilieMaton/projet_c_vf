# Jeu en C – Sauvegarde de Scores

Ce projet est un petit programme en C qui permet de jouer à un des jeux simple de mathématiques niveau cm1 et de sauvegarder les scores des joueurs automatiquement dans un fichier. Chaque score est enregistré avec le nom du joueur et la date/heure de la partie.

## Fonctionnalités

- Jouer aux jeux depuis le terminal
- Sauvegarder les scores
- Fichiers de test inclus pour vérifier le bon fonctionnement des modules

## Installation

Pour compiler le projet, utilisez `gcc` (ou tout compilateur C compatible) :


gcc main.c fonctions_utiles.c fonctions_jeux.c -o main

Puis exécuter le programme :

./main.exe

## Organisation du projet
main.c : point d’entrée du programme
fonctions_utiles.c/h : fonctions utilitaires réutilisables
fonctions_jeux.c/h : fonctions liées au fonctionnement du jeu
scores.txt : fichier de sauvegarde des scores
test_fonctions_jeux.c : fichiers de test pour valider les fonctions jeux
test_fonctions_utiles.c : fichiers de test pour valider les fonctions utiles





MATON Emilie
AMAR Lina
