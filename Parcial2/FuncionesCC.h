#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>

//Local 
typedef struct Local{
	char nombreLocal[35];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numeroLocal;//Columnas
	char estadoLocal[35];
	// Completelo con lo que quiera
} local_t;


/*Agregar las funciones que necesite para satisfacer los requerimientos */
void mostrarLocal(local_t ** centroComercial, int numPiso,
		int numLocalxPiso, int numPisos, int numLocalesxPiso);
/*Muestra el local*/

local_t ** crearMatrizDin(int numPisos, int numLocales);
/*crea la matriz de manera dinamica*/

local_t crearLocal(int numPiso, int numLocal);


local_t crearLocal2(int numPiso, int numLocal);


void imprimirDatosPasoValor(local_t local);


int ImprimirTodo(local_t ** matriz, int cont, int cont2);


local_t eliminarLocal(int numPiso, int numLocal);


local_t mantenerLocal2(int numPiso, int numLocal);


#endif /* FUNCIONESCC_H_ */