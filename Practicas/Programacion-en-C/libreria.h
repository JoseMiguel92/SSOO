#ifndef _LIBRERIA_H
#define _LIBRERIA_H
/*
 * Autores: Pablo Garcia Benayas y Jose Miguel Garcia Benayas
 * Libreria práctica 1 de sistemas operativos
 * 
 * 
 * */

/* Lectura de la entrada estándar, muestra las n primeras líneas en la 
 * salida estándar recibidas por la entrada estándar.
 */
int head(int n);

/* Lectura de la entrada estándar, muestra las n últimas líneas en la
 * salida estándar recibidas por la entrada estándar.
 */ 
int tail(int n);

/* Muestra las n líneas más largas recibidas de mayor a menor longitud,
 * o todas si hay menos de n líneas por la salida estándar recibidas
 * por la entrada estándar. 
 */
int longlines(int n);

#endif