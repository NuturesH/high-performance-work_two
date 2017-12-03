#include <stdio.h>
#include <omp.h>

int main ()
{
	int i,j,num,k;
	double serial_time;
	double start, finish;
//串行部分
	FILE *fp = NULL;
	fp = fopen("0.txt","w");
	start = omp_get_wtime();
	k=0;
	
	for (i=2; i<100000; i++)
	{
		num = 0;
		for ( j = 1;j<=i;j++)
			{
			if(i%j == 0) 
                        num += 1;
			}
		if (num <= 2)
			{
			fprintf(fp,"%d ",i);
			k+=1;
			//printf("%d ",k);
			}
	}
	fclose(fp);
	finish = omp_get_wtime();
	serial_time = (double)(finish-start);
	
//并行部分
//一个线程
	start = omp_get_wtime();
	fp = fopen("1.txt","w");
	#pragma omp parallel num_threads(1)
	#pragma omp parallel private(num)
	for(i = 2; i <= 100000; i++){
        int num = 0;
        #pragma omp parallel for reduction(+:num)
        for(j = 1; j <= i; j++)
            if(i % j == 0)
                num += 1;
        
        if(num <= 2)
            fprintf(fp, "%d ", i);
    }
        fclose(fp);
        finish = omp_get_wtime();
        double parellel_1 = (double)(finish - start);
  	double speedup_ratio_1 = serial_time / parellel_1;
	
//两个线程
	start = omp_get_wtime();
	fp = fopen("2.txt","w");
	#pragma omp parallel num_threads(2)
	#pragma omp parallel private(num)
	for(i = 2; i <= 100000; i++){
        int num = 0;
        #pragma omp parallel for reduction(+:num)
        for(j = 1; j <= i; j++)
            if(i % j == 0)
                num +=1;
        
        if(num <= 2)
            fprintf(fp, "%d ", i);
    }
        fclose(fp);
        finish = omp_get_wtime();
        double parellel_2 = (double)(finish - start);
	double speedup_ratio_2 = serial_time / parellel_2;

//三个线程
	start = omp_get_wtime();
	fp = fopen("3.txt","w");
	#pragma omp parallel num_threads(3)
	#pragma omp parallel private(num)
	for(i = 2; i <= 100000; i++){
        int num = 0;
        #pragma omp parallel for reduction(+:num)
        for(j = 1; j <= i; j++)
            if(i % j == 0)
                num +=1;
        
        if(num <= 2)
            fprintf(fp, "%d ", i);
     }
        fclose(fp);
        finish = omp_get_wtime();
        double parellel_3 = (double)(finish - start);
	double speedup_ratio_3 = serial_time / parellel_3;
	
//四个线程
	start = omp_get_wtime();
	fp = fopen("4.txt","w");
	#pragma omp parallel num_threads(4)
	#pragma omp parallel private(num)
	for(i = 2; i <= 100000; i++){
        int num = 0;
        #pragma omp parallel for reduction(+:num)
        for(j = 1; j <= i; j++)
            if(i % j == 0)
                num +=1;
        
        if(num <= 2)
            fprintf(fp, "%d ", i);
    }
        fclose(fp);
        finish = omp_get_wtime();
        double parellel_4 = (double)(finish - start);
	double speedup_ratio_4 = serial_time / parellel_4;

	
//五个线程
	start = omp_get_wtime();
	fp = fopen("5.txt","w");
	#pragma omp parallel num_threads(5)
	#pragma omp parallel private(num)
	for(i = 2; i <= 100000; i++){
        int num = 0;
        #pragma omp parallel for reduction(+:num)
        for(j = 1; j <= i; j++)
            if(i % j == 0)
                num +=1;
        
        if(num <= 2)
            fprintf(fp, "%d ", i);
    }
        fclose(fp);
        finish = omp_get_wtime();
        double parellel_5 = (double)(finish - start);
	double speedup_ratio_5 = serial_time / parellel_5;

	
//六个线程
	start = omp_get_wtime();
	fp = fopen("6.txt","w");
	#pragma omp parallel num_threads(6)
	#pragma omp parallel private(num)
	for(i = 2; i <= 100000; i++){
        int num = 0;
        #pragma omp parallel for reduction(+:num)
        for(j = 1; j <= i; j++)
            if(i % j == 0)
                num +=1;
        
        if(num <= 2)
            fprintf(fp, "%d ", i);
        }
        fclose(fp);
        finish = omp_get_wtime();
        double parellel_6 = (double)(finish - start);
	double speedup_ratio_6 = serial_time / parellel_6;

//七个线程
	start = omp_get_wtime();
	fp = fopen("7.txt","w");
	#pragma omp parallel num_threads(7)
	#pragma omp parallel private(num)
	for(i = 2; i <= 100000; i++)
	{
        int num = 0;
        #pragma omp parallel for reduction(+:num)
        for(j = 1; j <= i; j++)
            if(i % j == 0)
                num +=1;
        
        if(num <= 2)
            fprintf(fp, "%d ", i);
  	}
        fclose(fp);
        finish = omp_get_wtime();
        double parellel_7 = (double)(finish - start);
        double speedup_ratio_7 = serial_time / parellel_7;


//八个线程
	start = omp_get_wtime();
	fp = fopen("8.txt","w");
	#pragma omp parallel num_threads(8)
	#pragma omp parallel private(num)
	for(i = 2; i <= 100000; i++)
	{
        int num = 0;
        #pragma omp parallel for reduction(+:num)
        for(j = 1; j <= i; j++)
            if(i % j == 0)
                num +=1;
        
        if(num <= 2)
            fprintf(fp, "%d ", i);
   	 }
        fclose(fp);
        finish = omp_get_wtime();
        double parellel_8 = (double)(finish - start);
	double speedup_ratio_8 = serial_time / parellel_8;


	printf("\n素数的个数：");
	printf("%d ",k);
	printf("\n串行所运行时间：");
	printf("%8.6lfs\n",serial_time);
	
	printf ("一个线程并行所运行的时间:");
	printf ("%8.6lfs\n",parellel_1);
	printf ("一个线程的加速比：");
	printf ("%8.6lf\n",speedup_ratio_1);

	printf ("两个线程并行所运行的时间:");
	printf ("%8.6lfs\n",parellel_2);
	printf ("两个线程的加速比：");
	printf ("%8.6lf\n",speedup_ratio_2);

	printf ("三个线程并行所运行的时间:");
	printf ("%8.6lfs\n",parellel_3);
	printf ("三个线程的加速比：");
	printf ("%8.6lf\n",speedup_ratio_3);	

	printf ("四个线程并行所运行的时间:");
	printf ("%8.6lfs\n",parellel_4);
	printf ("四个线程的加速比：");
	printf ("%8.6lf\n",speedup_ratio_4);
	
	printf ("五个线程并行所运行的时间:");
	printf ("%8.6lfs\n",parellel_5);
	printf ("五个线程的加速比：");
	printf ("%8.6lf\n",speedup_ratio_5);


	printf ("六个线程并行所运行的时间:");
	printf ("%8.6lfs\n",parellel_6);
	printf ("六个线程的加速比：");
	printf ("%8.6lf\n",speedup_ratio_6);
	

	printf ("七个线程并行所运行的时间:");
	printf ("%8.6lfs\n",parellel_7);
	printf ("七个线程的加速比：");
	printf ("%8.6lf\n",speedup_ratio_7);


	printf ("八个线程并行所运行的时间:");
	printf ("%8.6lfs\n",parellel_8);
	printf ("八个线程的加速比：");
	printf ("%8.6lf\n",speedup_ratio_8);	

}
