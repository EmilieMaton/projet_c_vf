#include "fonctions_utiles.h"
#include <stdio.h>          
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>





//======================================= puissance
float puiss(int nb, int exp){

    int i;
    float resultat = 1;

    if (exp>0){
        for(i=1; i<=exp; i = i+1){
            resultat = resultat * nb; 
        }
        return resultat;
    }
    else if (exp<0){
        for(i=1; i<=-exp; i = i+1){
            resultat = resultat * nb;
        }
        return 1/resultat;
    }
    else{
        return 1;
    }
}

//======================================= somme
int som(int n1,int n2){
    return n1+n2;
}

//======================================= produit
int prod(int n1, int n2){
    return n1*n2;
}

//======================================= différence
int diff(int n1, int n2){
    return n1-n2;
}

//======================================= permu tation pointeur
void permutation_si_croissant(int *nb1, int *nb2){
    if(*nb1<*nb2){
        int temp;
        temp=*nb1;
        *nb1=*nb2;
        *nb2=temp;
    }
}

//======================================= génération entier aléatoire
int random(int borne_inf, int borne_sup){
    int a;
    if (borne_inf > borne_sup) {
        int temp = borne_inf;
        borne_inf = borne_sup;
        borne_sup = temp;
    }
    a = rand() %  (borne_sup - borne_inf + 1) + borne_inf;
    return a;
}

//======================================= vérification réponse entière
int verif_entier(int reponse, int score) {
    int essai;
    int points[] = {10, 5, 1}; 
    int i = 0;

    while (i < 3) {
        printf("Entrez le resultat: ");
        while (scanf("%d", &essai) != 1) {
            printf("Saisir un entier.\n");
            while (getchar() != '\n');
            printf("Entrez le resultat: ");
        }

        printf("Vous avez entré %d\n", essai);

        if (essai == reponse) {
            printf("Bonne réponse.\n");
            printf("                                                            +%d\n", points[i]);
            score = score + points[i];
            return score;
        } else {
            if (i < 2) {
                printf("Faux. Veuillez réessayer.\n\n");
            }
        }

        i = i + 1;
    }

    printf("\nLa bonne réponse était %d\n", reponse);
    return score;
}



//======================================= vérification réponse réelle
int verif_reel(float reponse, int score) {
    float essai;
    const float eps_a = 1e-6f;
    const float eps_r = 1e-5f;

    int points[] = {10, 5, 1};
    int i = 0;

    while (i < 3) {

        printf("Entrez le resultat: ");

        while (scanf("%f", &essai) != 1) {
            printf("Saisie invalide.\n");
            while (getchar() != '\n');
            printf("Entrez le resultat: ");
        }

        printf("Vous avez entré %f\n", essai);

        if (fabsf(reponse - essai) <= eps_a + eps_r * fabsf(reponse)) {
            printf("Bonne réponse.\n");
            printf("                                                            +%d\n", points[i]);
            score = score + points[i];
            return score;
        } else {
            if (i < 2) {
                printf("Faux. Veuillez réessayer.\n\n");
            }
        }

        i = i + 1;
    }

    return score;
}

//======================================= conversion heure, minute vers minute, seconde
int conv(int d1, int d2){
    d1 = d1 + (d2 * 60);
    return d1;
}


//======================================= affichage table de multiplication
void AfficheTable(int table){                 
    for(int i = 1; i <= 10; i = i + 1){
        printf("%d x %d = %d\n",table,i,table*i);            
    }
}



//======================================= affichage nombres en lettre
void nb(int nombre){
    
    char nombre_unite[][16] = {"","un","deux","trois","quatre","cinq","six","sept","huit","neuf","dix","onze","douze","treize","quatorze","quinze","seize","dix-sept","dix-huit","dix-neuf"};
    char dizaines[][16] = {"","dix","vingt","trente","quarante","cinquante","soixante","soixante-dix","quatre-vingts","quatre-vingt-dix"};    
    
    int unite = nombre % 10;
    int dizaine = (nombre / 10) % 10;
    int centaine = nombre / 100;

    if (centaine > 0){
        if ((centaine != 1)&&((dizaine == 0)&&(unite == 0))){
            printf("%s cents ",nombre_unite[centaine]);   
        }
        else if(centaine == 1){
            printf("cent ");
        }
        else{
             printf("%s cent ",nombre_unite[centaine]);
        }
    }
    if (dizaine == 1){
        printf("%s",nombre_unite[unite + 10]);       
    }
    else if (dizaine == 7){
        if (unite == 1){
            printf(" soixante-et-onze");
        }
        else{
            printf(" soixante-%s", nombre_unite[unite + 10]);
        }
    }
    else if(dizaine == 9){
        
        printf(" quatre-vingts-%s", nombre_unite[unite + 10]);
    }
    else if (dizaine == 0){
        printf("%s", nombre_unite[unite]);
    }
    else{
        if (unite != 0){
            if (unite == 1){
                if(dizaine == 8){
                    printf("quatre-vingts-un");
                }
                else{
                    printf(" %s-et-un", dizaines[dizaine]);
                }
                
            }
            else{
                printf("%s-%s", dizaines[dizaine], nombre_unite[unite]);
            }
        }
        else{
            printf("%s", dizaines[dizaine]);
        }
    }
}

int pgcd(int nb1, int nb2) {
    int temp;
    while (nb2 != 0) {
        temp = nb2;
        nb2 = nb1 % nb2;
        nb1 = temp;
    }
    return nb1;
}






//======================================= extraction element d'un tableau
int extraire(int tab[], int i, int pos_fin) {
    int val = tab[i];
    tab[i] = tab[pos_fin];
    tab[pos_fin] = 0;
    return val;
}

