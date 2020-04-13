#include "FuncionesCC.h"
#include <string.h>

/* Funcion de ejemplo que imprimiria la informacion de un local */
void mostrarLocal(local_t ** centroComercial, int numPiso,
		int numLocalxPiso, int numPisos, int numLocalesxPiso) {
	
	//Se valida si el numero ingresado esta en el rango
	if(numPiso<=numLocalxPiso && numLocalxPiso <= numLocalesxPiso)
	{
		printf("Nombre local : %s \n", centroComercial[numPiso][numLocalxPiso].nombreLocal);
		printf("Numero local : %d \n", centroComercial[numPiso][numLocalxPiso].numeroLocal);
		printf("Estado local : %s \n", centroComercial[numPiso][numLocalxPiso].estadoLocal);
	}
	//TODO completarlo con los datos que le sirvan en su caso
}

local_t ** crearMatrizDin(int numPiso, int numLocal){
    local_t** matriz= malloc(sizeof(local_t*)*(numPiso));
    for(int i=0;i<numPiso;i++){
        matriz[i]=malloc(sizeof(local_t)*(numLocal));
    }
    return matriz;
}

local_t crearLocal(int numPiso, int numLocal){
	local_t local;
	printf("Ingrese el nombre (max 35 caracteres):\n");
	fflush(stdin);
        fgets(local.nombreLocal, 35, stdin );
        local.nombreLocal[strcspn(local.nombreLocal, "\n")] = 0;
	local.pisoLocal = numPiso;
	local.numeroLocal = numLocal;
	local.idLocal = numPiso + numLocal*3;
	char Ocupado[]={"Ocupado"};
	strcpy(local.estadoLocal,Ocupado);
	return local;
}


local_t crearLocal2(int numPiso, int numLocal){
	local_t local;
	char vacio[6] = {"Vacio"};
	char Disponible[11] = {"Disponible"};
	strcpy(local.nombreLocal,vacio);
	local.pisoLocal = numPiso;
	local.numeroLocal = numLocal;
	local.idLocal = numPiso + numLocal*3;
	strcpy(local.estadoLocal,Disponible);
	return local;
}

void imprimirDatosPasoValor(local_t local){
		printf("Nombre local : %s \n", local.nombreLocal); 
		printf("Id local : %i \n", local.idLocal);
		printf("Piso local : %d \n", local.pisoLocal);
		printf("Numero local : %d \n", local.numeroLocal);
		printf("Estado local : %s \n", local.estadoLocal);
}

int ImprimirTodo(local_t ** matriz, int cont, int cont2){
	int confirmacion;
	printf("Esta seguro de realizar esta accion?\n 1. Si \n 2. No \n");
	scanf("%i", &confirmacion);
	if (confirmacion == 1)
	{
		for (int i = 0; i < cont; ++i){
			for (int j = 0; j <cont2 ; ++j)
			{
				imprimirDatosPasoValor(matriz[i][j]);
			}
		}
		return 0;
	}else if (confirmacion == 2){
			return 0;		
	}else if (confirmacion != 2 || confirmacion != 1){
		ImprimirTodo(matriz,cont,cont2);
	}

}

local_t eliminarLocal(int numPiso, int numLocal){
	local_t local;
	char vacio[6] = {"Vacio"};
	char Disponible[11] = {"Disponible"};
	strcpy(local.nombreLocal,vacio);
	strcpy(local.estadoLocal,Disponible);
	local.pisoLocal = numPiso;
	local.idLocal = numPiso + numLocal*3;
	local.numeroLocal = numLocal;
	return local;
}

local_t mantenerLocal2(int numPiso, int numLocal){
		local_t local;
		char vacio[6] = {"Vacio"};
		strcpy(local.nombreLocal,vacio);
		char Mantenimiento[] = {"Mantenimiento"};
		strcpy(local.estadoLocal,Mantenimiento);
		local.numeroLocal = numLocal;
		local.pisoLocal = numLocal;
		local.idLocal = numPiso + numLocal*3;
		return local;
	}
