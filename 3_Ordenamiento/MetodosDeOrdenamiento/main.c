#include <stdio.h>
#include <stdlib.h>

//PROTOTIPOS
int menuOpciones();
void cargarArregloRandom(int arreglo[], int validos);
void mostrarArreglo(int arreglo[], int validos);

//MAIN
int main()
{
    int opcion;

    srand(time(NULL)); //Para que funcione el Random

    do {
        opcion = menuOpciones();

        //Variables
        int miArregloRandom[DIM];

        switch(opcion) {
            case 1:
                printf("Ordenamiento por Seleccion O(n)\n");
                cargarArregloRandom(miArregloRandom, DIM);  //Lo cargo completo

                mostrarArreglo(miArregloRandom,DIM);

                printf("\n\n");
                system("pause");
                break;
            case 2:
                //desarrollo del ejercicio 2
                printf("Ejecucion Ej 2\n");

                printf("\n\n");
                system("pause");
                break;
            case 0:
                printf("Usted ha salido del programa...\n");
                break;
            default:
                printf("Opcion invalida\n");

                printf("\n\n");
                system("pause");
        }
    }while(opcion != 0);

    return 0;
}

//FUNCIONES
int menuOpciones(){

    int op;

    system("cls");

    printf("========== MENU ==========\n");
    printf("1 - Ordenamiento por Seleccion\n");
    printf("2 - Ejercicio 2\n");
    printf("3 - Ejercicio 3\n");

    printf("\n0 - Salir\n");

    printf("\nIngrese un numero: ");
    scanf("%d", &op);

    system("cls");

    return op;
}

void cargarArregloRandom(int arreglo[], int validos){
    for(int i = 0; i < validos && i < DIM; i++){
        arreglo[i] = rand() % 100; // números entre 0 y 99
    }
}

void mostrarArreglo(int arreglo[], int validos){
    printf("----- ARREGLO -----\n\n");

    for(int i = 0; i < validos; i++){
        printf("%d | ", arreglo[i]);
    }

    printf("\n\n");
}

