#include <iostream>
#include <time.h> // time(NULL)
#include <stdlib.h> // rand() y srand()

using namespace std;

int main() {

    srand(time(NULL)); // Semilla para números aleatorios
    
    int numeroRandom;
    int limiteInferior = 0;
    int limiteSuperior = 9;

    int array[5]; // Array de 5 enteros
    // {0,0,0,0,0}

    for (int i = 0; i < 5; i++) {
        numeroRandom = limiteInferior + rand() % (limiteSuperior + 1 - limiteInferior);
        array[i] = numeroRandom;
    }

    // {3,4,1,6,9}

    for (int i = 0; i < 5; i++) {
        cout << array[i] << "  ";
    }

    // Inciso a). Calcualr si el numero tiene digitos repetidos o todos los digitos son diferentes (no se repiten)

    bool digitosRepetidos = false;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            /* cout << "\nComparando " << array[i] << " con " << array[j]; */
            if (array[i] == array[j]) {
                digitosRepetidos = true;
                break;
            }
        }
    }

    if (digitosRepetidos) {
        cout << "\nEl numero tiene digitos repetidos";
    } else {
        cout << "\nEl numero NO tiene digitos repetidos";
    }

    // Inciso b) y c). Calcular que números de 0 a 9 se repiten en el número generado

    int contador[10] = {0,0,0,0,0,0,0,0,0,0};

    // {0,0,0,0,0,0,0,0,0,0}
    // {1,1,0,1,0,1,2,0,0,0}

    for (int i = 0; i < 5; i++) {
        contador[array[i]]++;
    }

    for (int i = 0; i < 10; i++) {
        if (contador[i] > 0) {
            cout << "\nEl numero " << i << " se repite " << contador[i] << " veces";
        }
    }

    return 0;
}