//======================================= calculer avec x + -
int calculer(char op, int a, int b) {
    if (op == 'x') return a * b;
    if (op == '-') return a - b;
    if (op == '+') return a + b;
    return 0;
}

//======================================= verification de l operateur 
bool verifier(char op, int a, int b) {
    if (op == '-') {
        if (a - b <= 0) return false;
    }
    return true;
}

//======================================= choisir operateur version 1
char choisir_operateur2(int a, int b) {
    char op[3] = {'x', '-', '+'};
    int alea;
    bool verif = false;

    while (!verif) {   // tant que !verif est vrai donc tant que verif est fausse
        alea = rand() % 3;
        verif = verifier(op[alea], a, b);
    }

    return op[alea];
}

//======================================= choisir operateur version 
char choisir_operateur(int a, int b) {
    char op[3] = {'x', '-', '+'};
    int alea;

    do {
        alea = rand() % 3;
    } while (!verifier(op[alea], a, b));

    return op[alea];
}

//======================================= retourne indice d un element du tableau
int indice (int element, int tab[], int taille){
    int indice;
    for(indice = 0; indice < taille; indice = indice + 1){
        if (element == tab[indice]){
            return indice;
        }
    }
    return -1;
}


//======================================= verification presence d un element des tableau
int verif_presence(int element, int tab[], int taille) {
    for(int i = 0; i < taille; i = i + 1) {
        if(tab[i] == element) {
            return i;
        }
    }
    return -1;
}


//======================================= etape du calcule 
int etape_calcul(int nombre[], int nb) {

    
    

    int choix1;
    int choix2;
    char operateur;
    int indice_c1;
    int indice_c2;
    char op[3] = {'x', '-', '+'}; 

    for (int k = 0; k < nb; k = k + 1) {
        printf("---> %d\n", nombre[k]);
    }

    printf("\nChiffre 1 : ");
    while ((scanf("%d", &choix1) != 1) || (verif_presence(choix1, nombre, nb) == -1)) {
        while (getchar() != '\n');
        printf("Saisir un entier valide.\n");
    }
    printf("\n");

    indice_c1 = verif_presence(choix1, nombre, nb); 
    choix1 = extraire(nombre, indice_c1, nb - 1);
    

    for (int k = 0; k < nb-1; k = k + 1) {
        printf("---> %d\n", nombre[k]);
    }

    printf("\nChiffre 2 : ");
    while ((scanf("%d", &choix2) != 1) || (verif_presence(choix2, nombre, nb - 1) == -1)) {
        while (getchar() != '\n');
        printf("Saisir un entier valide.\n");
    }
    printf("\n");
    indice_c2 = verif_presence(choix2, nombre, nb);
    choix2 = extraire(nombre, indice_c2, nb - 2);
    

    for (int i = 0; i < 3; i = i + 1) {
        printf("---> %c\n", op[i]);
    }

    printf("\nOperateur : ");
    
    while ((scanf(" %c", &operateur) != 1) || ((operateur != op[0]) && (operateur != op[1]) && (operateur != op[2])) || (calculer(operateur, choix1, choix2) <= 0)) {
        while (getchar() != '\n');
        printf("Saisir un caractere valide\n");
    }

    int aha = calculer(operateur, choix1, choix2);
    printf("%d %c %d = %d\n", choix1, operateur, choix2, aha);
    nombre[nb - 2] = aha;
    return aha;
}







//======================================= generation tableau aleatoire
void gen_tab(int tab[], int taille, int borne_i, int borne_s){
    for (int i=0; i < taille; i = i + 1 ){
        tab[i] = random(borne_i, borne_s);
    }
}

//======================================= affichage tableau
void affiche_tab(int tab[], int taille){
    for (int i=0; i < taille; i = i + 1 ){
        printf("%d  ", tab[i]);
    }
    printf("\n");
}

//======================================= calcule moyenne
float calc_moy(int tab[], int taille){
    float somme = 0;
    for (int i=0; i < taille; i = i + 1 ){
        somme =  somme + tab[i];
    }
    return somme / taille;
}

//======================================= arrondi 

float arrondir(float nombre, int apres_virgule) {
    float facteur = pow(10, apres_virgule);      
    int temp = round(nombre * facteur);      
    return temp / facteur;                   
}







//======================================= SAUVEGARDE
void sauvegarderScore(char nom[], int score) {
    // Récupération de la date et heure actuelle
    time_t t = time(NULL); // récupère l'heure actuelle du syst nb de seconde depuis 70   + time_t est un type
    struct tm date = *localtime(&t); // structure locale, accès avec le point

    // Ouverture du fichier en mode ajout
    FILE *fichier = fopen("scores.txt", "a"); 
    if (fichier == NULL) {
        printf("Erreur ouverture fichier\n");
        return;
    }

    // Écriture formatée dans le fichier
    fprintf(fichier, "%s %d %02d-%02d-%04d %02d:%02d:%02d\n",
        nom, score,
        date.tm_mday,
        date.tm_mon + 1,
        date.tm_year + 1900,
        date.tm_hour,
        date.tm_min,
        date.tm_sec);

    fclose(fichier);
}
//======================================= CHARGEMENT SCORE 
int chargerScore(char nom[]) {
    FILE *fichier = fopen("scores.txt", "r");
    if (fichier == NULL) return 0;

    char nomFichier[50];
    int score;
    char date[20], heure[20];
    int dernierScore = 0;

    while (fscanf(fichier, "%s %d %s %s", nomFichier, &score, date, heure) != EOF) {
        if (strcmp(nom, nomFichier) == 0) {
            dernierScore = score;
        }
    }

    fclose(fichier);
    return dernierScore;
}