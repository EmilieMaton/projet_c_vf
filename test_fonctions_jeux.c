#include <stdio.h>
#include <assert.h>
#include "module1.h"
#include "module2.h" 

int main() {
    printf("Test addition: %d\n", addition(0));
    assert(addition(0) >= 0);  // exemple d'assert simple

    printf("Test multiplication: %d\n", multiplication(0));
    assert(multiplication(0) >= 0);

    printf("Tous les tests passent !\n");
    return 0;
}