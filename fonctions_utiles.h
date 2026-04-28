
#ifndef FONCTIONS_UTILES_H
#define FONCTIONS_UTILES_H

#include <stdbool.h>

/**
 * puiss - calcule la puissance (positive ou negative) d'un entier
 * @nb: base
 * @exp: exposant (negatif ou positif)
 *
 * Retourne nb élevé à la puissance exp.
 */
float puiss(int nb, int exp);

/**
 * som - somme de deux entiers
 * @n1: premier entier
 * @n2: second entier
 *
 * Retourne n1 + n2.
 */
int som(int n1,int n2);

/**
 * prod - produit de deux entiers
 * @n1: premier entier
 * @n2: second entier
 *
 * Retourne n1 * n2.
 */
int prod(int n1, int n2);

/**
 * diff - différence de deux entiers
 * @n1: premier entier
 * @n2: second entier
 *
 * Retourne n1 - n2.
 */
int diff(int n1, int n2);

/**
 * permutation_si_croissant avec pointeurs - échange les valeurs de deux entiers
 * @nb1: pointeur vers le premier entier
 * @nb2: pointeur vers le second entier
 */
void permutation_si_croissant(int *nb1, int *nb2);

/**
 * random - génère un entier aléatoire dans un intervalle
 * @borne_inf: borne inférieure (incluse)
 * @borne_sup: borne supérieure (incluse)
 *
 * Retourne un entier aléatoire entre borne_inf et borne_sup.
 */
int random(int borne_inf, int borne_sup);

/**
 * verif_entier - vérifie une réponse de type int, entière
 * @reponse: valeur à vérifier
 * @score: score actuel à incrémenter
 *
 * Retourne le score qui augmente de 10, 5 ou 0.
 */
int verif_entier(int reponse, int score);

/**
 * verif_reel - vérifie une réponse flottante
 * @reponse: valeur à vérifier
 * @score: score actuel
 *
 * Retourne le score qui augmente de 10, 5 ou 0.
 */
int verif_reel(float reponse, int score);

/**
 * conv - conversion heure/minute en minutes/secondes
 * @d1: durée unité la plus petite (minute ou seconde)
 * @d2: durée la plus grande (heure ou minute)
 *
 * Retourne la durée dans l'unité la plus petite (celle de d1).
 */
int conv(int d1, int d2);

/**
 * AfficheTable - affiche la table de multiplication d'un entier
 * @table: table à afficher
 */
void AfficheTable(int table);

/**
 * nb - affiche un entier en lettres
 * @nombre: entier à afficher
 */
void nb(int nombre);

/**
 * pgcd - calcule le plus grand commun diviseur de deux entiers
 * @nb1: premier entier
 * @nb2: second entier
 *
 * Retourne le PGCD de nb1 et nb2.
 */
int pgcd(int nb1, int nb2);

/**
 * extraire - extrait un élément d'un tableau, le remplace par le derniere élément non nul
 * @tab: tableau d'entiers
 * @i: indice de l'élément à extraire
 * @pos_fin: indice de fin
 *
 * Retourne l'élément extrait.
 */
int extraire(int tab[], int i, int pos_fin);

/**
 * calculer - effectue une opération arithmétique
 * @op: opérateur ('+', '-', '*')
 * @a: premier nombre à opérer
 * @b: second nombre à opérer
 *
 * Retourne le résultat.
 */
int calculer(char op, int a, int b);

/**
 * verifier - vérifie la validité d'un opérateur (il ne doit pas être <=0 si '-')
 * @op: opérateur
 * @a: premier nombre à opérer
 * @b: second nombre à opérer
 *
 * Retourne true si valide, false sinon.
 */
bool verifier(char op, int a, int b);

/**
 * choisir_operateur - choisit un opérateur pour un calcul sur deux entiers
 * @a: premier entier
 * @b: second entier
 *
 * Retourne un caractère représentant l'opérateur.
 */
char choisir_operateur(int a, int b);

/**
 * indice - retourne l'indice d'un élément dans un tableau
 * @element: valeur à chercher
 * @tab: tableau d'entiers
 * @taille: taille du tableau
 *
 * Retourne l'indice ou -1 si absent.
 */
int indice(int element, int tab[], int taille);

/**
 * verif_presence - vérifie la présence d'un élément dans un tableau
 * @element: valeur à chercher
 * @tab: tableau d'entiers
 * @taille: taille du tableau
 *
 * Retourne 1 si présent, 0 sinon.
 */
int verif_presence(int element, int tab[], int taille);

/**
 * etape_calcul - effectue une étape de calcul sur deux éléments d'un tableau
 * @nombre: tableau d'entiers
 * @nb: nombre d'éléments
 *
 * Retourne un entier résultat de l'étape.
 */
int etape_calcul(int nombre[], int nb);

/**
 * gen_tab - génère un tableau aléatoire
 * @tab: tableau à remplir
 * @taille: nombre d'éléments
 * @borne_i: valeur minimale (pas forcement atteinte)
 * @borne_s: valeur maximale (pas forcement atteinte)
 */
void gen_tab(int tab[], int taille, int borne_i, int borne_s);

/**
 * affiche_tab - affiche un tableau d'entiers
 * @tab: tableau à afficher
 * @taille: nombre d'éléments
 */
void affiche_tab(int tab[], int taille);

/**
 * calc_moy - calcule la moyenne d'un tableau d'entiers
 * @tab: tableau d'entiers
 * @taille: nombre d'éléments
 *
 * Retourne la moyenne comme float.
 */
float calc_moy(int tab[], int taille);

/**
 * arrondir - arrondit un nombre flottant à une précision donnée
 * @nombre: nombre à arrondir
 * @apres_virgule: nombre de chiffres après la virgule
 *
 * Retourne le nombre arrondi.
 */
float arrondir(float nombre, int apres_virgule);

/**
 * sauvegarderScore - sauvegarde un score, nom, date, heure dans un fichier
 * @nom: nom du joueur
 * @score: score à sauvegarder
 */
void sauvegarderScore(char nom[], int score);

/**
 * chargerScore - charge un score depuis un fichier
 * @nom: nom du joueur
 *
 * Retourne le score chargé.
 */
int chargerScore(char nom[]);

#endif