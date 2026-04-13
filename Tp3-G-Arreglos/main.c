#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

#define DIM 5
#define DIGRANDOM 10  //largo de digitos Random


///Prototipado
int listadoEjercicios();

    //ejercico1
void cargarArreglo(int arreglo[], int *validos);
    //ejercicio2
void mostrarArreglo(int arreglo[], int *validos);
    //ejercicio3
void cargarArregloRandom(int arreglo[],int *validos,int cantDatos);
int sumarArreglo(int arreglo[],int *validos);
    //ejercicio4
void pasarAPila(int arreglo[],int *validos, Pila *pilaEj4);
    //ejercicio5
void cargarArregloRandomFlotante(float arreglo[],int *validos,int cantDatos);
void mostrarArregloFlotante(float arreglo[], int *validos);
float sumarArregloFlotante(float arreglo[],int *validos);
    //ejercicio6
void cargarArregloCharRandom(char arreglo[],int *validos, int cantDatos);
void mostrarArregloChar(char arreglo[], int *validos);
int buscarEnArreglo(char arreglo[], int *validos, char *letraEj6);
    //ejercicio7
void cargarArregloCharRandomUpper(char arreglo[],int *validos, int cantDatos);
void ordenamientoPorInsercionChar(char arreglo[],int validos);
void insertarCharOrdenado(char arreglo[],int *validos, char *caracter);
    //ejercicio8
char ultimaLetraDeArray(char arreglo[],int *validos);
    //ejercicio9
int esCapicua(char arreglo[]);
    //ejercicio10
void invertirArray(int arreglo[], int validos);
    //ejercicio11
void ordenamientoPorSeleccion(int arreglo[], int *validos);
void ordenamientoPorInsercion(int arreglo[], int *validos);
    //ejercicio12
void intercalarArrays(char arregloA[], char arregloB[], char arregloC[], int validosA, int validosB, int *validosC);
    //ejercicio13
void sumaAnteriorArray (int arreglo[], int validos, int arregloSum[], int *validosSum);
void mostrarArrayLineal(int arreglo[], int validos);

