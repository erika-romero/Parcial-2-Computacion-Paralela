#!/usr/bin/perl

# Fichero para automatización de ejecución por lotes de un ejecutable
# dado parámetros de entrada.
# $ --> variable
# @ --> vector
$repeticiones = 30;
@ejecutables = ("matricesApp");
@matrizSize = ("100","200","400","800","1000","1200","2000","4000");
$path = "/home/erik-/Escritorio/ComputacionP/pipThreads/";
$cores = 8;

foreach $exe (@ejecutables) {
	foreach $size (@matrizSize) {
		$fichero = "$path"."Soluciones/"."$exe"."-size"."$size";
		#print("$fichero\n");
		for ($i=0; $i<$repeticiones; $i++) {
			print("$path$exe $size $cores\n");
			system("$path$exe $size $cores >> $fichero");
		}
	}
}
exit(1);
