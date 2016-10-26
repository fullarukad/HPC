/******************************************************************************
* FILE: omp_hello.c
* DESCRIPTION:
*   OpenMP - suma de dos matricez  - C/C++ Version
*  
*
*	¿para que se usa la sentencia shedule? 
*	**la sentencia shedule se usa para determinar cuantas iteraciones
*	**de un bucle se ejecutan en un grupo de hilos
* 
*		
*   thread's number.
* AUTHOR: Douglas hernandez  25/10
******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N =100; 
#define CHUNKSIZE 10 numero de iteracion en el grupo de hilos
int main (int argc, char *argv[]) 
{
int nthreads, tid;

float  a[N][N],b[N][N],c[N][N];

/* Some initializations */
for (i=0; i < N; i++){
	for(j=0;j<N;j++){
	  a[i][j]= b[i][j] = 1.0;
	}		
}
	
chunk = CHUNKSIZE;

/* Fork a team of threads giving them their own copies of variables */
#pragma omp parallel shared(a,b,c,nthreads,chunk) private(nthreads, tid)
  {

  /* Obtain thread number */
  tid = omp_get_thread_num();
  printf("Hello World from thread = %d\n", tid);

  /* Only master thread does this */
  if (tid == 0) 
    {
    nthreads = omp_get_num_threads();//obtiene el numero de hilos
    printf("Number of threads = %d\n", nthreads);
    }

    printf("Thread %d starting...\n",tid);//ID thread working...
	
	#pragma omp for schedule(dynamic,chunk)
		for (i=0; i < N; i++){
			for(j=0;j<N;j++){
			  c[i][j]=a[i][j]+b[i][j];
			}		
		}	
  }  //termina la seccion pragma
  
  for (i=0; i < N; i++){
	for(j=0;j<N;j++){
	  printf("resultado : pos(%d,%d) , %f",i,j,c[i][j]);	
	}
	printf("\n");	
  }
}
