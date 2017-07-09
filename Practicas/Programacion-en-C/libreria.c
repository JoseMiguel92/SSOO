/*
 * Autores: Pablo Garcia Benayas y Jose Miguel Garcia Benayas
 * Implementación de las funciones de la libreria "libreria.h" para la 
 * práctica 1 de sistemas operativos
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"
#define LINE_LENGTH 1024

void imprimir(char** a, int n){
	int i;
	for(i=0;i<n;i++){
		fputs(a[i],stdout);
	}
}

/* Lectura de la entrada estándar, muestra las n primeras líneas en la 
 * salida estándar recibidas por la entrada estándar.
 */
int head(int n){
	//Variables
	int i;
	char buffer[LINE_LENGTH];

	//Imprime las lineas que recibe por la entrada estandar, hasta i<=n o recibir NULL
	i=1;
	while(i<=n && (fgets(buffer,LINE_LENGTH,stdin)!=NULL)){
		fputs(buffer,stdout);
		i++;
	}
	return 0;
}

/* Lectura de la entrada estándar, muestra las n últimas líneas en la
 * salida estándar recibidas por la entrada estándar.
 */ 
int tail(int n){
	//Variables
	int i;
	char buffer[LINE_LENGTH];
	char **array;
	
	//Reserva de memoria para el array de char*
	array = (char**)malloc(n*sizeof(char*));
	
	//Reserva de memoria en cada posición del array para almacenar un string de longitud LINE_LENGTH
	for(i=0;i<n;i++){
		array[i] = (char*) malloc(LINE_LENGTH*sizeof(char));
	}
	
	//Lectura de lineas por la entrada estandar hasta que recibe NULL
	while(fgets(buffer,LINE_LENGTH,stdin)!=NULL){
		for(i=1;i<n;i++){
			strcpy(array[i-1],array[i]);
		}
		strcpy(array[n-1],buffer);
	}
	//Imprimir n lineas por la salida estandar
	imprimir(array,n);
	
	//Liberar memoria creada para los string de cada posicion y el array
	for(i=0;i<n;i++){
		free(array[i]);
	}
	free(array);
	return 0;
}

/* Muestra las n líneas más largas recibidas de mayor a menor longitud,
 * o todas si hay menos de n líneas por la salida estándar recibidas
 * por la entrada estándar. 
 */
int longlines(int n){
	//Variables
	int i,j;
	char buffer[LINE_LENGTH];
	char **array;
	int position;
	
	//Reserva de memoria para el array de char*
	array = (char**)malloc(n*sizeof(char*));
	
	//Reserva de memoria en cada posición del array para almacenar un string de longitud LINE_LENGTH
	for(i=0;i<n;i++){
		array[i] = (char*) malloc(LINE_LENGTH*sizeof(char));
	}
	//position = 0;
	
	
	//Lectura de lineas por entrada estandar hasta que recibe NULL
	while(fgets(buffer,LINE_LENGTH,stdin) != NULL){
		position = 0;
		i=0;
		//Incluye la linea leida en la posición que le corresponde si el tamaño es mayor al existente
		while(i<n && position == 0){
			if(strlen(buffer)>strlen(array[i])){
				for(j=n-1;j>i;j--){
					strcpy(array[j],array[j-1]);
				}
				strcpy(array[i],buffer);
				position = 1;
			}
			i++;
		}
	}
	
	//Imprimir las n linas por salida estandar
	for(i=0;i<n;i++){
		fputs(array[i],stdout);
	}
	
	//Liberar memoria creada para los string de cada posicion y el array
	for(i=0;i<n;i++){
		free(array[i]);
	}
	free(array);
	return 0;
}