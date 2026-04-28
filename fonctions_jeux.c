#include "fonctions_jeux.h"
#include "fonctions_utiles.h"  
#include <stdio.h>           
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>




//======================================= JEU ADDITION
int addition(int score){

// Déclaration des variables
    int nb1;
    int nb2;
    int reponse;

// Génération de deux entiers
    nb1 = random(1,100);
    nb2 = random(1,100);

// Calcul de la reponse 
    reponse = som(nb1,nb2);

// Affichage question + saisie de la réponse
    printf("\n");         
    printf("%d+%d=?\n",nb1,nb2);
    printf("\n"); 
    score = verif_entier(reponse,score);
    return score;
}



//======================================= JEU MULTIPLICATION
int multiplication(int score){

// Déclaration des variables
    int nb1;
    int nb2;
    int reponse;
    
// Génération de deux entiers
    nb1 = random(1,10);
    nb2 = random(1,10);

// Calcul de la reponse 
    reponse = prod(nb1,nb2);

// Affichage question + saisie de la réponse
    printf("\n");
    printf("%d x %d=?\n",nb1,nb2);
    printf("\n");
    score = verif_entier(reponse,score);
    return score;

}
               
    

//======================================= JEU SOUSTRACTION
int soustraction(int score){

// Déclaration des variables
    int nb1;
    int nb2;
    int reponse;
   
// Génération des entiers
    nb1 = random(0,100);
    nb2 = random(0,100);

// permutation_si_croissant eventuelle
    permutation_si_croissant(&nb1,&nb2);

// Calcul du résultat
    reponse = diff(nb1,nb2);
      
// Affichage et vérification
    printf("%d - %d=?\n",nb1,nb2); 
    score = verif_entier(reponse,score);
    return score;
}



//======================================= JEU TABLES MULTIPLICATION
int ChoixTable(int score){  

// Déclaration des variables
    int essai;
    int choix;
    int produit;
    int echec = 0;

// Choix table
    printf("\nChoisir une table de 1 à 10: ");  
    while (scanf("%d", &choix) != 1 ){
        printf("Saisir un entier positif.\n");
        while (getchar() != '\n');  
    }
    AfficheTable(choix);    
    printf("\n");
    printf("\n");
// Boucle affichage opération
    for (int i=1; i<=10; i=i+1){
        printf("%d x %d = ?\n",choix,i );  
        produit=prod(i,choix);
        scanf("%d",&essai);
        if (essai == produit){
            printf("Gagné!\n");
            
        }
        else{
            printf("Perdu.\n");
            echec = echec + 1;
        }
    }

// Comptage des points
    if (echec == 0){
        score = score + 10;
        printf("Bravo! Vous n’avez fait aucune erreur.                      +10 \n");
    }
    else if (echec == 1){
        score = score + 5;
        printf("Vous avez fait une seule faute.                             +5 \n");
    }
    else if (echec == 2){
        score = score + 1;
        printf("Vous avez fait deux fautes.                                 +1 \n");
    }
    else {
        printf("Vous avez fait trop de fautes.\n");
    } 
    return score;
}

