#include <stdio.h>
#include <omp.h>
#include <time.h>
//reduction
int main()
{
	clock_t start,finish;
	double totaltime;
	start=clock();
	int i,n;
	float a[10],b[10],result;
	// initializations
	n = 10;
	result = 0.0;
	for (i=0; i<n; i++)
	{
		a[i] = i*1.5;
		b[i] = i*2.5;
	}
	#pragma omp parallel for private(i) reduction(+:result)
	for (i=0; i<n; i++)
	{
		result = result + (a[i] * b[i]);
	}
	printf ("a*b=%12.6lf\n",result);
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
	printf ("run time=%8.6lfs\n",totaltime);
	return 0;
}
