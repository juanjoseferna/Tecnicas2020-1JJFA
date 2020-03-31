#include "28M.c"


int menu(people_t matriz[],int cont, people_t matrizanual[]){
	int opc;
	printf("Ingrese un numero segun la opcion que desee \n 1. Agregar persona de la red\n" 
		" 2. Buscar segun el mes de nacimiento \n 3. Reemplazar persona de la red segun el nombre \n 4. Imprimir todo\n 0. Salir \n");	
	scanf("%i", &opc);
	if (opc == 1){
		matriz[cont] = llenarPersonas();
		int mes = matriz[cont].mesnac - 1;
		matrizanual[mes]=matriz[cont];
		cont ++;
		menu(matriz, cont, matrizanual);
	}
	else if (opc ==2){
		BuscarPersonaMes(matriz, cont);
		menu(matriz, cont, matrizanual);

	}
	else if (opc ==3){
		char nombre[50];
			printf("ingrese el nombre que desea buscar (max 50 caracteres)\n");
			fflush(stdin);
	        fgets(nombre, 50, stdin );
  	        nombre[strcspn(nombre, "\n")] = 0;
		int i = BuscarIndice(matriz, cont, nombre);
		matriz[i] = BuscarPersonaNombre(matriz, cont, nombre); 
		int mes = matriz[i].mesnac - 1;
		matrizanual[mes]=matriz[i];
		menu(matriz, cont, matrizanual);

	}
	else if (opc == 4){
		ImprimirTodo(matriz,cont);
		menu(matriz, cont, matrizanual);
	}
	else if (opc == 0){
		printf("Hasta la proxima\n");
		return 0;	
	}
}

int main(){
	people_t matriz[59];
	int cont = 0;
	people_t matrizanual [11];
	int * pCont = &cont;
	menu(matriz, *pCont, matrizanual);
	return 0;
}