///Codigo Main
int main(){

    int numEjercicio;

    do{
        numEjercicio = listadoEjercicios();

    //VARIABLES EJERCICIOS
        //Ejercicio1
        int miArregloEj1 [DIM] = {0};
        int validosEj1 = 0;

        //Ejercicio2
        int miArregloEj2 [DIM] = {0};
        int validosEj2 = 0;

        //Ejercicio3
        int miArregloEj3 [DIM] = {0};
        int validosEj3 = 0;

        //Ejercicio4
        int miArregloEj4 [DIM] = {0};
        int validosEj4 = 0;
        Pila pilaEj4;
        inicpila(&pilaEj4);

        //Ejercicio5
        float miArregloEj5 [100] = {0};
        int validosEj5 = 0;

        //Ejercicio6
        char miArregloEj6 [DIM];
        int validosEj6 = 0;
        char letraEj6;
        int resultadoEj6;

        //Ejercicio7
        char miArregloEj7 [DIM];
        int validosEj7 = 0;
        char letraEj7;

        //Ejercicio8
        char miArregloEj8 [DIM];
        int validosEj8 = 0;

        //Ejercicio9
        char miArregloEj9[DIM*10];

        //Ejercicio10
        int miArregloEj10 [DIM];
        int validosEj10 = 0;

        //Ejercicio11
        int miArregloEj11[DIM];
        int validosEj11 = 0;
        char opcionEj11;
        int errorEj11 = 0;

        //Ejercicio12
        char miArregloEj12A [DIM];
        int validosEj12A = 0;
        char miArregloEj12B [DIM];
        int validosEj12B = 0;
        char miArregloEj12C [DIM*2];
        int validosEj12C = 0;

        //Ejercicio13
        int miArregloEj13 [DIM];
        int validosEj13 = 0;
        int miArregloEj13Sum [DIM];
        int validosEj13Sum = 0;



    switch(numEjercicio){
        case 1:
            //EJERCICIO 1

            cargarArreglo(miArregloEj1, &validosEj1);

            system ("pause");
            break;

        case 2:
            //EJERCICIO 2

            cargarArreglo(miArregloEj2, &validosEj2); //Usa la funcion del Ej1
            mostrarArreglo(miArregloEj2, &validosEj2);

            system ("pause");
            break;

        case 3:
            //EJERCICIO 3
            cargarArregloRandom(miArregloEj3, &validosEj3,DIM);
            mostrarArreglo(miArregloEj3, &validosEj3);      //Funcion del Ejercicio2

            printf("La suma del Array es: %i \n\n", sumarArreglo(miArregloEj3, &validosEj3));

            system ("pause");
            break;

        case 4:
            //EJERCICIO 4
            cargarArregloRandom(miArregloEj4,&validosEj4,DIM);
            mostrarArreglo(miArregloEj4, &validosEj4);

            pasarAPila(miArregloEj4,&validosEj4,&pilaEj4);
            mostrar(&pilaEj4);

            system ("pause");
            break;

        case 5:
            //EJERCICIO 5
            cargarArregloRandomFlotante(miArregloEj5,&validosEj5,100);
            mostrarArregloFlotante(miArregloEj5,&validosEj5);

            printf("La suma del Array es: %.2f \n\n",sumarArregloFlotante(miArregloEj5,&validosEj5));

            system ("pause");
            break;

        case 6:
            // EJERCICIO 6
            cargarArregloCharRandom(miArregloEj6,&validosEj6,DIM);
            printf("Ingrese el caracter que desea comprobar: ");
            fflush(stdin);
            scanf("%c", &letraEj6);
            system("cls");

            resultadoEj6 = buscarEnArreglo(miArregloEj6,&validosEj6,&letraEj6);

            if(resultadoEj6 != 0)
                printf("El caracter \"%c\" SI se encuentra, en la posicion %i del Arreglo.\n\n",letraEj6,resultadoEj6);
            else
                printf("El caracter \"%c\" NO se encuentra en el Arreglo.\n\n",letraEj6);

            mostrarArregloChar(miArregloEj6,&validosEj6);

            system ("pause");
            break;

        case 7:
            //EJERCICIO 7

            cargarArregloCharRandomUpper(miArregloEj7,&validosEj7,DIM-1); //Dejo un espacio libre para ingresar dato

            ordenamientoPorInsercionChar(miArregloEj7,validosEj7);
            mostrarArregloChar(miArregloEj7,&validosEj7);

            printf("Indique el caracter que desea ingresar en el Array: ");
            fflush(stdin);
            scanf("%c",&letraEj7);
            printf("\n");
            insertarCharOrdenado(miArregloEj7,&validosEj7,&letraEj7);

            mostrarArregloChar(miArregloEj7,&validosEj7);

            system ("pause");
            break;

        case 8:
            //EJERCICIO 8
            cargarArregloCharRandom(miArregloEj8,&validosEj8,DIM);
            mostrarArregloChar(miArregloEj8,&validosEj8);

            printf("\nLa ultima letra del Array es: %c \n\n",ultimaLetraDeArray(miArregloEj8,&validosEj8));
            system ("pause");
            break;

        case 9:
            //EJERCICIO 9
            printf("Escriba una frase: ");
            fflush(stdin);
            gets(miArregloEj9); //Lo guarda en el arreglo

            if (esCapicua(miArregloEj9) == 1){
                printf("\nLa frase %s, es capicua.\n\n",miArregloEj9);
            }else{
                printf("\nLa frase %s, no es capicua.\n\n",miArregloEj9);
            }

            system ("pause");
            break;

        case 10:
            //EJERCICIO 10
            cargarArregloRandom(miArregloEj10,&validosEj10,DIM);
            mostrarArreglo(miArregloEj10,&validosEj10);

            invertirArray(miArregloEj10,validosEj10);

            mostrarArreglo(miArregloEj10,&validosEj10);


            system ("pause");
            break;

        case 11:
            //EJERCICIO 11
            cargarArregloRandom(miArregloEj11,&validosEj11,DIM);
            printf("\t---- ARREGLO DESORDENADO ----\n\n");
            mostrarArrayLineal(miArregloEj11,validosEj11);

            do{
                printf("\n\nDesea ordenarlo por Seleccion o Insercion? (s/i): ");
                fflush(stdin);
                scanf(" %c",&opcionEj11);
                printf("\n\n");

                errorEj11 = 0; //Si pone mal la opcion cambia a 1

                if(opcionEj11 == 's' || opcionEj11 == 'S'){
                    ordenamientoPorSeleccion(miArregloEj11,&validosEj11);

                }else if(opcionEj11 == 'i' || opcionEj11 == 'I'){
                    ordenamientoPorInsercion(miArregloEj11,&validosEj11);

                }else{
                    printf("Ingrese una opcion valida");
                    errorEj11 = 1;
                }

            }while(errorEj11 == 1);

            printf("\t---- ARREGLO ORDENADO ----\n\n");
            mostrarArrayLineal(miArregloEj11,validosEj11);

            system ("pause");
            break;

        case 12:
            //EJERCICIO 12
            cargarArregloCharRandomUpper(miArregloEj12A,&validosEj12A,DIM);
            ordenamientoPorInsercionChar(miArregloEj12A,validosEj12A);
            mostrarArregloChar(miArregloEj12A,&validosEj12A);

            cargarArregloCharRandomUpper(miArregloEj12B,&validosEj12B,DIM);
            ordenamientoPorInsercionChar(miArregloEj12B,validosEj12B);
            mostrarArregloChar(miArregloEj12B,&validosEj12B);

            intercalarArrays(miArregloEj12A,miArregloEj12B,miArregloEj12C,validosEj12A,validosEj12B,&validosEj12C);
            mostrarArregloChar(miArregloEj12C,&validosEj12C);

            system ("pause");
            break;

        case 13:
            //EJERCICIO 13
            cargarArregloRandom(miArregloEj13,&validosEj13,DIM);


            sumaAnteriorArray(miArregloEj13,validosEj13,miArregloEj13Sum,&validosEj13Sum);

            printf("\t\t---- ARREGLO RANDOM ----\n\n");
            mostrarArrayLineal(miArregloEj13,validosEj13);

            printf("\t---- SUMATORIA DE LAS POSICIONES ANTERIOR----\n\n");
            mostrarArrayLineal(miArregloEj13Sum,validosEj13Sum);

            system ("pause");
            break;

        case 0:
            printf("\nPROGRAMA TERMINADO\n");
            break;

        default:
            printf("\nINGRESE UN EJERCICIO VALIDO\n");
            system ("pause");
            break;
        }
    }while(numEjercicio!=0);
}

