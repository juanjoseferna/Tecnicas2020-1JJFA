#include "FuncionesCC.h"
#include <stdio.h>
#include "FuncionesCC.c"

int menu()
{

    int opc = 0;

    printf("Ingrese su opcion\n 1. Mostrar un local \n 2. Crear Local \n 3. Para imprimir todo el centro comercial \n 4. Para eliminar el local"
    "\n 5. Poner mantenimiento los locales de un piso(Esto elimina todos los locales) \n 6. Para quitar mantenimiento de un piso\n"
    " 7. Para cambiar el nombre de algun local \n 8. Para guardar el centro comercial en un archivo de texto \n"
    " 9. Para importar o exportar archivos \n 10. Opciones de ordenamientos \n 0. Para salir \n");
    scanf("%d", &opc);

    return opc;
}

int dimensionarPisos (int numPisos){
    printf("Digite el numero de pisos:\n");
    scanf("%d", &numPisos);
    if (numPisos <= 0){
        printf("Numero invalido\n");
        return dimensionarPisos(numPisos);
    }
    else {
        return numPisos;
    }
}

int dimensionarLocales(int numLocalesxPiso){
    printf("Digite el numero de locales por piso:\n");
    scanf("%d", &numLocalesxPiso);
    if (numLocalesxPiso <= 0){
        printf("Numero invalido\n");
        return dimensionarLocales(numLocalesxPiso);
    }
    else {
        return numLocalesxPiso;
    }
}

void historiaCentroComercial (){
    printf("Bienvenido al nuevo centro comercial Heids que ha sido creado por Wayne Enterprises a este anio del 2031,\nusted sera el encargado de llevar todo lo que tenga que ver con el sistema de locales,"
        " cuya administracion \ndebera ser minuciosamente llevada a cabo por usted, el sistema presenta algunas fallas pero nada de lo que\nse debera"
        " preocupar \n");
    Sleep(3000);
}


