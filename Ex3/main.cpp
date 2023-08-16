#include <omp.h>
#include <stdio.h>

int main() {

	int a[] = {0,0,0,0,0,0,0,0};
	
	omp_set_num_threads(8);
	
	#pragma omp parallel
	{
		int myid = omp_get_thread_num();
		a[myid] = myid + 10;
		printf("\n Thread %d >>> a[%d] = %d ", myid, myid, a[myid]);
	}

}
