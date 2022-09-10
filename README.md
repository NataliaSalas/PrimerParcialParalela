# PrimerParcialParalela

**Integrantes:** Catalina Perdomo y Natalia Salas

## Contenido
Para el desarrollo del siguiente trabajo, se desarrolló un programa en lenguaje C. En primera instancia se crearon cuatro Benchmarks, los cuales consisten en una multiplicación de matrices (NxN) con valores enteros, enteros random, double y double random. Se realizo con 12 tamaños de matrices diferentes:("300","380","480","555","900","1000","1555","2100","2659","3000","3123","3200"). 
- Para la resolución de este trabajo, se implementó el paradigma de programación modular y se crearon subprogramas: 

> - lanzador.pl: Para realizar la ejecución automatizada de las pruebas de los Benchmarks, se realizó un lanzador en lenguaje Perl el cual se itera sobre la cantidad de ejecutables, la cantidad de cargas y la cantidad de repeticiones y todos estos datos se almacenan en un fichero .txt .
> - Makefile: Este archivo define un conjunto de tareas a ejecutar, contiene las órdenes que debe ejecutar la utilidad make
> - mm_lib.c: Contiene cada una de las funciones y los métodos para imprimir, inicializar, realizar la multiplicación con los diferentes valores de las matrices. 
> - mm_lib.h: En este programa se encuentra la interfaz del prototipo de funciones. Es la interfaz del mm_lib.c
> - mm_main_double.c: En este programa se encuentra el programa principal, para realizar la multiplicación de matrices con valores double. 
> - mm_main_double_rnd.c: En este programa se encuentra el programa principal para realizar la multiplicación de matrices con valores double random. 
> - mm_main_int.c: En este programa se encuentra el programa principal para realizar la multiplicación de matrices con valores enteros. 
> - mm_main_int_rnd.c: En este programa se encuentra el programa principal para realizar la multiplicación de matrices con valores enteros random. 
