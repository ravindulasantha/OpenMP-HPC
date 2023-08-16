#include <omp.h>
#include <stdio.h>

int main() {

	#pragma omp parallel num_threads(3)
	{
		int nt = omp_get_num_threads();
		int id = omp_get_thread_num();
		
		printf("\n I am thread %d of %d ", id, nt);
	}
}
