#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>

//Local
enum mesCreacion {
	Enero = 1,
	Febrero = 2,
	Marzo = 3,
	Abril = 4,
	Mayo = 5,
	Junio = 6,
	Julio = 7,
	Agosto = 8,
	Septiembre = 9,
	Octubre = 10,
	Noviembre =11,
	Diciembre = 12
};
typedef enum mesCreacion meses;

typedef struct Local{
	char nombreLocal[35];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numeroLocal;//Columnas
	char estadoLocal[35];
	int ingresosLocal;
	meses mesCreacion;
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


int imprimirTodo(local_t ** matriz, int cont, int cont2);


local_t eliminarLocal(int numPiso, int numLocal);


local_t mantenerLocal2(int numPiso, int numLocal);


void imprimirPuntos();


void guardarMatrizAuxiliar(local_t local,  FILE * flujo);


void guardarMatriz( local_t **matriz, int filas, int cols);


int exportarArchivos(local_t **matriz ,int numPisos, int numLocalesxPiso);


int importarArchivos(local_t **matriz ,int numPisos, int numLocalesxPiso);


void merge(local_t Lista[], int l, int m, int r);


void mergeSort(local_t Lista[], int l, int r);


void printLista(local_t Lista[], int size);


int ordenarMergerSort(local_t **centroComercial, int numPisos, int numLocalesxPiso);


void insertFuntion( local_t centroComercial[], int Lista_size );


void ordenamientoInserction(local_t **centroComercial, int numPisos, int numLocalesxPiso);


void selectionSort( local_t Lista[],int numLocalesxPiso );


void ordenarSelection( local_t ** centroComercial, int numPisos, int numLocalesxPiso );

#endif /* FUNCIONESCC_H_ */