int main(){
    historiaCentroComercial();
    int numPisos=0;
    int numLocalesxPiso=0;
    numPisos = dimensionarPisos(numPisos);
    numLocalesxPiso = dimensionarLocales(numLocalesxPiso);
    local_t ** centroComercial;
    centroComercial= crearMatrizDin(numPisos, numLocalesxPiso);
    int opc;
    
    for (int i = 0; i < numPisos; ++i){
        for (int j = 0; j < numLocalesxPiso; ++j){
            centroComercial[i][j]= crearLocal2(i,j);
        }
    }
    do
    {
        opc = menu();
        switch (opc)
        {
            case 1:{
                int salida = 0;
                do{
                    int numPiso,numLocalxPiso; 
                    printf("Ingrese el numero del piso\n");
                    scanf("%i",&numPiso);
                    printf("Ingrese el numero del local\n");
                    scanf("%i",&numLocalxPiso);
                    if (numPiso > numPisos || numLocalxPiso > numLocalesxPiso || numPiso <=0 || numLocalxPiso <= 0){
                        printf("Error_404\n");
                        printf("Si quiere volver al menu ingrese 1 y si quiere volver a intentarlo ingrese 0\n");
                        scanf("%i",&salida);
                    }else{
                        mostrarLocal(centroComercial,numPiso-1,numLocalxPiso-1,numPisos, numLocalesxPiso);
                        salida = 1;
                    }
                } while (salida != 1);
                break;
            }
            case 2:{
                int salida = 0;
                    do{
                    int numPiso,numLocalxPiso;
                    printf("Ingrese el numero del piso\n");
                    scanf("%i",&numPiso);
                    printf("Ingrese el numero del local\n");
                    scanf("%i",&numLocalxPiso);
                    char Disponible[] = {"Disponible"};
                    if (numPiso > numPisos || numLocalxPiso > numLocalesxPiso|| numPiso <=0 || numLocalxPiso <= 0){
                        printf("Error_404\n");
                        printf("Si quiere volver al menu ingrese 1 y si quiere volver a intentarlo ingrese 0\n");
                        scanf("%i",&salida);
                    }else{
                        numPiso --;
                        numLocalxPiso--;
                        if (strcmp(centroComercial[numPiso][numLocalxPiso].estadoLocal,Disponible) == 0){
                        centroComercial[numPiso][numLocalxPiso]=crearLocal(numPiso,numLocalxPiso);
                        mostrarLocal(centroComercial,numPiso,numLocalxPiso,numPisos, numLocalesxPiso);
                        salida = 1;
                        }
                    }
                } while(salida != 1);
                break;
            }
            case 3:
                imprimirTodo(centroComercial,numPisos,numLocalesxPiso);
                break;
            
            case 4:{
                int salida = 0;
                do{
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
                        printf("Si quiere volver al menu ingrese 1 y si quiere volver a intentarlo ingrese 0\n");
                        scanf("%i",&salida);
                    }else{
                    centroComercial[numPiso][numLocalxPiso]= eliminarLocal(numPiso,numLocalxPiso);
                    mostrarLocal(centroComercial,numPiso,numLocalxPiso,numPisos, numLocalesxPiso);
                    printf("Piso eliminado\n");

                    }
                } while (salida != 1);
                break;
            }
            case 5:{
                int salida = 0;
                do{
                    int numPiso;
                    printf("Ingrese el numero del piso\n");
                    scanf("%i",&numPiso);
                    char Mantenimiento[] = {"Mantenimiento"};
                    numPiso--;
                    if (strcmp(centroComercial[numPiso][0].estadoLocal,Mantenimiento) == 0){
                        printf("Este piso esta en mantenimiento\n");
                        printf("Si quiere volver al menu ingrese 1 y si quiere volver a intentarlo ingrese 0\n");
                        scanf("%i",&salida);
                    }else{ 
                        for (int i = 0; i < numLocalesxPiso; ++i){
                          centroComercial [numPiso][i]=mantenerLocal2(numPiso,i); 
                        }
                        salida = 1;
                    }
                } while (salida != 1);
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
                int salida = 0;
                do{
                    int numPiso,numLocalxPiso;
                    printf("Ingrese el numero del piso donde se encuentre el local\n");
                    scanf("%i",&numPiso);
                    printf("Ingrese el numero del local que desea cambiar\n");
                    scanf("%i",&numLocalxPiso);
                    char Disponible[] = {"Disponible"};
                    if (numPiso > numPisos || numLocalxPiso > numLocalesxPiso){
                        printf("Error_404\n");
                        printf("Si quiere volver al menu ingrese 1 y si quiere volver a intentarlo ingrese 0\n");
                        scanf("%i",&salida);
                    }else{
                        numPiso --;
                        numLocalxPiso--;
                        if (strcmp(centroComercial[numPiso][numLocalxPiso].estadoLocal,Disponible) != 0){
                        centroComercial[numPiso][numLocalxPiso]=crearLocal(numPiso,numLocalxPiso);
                        mostrarLocal(centroComercial,numPiso,numLocalxPiso,numPisos, numLocalesxPiso);
                        salida = 1;
                        }else{
                            printf("El piso esta desocupado\n");
                        }
                    }
                } while (salida != 1);
                break;
            }
            case 8:{
                int salida = 0;
                printf("Esta seguro de realizar esta accion, demorara 21 segundos y"
                    " borrara el centroComercial.txt que tenia anteriormente\n"
                    " 1. Si \n 2. No \n");
                scanf("%i", &salida);
                if (salida ==1){
                    guardarMatriz(centroComercial,numPisos,numLocalesxPiso);
                    }
                break;
                }
            case 9:{
                int salida = 0;
                printf(" 1. Exportar\n 2. Importar(OJO: se eliminara el centro comercial anteriormente creado y si no son las mismas dimensiones"
                    " se borraran los demas pisos) \n 0. Para salir \n");
                scanf("%i", &salida);
                if (salida ==1){
                    exportarArchivos(centroComercial,numPisos,numLocalesxPiso);
                    }
                else if (salida == 2){
                    importarArchivos(centroComercial,numPisos,numLocalesxPiso);
                    }
                break;
                }
            case 10:{
                int salida = 0;
                printf(" 1. Mergersort \n 2. Insertion \n 3. Selection \n 0. Salir\n");
                scanf("%i", &salida);
                if (salida ==1){
                    ordenarMergerSort(centroComercial, numPisos, numLocalesxPiso);
                    imprimirPuntos();
                    printf("\n");
                    }
                else if (salida == 2){
                    ordenarInserction(centroComercial, numPisos, numLocalesxPiso);
                    imprimirPuntos();
                    printf("\n");
                    }
                else if (salida == 3){
                    ordenarSelection(centroComercial, numPisos, numLocalesxPiso);
                    imprimirPuntos();
                    printf("\n");
                }
                break;
            }
        }
    } while (opc != 0);
	
    return 0;
}