//======================================= JEU DIVISION
int division(int score){

// Déclaration des variables
    int nb1;
    int nb2;
    int quotient;
    int reste;
    int essai1;
    int essai2;

// Génération des entiers 
    nb1 = random(1,100);                            
    nb2 = random(1,10);
    permutation_si_croissant(&nb1,&nb2); //Pour que nb1 soit toujours plus grand que nb2 mais pas obligatoire

// Calcul resultat
    quotient = nb1 / nb2;
    reste = nb1 % nb2;  


// Affichage de la question               
    printf("%d |- %d=?\n",nb1,nb2); 

// Saisie + Vérification
    printf("Entrez le quotient: \n");
    while (scanf("%d", &essai1) != 1 ) {
        printf("Saisir un entier positif.\n");
        while (getchar() != '\n');  
    }

    printf("Entrez le reste: \n");
    while (scanf("%d", &essai2) != 1 ) {
        printf("Saisir un entier positif.\n");
        while (getchar() != '\n');  
    }

    printf("Vous avez entré: quotient = %d et reste = %d\n", essai1, essai2);


    if ((quotient==essai1) && (reste==essai2)){
        printf("Bravo!                          +10\n");
        score = score + 10;

    }
    else{
        printf("Non. Veuillez ressayer.\n");
        printf("Entrez le quotient: \n");
        while (scanf("%d", &essai1) != 1 ) {
            printf("Saisir un entier positif.\n");
            while (getchar() != '\n');  
        }
        printf("Entrez le reste: \n");
        while (scanf("%d", &essai2) != 1 ) {
            printf("Saisir un entier positif.\n");
            while (getchar() != '\n');  
        }
        printf("Vous avez entré quotient = %d et reste = %d\n", essai1, essai2);
        if ((quotient==essai1) && (reste==essai2)){
            printf("Bonne réponse.                          +5\n");
            score = score + 5;

        }
        else{
            printf("Encore faux. Ressayez:\n");
            printf("Entrez le quotient: \n");
            while (scanf("%d", &essai1) != 1 ) {
                printf("Saisir un entier positif.\n");
                while (getchar() != '\n');  
            }

            printf("Entrez le reste: \n");
            while (scanf("%d", &essai2) != 1 ) {
                printf("Saisir un entier positif.\n");
                while (getchar() != '\n');  
            }

            printf("Vous avez entré quotient = %d et reste = %d\n", essai1, essai2);
            if ((quotient==essai1) && (reste==essai2)){
                printf("Bonne réponse.                          +1\n");
                score = score + 1;
            }
            else{
                printf("La bonne réponse était: quotient = %d, reste = %d\n", quotient, reste);
            }
        }
    }
    return score;
}




//======================================= JEU CONVERSION MASSE
int conversion_masse(int score){

// Déclaration des variables 
    int masse;
    float reponse;
    int unite_initiale;
    int unite_finale;
    float essai;
    float facteur_conversion;
    char unite[][16]={"mg","cg","dg","g","dag","hg","kg"};

// Affichage table
    printf("MESURE DE MASSE");
    printf("\n");
    printf("TABLE DE CONVERSION:\n");
    printf("+------+------+-------+-------+------+------+------+\n");
    printf("|  kg  |  hg  |  dag  |   g   |  dg  |  cg  |  mg  |\n");
    printf("+------+------+-------+-------+------+------+------+\n");
    printf("|      |      |       |       |      |      |      |\n");
    printf("|      |      |       |       |      |      |      |\n");
    printf("|      |      |       |       |      |      |      |\n");
    printf("+------+------+-------+-------+------+------+------+\n");

    
// Génération aléatoire
    masse = rand() % 10 + 1;
    unite_initiale = rand() % 7;                                              
    do {
        unite_finale = rand() % 7; 
    } while (unite_finale == unite_initiale); // Eviter que les deux unités de mesure soient identiques

// Affichage
    printf("%d %s = ? %s\n", masse, unite[unite_initiale], unite[unite_finale]);

// Calcul
    facteur_conversion = (pow(10,(unite_initiale-unite_finale)));
    reponse = masse * facteur_conversion;
    

// Vérification + Affichage de la réponse 


    score = verif_reel(reponse,score);
    printf("---> ");
    if(reponse > 1){
        printf("%d %s = %.0f %s\n", masse, unite[unite_initiale], reponse, unite[unite_finale]);
    }
    else{
        printf("%d %s = %f %s\n", masse, unite[unite_initiale], reponse, unite[unite_finale]);
    }
    return score;
}
                   



