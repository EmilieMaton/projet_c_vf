#include "module2.h"
#include <stdio.h>          
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

int main() {
    printf("Test de la fonction som : 2+3 = %d\n", som(2,3));
    printf("Test de la fonction puiss : 2^3 = %.2f\n", puiss(2,3));
    

    // ===================== TESTS FONCTIONS ARITHMÉTIQUES =====================
    assert(som(2, 3) == 5);
    assert(prod(2, 3) == 6);
    assert(diff(5, 3) == 2);
   

    // ===================== TEST PUISSANCE =====================
    assert(puiss(2, 3) == 8.0f);
    assert(puiss(5, 0) == 1.0f);
    

    // ===================== TEST PERMUTATION =====================
    int a = 5, b = 10;
    permutation(&a, &b);
    assert(a == 10 && b == 5);

    // ===================== TEST RANDOM =====================
    int r = random(1, 10);
    assert(r >= 1 && r <= 10);

    // ===================== TEST CONVERSION =====================
    assert(conv(30, 2) == 150); 

    // ===================== TEST PGCD =====================
    assert(pgcd(12, 8) == 4);
    assert(pgcd(7, 3) == 1);

    // ===================== TEST CALCUL =====================
    assert(calculer('+', 3, 4) == 7);
    assert(calculer('-', 10, 4) == 6);
    assert(calculer('x', 2, 3) == 6);
    printf("Tous les tests du module2 passent !\n");

    // ===================== TEST OPÉRATEUR =====================
    assert(verifier('+', 2, 3) == true);
    assert(verifier('-', 5, 3) == true);

    // ===================== TEST CHOIX OPERATEUR =====================
    char op = choisir_operateur(2,3);
    assert(op == '+' || op == '-' || op == 'x');

    // ===================== TEST INDICE =====================
    int tab[] = {1,2,3,4,5};
    assert(indice(3, tab, 5) == 2);

    // ===================== TEST VERIF PRESENCE =====================
    assert(verif_presence(4, tab, 5) == 3);
    assert(verif_presence(10, tab, 5) == -1);

    // ===================== TEST ETAPE CALCUL =====================
    int etab[] = {1,2,3};
    assert(etape_calcul(etab, 3) >= 0);

    // ===================== TEST GENERATION TABLEAU =====================
    int t[5];
    gen_tab(t, 5, 1, 10);
    for (int i=0; i<5; i++) {
        assert(t[i] >= 1 && t[i] <= 10);
    }

    // ===================== TEST AFFICHAGE TABLEAU / ARRONDI / MOYENNE =====================
    
    affiche_tab(tab, 5);
    float moyenne = calc_moy(tab, 5);
    float arr = arrondir(3.14159f, 2);
    printf("Moyenne: %.2f, Arrondi: %.2f\n", moyenne, arr);

    // ===================== TEST SAUVEGARDE ET CHARGEMENT =====================
    sauvegarderScore("test.txt", 42);
    int score = chargerScore("test.txt");
    assert(score == 42);

    printf("Tous les tests du module2 passent !\n");
    return 0;
}