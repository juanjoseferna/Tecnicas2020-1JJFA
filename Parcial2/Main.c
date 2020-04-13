#include "FuncionesCC.h"
#include <stdio.h>
#include "FuncionesCC.c"

int menu()
{

    int opc = 0;

    printf("Ingrese su opcion\n 1. Mostrar un local \n 2. Crear Local \n 3. Para imprimir todo el centro comercial \n 4. Para eliminar el local"
    "\n 5. Poner mantenimiento los locales de un piso(Esto elimina todos los locales) \n 6. Para quitar mantenimiento de un piso\n"
    " 7. Para cambiar el nombre de algun local \n 0. Para salir \n");
    scanf("%d", &opc);

    return opc;
}


int main(){
    int numPisos, numLocalesxPiso;
    printf("Digite el numero de pisos:\n");
    scanf("%d", &numPisos);
    printf("Digite el numero de locales por piso:\n");
    scanf("%d", &numLocalesxPiso);
    local_t ** centroComercial;
    centroComercial= crearMatrizDin(numPisos, numLocalesxPiso);
    int opc;
    for (int i = 0; i < numPisos; ++i){
    for (int j = 0; j < numLocalesxPiso; ++j){
        centroComercial[i][j]= crearLocal2(i,j);
    }}
    do
    {
        opc = menu();
        switch (opc)
        {
            case 1:{
                int numPiso,numLocalxPiso;
                printf("Ingrese el numero del piso\n");
                scanf("%i",&numPiso);
                printf("Ingrese el numero del local\n");
                scanf("%i",&numLocalxPiso);
                if (numPiso > numPisos || numLocalxPiso > numLocalesxPiso){
                    printf("Error_404\n");
                     ;
                }else{
                    mostrarLocal(centroComercial,numPiso-1,numLocalxPiso-1,numPisos, numLocalesxPiso);
                }
               
                break;
            }
            case 2:{
                int numPiso,numLocalxPiso;
                printf("Ingrese el numero del piso\n");
                scanf("%i",&numPiso);
                printf("Ingrese el numero del local\n");
                scanf("%i",&numLocalxPiso);
                char Disponible[] = {"Disponible"};
                if (numPiso > numPisos || numLocalxPiso > numLocalesxPiso){
                    printf("Error_404\n");
                     ;
                }else{
                    numPiso --;
                    numLocalxPiso--;
                    if (strcmp(centroComercial[numPiso][numLocalxPiso].estadoLocal,Disponible) == 0){
                    centroComercial[numPiso][numLocalxPiso]=crearLocal(numPiso,numLocalxPiso);
                    mostrarLocal(centroComercial,numPiso,numLocalxPiso,numPisos, numLocalesxPiso);
                    }
                }

                break;
            }
            case 3:
                ImprimirTodo(centroComercial,numPisos,numLocalesxPiso);
                break;
            
            case 4:{
                int numPiso,numLocalxPiso;
                printf("Ingrese el numero del piso\n");
                scanf("%i",&numPiso);
                printf("Ingrese el numero del local\n");
                scanf("%i",&numLocalxPiso);
                char Disponible[] = {"Disponible"};
                numPiso --;
                numLocalxPiso--;
                if (strcmp(centroComercial[numPiso][numLocalxPiso].estadoLocal,Disponible) == 0){
                    printf("Este local esta vacio\n");
                }else{
                centroComercial[numPiso][numLocalxPiso]= eliminarLocal(numPiso,numLocalxPiso);
                mostrarLocal(centroComercial,numPiso,numLocalxPiso,numPisos, numLocalesxPiso);
                printf("Piso eliminado\n");
                }
                break;
            }
            case 5:{
                int numPiso;
                printf("Ingrese el numero del piso\n");
                scanf("%i",&numPiso);
                char Mantenimiento[] = {"Mantenimiento"};
                numPiso--;
                if (strcmp(centroComercial[numPiso][0].estadoLocal,Mantenimiento) == 0){
                    printf("Este piso esta en mantenimiento\n");
                }else{ 
                    for (int i = 0; i < numLocalesxPiso; ++i){
                      centroComercial [numPiso][i]=mantenerLocal2(numPiso,i);
                    }
                }
                break;
            }
            case 6:{
                int numPiso;
                printf("Ingrese el numero del piso\n");
                scanf("%i",&numPiso);
                char Mantenimiento[] = {"Mantenimiento"};
                numPiso--;
                if (strcmp(centroComercial[numPiso][0].estadoLocal,Mantenimiento) != 0){
                    printf("Este piso no esta en mantenimiento\n");
                }else{ 
                    for (int i = 0; i < numLocalesxPiso; ++i){
                      centroComercial [numPiso][i]=eliminarLocal(numPiso,i);
                      printf("El piso ya no esta en mantenimiento\n");
                    }
                }
                break;
            }
            case 7:{
                int numPiso,numLocalxPiso;
                printf("Ingrese el numero del piso donde se encuentre el local\n");
                scanf("%i",&numPiso);
                printf("Ingrese el numero del local que desea cambiar\n");
                scanf("%i",&numLocalxPiso);
                char Disponible[] = {"Disponible"};
                if (numPiso > numPisos || numLocalxPiso > numLocalesxPiso){
                    printf("Error_404\n");
                     ;
                }else{
                    numPiso --;
                    numLocalxPiso--;
                    if (strcmp(centroComercial[numPiso][numLocalxPiso].estadoLocal,Disponible) != 0){
                    centroComercial[numPiso][numLocalxPiso]=crearLocal(numPiso,numLocalxPiso);
                    mostrarLocal(centroComercial,numPiso,numLocalxPiso,numPisos, numLocalesxPiso);
                    }else{
                        printf("El piso esta desocupado\n");
                    }
                }

            }
        }
    } while (opc != 0);
	
	return 0;
}