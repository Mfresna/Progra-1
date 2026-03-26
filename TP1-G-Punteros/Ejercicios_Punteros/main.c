#include <stdio.h>
#include <stdlib.h>

//PROTOTIPOS
void menuOpciones(int *opcion);
void cambiarSigno(int *num);
void cargar(int *a, int *b);
void validarEdad(int *edad);
void dividir(int dividendo, int divisor, int *cociente, int *resto);
void convertirTiempo(int segundos, int *minutos, int *horas);
void datos16 (int *x, float *y, char *c);

//MAIN
int main()
{
    int opcion;

    do {
        menuOpciones(&opcion);

        //Variables
        int numero = 0;

        int a;
        int b;

        int edad;

        int dividendo;
        int divisor;
        int cociente;
        int resto;

        int segundos = 0;
        int minutos;
        int horas;

        int x=9;
float y=44.6;
char c='a';

        switch(opcion) {
            case 1:
                printf("Ingrese un valor numerico:");
                scanf("%d",&numero);

                cambiarSigno(&numero);

                printf("Ahora el numero es: %d", numero);

                printf("\n\n");
                system("pause");
                break;
            case 2:

                cargar(&a,&b);

                printf("El usuario cargo:");
                printf("\n\t valor A: %d", a);
                printf("\n\t valor B: %d", b);

                printf("\n\n");
                system("pause");
                break;
            case 3:

                validarEdad(&edad);

                printf("\nLa edad final del usuario es: %d", edad);

                printf("\n\n");
                system("pause");
                break;

            case 4:

                printf("\nDividir:");
                scanf("%d",&dividendo);

                do{
                    printf("Entre:");
                    scanf("%d",&divisor);

                    if(divisor == 0){
                        printf("No se puede dividir por cero!");
                    }

                }while(divisor == 0);


                dividir(dividendo, divisor, &cociente, &resto);

                printf("\nEl resultado es: %d y su resto es: %d",cociente, resto);

                printf("\n\n");
                system("pause");
                break;
            case 5:

                printf("\nSegundos a convertir:");
                scanf("%d",&segundos);

                convertirTiempo(segundos, &minutos ,&horas);

                printf("\nSon %d horas o %d minutos",horas, minutos);

                printf("\n\n");
                system("pause");
                break;
            case 6:
                datos16(&x,&y,&c);

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
void menuOpciones(int *opcion){

    system("cls");

    printf("========== MENU ==========\n");
    printf("1 - Cambiar signo usando referencia\n");
    printf("2 - Cargar dos números por referencia\n");
    printf("3 - Validar edad con puntero\n");
    printf("4 - Dividir con resultado y resto (dos return)\n");
    printf("5 - Segundos a Horas y Minutos\n");

    printf("\n0 - Salir\n");

    printf("\nIngrese un numero: ");
    scanf("%d", opcion);

    system("cls");

}

    //Ejercicio 1
void cambiarSigno(int *num) {
    *num = -(*num);
}

    //Ejercicio 2
void cargar(int *a, int *b) {
    printf("Ingrese el primer numero: ");
    scanf("%d",     a);

    printf("Ingrese el segundo numero: ");
    scanf("%d", b);
}

    //Ejercicio 3
void validarEdad(int *edad) {
    do {
        printf("Ingrese edad (1 a 18): ");
        scanf("%d", edad);

        if (*edad <= 0 || *edad > 18) {
            printf("Edad incorrecta. Debe ser mayor a 0 y menor o igual a 18.\n");
        }

    } while (*edad <= 0 || *edad > 18);
}

    //Ejercicio 4
void dividir(int dividendo, int divisor, int *cociente, int *resto) {
    if(divisor != 0){
        *cociente = dividendo / divisor;
        *resto = dividendo % divisor;
    }else{
        *cociente = 0;
        *resto = 0;
    }

}

    //Ejercicio 5
void convertirTiempo(int segundos, int *minutos, int *horas) {
    *minutos = segundos / 60;
    *horas = segundos / 3600;
}



void datos16 (int *x, float *y, char *c)
{
printf("%p - %p - %p \n", x, y, c);
printf("%d - %f - %c", x, y, c);
*x=8;
*y=4.2;
*c='g';
}