///Funciones

int listadoEjercicios(){

    int input;

    system("cls");
    printf("EJERCICIOS DEL TP 3 - ARREGLOS");
    printf("\n----------------------------------------\n");
    printf("\n1-Ingrese valores a un Array");
    printf("\n2-Ingresar valores a un Array y mostrarlos");
    printf("\n3-Sume los valores de un Array random");
    printf("\n4-Pasar Array a una Pila");
    printf("\n5-Sumar un Array de 100 elementos 'float'");
    printf("\n6-Comprobar si se encuentra en el Array de caracteres");
    printf("\n7-Ordena un array e inserta un Caracter en orden");
    printf("\n8-Obtiene el mayor/ultimo elemento de un Array");
    printf("\n9-Su frase es capicua?");
    printf("\n10-Invertir un arreglo");
    printf("\n11-Ordenamiento por Seleccion o Insercion");
    printf("\n12-Intercalar 2 Arrays ordenados alfabeticamente");
    printf("\n13-Sumar los valores anteriores de un Array");

    printf("\n0-EXIT");
    printf("\n\nINGRESE EL EJERCICIO A EJECUTAR: ");
    scanf("%i",&input);
    system("cls");

    return input;

}

//FUNCIONES EJERCICIO 1
void cargarArreglo(int arreglo[], int *validos){
    char seguir;

    do{
        printf("Ingrese un dato al arreglo: ");
        scanf("%i", &arreglo[*validos]);

        (*validos)++;

        if ((*validos) >= DIM){
            printf("\nEste fue el ultimo dato almacenado, se llego al limite del Array.\n\n");
        }else {
            printf("\nDesea continuar? (s/n): ");
            fflush(stdin);
            scanf("%c", &seguir);
        }
    }while((*validos) < DIM && seguir == 's');

    system("cls");
}

