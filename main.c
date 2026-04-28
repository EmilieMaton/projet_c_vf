#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "fonctions_jeux.h"
#include "fonctions_utiles.h"


int main(){ 
    
// Déclaration des variables

    int choix=-1;
    char nom[20];
    int score;
    int ancien_score;
    
// Générateur de nombre aléatoire

    srand(time(NULL));

// Chargement score de l'utilisateur

    printf("Veuillez saisir votre Pseudo: ");
    scanf("%s", nom);
    score = chargerScore(nom);
    printf("Score actuel : %d\n", score);

    
    while (choix!=0){
        printf("+------------------------------------+\n");
        printf("|1  : Addition                       |\n");
        printf("|2  : Soustraction                   |\n");
        printf("|3  : Multiplication                 |\n");
        printf("|4  : Tables des multiplications     |\n");
        printf("|5  : Divisions                      |\n");
        printf("|6  : Conversions: Longueurs         |\n");
        printf("|7  : Conversions: Masses            |\n");
        printf("|8  : Conversions: Aires             |\n");
        printf("|9  : Conversions: Duree             |\n");
        printf("|10 : Les grands nombres             |\n");
        printf("|11 : Problemes                      |\n");
        printf("|12 : Jeu des operations             |\n");
        printf("|13 : Fractions                      |\n");
        printf("|14 : Angle d un triangle            |\n");
        printf("|15 : Statistique: Moyenne           |\n");
        printf("|16 : Calcul: Aires                  |\n");
        printf("|0  : Sortir du jeu                  |\n");
        printf("+------------------------------------+\n");

        printf("Quel est votre choix ? ");
        //contrôle de saisie
        while (scanf("%d", &choix) != 1 ) {
            printf("Saisir un entier positif.\n");
            while (getchar() != '\n');  
        }
// Menu        
        switch(choix){

            case 0: printf("Merci de votre visite\n");
            printf("Score: %d",score); // Affichage du nouveau score 
            break;

            case 1:
            printf("\n");
            printf("+------------+\n");
            printf("|  ADDITION  |\n");
            printf("+------------+\n");
            printf("\n");
            ancien_score = score; // sauvegarde de l'ancien score
            score = addition(score); // appel de la fonction correspondant au jeu
            if (score != ancien_score) { // sauvegarde du score si modification 
                sauvegarderScore(nom, score);
            }
        
            break;

            case 2:
            printf("\n");
            printf("+----------------+\n");
            printf("|  SOUSTRACTION  |\n");
            printf("+----------------+\n");
            printf("\n");
            ancien_score = score;
            score = soustraction(score);
            if (score != ancien_score) {
                sauvegarderScore(nom, score);
            }
            break;

            case 3:
            printf("\n");
            printf("+------------------+\n");
            printf("|  MULTIPLICATION  |\n");
            printf("+------------------+\n");
            printf("\n");
            ancien_score = score;
            score = multiplication(score);
            if (score != ancien_score) {
                sauvegarderScore(nom, score);
            }
            break;

            case 4:
            printf("\n");
            printf("+-------------------------------+\n");
            printf("|  TABLES DE MULTIPLICATION     |\n");
            printf("+-------------------------------+\n");
            printf("\n");
            ancien_score = score;
            score = ChoixTable(score);
            if (score != ancien_score) {
                sauvegarderScore(nom, score);
            }
            break;

            case 5:
            printf("\n");
            printf("+-------------+\n");
            printf("|  DIVISION   |\n");
            printf("+-------------+\n");
            printf("\n");
            ancien_score = score;
            score = division(score);
            if (score != ancien_score) {
                sauvegarderScore(nom, score);
            }
            break;

            case 6:
            printf("\n");
            printf("+-------------------------+\n");
            printf("| CONVERSIONS: LONGUEURS  |\n");
            printf("+-------------------------+\n");
            printf("\n");
            ancien_score = score;
            score = conversion_longueur(score);
            if (score != ancien_score) {
                sauvegarderScore(nom, score);
            }
            break;

            case 7:
            printf("\n");
            printf("+----------------------+\n");
            printf("| CONVERSIONS: MASSES  |\n");
            printf("+----------------------+\n");
            printf("\n");
            ancien_score = score;
            score = conversion_masse(score);
            if (score != ancien_score) {
                sauvegarderScore(nom, score);
            }
            break;

            case 8:
            printf("\n");
            printf("+---------------------+\n");
            printf("| CONVERSIONS: AIRES  |\n");
            printf("+---------------------+\n");
            printf("\n");
            ancien_score = score;
            score = conversion_aires(score);
            if (score != ancien_score) {
                sauvegarderScore(nom, score);
            }
            break;

            case 9:
            printf("\n");
            printf("+---------------------+\n");
            printf("| CONVERSION: DUREES  |\n");
            printf("+---------------------+\n");
            printf("\n");
            ancien_score = score;
            score = conversion_duree(score);
            if (score != ancien_score) {
                sauvegarderScore(nom, score);
            }
            break;

            case 10:
            printf("\n");
            printf("+----------------------+\n");
            printf("|  LES GRANDS NOMBRES  |\n");
            printf("+----------------------+\n");
            printf("\n");
            ancien_score = score;
            score = grands_nombres(score);
            if (score != ancien_score) {
                sauvegarderScore(nom, score);
            }
            break;

            case 11:
            printf("\n");
            printf("+-------------+\n");
            printf("|  PROBLEMES  |\n");
            printf("+-------------+\n");
            printf("\n");
            ancien_score = score;
            score = probleme(score);
            if (score != ancien_score) {
                sauvegarderScore(nom, score);
            }
            break;

            case 12:
            printf("\n");
            printf("+------------------------+\n");
            printf("|  JEU DES OPERATIONS    |\n");
            printf("+------------------------+\n");
            printf("\n");
            ancien_score = score;
            score = jeu_op(score);
            if (score != ancien_score) {
                sauvegarderScore(nom, score);
            }
            break;

            case 13:
            printf("\n");
            printf("+-------------+\n");
            printf("|  FRACTIONS  |\n");
            printf("+-------------+\n");
            printf("\n");
            ancien_score = score;
            score = fractions(score);
            if (score != ancien_score) {
                sauvegarderScore(nom, score);
            }
            break;

            case 14:
            printf("\n");
            printf("+--------------------------+\n");
            printf("|   ANGLES D'UN TRIANGLE   |\n");
            printf("+--------------------------+\n");
            printf("\n");
            ancien_score = score;
            score = angle_triangle(score);
            if (score != ancien_score) {
                sauvegarderScore(nom, score);
            }
            break;

            case 15:
            printf("\n");
            printf("+--------------------------+\n");
            printf("|  STATISTIQUE: MOYENNE    |\n");
            printf("+--------------------------+\n");
            printf("\n");
            ancien_score = score;
            score = moyenne(score);
            if (score != ancien_score) {
                sauvegarderScore(nom, score);
            }
            break;

            case 16:
            printf("\n");
            printf("+----------------+\n");
            printf("|  CALCUL AIRES  |\n");
            printf("+----------------+\n");
            printf("\n");
            ancien_score = score;
            score = calcul_aires(score);
            if (score != ancien_score) {
                sauvegarderScore(nom, score);
            }
            break;
            default : printf ("Le choix doit être compris entre 0 et 15.\n");
        }
    }
    return score;
}

