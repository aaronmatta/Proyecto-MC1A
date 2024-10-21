#include <iostream> // cout, cin (Para imprimir en consola y leer de consola)
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

        int numeroRandomGenerado = rand(); // Número aleatorio generado

        /* cout << numeroRandomGenerado << "\n"; // Numeros aleatorios
        cout << numeroRandomGenerado % 10 << "\n"; // Numeros de 0 a 9  */

        numeroRandom = limiteInferior + numeroRandomGenerado % (limiteSuperior + 1 - limiteInferior);
        array[i] = numeroRandom;
    }

    // {3,4,1,6,9}

    cout << "\n";
    for (int i = 0; i < 5; i++) {
        cout << array[i] << "  ";
    }
    cout << "\n";

    // Inciso a). Calcular si el numero tiene digitos repetidos o todos los digitos son diferentes (no se repiten)

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
        cout << "\nEl numero tiene digitos repetidos\n";
    } else {
        cout << "\nEl numero NO tiene digitos repetidos\n";
    }

    // Inciso c). Calcular que números de 0 a 9 se repiten en el número generado

    int contador[10] = {0,0,0,0,0,0,0,0,0,0};

    // {0,0,0,0,0,0,0,0,0,0}
    // {1,0,0,0,0,0,2,3,0,0}

    for (int i = 0; i < 5; i++) {
        contador[array[i]]++;
    }

    for (int i = 0; i < 10; i++) {
        if (contador[i] > 0) {
            cout << "\nEl numero " << i << " se repite " << contador[i] << " veces";
        }
    }

    // Inciso b). Calcular cual fué el número que se repitió mas veces.
    // {2,1,2,0,0,0,0,0,0,0}
    int numeroMasRepetido = 0;
    int vecesRepetido = 0;
    bool hayEmpate = false;

    if (digitosRepetidos) {
        for (int i = 0; i < 10; i++) {
            if (contador[i] > vecesRepetido) {
                numeroMasRepetido = i;
                vecesRepetido = contador[i];
                hayEmpate = false;
            } else if (i != numeroMasRepetido && contador[i] == vecesRepetido) { //vecesRepetido > 1
                hayEmpate = true;
            }
        }
    }

    if (hayEmpate) {
        cout << "\nHay un empate entre estos dos numeros: ";

        for (int i = 0; i < 10; i++) {
            if (contador[i] == vecesRepetido) {
                cout << i << " ";
            }
        }

        cout << ", los cuales se repitieron " << vecesRepetido << " veces.\n";
    
    } else if (digitosRepetidos){
        cout << "\n\nEl numero que se repitio mas veces fue el " << numeroMasRepetido << " con " << vecesRepetido << " veces\n";
    } else {
        cout << "\n\nTodos los numeros son distintos\n";
    }

    return 0;
}
