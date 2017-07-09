#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

/* 
 * Autores: Pablo Garcia Benayas y Jose Miguel Garcia Benayas
 * Programa para probar el correcto funcionamiento de la 
 *  libreria implementada
*/

int error(char *value){
	printf("Error, argumentos no validos.Uso:\n\t%s head -N\n\t%s tail -N\n\t%s longlines -N\nN debe ser el numero de lineas que desea\n",value,value,value);
	return 1;
}

int main(int argc, char *argv[]){

	int lines;
	char *num;
	
	switch(argc){
		case 3:
			num = argv[2]+1;
			if(strcmp(num,"\0")!=0){
				lines = atoi(num);
			
				if(strcmp(argv[1],"head")==0){
					head(lines);
				}else if(strcmp(argv[1],"tail")==0){
					tail(lines);
				}else if(strcmp(argv[1],"longlines")==0){
					longlines(lines);
				}else{
					return error(argv[0]);
				}
			}else{
				printf("Error, el parametro -N no es valido, introduzca un numero de lineas valido.\n");
			}
		break;
		default:
			return error(argv[0]);
	} 
	return 0;
}