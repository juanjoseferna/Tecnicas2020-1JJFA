#include "FuncionesCC.h"
#include <string.h>
#include <windows.h>

void imprimirMes(meses mesCreacion){
	if (mesCreacion == 1){
		printf("Mes de creacion : Enero\n" );
	}
	else if (mesCreacion == 2){
		printf("Mes de creacion : Febrero\n" );
	}
	else if (mesCreacion == 3){
		printf("Mes de creacion : Marzo\n" );
	}
	else if (mesCreacion == 4){
		printf("Mes de creacion : Abril\n" );
	}
	else if (mesCreacion == 5){
		printf("Mes de creacion : Mayo\n" );
	}
	else if (mesCreacion == 6){
		printf("Mes de creacion : Junio\n" );
	}
	else if (mesCreacion == 7){
		printf("Mes de creacion : Julio\n" );
	}
	else if (mesCreacion == 8){
		printf("Mes de creacion : Agosto\n" );
	}
	else if (mesCreacion == 9){
		printf("Mes de creacion : Septiembre\n" );
	}
	else if (mesCreacion == 10){
		printf("Mes de creacion : Octubre\n" );
	}
	else if (mesCreacion == 11){
		printf("Mes de creacion : Noviembre\n" );
	}
	else if (mesCreacion == 12){
		printf("Mes de creacion : Diciembre\n" );
	}
	else if (mesCreacion == 0){
		printf("Mes de creacion : Invalido\n" );
	}
}


