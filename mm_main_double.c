/*******************************************
* Fecha: 30 - Agosto - 2022
* Autor: Natalia Salas
* Materia: Parallel and Distributed Computing 
* Tema: Construcción Benchmark Multiplicación de matrices
* Objetivo: Uso Pthreads
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include "mm_lib.h"

/*Se requiere reservar un espacio de memoria*/
#define DATA_SIZE (1024*1024*64*3)
static double MEM_CHUNK[DATA_SIZE];

/*Se decalara las variables GLOBALES*/
double *a, *b, *c; //Matrices doubles
int Num_hilos; //Cantidad de hilos 
int N; //Dimension de matriz

int main(int argc, char **argv){
	N=(int) atof(argv[1]);
	
	/*Decalaración de matrices con apuntadores de memoria*/
	
	a=MEM_CHUNK;
	b=a + N*N;
	c=b + N*N;
	
	inicializacion_double(a,b,c,N);
	impresion_double(a,N);
	impresion_double(b,N);
	punto_prueba_inicial();
	mm_c_double(a,b,c,N);
	punto_prueba_final();
	impresion_double(c,N);
	
	return 0;
}
