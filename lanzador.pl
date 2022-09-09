#!/usr/bin/perl

=begin comment
Fecha: 09 - Agosto - 2022
Autor: Natalia Salas
Materia: Parallel and Distributed Computing 
Tema: Ejecucion automatizada de Benchmarks
=cut

#Vector para las ejecutables o benchmarks
@Benchmarks = ("mm_main_int","mm_main_int_rnd","mm_main_double","mm_main_double_rnd");
#Vector para las cargas
@Cargas = ("300","380","480","555","900","1000","1555","2100","2659","3000","3123","3200");
#Número de repeticiones
$n=30;
#Se almacena la ubicación 
$Path = "/home/ubuntu/Documents/Paralela/BenchmarksParcial/";

#Se itera sobre 
#la cantidad de ejecutables
#la cantidad de cargas 
#la cantidad de repeticiones

foreach $exes (@Benchmarks){
    foreach $carga (@Cargas){
        #Se crea el fichero para almacenar datos
        #concatenacion.
        $file = "Soluciones/".$exes."-size-".$carga.".txt"; 
        #printf("$Path$file\n");
        for ($i=0;$i<$n;$i++){
            system("$Path$exes $carga >> $file"); #>> lo guarde en file
            #printf("$Path$exes $carga\n");
        }
        #Cerrar el fichero
        close($file);
    }
}
