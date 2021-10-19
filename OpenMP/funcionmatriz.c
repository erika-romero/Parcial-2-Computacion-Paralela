#include <stdio.h>
#include "funcionmatriz.h"

void matrizInit(int N,double *matrizA,double *matrizB,double *matrizC ){
       	for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				matrizA[j+i*N]=2.0*(i+j);
				matrizB[j+i*N]=3.2*(i+j);
		                matrizC[j+i*N]=1.0;                       ;
			}

		}

}



void multMatrices(int N,double *matrizA,double *matrizB,double *matrizC){


	for (int i=0;i<N;i++){

		for (int j=0;j<N;j++){
			double *pA;
			double *pB;
			double suma=0.0;
			pA = matrizA+(i*N);
			pB = matrizB+j;
			  for (int k=0;k<N;k++,pA++,pB+=N){

			       suma+=(*pA * *pB);
			}
			matrizC[i*N+j]=suma;
		}
	}
}

void imprimirMatriz(int N,double *matriz){


	for (int i=0;i<N;i++){

		for (int j=0;j<N;j++){
		   printf("%f\t",matriz[j+i*N]);
		}
        }
	printf("\n");
}

