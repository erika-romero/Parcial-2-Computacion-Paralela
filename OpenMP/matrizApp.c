#include <stdio.h>
#include <stdlib.h>
#include "funcionmatriz.h"
#include "ctime.h"
#include <omp.h>

#define SIZE_DATA (1024*1024*64*3)

static double MEM_CHUNK[SIZE_DATA];




int main(int argc,char **argv){


int N = (int) atof(argv[1]); //tamaño de la matriz
int numThreads = (int) atof(argv[2]); //cantidad de hilos a emplear

//#pragma omp parallel

{

double *matrizA, *matrizB, *matrizC;

matrizA=MEM_CHUNK;
matrizB=matrizA+N*N;
matrizC=matrizB + N*N;

//se deja que el hilo principal(maestro) haga las rutinas de inicializacion
//#pragma omp master


matrizInit(N,matrizA,matrizB,matrizC);



/*
printf("matriz A =\n");
imprimirMatriz(N,matrizA);
printf("\n");


printf("matriz B =\n");
imprimirMatriz(N,matrizB);
printf("\n");
*/

omp_set_num_threads (numThreads);
sampleStart();

//prueba multiplicacion de matrices con openMP

#pragma omp parallel for

for (int i=0;i<N;i++){
	for (int j=0;j<N;j++){
		double *pA, *pB;
		double suma=0.0;
		pA=matrizA+(i*N);
		pB=matrizB+j;
		for(int k=0;k<N;k++,pB+=N){
			suma+=(*pA * *pB);

		}

		matrizC[i*N+j]=suma;
	}

}

sampleStop();

}

printTime();


}
