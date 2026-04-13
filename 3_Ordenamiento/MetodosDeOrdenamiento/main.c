#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 100
#define DIMBIG 10000

//PROTOTIPOS
int menuOpciones();
void cargarArregloRandom(int arreglo[], int validos);
void mostrarArreglo(int arreglo[], int validos);

void ordenamientoPorSeleccion(int arreglo[], int validos);
void ordenamientoPorInsercion(int arreglo[], int validos);
void ordenamientoBurbujeo(int arreglo[], int validos);

int busquedaBinaria(int arreglo[], int validos, int dato);

void copiarArreglo(int origen[], int destino[], int n);
void tiemposOrdenameinto();

//MAIN
int main()
{
    int opcion;

    srand(time(NULL)); //Para que funcione el Random

    do {
        opcion = menuOpciones();

        //Variables
        int miArregloRandom[DIM];
        int datoBuscado;

        switch(opcion) {
            case 1:
                printf("Ordenamiento por Seleccion O(n)\n\n");
                cargarArregloRandom(miArregloRandom, DIM);  //Lo cargo completo

                printf("ARREGLO ORIGINAL:\n");
                mostrarArreglo(miArregloRandom, DIM);

                ordenamientoPorSeleccion(miArregloRandom, DIM);

                printf("\nARREGLO ORDENADO POR SELECCION:\n");
                mostrarArreglo(miArregloRandom, DIM);

                printf("\n\n");
                system("pause");
                break;
            case 2:
                printf("Ordenamiento por Insercion O(n^2)\n\n");
                cargarArregloRandom(miArregloRandom, DIM);  //Lo cargo completo

                printf("ARREGLO ORIGINAL:\n");
                mostrarArreglo(miArregloRandom, DIM);

                ordenamientoPorInsercion(miArregloRandom, DIM);

                printf("\nARREGLO ORDENADO POR INSERCION:\n");
                mostrarArreglo(miArregloRandom, DIM);

                printf("\n\n");
                system("pause");
                break;
            case 3:
                printf("Ordenamiento por Burbujeo O(n^2)\n\n");
                cargarArregloRandom(miArregloRandom, DIM);  //Lo cargo completo

                printf("ARREGLO ORIGINAL:\n");
                mostrarArreglo(miArregloRandom, DIM);

                ordenamientoBurbujeo(miArregloRandom, DIM);

                printf("\nARREGLO ORDENADO POR BURBUJEO:\n");
                mostrarArreglo(miArregloRandom, DIM);

                printf("\n\n");
                system("pause");

                break;
            case 4:
                printf("Busqueda Binaria O(log n)\n\n");
                cargarArregloRandom(miArregloRandom, DIM);  //Lo cargo completo
                ordenamientoPorSeleccion(miArregloRandom, DIM); //Lo Ordeno previamente

                printf("Ingrese el dato buscado:");
                scanf("%d", &datoBuscado);
                printf("\n\n");

                busquedaBinaria(miArregloRandom, DIM,datoBuscado);

                printf("\nARREGLO ORDENADO:\n");
                mostrarArreglo(miArregloRandom, DIM);
                printf("\n\nPOSICION DEL DATO HALLADO: %d\n",busquedaBinaria(miArregloRandom, DIM,datoBuscado));

                printf("\n\n");
                system("pause");
                break;
            case 5:
                //Comparacion de los 3 ordenamientos
                tiemposOrdenameinto();
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
    printf("2 - Ordenamiento por Insercion\n");
    printf("3 - Ordenamiento por Burbujeo\n");
    printf("4 - Busqueda Binaria\n");
    printf("5 - Comparacion de Ordenamientos\n");

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
    for(int i = 0; i < validos; i++){
        printf("%d | ", arreglo[i]);
    }
    printf("\n\n");
}


///SELECCION
void ordenamientoPorSeleccion(int arreglo[], int validos){
    int i, j, minimo;

    //Siempre se hace a validos-1 pq cuando voy ordenando voy de izq a der entonces en 20 posiciones,
    //cuando llego a la posicion 19, la posicion 20 ya estára ordenada por naturaleza
    for(i = 0; i < validos - 1; i++){
        //Asumo que el numero mas chico está en la posicion 0
        minimo = i;

        //Recorro el arreglo desde la posicion 1 a final
        for(j = i + 1; j < validos; j++){
            //Si encuentro un numero mas chico que minimo, lo reemplazo y hay un nuevo minimo
            if(arreglo[j] < arreglo[minimo]){
                minimo = j;
            }
        }

        //Si se encontró un nuevo minimo Ej. posicion[0] = 30 y posicion [5] = 20
        //Debo hacer un enroque y pasar 20 a [0] y 30 a [5]
        if(minimo != i){
            int aux = arreglo[i];
            arreglo[i] = arreglo[minimo];
            arreglo[minimo] = aux;
        }
    }
}

///INSERCION
void ordenamientoPorInsercion(int arreglo[], int validos){
    int i, j, actual;

    //Recorro todo el arreglo hasta los validos
    for(i = 1; i < validos; i++){

        actual = arreglo[i];    //Guarda el valor de la posicion actual
        j = i - 1;

        //Muevo el actual hasta la derecha hasta que actual sea mas grande que su anterior
        //Ej {4,5,6,3} actual = 3
            //el 6 es mas grande que actual? SI entonces el 6 pisa el 3 {4,5,6,6}
            //el 5 es mas grande que actual? SI entonces el 5 pisa el 6 {4,5,5,6}
            //el 4 es mas grande que actual? SI entonces el 4 pisa el 5 {4,4,5,6}
            //Llega al principio del arreglo (j=0) entonces actual va en arreglo[i] (arreglo[0])  {3,4,5,6}
        while(j >= 0 && arreglo[j] > actual){
            arreglo[j + 1] = arreglo[j];
            j--;
        }

        arreglo[j + 1] = actual;
    }
}

///BURBUJEO
void ordenamientoBurbujeo(int arreglo[], int validos){
    int i, j, flag;

    //Para cada posicion del arreglo osea cada numero se va a comparar con el siguiente,
    //se llama burbujeo pq cada numero sube en la posicion hasta su lugar
    for(i = 0; i < validos - 1; i++){
        flag = 0;

        // El elemento en la posición j se compara con el siguiente (j+1).
        // Si el elemento en j es mayor que el de j+1, se intercambian.
        // De esta forma, el valor mayor se va desplazando hacia la derecha.
        //
        // Ejemplo: {3,1,4,6}
        //
        // 3 > 1 -> intercambio → {1,3,4,6}
        // 3 > 4 -> no se intercambia
        // 4 > 6 -> no se intercambia
        //
        // Fin de la pasada: el número más grande queda al final.
        for(j = 0; j < validos - 1 - i; j++){
            if(arreglo[j] > arreglo[j+1]){
                int aux = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = aux;
                flag = 1;
            }
        }

        if(flag == 0){
            break; // ya está ordenado
        }
    }
}

///BUSQUEDA BINARIA
    //Solo se puede usar en arreglo ya ordenados
int busquedaBinaria(int arreglo[], int validos, int dato){
    int pri = 0;
    int ult = validos - 1;
    int medio;

    //Se va a ejecutar hasta enonctrar la posicion
    while(pri <= ult){
        medio = (pri + ult) / 2; //posicion media ( (0+validos)/2)

        if(arreglo[medio] == dato){
            return medio; // encontrado
        }
        else if(dato < arreglo[medio]){
            //Si el dato es menor que el dato del medio voy a la izq
            ult = medio - 1;
        }
        else{
            //Si el dato es menor que el dato del medio voy a la derecha
            pri = medio + 1;
        }
    }

    return -1; // no encontrado
}


///COMPARACION DE ORDENAMIENTOS
void copiarArreglo(int origen[], int destino[], int n){
    for(int i=0; i<n; i++){
        destino[i] = origen[i];
    }
}

void tiemposOrdenameinto(){

    int original[DIMBIG];
    int sel[DIMBIG], ins[DIMBIG], bur[DIMBIG];

    srand(time(NULL));

    cargarArregloRandom(original, DIMBIG);

    copiarArreglo(original, sel, DIMBIG);
    copiarArreglo(original, ins, DIMBIG);
    copiarArreglo(original, bur, DIMBIG);

    clock_t inicio, fin;

    /// SELECCION
    inicio = clock();
    ordenamientoPorSeleccion(sel, DIMBIG);
    fin = clock();
    double tiempoSel = (double)(fin - inicio) / CLOCKS_PER_SEC;

    /// INSERCION
    inicio = clock();
    ordenamientoPorInsercion(ins, DIMBIG);
    fin = clock();
    double tiempoIns = (double)(fin - inicio) / CLOCKS_PER_SEC;

    /// BURBUJEO
    inicio = clock();
    ordenamientoBurbujeo(bur, DIMBIG);
    fin = clock();
    double tiempoBur = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("\n--- TIEMPOS DE ORDENAMIENTO ---\n\n");
    printf("Seleccion: %.5f segundos\n", tiempoSel);
    printf("Insercion: %.5f segundos\n", tiempoIns);
    printf("Burbujeo: %.5f segundos\n", tiempoBur);
}
