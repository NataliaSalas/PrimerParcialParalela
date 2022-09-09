/*******************************************
* Fecha: 09 - Agosto - 2022
* Autor: Natalia Salas
* Materia: Parallel and Distributed Computing 
* Tema: Construcción Benchmark Multiplicación de matrices
* Objetivo: 
*******************************************/

#ifndef MM_LIB_H_INCLUDED
#define MM_LIB_H_INCLUDED

#include "mm_lib.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include <stdint.h>

/*Función Inicialización*/
void inicializacion_int(int *matrizA, int *matrizB, int *matrizC, int N);

/*Función Impresión*/
void impresion_int(int *matriz, int n);

/*Funcion para crear aleatorios INT*/
int random_int();

/*Función Inicialización Aleatoria*/
void inicializacion_int_rnd(int *matrizA, int *matrizB, int *matrizC, int N);

/**Multiplicación de matrices: Clasica*/
void mm_c_int(int *a, int *b, int *c, int N);

/**DOUBLE**/
/*Función Inicialización*/
void inicializacion_double(double *matrizA, double *matrizB, double *matrizC, int N);

/*Función Impresión*/
void impresion_double(double *matriz, int n);

/*Funcion para crear aleatorios INT*/
double random_double();

/*Función Inicialización Aleatoria*/
void inicializacion_double_rnd(double *matrizA, double *matrizB, double *matrizC, int N);

/**Multiplicación de matrices: Clasica*/
void mm_c_double(double *a, double *b, double *c, int N);

/*Función evaluación inicia de tiempo*/
void punto_prueba_inicial();

/*Función evaluación final de tiempo, impresión de resultado*/
void punto_prueba_final();

#endif

