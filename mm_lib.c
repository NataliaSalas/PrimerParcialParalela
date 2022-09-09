/*******************************************
* Fecha: 09 - Agosto - 2022
* Autor: Natalia Salas
* Materia: Parallel and Distributed Computing 
* Tema: Construcción Benchmark Multiplicación de matrices
* Objetivo: 
*******************************************/

#include "mm_lib.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include <stdint.h>
#include <unistd.h>

struct timespec inicioCuenta, finCuenta;

/*Función Impresión Int*/
void impresion_int(int *matriz, int n){
	/*Impresión*/
	int i,j;
	if(n<5){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf(" %d", matriz[j+i*n]);
			}
			printf("\n");
		}
		printf("\n--------------\n");
	}
}

/*Funcion para crear aleatorios INT*/
int random_int(){
	int min=0, max=9;
	static int flag=-1;
	if((flag = (flag<0))){
		srand(time(NULL)+getpid());
	}
	if(min>max){
		return errno=EDOM, NAN;
	}
	return min+(int)rand()/((int)RAND_MAX/(max-min));
}

/*Función Inicialización Int*/
void inicializacion_int(int *matrizA, int *matrizB, int *matrizC, int N){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matrizA[i+j*N]=2*(i+j);
			matrizB[i+j*N]=2*i+3*j;
			matrizC[i+j*N]=0;
		}
	}
}

/*Función Inicialización Aleatoria Int*/
void inicializacion_int_rnd(int *matrizA, int *matrizB, int *matrizC, int N){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matrizA[i+j*N]=random_int();
			matrizB[i+j*N]=random_int();
			matrizC[i+j*N]=0;
		}
	}
}

/**Benchmark01 Int*/
void mm_c_int(int *a, int *b, int *c, int N){
	int i,j,k, suma;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			suma=0;
			/*Punteros Auxiliares*/
			int *pA,*pB;
			pA=a+(i*N); /*columna*/
			pB=b+(j); /*fila*/
			for(k=0;k<N;k++, pA++, pB+=N){
				suma+=(*pA * *pB);
			}
			c[j+i*N]=suma;
		}
	}
}

/**DOUBLE**/
/*Función Impresión Double*/
void impresion_double(double *matriz, int n){
	/*Impresión*/
	int i,j;
	if(n<5){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf(" %f", matriz[j+i*n]);
			}
			printf("\n");
		}
		printf("\n--------------\n");
	}
}

/*Funcion para crear aleatorios DOUBLE*/
double random_double(){
	double min=0.001, max=9.999;
	static int flag=-1;
	if((flag = (flag<0))){
		srand(time(NULL)+getpid());
	}
	if(min>max){
		return errno=EDOM, NAN;
	}
	return min+(double)rand()/((double)RAND_MAX/(max-min));
}

/*Función Inicialización Double*/
void inicializacion_double(double *matrizA, double *matrizB, double *matrizC, int N){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matrizA[i+j*N]=2.1*(i+j);
			matrizB[i+j*N]=2.1*i+3.1*j;
			matrizC[i+j*N]=0;
		}
	}
}

/*Función Inicialización Aleatoria Double*/
void inicializacion_double_rnd(double *matrizA, double *matrizB, double *matrizC, int N){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matrizA[i+j*N]=random_double();
			matrizB[i+j*N]=random_double();
			matrizC[i+j*N]=0;
		}
	}
}

/**Benchmark05 Double*/
void mm_c_double(double *a, double *b, double *c, int N){
	int i,j,k;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			double suma=0;
			/*Punteros Auxiliares*/
			double *pA,*pB;
			pA=a+(i*N); /*columna*/
			pB=b+(j); /*fila*/
			for(k=0;k<N;k++, pA++, pB+=N){
				suma+=(*pA * *pB);
			}
			c[j+i*N]=suma;
		}
	}
}

/*Función evaluación inicia de tiempo*/
void punto_prueba_inicial(){
	clock_gettime(CLOCK_MONOTONIC,&inicioCuenta);
}

/*Función evaluación final de tiempo, impresión de resultado*/
void punto_prueba_final(){
	double total_time;
	clock_gettime(CLOCK_MONOTONIC,&finCuenta);
	total_time=(finCuenta.tv_sec - inicioCuenta.tv_sec)*1e9;
	total_time=(total_time + finCuenta.tv_nsec - inicioCuenta.tv_nsec)*1e-9;
	printf("%f\n", total_time);
}


