#include <string.h>
#include "28M.h"

/* Esta muy bien organizado tu codigo, ojo con el estándar de nombramiento, no 
vi la función recursiva y tampoco es muy evidente el uso de enums */

struct people llenarPersonas(){
	struct people persona;
	printf("Ingrese el nombre (max 50 caracteres):\n");
	fflush(stdin);
        fgets(persona.nombre, 50, stdin );
        persona.nombre[strcspn(persona.nombre, "\n")] = 0;
	printf("Ingrese su dia de nacimiento (DD)\n");
	scanf("%i",&persona.dianac);
	printf("Ingrese su mes de nacimiento (M ej: 1 es enero)\n");
	scanf("%i",&persona.mesnac);
	printf("Ingrese su anio de nacimiento (AAA)\n");
	scanf("%i",&persona.anonac);
	return persona;
};

void imprimirDatosPasoValor(people_t persona){
	printf("Nombre:%s \n", persona.nombre );
	printf("Dia de nacimiento:%i \n", persona.dianac );
	printf("Mes de nacimiento:%i \n", persona.mesnac );
	printf("Anio de nacimiento:%i\n", persona.anonac);
}

void BuscarPersonaMes(people_t matriz[], int cont){
	int mes ;
	printf("ingrese el mes que desea buscar por el numero (01 es enero)\n");
	scanf("%i", &mes);
	for (int i = 0; i <= cont; ++i){
		if (matriz[i].mesnac == mes){
			imprimirDatosPasoValor(matriz[i]);
		}
	}
}

people_t BuscarPersonaNombre(people_t matriz[], int cont,char nombre[]){
	for (int i = 0; i <= cont; ++i){
		if (strcmp(matriz[i].nombre,nombre) == 0){
			imprimirDatosPasoValor(matriz[i]);
			int confirmacion;
			printf("Esta seguro de realizar esta accion?\n 1. Si \n 2. No \n");
			scanf("%i", &confirmacion);
			if (confirmacion == 1){
				matriz[i] = llenarPersonas();
				return matriz[i];
			}else{
				return matriz[i];
			}
		}
	}

}

int BuscarIndice(people_t matriz[], int cont,char nombre[]){
	for (int i = 0; i <= cont; ++i){
		// Luisa: posiblemente esto no te funcione, pq las cadenas no se pueden comparar con ==
		if (matriz[i].nombre == nombre){
			return i;
		}
	}
}

void ImprimirTodo(people_t matriz[], int cont){
	int salida = 1;
	while (salida != 0){
		int confirmacion;
		printf("Esta seguro de realizar esta accion?\n 1. Si \n 2. No \n");
		scanf("%i", &confirmacion);
		if (confirmacion == 1)
		{
			for (int i = 0; i < cont; ++i){
				imprimirDatosPasoValor(matriz[i]);
			}
			salida = 0;
			if (cont == 0)
			{
					printf("Creo que no se ha agregado nada aun.\n");
			}
		}
		else if (confirmacion == 2){
				salida = 0;		
		}
	}
}