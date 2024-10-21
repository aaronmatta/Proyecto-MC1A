#include <iostream>
#include <time.h> // time(NULL)
#include <stdlib.h> // rand() y srand()

using namespace std;

int main(int argc, char **argv) {

    srand(time(NULL)); // Semilla para números aleatorios
    
    int numeroRandom;
    int limiteInferior = 0;
    int limiteSuperior = 9;

    int array[5]; // Array de 5 enteros

    for (int i = 0; i < 5; i++) {
        numeroRandom = limiteInferior + rand() % (limiteSuperior + 1 - limiteInferior);
        array[i] = numeroRandom;

    }

    for (int i = 0; i < 5; i++) {
        cout << array[i] << "\n";
    }

    return 0;
}
