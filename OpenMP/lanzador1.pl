#!/usr/bin/perl



$repeticiones = 30;
@ejecutables = ("matrizApp");
@matrizSize = ("100","1000","2400");
$path = "/home/erik-/Escritorio/ComputacionP/separada_01/";
$cores = 8;


foreach $exe (@ejecutables){
	foreach $size (@matrizSize){
		$fichero = "$path"."Soluciones8/"."$exe"."-size"."$size";
		#print("$fichero\n" );
		for($i = 0; $i < $repeticiones ; $i ++){
			print("$path$exe $size $cores \n");
			system("$path$exe $size $cores >> $fichero");
		}
	}
}
exit(1);
