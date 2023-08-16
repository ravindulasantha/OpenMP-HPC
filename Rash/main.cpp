#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <iostream>

int main() {
    const int N = 100000000; // Number of iterations

    clock_t start_seq = clock();
    double sum_seq = 0.0;
    for (int i = 0; i < N; ++i) {
        sum_seq += 1.0 / (i + 1);
    }
    clock_t end_seq = clock();
    double diff_seq = ((double) (end_seq - start_seq)) / CLOCKS_PER_SEC;

    clock_t start_par = clock();
    double sum_par = 0.0;
    #pragma omp parallel for reduction(+:sum_par)
    for (int i = 0; i < N; ++i) {
        sum_par += 1.0 / (i + 1);
    }
    clock_t end_par = clock();
    double diff_par = ((double) (end_par - start_par)) / CLOCKS_PER_SEC;

    printf("Sequential sum: %f\n", sum_seq);
    printf("Parallel sum: %f\n", sum_par);
    printf("Time taken for sequential execution: %f seconds\n", diff_seq);
    printf("Time taken for parallel execution: %f seconds\n", diff_par);


    return 0;
}

