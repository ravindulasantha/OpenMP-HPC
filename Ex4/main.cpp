#include <omp.h>
#include <stdio.h>

int main() {

	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int n = sizeof(a)/sizeof(a[0]);
	
	omp_set_num_threads(4);
	
	#pragma omp parallel
	{
		int nthreads = omp_get_num_threads();
		int myid = omp_get_thread_num();
		
		for(int i=myid; i<n; i+=nthreads){
			a[i] += 10;
			printf("\n Thread %d >>> a[%d] = %d ", myid, i, a[i]);
		}
	}

}