//======================================= JEU CONVERSION LONGUEUR
int conversion_longueur(int score){

// Déclaration des variables
    int longueur;
    float reponse;
    int unite_initiale;
    int unite_finale;
    float essai;
    float facteur_conversion;
    char unite[][16]={"mm","cm","dm","m","dam","hm","km"};

// Affichage de la table 
    printf("MESURE DE LONGUEUR");
    printf("\n");
    printf("TABLE DE CONVERSION:\n");
    printf("+------+------+-------+-------+------+------+------+\n");
    printf("|  km  |  hm  |  dam  |   m   |  dm  |  cm  |  mm  |\n");
    printf("+------+------+-------+-------+------+------+------+\n");
    printf("|      |      |       |       |      |      |      |\n");
    printf("|      |      |       |       |      |      |      |\n");
    printf("|      |      |       |       |      |      |      |\n");
    printf("+------+------+-------+-------+------+------+------+\n");

    
   
// Génération aléatoire
    longueur = rand() % 10 + 1;
    unite_initiale = rand() % 7;                                              
    do {
        unite_finale = rand() % 7; 
    } while (unite_finale == unite_initiale);

// Affichage
    printf("%d %s = ? %s\n", longueur, unite[unite_initiale], unite[unite_finale]);

// Calcul
    facteur_conversion = (puiss(10,(unite_initiale - unite_finale)));
    reponse = longueur * facteur_conversion;

// Vérification + affichage de la réponse
    score = verif_reel(reponse,score);
    printf("---> ");
    if(reponse > 1){
        printf("%d %s = %.0f %s\n", longueur, unite[unite_initiale], reponse, unite[unite_finale]);
    }
    else{
        printf("%d %s = %f %s\n", longueur, unite[unite_initiale], reponse, unite[unite_finale]);
    }
    return score;
}

