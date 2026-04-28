#ifndef FONCTIONS_JEUX_H
#define FONCTIONS_JEUX_H

/**
 * @file module1.h
 * @brief Déclarations des fonctions des jeux (addition, multiplication, etc.)
 *
 * Ce module contient toutes les fonctions de jeux qui interagissent
 * avec l'utilisateur et utilisent le module2.
 */

//======================================= JEU ADDITION
/**
 * @brief Jeu d'addition
 * @param score Score actuel du joueur
 * @return Nouveau score après le jeu
 */
int addition(int score);

//======================================= JEU MULTIPLICATION
/**
 * @brief Jeu de multiplication
 * @param score Score actuel du joueur
 * @return Nouveau score après le jeu
 */
int multiplication(int score);

//======================================= JEU SOUSTRACTION
/**
 * @brief Jeu de soustraction
 * @param score Score actuel du joueur
 * @return Nouveau score après le jeu
 */
int soustraction(int score);

//======================================= JEU TABLES MULTIPLICATION
/**
 * @brief Choix d'une table de multiplication pour le jeu
 * @param score Score actuel du joueur
 * @return Nouveau score après le jeu
 */
int ChoixTable(int score);

//======================================= JEU DIVISION
/**
 * @brief Jeu de division
 * @param score Score actuel du joueur
 * @return Nouveau score après le jeu
 */
int division(int score);

//======================================= JEU CONVERSION MASSE
/**
 * @brief Jeu de conversion de masse
 * @param score Score actuel du joueur
 * @return Nouveau score après le jeu
 */
int conversion_masse(int score);

//======================================= JEU CONVERSION LONGUEUR
/**
 * @brief Jeu de conversion de longueur
 * @param score Score actuel du joueur
 * @return Nouveau score après le jeu
 */
int conversion_longueur(int score);

//======================================= JEU CONVERSION AIRES
/**
 * @brief Jeu de conversion d'aires
 * @param score Score actuel du joueur
 * @return Nouveau score après le jeu
 */
int conversion_aires(int score);

//======================================= JEU CONVERSION DUREE
/**
 * @brief Jeu de conversion de durée
 * @param score Score actuel du joueur
 * @return Nouveau score après le jeu
 */
int conversion_duree(int score);

//======================================= JEU GRANDS NOMBRES
/**
 * @brief Jeu des grands nombres, ecrire un grand nombre en français avec les chiffres.
 * @param score Score actuel du joueur
 * @return Nouveau score après le jeu
 */
int grands_nombres(int score);

//======================================= JEU PROBLEMES
/**
 * @brief Jeu de résolution de problèmes simples
 * @param score Score actuel du joueur
 * @return Nouveau score après le jeu
 */
int probleme(int score);

//======================================= JEU FRACTION
/**
 * @brief Jeu de fractions
 * @param score Score actuel du joueur
 * @return Nouveau score après le jeu
 */
int fractions(int score);

//======================================= JEU DES OPERATIONS
/**
 * @brief Jeu des opérations: trouver la suite d'opérations à effectuer à partir de 4 chiffres pour trouver un nombre fixé.
 * @param score Score actuel du joueur
 * @return Nouveau score après le jeu
 */
int jeu_op(int score);

//======================================= JEU ANGLE TRIANGLE
/**
 * @brief Jeu sur les angles de triangle: calculer la mesure en degré du 3ème angle d'un triangle
 * @param score Score actuel du joueur
 * @return Nouveau score après le jeu
 */
int angle_triangle(int score);

//======================================= JEU MOYENNE
/**
 * @brief Jeu de calcul de moyenne
 * @param score Score actuel du joueur
 * @return Nouveau score après le jeu
 */
int moyenne(int score);


//======================================= JEU CALCUL AIRES
/**
 * Affiche un carré, calcule son aire et met à jour le score.
 * @param score : score actuel
 * @return : score mis à jour
 */
int carre(int score);

/**
 * Affiche un rectangle, calcule son aire et met à jour le score.
 * @param score : score actuel
 * @return : score mis à jour
 */
int rectangle(int score);

/**
 * Affiche un triangle, calcule son aire et met à jour le score.
 * @param score : score actuel
 * @return : score mis à jour
 */
int triangle(int score);

/**
 * Affiche un trapèze, calcule son aire et met à jour le score.
 * @param score : score actuel
 * @return : score mis à jour
 */
int trapeze(int score);

/**
 * Affiche un cercle, calcule son aire et met à jour le score.
 * @param score : score actuel
 * @return : score mis à jour
 */
int cercle(int score);

/**
 * Choisit une figure aléatoire (carré, rectangle, trapèze, cercle, triangle),
 * affiche le problème correspondant, calcule l'aire et met à jour le score.
 * @param score : score actuel
 * @return : score mis à jour
 */
int calcul_aires(int score);

#endif // MODULE1_H