//FUNCIONES EJERCICIO 2
void mostrarArreglo(int arreglo[], int *validos){
    printf("\t----- ARREGLO -----\n\n");

    for(int i=0; i< *validos ; i++){
        printf("El valor de la posicion %i es: %i\n", i+1, arreglo[i]);
    }

    printf("\n\n");
}

//FUNCIONES EJERCICIO 3
void cargarArregloRandom(int arreglo[],int *validos,int cantDatos){
    srand(time(NULL));

    for(int i=0; i<cantDatos; i++){
        arreglo[i] = rand()%DIGRANDOM;
        (*validos)++;
    }
}

int sumarArreglo(int arreglo[],int *validos){
    int suma = 0;

    for(int i=0; i<(*validos); i++){
        suma += arreglo[i];
    }
    return suma;
}

//FUNCIONES EJERCICIO 4
void pasarAPila(int arreglo[],int *validos, Pila *pilaEj4){

    for (int i=0; i<(*validos); i++){
        apilar(pilaEj4,arreglo[i]);
    }
}

//FUNCIONES EJERCICIO 5
void cargarArregloRandomFlotante(float arreglo[],int *validos,int cantDatos){
    srand(time(NULL));

    for(int i=0; i<cantDatos; i++){
        arreglo[i] = (float)(rand()%10000) / 100; //entero hasta 10.000 y lo convierte en 100,00 (float)
        (*validos)++;
    }
}

void mostrarArregloFlotante(float arreglo[], int *validos){
    printf("\t----- ARREGLO -----\n\n");

    for(int i=0; i< *validos ; i++){
        printf("El valor de la posicion %i es: %.2f\n", i+1, arreglo[i]);
    }

    printf("\n\n");
}

float sumarArregloFlotante(float arreglo[],int *validos){
    float suma = 0;

    for(int i=0; i<(*validos); i++){
        suma += arreglo[i];
    }
    return suma;
}

//FUNCIONES EJERCICIO 6
void cargarArregloCharRandom(char arreglo[],int *validos, int cantDatos){
    srand(time(NULL));

    cantDatos += *validos; //Me desplazo las posiciones de Validos para seguir cargando

    for(int i=(*validos); i<cantDatos && i<DIM ; i++){
        int letraAscii = (rand()%58) + 65;

        if(letraAscii>90 && letraAscii<97){
            //No carga nada al array
            i--;
        }else{
            arreglo[i] = letraAscii;
            (*validos)++;
        }
    }
}

void mostrarArregloChar(char arreglo[], int *validos){
    printf("\t----- ARREGLO DE CARACTERES -----\n\n");

    for(int i=0; i< *validos ; i++){
        printf("El caracter de la posicion %i es: %c\n", i+1, arreglo[i]);
    }

    printf("\n");
}

int buscarEnArreglo(char arreglo[], int *validos, char *letraEj6){
    int resultado = 0;

    for(int i=0; i< *validos ; i++){
        if(arreglo[i] == (*letraEj6)){
            resultado = i+1;
        }
    }

    return resultado;
}

//FUNCIONES EJERCICIO 7
void cargarArregloCharRandomUpper(char arreglo[],int *validos, int cantDatos){
    srand(time(NULL));

    cantDatos += *validos; //Me desplazo las posiciones de Validos para seguir cargando

    for(int i=0; i<cantDatos && i<DIM; i++) {
        arreglo[i] = (rand() % 26) + 65;
        (*validos)++;
    }

}

void ordenamientoPorInsercionChar(char arreglo[],int validos){

    char index;
    int j;

    for(int i=1; i < validos; i++){

        index = arreglo[i];
        j=i-1;

        while(j>=0 && arreglo[j] > index){
            arreglo[j+1] = arreglo[j];
            j--;
        }

        arreglo[j+1] = index;
    }
}

void insertarCharOrdenado(char arreglo[],int *validos, char *caracter){

    int i=(*validos)-1;

    while(i>=0 && *caracter < arreglo[i]){
        arreglo[i+1]=arreglo[i];
        i--;
    }

    arreglo[i+1] = *caracter;

    (*validos) += 1;
}

