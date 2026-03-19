#include <stdio.h>
#include <stdlib.h>

//PROTOTIPOS
int menuOpciones();

//MAIN
int main()
{
    int opcion;

    do {
        opcion = menuOpciones();

        switch(opcion) {
            case 1:
                //desarrollo del ejercicio 1
                printf("Ejecucion Ej 1\n");

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
    printf("1 - Ejercicio 1\n");
    printf("2 - Ejercicio 2\n");
    printf("3 - Ejercicio 3\n");

    printf("\n0 - Salir\n");

    printf("\nIngrese un numero: ");
    scanf("%d", &op);

    system("cls");

    return op;

}
