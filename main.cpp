#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int N = 1000;
    int A[N], B[N], C[N];

    // Números aleatorios
    srand((unsigned)time(NULL));

    // Arreglos A y B
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

    // Suma de arreglos en paralelo
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }

    // Mostrar algunos resultados para comprobar
    cout << "Indice\tA\tB\tC (A+B)" << endl;
    for (int i = 0; i < 20; i++) {
        cout << i << "\t" << A[i] << "\t" << B[i] << "\t" << C[i] << endl;
    }

    return 0;
}

 // Esta linea se usa para activar openOMP y crear el archivo que se ejecuta en terminal
 // g++ -Xpreprocessor -fopenmp -I$(brew --prefix libomp)/include -L$(brew --prefix libomp)/lib -lomp main.cpp -o Suma

 // Con esto se ejecuta el programa en OMP ./Suma