//FUNCIONES EJERCICIO 8
char ultimaLetraDeArray(char arreglo[],int *validos){
    char letra = 0;
    int control;

    for(int i=0; i<(*validos); i++){

        if(letra < arreglo[i]){
            //Si es mayuscula la paso a minuscula
            if(arreglo[i]<=90){
                letra = arreglo[i]+32; //almaceno letra en minuscula
                control = 1;
            }else{
                letra = arreglo[i]; //ya esta en minuscula
                control = 0;
            }
        }
    }

    if(control==1){
        letra -= 32;
    }

    return letra;
}

//FUNCIONES EJERCICIO 9
int esCapicua(char arreglo[]){
    int largo=0;
    int control = 1;

    while(arreglo[largo] != NULL){
        largo++;
    }

    for(int i=0; i<(largo/2); i++){

        char letraA;
        char letraB;

        //CAMBIO LAS MAYUSCULAS POR LAS MINUSCULAS PARA EVITAR PROBELMA
        if(arreglo[i]<90)
            letraA=(arreglo[i])+32;
        else
            letraA=arreglo[i];

        if(arreglo[(largo-1)-i]<90)
            letraB=(arreglo[(largo-1)-i])+32;
        else
            letraB=arreglo[(largo-1)-i];
        //---------------------------------

        if(letraA != letraB){
            control = 0; //NO ES CAPICUA
        }
    }

    return control;
}

//FUNCIONES EJERCICIO 10
void invertirArray(int arreglo[], int validos){
    int aux;

    for(int i=0; i<(validos/2) ;i++){
        aux = arreglo[i];
        arreglo[i] = arreglo[validos-1-i];
        arreglo[validos-1-i]=aux;
    }
}

//FUNCIONES EJERCICIO 11
void ordenamientoPorSeleccion(int arreglo[], int *validos){
  int i, j, minimo;

  for (i = 0; i < (*validos) - 1; i++) {
    minimo = i;

    for (j = i + 1; j < (*validos); j++) {
      if (arreglo[j] < arreglo[minimo]) {
        minimo = j;
      }
    }

    if (minimo != i) {
      int aux = arreglo[i];
      arreglo[i] = arreglo[minimo];
      arreglo[minimo] = aux;
    }
  }
}

void ordenamientoPorInsercion(int arreglo[], int *validos){
    int i,j,index;

    for(i=1; i< *validos; i++){

        index = arreglo[i];
        j=i-1;

        while(j>=0 && arreglo[j] > index){
            arreglo[j+1] = arreglo[j];
            j--;
        }

        arreglo[j+1] = index;
    }
}

//FUNCIONES EJERCICIO 12
void intercalarArrays(char arregloA[], char arregloB[], char arregloC[], int validosA, int validosB, int *validosC){
    int i = 0, j = 0, k = 0;

    *validosC = 0; //Inicializo C en 0 por si los arreglos estan vacios

    // Mientras ambos tengan elementos
    while(i < validosA && j < validosB){
        if(arregloA[i] <= arregloB[j]){
            arregloC[k++] = arregloA[i++];
        } else {
            arregloC[k++] = arregloB[j++];
        }
        (*validosC)++;
    }

    // Copiar lo que queda de A
    while(i < validosA){
        arregloC[k++] = arregloA[i++];
        (*validosC)++;
    }

    // Copiar lo que queda de B
    while(j < validosB){
        arregloC[k++] = arregloB[j++];
        (*validosC)++;
    }
}


//FUNCIONES EJERCICIO 13
void sumaAnteriorArray (int arreglo[], int validos, int arregloSum[], int *validosSum){
    int sumaAnt = 0;

    for(int i=0; i<validos; i++){
        sumaAnt=0;

        for(int j=i; j>=0; j--){
            sumaAnt += arreglo[j];
        }

        arregloSum[i] = sumaAnt;
        (*validosSum)++;
    }
}

void mostrarArrayLineal(int arreglo[], int validos){

    for(int i=0; i<validos; i++){

        printf(" %i |", arreglo[i]);
    }
    printf("\n\n");
}
