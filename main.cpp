#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int N = 1000;
    int A[N], B[N], C[N], thread_id[N];

    srand((unsigned)time(NULL));

    // Initialize arrays
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

    omp_set_num_threads(4);
    // Parallel sum
    #pragma omp parallel for schedule(static,1)
    for (int i = 0; i < N; i++) {
        thread_id[i] = omp_get_thread_num();
        C[i] = A[i] + B[i];
    }

    // Print only first 10 results (outside parallel region)
    cout << "Index\tThread\tA\tB\tC\n";
    for (int i = 0; i < 20; i++) {
        cout << i << "\t"
             << thread_id[i] << "\t"
             << A[i] << "\t"
             << B[i] << "\t"
             << C[i] << endl;
    }

    #pragma omp parallel
    {
    #pragma omp single
    cout << "OpenMP threads in use: "
         << omp_get_num_threads() << endl;
    }

    return 0;
}