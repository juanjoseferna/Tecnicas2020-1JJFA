#include <stdio.h>


typedef struct people people_t;

struct people{
	char nombre[50];
	int dianac;
	int mesnac;
	int anonac;
	
};

typedef enum mesesano{
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
	Noviembre = 11,
	Diciem = 12
} meses;

struct people llenarPersonas();
/*Se usa para llenar los datos y retorna todos los datos */ 

void imprimirDatosPasoValor(people_t persona); 
/*Imprime los datos*/

void BuscarPersonaMes(people_t matriz[], int cont);
/*Busca a las personas segun el mes*/

people_t BuscarPersonaNombre(people_t matriz[], int cont,char nombre[]);
/*Busca y reemplaza a las personas segun su nombre */

int BuscarIndice(people_t matriz[], int cont,char nombre[]);
/*Es un complemento de la funcion "BuscarPersonaNombre", esta recibe todo y se encarga de retornar el indice*/ 

void ImprimirTodo(people_t matriz[], int cont);
/*Imprime todo*/