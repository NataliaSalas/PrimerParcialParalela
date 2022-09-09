#/*******************************************
#* Fecha: 09 - Agosto - 2022
#* Autor: Natalia Salas
#* Materia: Parallel and Distributed Computing 
#* Tema: Construcción Benchmark Multiplicación de matrices
#* Objetivo: 
#*******************************************/


GCC = gcc
FLAGS = -ansi -pedantic -Wall -std=c99 -D_POSIX_C_SOURCE=199309L
MATHFLAG = -lm 

PROGRS = mm_main_int mm_main_int_rnd mm_main_double mm_main_double_rnd 

all: $(PROGRS) 

mm_main_int: 
	$(GCC) $(FLAGS) -c $@.c
	$(GCC) $(FLAGS) -c mm_lib.c
	$(GCC) $(FLAGS) -o $@ $@.o mm_lib.o $(MATHFLAG)

mm_main_int_rnd: 
	$(GCC) $(FLAGS) -c $@.c
	$(GCC) $(FLAGS) -c mm_lib.c
	$(GCC) $(FLAGS) -o $@ $@.o mm_lib.o $(MATHFLAG)

mm_main_double: 
	$(GCC) $(FLAGS) -c $@.c
	$(GCC) $(FLAGS) -c mm_lib.c
	$(GCC) $(FLAGS) -o $@ $@.o mm_lib.o $(MATHFLAG)

mm_main_double_rnd: 
	$(GCC) $(FLAGS) -c $@.c
	$(GCC) $(FLAGS) -c mm_lib.c
	$(GCC) $(FLAGS) -o $@ $@.o mm_lib.o $(MATHFLAG)
	
clean: 
	$(RM) *.o $(PROGRS)
	