/* Funcion de ejemplo que imprimiria la informacion de un local */
void mostrarLocal(local_t ** centroComercial, int numPiso,
		int numLocalxPiso, int numPisos, int numLocalesxPiso) {
	
	//Se valida si el numero ingresado esta en el rango
	if(numPiso<=numLocalxPiso && numLocalxPiso <= numLocalesxPiso)
	{
		printf("Nombre local : %s \n", centroComercial[numPiso][numLocalxPiso].nombreLocal);
		printf("Numero local : %d \n", centroComercial[numPiso][numLocalxPiso].numeroLocal);
		printf("Estado local : %s \n", centroComercial[numPiso][numLocalxPiso].estadoLocal);
		printf("Ingresos local : %i\n", centroComercial[numPiso][numLocalxPiso].ingresosLocal);
		imprimirMes(centroComercial[numPiso][numLocalxPiso].mesCreacion);
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
	printf("Ingrese los ingresos del local\n");
	int ingresos;
	scanf("%i", &ingresos);
	local.ingresosLocal = ingresos;
	printf("Ingrese el mes en el que se ha sido incorporado el local al centro comercial"
		" \n(recuerde que el centro comercial solo tiene un anio, Ej: 1. Enero)\n");
	meses mesInco;
	scanf("%d", &mesInco);
	local.mesCreacion = mesInco;
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
	local.ingresosLocal = 0;
	local.mesCreacion = 0;
	return local;
}

void imprimirDatosPasoValor(local_t local){
		printf("Nombre local : %s \n", local.nombreLocal); 
		printf("Id local : %i \n", local.idLocal);
		printf("Piso local : %d \n", local.pisoLocal + 1);
		printf("Numero local : %d \n", local.numeroLocal + 1);
		printf("Estado local : %s \n", local.estadoLocal);
		printf("Ingresos local : %i$ \n", local.ingresosLocal);
		imprimirMes(local.mesCreacion);
}

int imprimirTodo(local_t ** matriz, int cont, int cont2){
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
	}else{
		imprimirTodo(matriz,cont,cont2);
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
	local.ingresosLocal = 0;
	local.mesCreacion = 0;
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

void imprimirPuntos(){
	for (int i = 0; i < 10; ++i)
	{
		printf(".");
		Sleep(1000);
	}
}

void guardarMatrizAuxiliar(local_t local,  FILE * centroComercial){
		fprintf (centroComercial,"Nombre local : %s \n", local.nombreLocal); 
		fprintf (centroComercial,"Id local : %i \n", local.idLocal);
		fprintf (centroComercial,"Piso local : %d \n", local.pisoLocal + 1);
		fprintf (centroComercial,"Numero local : %d \n", local.numeroLocal + 1);
		fprintf (centroComercial,"Estado local : %s \n", local.estadoLocal);
		fprintf(centroComercial, "Ingresos local : %i \n", local.ingresosLocal);
		fprintf(centroComercial, "Mes de creacion : %d \n", local.mesCreacion);
		fprintf(centroComercial, "\n" );
}

void guardarMatriz( local_t **matriz, int numPisos, int numLocalesxPiso) {
	char nombre[21] = {"centroComercial.txt"};
	FILE * centroComercial = fopen(nombre, "w");
	for (int i = 0; i < numPisos; i++) {
		for (int j = 0; j < numLocalesxPiso; j++) {
			guardarMatrizAuxiliar(matriz[i][j], centroComercial);
		}
	}
	imprimirPuntos();
	printf("\n");
	printf("Matriz correctamente guardada en centroComercial.txt\n");
	printf("Redirigiendo al menu \n");
	Sleep(1000);
	fclose(centroComercial);
}

int exportarArchivos(local_t **matriz ,int numPisos, int numLocalesxPiso){
	char nombre [25];
	printf("Ingrese el nombre que le quiere dar al archivo\n");
	fflush(stdin);
        fgets(nombre, 25, stdin );
        nombre[strcspn(nombre, "\n")] = 0;
    FILE * guardado;
    guardado=fopen(nombre,"wb");
    if (guardado == NULL){
    	return 0;
    }
    for (int i = 0; i < numPisos; ++i){
    	for (int j = 0; j < numLocalesxPiso; ++j)
    	{
    		fwrite(&matriz[i][j],sizeof(local_t),1,guardado);
    	}
    }
    fflush(guardado);
    fclose(guardado);
    imprimirPuntos();
	printf("\n");
	printf("Exportacion realizada con exito\n");
	printf("Redirigiendo al menu \n");
	Sleep(1000);
    return 1;
}

int importarArchivos(local_t **matriz ,int numPisos, int numLocalesxPiso){
	char nombre [25];
	printf("Ingrese el nombre del archivo que quiere leer\n");
	fflush(stdin);
        fgets(nombre, 25, stdin );
        nombre[strcspn(nombre, "\n")] = 0;
    FILE * guardado;
    guardado=fopen(nombre,"rb");
    if (guardado == NULL){
        return 0;
    }
    for (int i = 0; i < numPisos; ++i){
    	for (int j = 0; j < numLocalesxPiso; ++j)
    	{
    		fread(&matriz[i][j],sizeof(local_t),1,guardado);
    	}
    }
    
    imprimirPuntos();
	printf("\n");
	if (guardado != NULL){
		printf("Importacion realizada con exito\n");
	} else {
		printf("Importacion fallida \n");
	}
	printf("Redirigiendo al menu \n");
	Sleep(1000);
    fclose(guardado);
    return 1;
}

void merge(local_t Lista[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    local_t L[n1];
    local_t R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = Lista[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = Lista[m + 1+ j];
    i = 0;  
    j = 0;  
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i].ingresosLocal <= R[j].ingresosLocal) 
        { 
            Lista[k] = L[i]; 
            i++; 
        } 
        else
        { 
            Lista[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        Lista[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        Lista[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(local_t Lista[], int l, int r) { 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(Lista, l, m); 
        mergeSort(Lista, m+1, r); 
  
        merge(Lista, l, m, r); 
    } 
} 
  
void printLista(local_t Lista[], int size) { 
    int i; 
    for (i=0; i < size; i++) 
        printf(" Nombre: %s -- Ingresos: %d$ \n",Lista[i].nombreLocal,Lista[i].ingresosLocal);
    printf("\n"); 
} 
  
int ordenarMergerSort(local_t **centroComercial, int numPisos, int numLocalesxPiso){ 
    int numPisosUbi;
    int Lista_size = 0, contador = 0;
    
    printf("Digite el piso a organizar \n");
    scanf("%d",&numPisosUbi);
    for ( int i = 0; i < numLocalesxPiso; i++){
        if(strcmp(centroComercial[numPisosUbi - 1][i].estadoLocal, "Ocupado") == 0){
            Lista_size = Lista_size + 1;
        }
    }
    local_t Lista[Lista_size];
    for ( int i = 0; i < numLocalesxPiso; i++){
        if(strcmp(centroComercial[numPisosUbi - 1][i].estadoLocal, "Ocupado") == 0){
            Lista[contador]=centroComercial[numPisosUbi - 1][i];
            contador = contador + 1;
        }
    }
    mergeSort(Lista, 0, Lista_size - 1); 
    printLista(Lista, Lista_size);
} 

void insertFuntion( local_t centroComercial[], int Lista_size ) { 
    int i, j; 
    int temp;
    for ( i = 1; i < Lista_size; i++ ){ 
        temp = centroComercial[ i ].ingresosLocal; 
        j = i - 1; 
        while ( j >= 0 && centroComercial[ j ].ingresosLocal > temp ){ 
            centroComercial[ j + 1 ] = centroComercial[ j ]; 
            j = j - 1; 
        } 
        centroComercial[ j + 1 ].ingresosLocal = temp; 
    }
} 

void ordenarInserction(local_t **centroComercial, int numPisos, int numLocalesxPiso){
    int numPisosUbi ;
    int Lista_size = 0, contador = 0;
    
    printf("Digite el piso a organizar \n");
    scanf("%d",&numPisosUbi);
    numPisosUbi --;
    for ( int i = 0; i < numLocalesxPiso; i++){
        if(strcmp(centroComercial[numPisosUbi][i].estadoLocal, "Ocupado") == 0){
            Lista_size = Lista_size + 1;
        }
    }
    local_t Lista[Lista_size];
    for ( int i = 0; i < numLocalesxPiso; i++){
        if(strcmp(centroComercial[numPisosUbi][i].estadoLocal, "Ocupado") == 0){
            Lista[contador]=centroComercial[numPisosUbi][i];
            contador = contador + 1;
        }
    }
    insertFuntion( Lista,Lista_size );
    printf( "Estos son los nombres y los ingresos:\n" );

    for(int i = 0; i < Lista_size; i++ ){
        printf(" Nombre: %s -- Ingresos: %d$ \n",Lista[i].nombreLocal,Lista[i].ingresosLocal);
    }
    printf( "\n" );
}


void selectionSort( local_t Lista[],int numLocalesxPiso ){
    int min = 0;
    local_t temp;
    for(int i = 0;i <= numLocalesxPiso-1; i++){
        min = i;
        for (int  j = i + 1; j <= numLocalesxPiso-1; j++){
            if(Lista[j].ingresosLocal < Lista[min].ingresosLocal){
                min=j;
            }
        }
        temp = Lista[ i ];
        Lista[ i ] = Lista[ min ];
        Lista[min] = temp;
    }
}

void ordenarSelection( local_t ** centroComercial, int numPisos, int numLocalesxPiso ){
    int numPisosUbi;
    int Lista_size = 0, contador = 0;
    
    printf("Digite el piso a organizar \n");
    scanf("%d",&numPisosUbi);
    numPisosUbi --;
    for ( int i = 0; i < numLocalesxPiso; i++){
        if(strcmp(centroComercial[numPisosUbi][i].estadoLocal, "Ocupado") == 0){
            Lista_size = Lista_size + 1;
        }
    }
    printf("Lista_Size %d \n",Lista_size);
    local_t Lista[Lista_size];
    for ( int i = 0; i < numLocalesxPiso; i++){
        if(strcmp(centroComercial[numPisosUbi][i].estadoLocal, "Ocupado") == 0){
            Lista[contador]=centroComercial[numPisosUbi][i]; 
            contador = contador + 1;
        }
    }
    selectionSort( Lista,Lista_size  );
    printf( "Estos son los nombres y sus respectivos ingresos:\n" );
    for(int i = 0; i < Lista_size; i++ ){
        printf(" Nombre: %s -- Ingresos: %d$ \n",Lista[i].nombreLocal,Lista[i].ingresosLocal);
    }
    printf( "\n" );
}