//======================================= JEU CONVERSION AIRES
int conversion_aires(int score){

// Déclaration des variables
    int longueur;
    float facteur_conversion;
    float reponse;
    int unite_initiale;
    int unite_finale;
    float essai;
    char unite[][16]={"mm2","cm2","dm2","m2","dam2","hm2","km2"};

// Affichage du tableau
    printf("MESURE D AIRES");
    printf("\n");
    printf("TABLE DE CONVERSION:\n");
    printf("+-------+-------+-------+-------+-------+-------+-------+\n");
    printf("|  km2  |  hm2  | dam2  |   m2  |  dm2  |  cm2  |  mm2  |\n");
    printf("+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
    printf("|   |   |   |   |   |   |   |   |   |   |   |   |   |   |\n");
    printf("|   |   |   |   |   |   |   |   |   |   |   |   |   |   |\n");
    printf("|   |   |   |   |   |   |   |   |   |   |   |   |   |   |\n");
    printf("+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");

    
    
// Génération des aléatoires
    longueur = rand() % 10 + 1;
    unite_initiale = rand() % 7;                                              
    do {
        unite_finale = rand() % 7; 
    } while (unite_finale == unite_initiale);

// Affichage du problème
    printf("%d %s = ? %s\n", longueur, unite[unite_initiale], unite[unite_finale]);  

// Calcul solution
    facteur_conversion = (puiss(10,(unite_initiale - unite_finale) * 2));
    reponse = longueur * facteur_conversion;
    
    
// Résolution du problème
    score = verif_reel(reponse,score);
    printf("---> ");
    if(reponse > 1){
        printf("%d %s = %.0f %s\n", longueur, unite[unite_initiale], reponse, unite[unite_finale]);
    }
    else{
        printf("%d %s = %f %s\n", longueur, unite[unite_initiale], reponse, unite[unite_finale]);
    }
    return score;
}

//======================================= JEU CONVERSION DUREE
int conversion_duree(int score){

// Déclaration des variables
    char unite[][16] = {"heures","minutes","secondes"}; 
    int unite1;
    int unite2;
    int duree1;
    int duree2;
    int reponse;
    
// Génération aléatoire de l'indice de l' unité --> comme le modèle on prends des unités consécutives
    unite1 = rand()%2;
    unite2 = unite1 + 1;

// Génération aléatoire d'une durée --> en fonction de l'unité générée
    if (unite1 == 0){ // --> heures
        duree1 = rand() % 23 + 1;    
    }
    else if (unite1 == 1){ // --> minutes
        duree1 = rand() % 59 + 1;     
    }
    duree2 = rand() % 59 + 1; 

// Affichage de la question
    printf("%d%s + %d%s = ? %s\n", duree1, unite[unite1], duree2, unite[unite2], unite[unite2]);

// Calcul
    reponse = conv(duree2,duree1);


// Vérification + Affichage de la réponse
    score = verif_entier(reponse,score);
    printf("---> ");
    printf("%d%s + %d%s = %d %s\n", duree1, unite[unite1], duree2, unite[unite2], reponse, unite[unite2]);
    return score;
}



//======================================= JEU GRANDS NOMBRES
int grands_nombres(int score){

// Déclaration des variables
    int reponse;
    int million = random(0,99);    
    int mille = random(0,999);   
    int unite = random(0,999);  

// Constitution de l'entier
    reponse = million * 1000000 + mille * 1000 + unite;

    printf("---> ");
// Affichage    
    if(million != 0){
        nb(million);
        if(million == 1){
            printf(" million ");
        }
        else{
            printf(" millions ");
        }
    }
    if(mille != 0){
        nb(mille);
        printf(" mille ");
    }
    if(unite != 0){
        nb(unite);
    }
    printf("\n");
    score = verif_entier(reponse, score);
    return score;
}

//======================================= JEU PROBLEMES
int probleme(int score){

// Déclaration des variables
    char nom[][16] = {"Alice", "Louis", "Charles", "Julien", "Eva", "Sophie", "Vincent"};
    char item[2][7][16] = {
        {"sacs", "boites", "sachets", "boites", "pochettes", "paquets", "albums"}, 
        {"billes", "chocolats", "bonbons", "beignets", "timbres", "crayons", "photos"} 
    };
    char action[][16] =  {"On lui prend","On lui donne"};
    int reponse;
    int nb1;
    int prenom = random(0,7);
    int contenant = random(0,7);
    int nb_contenant = random(2,20);
    int nb_contenu = random(2,50);
    int nb_item_initial = nb_contenant * nb_contenu;
    int act = random(0,1);

    if ( act == 0){   // "on lui prend"
        nb1 = random(1,nb_item_initial);       
        nb1 = (nb1 / 2) + 2;
        reponse = nb_item_initial - nb1;
    }
    else{  // "on lui donne"
        nb1 = random(2,50);
        reponse = nb_item_initial + nb1;
    }

// Affichage du problème
printf("\n");
    printf("%s avait %d %s de %d %s.\n%s %d %s.\nCombien y-a-t-il de %s au total maintenant ?\n", nom[prenom],nb_contenant, item[0][contenant], nb_contenu, item[1][contenant], action[act],nb1, item[1][contenant], item[1][contenant] );
    

// Résolution
    score = verif_entier(reponse, score);
    return score;
}




//======================================= JEU FRACTION           
int fractions(int score){

// Déclaration des variables
    char op[3] = {'x', '-', '+'};
    float reponse;
    float numerateur1, numerateur2, denominateur1, denominateur2;
    char operateur;
    int alea;
    float numerateur;
    float denominateur;
    float num_final;
    float den_final;

// Génération des aléatoires
    numerateur1 = random(1,10);
    numerateur2 = random(1,10);
    denominateur1 = random(1,10);
    denominateur2 = random(1,10);
    alea = random(0,2);
    operateur = op[alea];

// Affichage du problème
    printf("\nVeuillez resoudre l'operation suivante: \n");
    printf("\n");
     
    printf("%-6.0f %6.0f\n", numerateur1, numerateur2);
    printf("_     %c     _\n", operateur);
    printf("\n");
    printf("%-6.0f %6.0f\n", denominateur1, denominateur2);
    printf("\n");

// Calcul des éléments de réponse
    den_final = denominateur1 * denominateur2;
    if (operateur == 'x'){
        num_final = numerateur1 * numerateur2;
    }
    else if (operateur == '-'){
        num_final = numerateur1 * denominateur2 - numerateur2 * denominateur1;
    }
    else{
        num_final = numerateur1 * denominateur2 + numerateur2 * denominateur1;
    }


    int nf = (int)num_final;
    int df = (int)den_final;
    int multiple;
    int pgdc;

    pgdc = pgcd(nf,df);
    
// Calcul de la forme irréductible
    nf = nf / pgdc;
    df = df / pgdc;

// Saisie utilisateur
    printf("Entrez le numerateur: "); // essai 1
    while (scanf("%f", &numerateur) != 1 ) {
        printf("Saisir un entier positif.\n");
        while (getchar() != '\n');  
    }
    printf("Entrez le denominateur: ");
    while (scanf("%f", &denominateur) != 1 ) {
        printf("Saisir un entier positif.\n");
        while (getchar() != '\n');  
    }

// Affichage de la réponse pour le test
    printf("Vous avez entré numerateur = %.0f et denominateur = %.0f\n", numerateur, denominateur);

    //fabs((numerateur/denominateur) - (num_final/den_final)) < 000001){
    // if ((numerateur/denominateur) == (num_final/den_final)){
    if ((numerateur/denominateur) == (num_final/den_final)){
        printf("Bravo!\n");
        printf("                                                            +10\n");
        score = score + 10;
    }
    else{
        printf("\n");
        printf("Non. Veuillez ressayer.\n");
        printf("Entrez le numerateur: ");      // essai 2
        while (scanf("%f", &numerateur) != 1 ) {
            printf("Saisir un entier positif.\n");
            while (getchar() != '\n');  
        }
        printf("Entrez le denominateur: ");
        while (scanf("%f", &denominateur) != 1 ) {
            printf("Saisir un entier positif.\n");
            while (getchar() != '\n');  
        }
        printf("Vous avez entré numerateur = %.0f et denominateur = %.0f\n", numerateur, denominateur);
        if ((numerateur/denominateur) == (num_final/den_final)){
            printf("Bonne réponse.\n");
            printf("                                                            +5\n");
            score = score + 5;
        }
        else{
            printf("\n");
            printf("Encore faux. Ressayez:\n");
            printf("Entrez le numerateur: ");     // essai 3
            while (scanf("%f", &numerateur) != 1 ) {
                printf("Saisir un entier positif.\n");
                while (getchar() != '\n');  
            }
            printf("Entrez le denominateur: ");
            while (scanf("%f", &denominateur) != 1 ) {
                printf("Saisir un entier positif.\n");
                while (getchar() != '\n');  
            }
            printf("Vous avez entré numerateur = %.0f et denominateur = %.0f\n", numerateur, denominateur);
            if ((numerateur/denominateur) == (num_final/den_final)){
                printf("Bonne réponse.\n");
                printf("                                                            +1\n");
                score = score + 1;
            }
            else{
                printf("\n");
                printf("La bonne réponse était: numerateur = %d, denominateur = %d\n", nf, df);  // Solution
            }
        }
    }
// Affichage de la fraction
    printf("\nReponse: \n");
    printf("%d\n", nf);
    printf("_\n");
    printf("\n");
    printf("%d\n", df);
// Point Bonus
    if ((numerateur == nf) && (denominateur == df) && (pgdc != 1)){
        printf("BONUS: Vous avez penser a mettre la fraction sous forme irreductible.\n");
        printf("                                                            +5\n");
        score = score + 5;
    }
    return score;
}


//======================================= JEU DES OPERATIONS
int jeu_op(int score) {

// Déclaration des variables et des tableaux
    int tab[4];
    char op[3] = {'x', '-', '+'};
    int nombre[4];
    char etape[15][50];
    int choix1;
    int choix2;
    char operateur;
    int nb = 4;
    int resultat;
    int nb1;
    int nb2;
    int j;

// Génération des tableaux
    for (int i = 0; i < nb; i++) {
        tab[i] = rand() % 10 + 1;
        nombre[i] = tab[i];
    }
    
// Générations des étapes de calcul
    for (j = 0; j < 3; j=j+1) {

        int a = rand() % nb;
        nb1 = extraire(tab, a, nb - 1);

        int b = rand() % (nb -1);
        nb2 = extraire(tab, b, nb - 2);

        char ope = choisir_operateur(nb1, nb2);
        resultat= calculer(ope, nb1, nb2);

        tab[nb - 2] = resultat;
        nb = nb - 1 ;   

// Formatage de l’étape de calcul sous forme de chaîne, stockage dans le tableau etape
        sprintf(etape[j], "%d %c %d = %d", nb1, ope, nb2, resultat);

    }

   
// Présentation du problème
    printf("\n\n");
    printf("\nEcrivez l'operation pour trouver: %d", resultat);
    printf("\nVous devez utiliser les nombres: %d, %d, %d, %d\n", nombre[0], nombre[1], nombre[2], nombre[3]);
    
// Résolution
    nb = 4;
    
    int resultat_provisoire;

    printf("Veuillez choisir, a chaque fois, 2 chiffres et un operateur.\n");
    printf("Le resultat ne devra pas etre inferieur ou egal a zero.\n");
    for (int i=0; i<3; i = i + 1){  // 3 tours
        printf("\n");
        printf("\n");
        resultat_provisoire = etape_calcul(nombre, nb);
        nb = nb - 1;
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n");
        if (resultat_provisoire == resultat){
            break;
        }
    }
// Vérification
    printf("Vous avez trouve %d.\n", resultat_provisoire);
    if (resultat_provisoire == resultat){
        printf("\nBravo\n");
        printf("                                                            +30\n");
        score = score + 30;
    }
// Solution
    else{
        printf("\n---> SOLUTION <---\n");
        for (int i = 0; i < 3; i++) {
            printf("%s\n", etape[i]);
        }
    }
    return score;
}

//======================================= JEU ANGLE TRIANGLE
int angle_triangle(int score){

// Affichage du problème
    printf("          A\n");
    printf("         /\\\n");
    printf("        /  \\\n");
    printf("       /    \\\n");
    printf("      /      \\\n");
    printf("   C /________\\ B\n");

// Déclaration des variables, génération
    int abc = random(1,178);
    int bca = random(1,(179-abc));
    int cab = 180 - abc - bca;

// Présentation du problème
    printf("\n");
    printf("                              ^\n");
    printf("\nTrouvez la mesure de angle CAB du triangle ABC tel que:\n");
    printf("    ^\n");
    printf("-> ABC = %d degres\n",abc);
    printf("    ^\n");
    printf("-> BCA = %d degres\n",bca);
    printf("\n");
    printf("\n");
// Vérification + résolution
    score = verif_entier(cab, score);
    return score;
}


//======================================= JEU MOYENNE
int moyenne(int score){
    printf("\nQuelle est la moyenne de la serie de nombres ci-dessous?\n");
    printf("\n");

// Génération aléatoire des paramètres de la série statistique
    int nb = random(3, 12); // taille du tableau, de la serie statistique.
    int tab[nb];
    int val_inf = random(1,10);
    int val_sup = random(20,30);
    gen_tab(tab, nb, val_inf, val_sup); 
    affiche_tab(tab, nb); // affichage

// Calcul de la moyenne
    float moy = calc_moy(tab, nb);// calc moyenne


// Création de l'arrondi
    moy = arrondir(moy, 1);

    printf("\n");

// Résolution du problème
    score = verif_reel(moy, score);
    printf("---> Moyenne = %.1f\n", moy);

    return score;
}


//======================================= JEU CALCUL AIRES

int rectangle (int score){
    // Déclaration des variables
    int largeur = random(1,30);
    int longueur = random(1,30);
    while (longueur == largeur) { // sinon c'est un carré
        longueur = random(1,30);
    }
    int reponse;
    permutation_si_croissant(&longueur, &largeur); // pour que le dessin soit cohérent

// Affichage du problème
printf("\nVeuillez calculer l'aire de rectangle de ce carré en cm2.\n");

    printf("\n");
    printf("+---------------------+  A\n");
    printf("|                     |  |\n");
    printf("|                     |  |\n");
    printf("|                     |  | %d cm\n", largeur);
    printf("|                     |  | \n");
    printf("|                     |  |\n");
    printf("+---------------------+  V\n");
    printf("<--------------------->\n");
    printf("         %d cm\n", longueur);

// Résolution
    reponse = largeur * longueur;
    score = verif_entier (reponse, score);
    return score;
}


int carre(int score){

// Déclaration des variables
    int cote = random(1,50);
    int reponse;

// Affichage du problème
printf("Veuillez calculer l'aire de ce carré en cm2.\n");

    printf("\n");
    printf("+-------------+\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("+-------------+\n");
    printf("<------------->\n");
    printf("      %dcm\n", cote);

// Résolution
    reponse = cote * cote;
    score = verif_entier (reponse, score);
    
    return score;
}

int triangle(int score){

// Déclaration des variables
    int hauteur = random(1,30);
    int base = random(1,30);
    while (base % 2 != 0) { // pour que l'aire reste un entier
        base = random(1,30);
    }
    int reponse;

// Affichage du problème
printf("Veuillez calculer l'aire de ce triangle en cm2.\n");

    printf("\n");
    printf("\n");
    printf("         /\\     A\n");
    printf("        /  \\    |  \n");
    printf("       /    \\   |  %d cm\n", hauteur );
    printf("      /      \\  |     \n");
    printf("   C /________\\ V      \n");
    printf("    <--------->\n");
    printf("        %dcm\n", base);

// Résolution
    reponse = (hauteur * base) / 2;
    score = verif_entier (reponse, score);
    
    return score;
}

int trapeze(int score){

// Déclaration des variables
    int hauteur;
    int petite_base;
    int grande_base;

    do {
        hauteur = random(1,30);
        petite_base = random(1,30);
        grande_base = random(1,30);
        while (grande_base == petite_base){
            grande_base = random(1,30);
        }
        permutation_si_croissant(&grande_base, &petite_base);
    } while (((grande_base + petite_base) * hauteur) % 2 != 0);
    int reponse;

// Affichage du problème
    printf("Veuillez calculer l'aire de ce trapèze en cm2.\n");
    printf("\n");
    printf("              %d cm\n", petite_base);
    printf("          <---------->\n");
    printf("          ____________       A\n");
    printf("         /            \\     |\n");
    printf("        /              \\    |\n");
    printf("       /                \\   |  %d cm\n", hauteur );
    printf("      /                  \\  |\n");
    printf("   C /____________________\\ V\n");
    printf("     <-------------------->\n");
    printf("              %dcm\n", grande_base);

// Résolution
    reponse = ((grande_base + petite_base) * hauteur) / 2;
    score = verif_entier (reponse, score);
    
    return score;
}



int cercle(int score){

// Déclaration des variables
    int diametre = random(2,30); // donc 1cm de rayon minimum
    while (diametre % 2 != 0){
        diametre = random(2,30);
    }
    int rayon = diametre / 2;
    float reponse;
    float pi = 3.14;
    
// Affichage du problème
    printf("Veuillez calculer l'aire de ce cercle en cm2.\n");
    printf("On considère que pi vaut 3.14.");
    printf("Arrondissez le résultat au dixième.");
    printf("\n");
    printf("      -----      \n");
    printf("   /         \\   \n");
    printf("  /           \\  \n");
    printf(" |      .      | \n");
    printf("  \\           /  \n");
    printf("   \\         /   \n");
    printf("      -----    \n");
    printf(" <------------->\n");
    printf("       %d cm\n", diametre);

// Résolution
    reponse = pi * rayon * rayon;
    
    reponse = arrondir (reponse, 1);
    
    score = verif_reel (reponse, score);
    printf("La bonne réponse était %.1f\n", reponse);

    return score;
}
//======================================= JEU CALCUL AIRES COMPILATION
int calcul_aires(int score){

    int figure = random (0,4);
    switch(figure){

        case 0: printf("CARRE\n");
        score = carre(score);
        break;

        case 1: printf("RECTANGLE\n");
        score = rectangle(score);
        break;

        case 2: printf("TRAPEZE\n");
        score = trapeze(score);
        break;

        case 3: printf("CERCLE\n");
        score = cercle(score);
        break;

        case 4: printf("TRIANGLE\n");
        score = triangle(score);
        break;
    }

    return score;
}


