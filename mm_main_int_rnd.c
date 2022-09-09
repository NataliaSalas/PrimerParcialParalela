/*******************************************
* Fecha: 09 - Agosto - 2022
* Autor: Natalia Salas
* Materia: Parallel and Distributed Computing 
* Tema: Construcción Benchmark Multiplicación de matrices
* Objetivo: 
*******************************************/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "mm_lib.h"

#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include <stdint.h>

/*Se requiere reservar un espacio de memoria*/
#define DATA_SIZE (1024*1024*64*3)
static int MEM_CHUNK[DATA_SIZE];

int main(int argc, char **argv){
	int N;
	N=(int) atof(argv[1]);
	
	/*Decalaración de matrices con apuntadores de memoria*/
	int *a, *b, *c;
	a=MEM_CHUNK;
	b=a + N*N;
	c=b + N*N;
	
	inicializacion_int_rnd(a,b,c,N);
	impresion_int(a,N);
	impresion_int(b,N);
	punto_prueba_inicial();
	mm_c_int(a,b,c,N);
	punto_prueba_final();
	impresion_int(c,N);
	
	return 0;
}
