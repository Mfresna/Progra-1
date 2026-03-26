#include <stdio.h>
#include <stdlib.h>

//LIBRERIAS PROPIAS
#include "pila.h"

//PROTOTIPOS
int menuOpciones();

//MAIN
int main()
{
    int opcion;

    do {
        opcion = menuOpciones();

        //Variables de Ejercicios
            Pila ejercicio1;
            inicpila(&ejercicio1);
            char mostrarPila;

        switch(opcion) {
            case 1:
                ingresarDato(&ejercicio1); //Le paso la direccion de mem de la pila

                system("cls");
                printf("Desea ver la pila, presione S para si... ");

                fflush(stdin);
                scanf("%c", &mostrarPila);

                if (mostrarPila == 's' || mostrarPila == 'S'){
                    mostrar(&ejercicio1);
                }

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
    printf("1 - Cargar Pila 1\n");
    printf("2 - Ejercicio 2\n");
    printf("3 - Ejercicio 3\n");

    printf("\n0 - Salir\n");

    printf("\nIngrese un numero: ");
    scanf("%d", &op);

    system("cls");

    return op;

}

    //Ejercicio 1
void ingresarDato (Pila *puntP1){

    char desicion;

    do{
        leer(puntP1);

        printf("Si desea finalizar presione F ... ");
        fflush(stdin);
        scanf("%c",&desicion);

    }while(desicion != 'f' && desicion != 'F');
}
