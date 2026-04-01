#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pila.h"

///PROTOTIPOS
int menuOpciones();
void cargarPilaRandom(Pila *p, int cantidad, int min, int max);

void pasarTopeABase(Pila *p);

void repartirMazo(Pila *mazo, Pila *jugador1, Pila *jugador2);

int compararCantidad(Pila pila1, Pila pila2);

void cargarPilaUsuario(Pila *p);
int pilasIguales(Pila pila1, Pila pila2);

void eliminarTopedeOtraPila(Pila *dada, Pila *modelo);
int eliminarElemento(Pila *pila, int valorBorrar);

void eliminarPiladePila(Pila *dada, Pila *modelo);

void dividirPila(Pila original, Pila *mayores, Pila *menores, int valor);

int esPar(Pila p);

int pilaANumero(Pila pila);

int sumaValorPila(Pila p, int elementosASumar);

int esCapicua(Pila pilaOrdenada);

void eliminarRepetidos(Pila *p);
int existeEnPila(Pila p, int valor);

Pila unirPilasValoresUnicos(Pila *a, Pila *b);

void juntarPilasOrdenadas(Pila a, Pila b, Pila *ordenadaFinal);

Pila ordenarPila(Pila *p);
int extraerMenor(Pila *p);

void insertarDatoOrdenado(Pila *p, int valor);


///MAIN
int main(){
    int opcion;
    //Es para generar numeros aleatorios
    srand(time(NULL));

    do {
        opcion = menuOpciones();

        ///VARIABLES DE EJERCICIOS
            //Ej1
        Pila pilaEj1;
        inicpila(&pilaEj1);

            //Ej2
        Pila mazo;
        inicpila(&mazo);

        Pila j1;
        inicpila(&j1);

        Pila j2;
        inicpila(&j2);

            //Ej3
        int largoPila;

        Pila pila1Ej3;
        inicpila(&pila1Ej3);

        Pila pila2Ej3;
        inicpila(&pila2Ej3);

            //Ej4
        Pila pila1Ej4;
        inicpila(&pila1Ej4);

        Pila pila2Ej4;
        inicpila(&pila2Ej4);

            //Ej5
        Pila dada;
        inicpila(&dada);

        Pila modelo;
        inicpila(&modelo);

            //Ej6
        Pila dada1;
        inicpila(&dada1);

        Pila modelo1;
        inicpila(&modelo1);

            //Ej7
        Pila original;
        inicpila(&original);

        Pila menores;
        inicpila(&menores);

        Pila mayores;
        inicpila(&mayores);

        int valorSeparacion;

            //Ej8
        Pila pilaEj8;
        inicpila(&pilaEj8);

            //Ej9
        Pila pilaEj9;
        inicpila(&pilaEj9);

            //Ej10
        Pila pilaEj10;
        inicpila(&pilaEj10);

            //Ej11
        Pila pilaEj11;
        inicpila(&pilaEj11);

            //Ej12
        Pila aEj12;
        inicpila(&aEj12);

        Pila bEj12;
        inicpila(&bEj12);

        Pila cEj12;
        inicpila(&cEj12);

            //Ej13
        Pila aEj13;
        inicpila(&aEj13);

        Pila bEj13;
        inicpila(&bEj13);

        Pila ordenadFinal;
        inicpila(&ordenadFinal);

            //Ej14
        Pila desordenada;
        inicpila(&desordenada);

        Pila ordenada;
        inicpila(&ordenada);

            //Ej15
        Pila desordenadaEj15;
        inicpila(&desordenadaEj15);

        Pila ordenadaEj15;
        inicpila(&ordenadaEj15);

        int valor = 0;


        switch(opcion) {
            case 1:
                printf("Ejecucion Ej 1\n");

                cargarPilaRandom(&pilaEj1, 10, 1, 10);
                mostrar(&pilaEj1);

                pasarTopeABase(&pilaEj1);
                mostrar(&pilaEj1);

                printf("\n\n");
                system("pause");
                break;
            case 2:
                cargarPilaRandom(&mazo, 9, 1, 10);
                mostrar(&mazo);

                repartirMazo(&mazo, &j1, &j2);

                printf("Jugador 1\n");
                mostrar(&j1);

                printf("Jugador 2\n");
                mostrar(&j2);


                printf("\n\n");
                system("pause");
                break;
            case 3:

                    //Pila 1
                printf("Ingrese el largo de la pila N 1: ");
                scanf("%d", &largoPila);
                cargarPilaRandom(&pila1Ej3,largoPila , 1, 10);


                    //Pila 2
                printf("Ingrese el largo de la pila N 2: ");
                scanf("%d", &largoPila);
                cargarPilaRandom(&pila2Ej3,largoPila , 1, 10);


                    //Limpio Pantalla
                system("cls");

                //Comparo cual de las dos es mas larga (-1 0 1)
                //Paso las dos pilas por copia porque como las voy a desapilar
                //me interesa que las pilas fuera de la fx queden originales, sino las pasaria por puntero

                if(compararCantidad(pila1Ej3,pila2Ej3)== 1){
                    printf("La pila mas larga es la 1\n");
                    mostrar(&pila1Ej3);
                }else if(compararCantidad(pila1Ej3,pila2Ej3)== -1){
                    printf("La pila mas larga es la 2\n");
                    mostrar(&pila2Ej3);
                }else{
                    printf("Las pilas son iguales\n");
                    mostrar(&pila1Ej3);
                    mostrar(&pila2Ej3);
                }

                printf("\n\n");
                system("pause");
                break;
            case 4:
                //cargo las dos pilas a mano
                for(int i=1; i<=2; i++){
                    printf("Cargar los valores de la pila N %d \n", i);

                    if(i == 1){
                        cargarPilaUsuario(&pila1Ej4);
                        mostrar(&pila1Ej4);
                    }else{
                        cargarPilaUsuario(&pila2Ej4);
                        mostrar(&pila2Ej4);
                    }

                    system("pause");
                    system("cls");
                }

                if(pilasIguales(pila1Ej4, pila2Ej4) == 1){
                    printf("Las Pilas son Iguales.\n");
                }else{
                    printf("Las Pilas NO son Iguales.\n");
                }

                mostrar(&pila1Ej4);
                mostrar(&pila2Ej4);

                printf("\n\n");
                system("pause");
                break;
            case 5:
                //cargo las dos pilas a mano

                printf("Cargar los valores de la pila MODELO\n");
                cargarPilaUsuario(&modelo);
                system("cls");

                cargarPilaRandom(&dada, 10, 1, 10);

                printf("Pila antes de eliminar valores\n");
                mostrar(&dada);

                eliminarTopedeOtraPila(&dada,&modelo);

                printf("Pila sin el valor TOPE de MODELO [ %d ]\n", tope(&modelo));
                mostrar(&dada);

                printf("\n\n");
                system("pause");
                break;
            case 6:
                printf("Cargar los valores de la pila MODELO\n");
                cargarPilaUsuario(&modelo1);
                system("cls");

                cargarPilaRandom(&dada1, 10, 1, 10);

                printf("Pila antes de eliminar valores\n");
                mostrar(&dada1);


                eliminarPiladePila(&dada1,&modelo1);
                printf("Pila despues de eliminar valores de MODELO\n");
                mostrar(&dada1);

                printf("\n\n");
                system("pause");
                break;
            case 8:
                //crea una pila con numeros randon de cantidad random hasta 49 elementos
                srand(time(NULL));
                cargarPilaRandom(&pilaEj8, rand()%50, 1, 10);

                mostrar(&pilaEj8);

                if(esPar(pilaEj8) == 1){
                    printf("La cantidad de elementos es par");
                }else{
                    printf("La cantidad de elementos es impar");
                }



                printf("\n\n");
                system("pause");
                break;

            case 9:
                //Hago el ejercicio donde el usuario ingrese los numeros en la pila
                printf("Cargar los valores de la pila\n");
                cargarPilaUsuario(&pilaEj9);
                system("cls");

                mostrar(&pilaEj9);
                //El retorno de la funcion pilaANumero se lo paso directamente al printf
                //(ahorrandome declarar una variable para almacenarlo)
                printf("El numero que forma la pila es: %d", pilaANumero(pilaEj9));

                printf("\n\n");
                system("pause");
                break;

            case 10:
                cargarPilaRandom(&pilaEj10,10,1,10);

                printf("La suma es: %d \n",sumaValorPila(pilaEj10, 2)); //La paso por copia para no romper la original
                mostrar(&pilaEj10);

                printf("\n\n");
                system("pause");
                break;

            case 11:
                printf("Cargar los valores de la pila\n");
                cargarPilaUsuario(&pilaEj11);
                system("cls");

                if(esCapicua(pilaEj11) == 1){
                    printf("La Pila es Capicua");
                }else{
                    printf("La Pila NO es Capicua");
                }

                mostrar(&pilaEj11);

                printf("\n\n");
                system("pause");
                break;

            case 12:
                cargarPilaRandom(&aEj12,8,1,10);

                cargarPilaRandom(&bEj12,8,1,10);

                printf("PILA A: \n");
                mostrar(&aEj12);
                printf("PILA B: \n");
                mostrar(&bEj12);

                printf("\n\nPILA C CON VALORES UNICOS: \n");

                    //la funcion retorna una pila, podria haberlo hecho por puntero tambien
                cEj12 = unirPilasValoresUnicos(&aEj12, &bEj12);
                mostrar(&cEj12);

                printf("\n\n");
                system("pause");
                break;

            case 13:
                printf("Cargar los valores de la pila A de menor a mayor\n");
                cargarPilaUsuario(&aEj13);
                system("cls");

                printf("Cargar los valores de la pila B de menor a mayor\n");
                cargarPilaUsuario(&bEj13);
                system("cls");

                juntarPilasOrdenadas(aEj13, bEj13, &ordenadFinal);

                printf("PILA A: \n");
                mostrar(&aEj13);
                printf("PILA B: \n");
                mostrar(&bEj13);

                printf("\n\nPILA C: \n");
                mostrar(&ordenadFinal);

                printf("\n\n");
                system("pause");
                break;

            case 14:
                cargarPilaRandom(&desordenada,10,1,10);

                ordenada = ordenarPila(&desordenada);

                printf("PILA desordenada: \n");
                mostrar(&desordenada);
                printf("\n\nPILA Ordenada: \n");
                mostrar(&ordenada);

                printf("\n\n");
                system("pause");
                break;

            case 15:
                cargarPilaRandom(&desordenadaEj15,10,1,10);

                ordenadaEj15 = ordenarPila(&desordenadaEj15);

                printf("\n\nPILA: \n");
                mostrar(&ordenadaEj15);

                printf("\n\nIngrese valor a insertar en la Pila:");
                scanf("%d",&valor);

                insertarDatoOrdenado(&ordenadaEj15, valor);

                printf("\n\nPILA CON DATO INSERTADO: \n");
                mostrar(&ordenadaEj15);

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

///FUNCIONES
int menuOpciones(){

    int op;

    system("cls");

    printf("========== MENU PILAS EXTRA ==========\n");
    printf("1 - Pasar Tope a Base\n");
    printf("2 - Repartir Mazo de Cartas en 2 jugadores\n");
    printf("3 - Que pila es mas larga?\n");
    printf("4 - Las Pilas son exactamente iguales?\n");
    printf("5 - Eliminar el valor TOPE de MODELO de la pila DADA\n");
    printf("6 - Eliminar MODELO de la pila DADA\n");
    printf("7 - Separar valores en Mayor y Menor\n");
    printf("8 - Cantidad de elementos es Par o Impar\n");
    printf("9 - De pila a Numero\n");
    printf("10 - Suma el Tope y el anterior de una Pila Random\n");
    printf("11 - Una Pila es Capicua?\n");
    printf("12 - Juntar dos Pilas con Valores Unicos\n");
    printf("13 - Juntar dos Pilas ordenadas y mantener el Orden\n");
    printf("14 - Ordenar una Pila\n");
    printf("15 - Insertar valor a pila ordenada\n");

    printf("\n0 - Salir\n");

    printf("\nIngrese un numero: ");
    scanf("%d", &op);

    system("cls");

    return op;

}

    //Carga una pila con numero random con valores entre min y max
void cargarPilaRandom(Pila *p, int cantidad, int min, int max){

    for(int i = 0; i < cantidad; i++){
        int num = rand() % (max - min + 1) + min;
        apilar(p, num);
    }
}


    //Ejercicio 1
void pasarTopeABase(Pila *p){

    Pila aux;
    inicpila(&aux);

    if(!pilavacia(p)){
        int topeOriginal = desapilar(p);

        //Paso la pila a una pila auxiliar (queda acomodado en orden inverso)
        while(!pilavacia(p)){
            apilar(&aux, desapilar(p));
        }


        apilar(p, topeOriginal);    //Inserto el Tope como base en la pila 'p'


        while(!pilavacia(&aux)){
            apilar(p, desapilar(&aux));
        }
    }
}

    //Ejercicio 2
void repartirMazo(Pila *mazo, Pila *jugador1, Pila *jugador2){

    //Si hago esto, que pasa cuando reparto un mazo de 9 cartas?
        /*while(!pilavacia(mazo)){
            apilar(jugador1, desapilar(mazo));
            apilar(jugador2, desapilar(mazo));
        }*/
    //---------------------------------------------------------


    //Opcional para que no siempre arranque a repartir por el Jugador 1
    srand(time(NULL));
    int turno = rand()%2; // va a devolver 0 o 1

    while(!pilavacia(mazo)){
        if(turno == 0){
            apilar(jugador1, desapilar(mazo));
            turno = 1;
        }else{
            apilar(jugador2, desapilar(mazo));
            turno = 0;
        }
    }

}

    //Ejercicio 3
int compararCantidad(Pila pila1, Pila pila2){

    int resultado;

    // Desapilo ambas al mismo tiempo (primero me aseguro que ninguna este vacia pq sino desapilar algo vacio se rompe)
    while(!pilavacia(&pila1) && !pilavacia(&pila2)){
        desapilar(&pila1);
        desapilar(&pila2);
    }

    //Acá ya se que alguna por lo menos está vacia

    if(!pilavacia(&pila2)){
        //Si la pila 2 NO está vacia entonces la vacia es la 1
        resultado = -1;
    }else if(!pilavacia(&pila1)){
        //Si la pila 1 NO está vacia entonces la vacia es la 2
        resultado = 1;
    }else{
        //ambas estan vacias
        resultado = 0;
    }

    return resultado;
}

    //Ejercicio 4
void cargarPilaUsuario(Pila *p){
    int valor;
    char seguir = 's';

    while(seguir == 's' || seguir == 'S'){
        printf("Ingrese un numero: ");
        scanf("%d", &valor);

        apilar(p, valor);

        printf("Desea ingresar otro numero? (s/n): ");
        fflush(stdin); // Limpia la memoria (lo vamos a ver mas adelante)
        scanf(" %c", &seguir);
    }
}

int pilasIguales(Pila pila1, Pila pila2){

    //Uso la funcion del Ejercicio3
    if(compararCantidad(pila1,pila2) != 0){
        //Si no devuelve 0 es porque no son iguales
        return 0;
    }

    //desapilo y me fijo que sean iguales
    while(!pilavacia(&pila1) && !pilavacia(&pila2)){

        if(desapilar(&pila1) != desapilar(&pila2)){
            // hago el return aca para que no siga buscando igualdad (tambien se podria trabajar con un Flag)
            return 0;
        }

    }

    return 1;
}

    //Ejercicio 5
int eliminarElemento(Pila *pila, int valorBorrar){
    Pila aux;
    inicpila(&aux);

    int existe = 0;

    while(!pilavacia(pila)){
        if(tope(pila) == valorBorrar){
            //desapila y tira el valor
            desapilar(pila);
            existe++;
        }else{
            //desapila y guarda en aux
            apilar(&aux,desapilar(pila));
        }
    }

    //Guardo en pila los valores diferentes a valorBorrar
    while(!pilavacia(&aux)){
        apilar(pila, desapilar(&aux));
    }

    //Aprovecha y ademas de borrarlo me dice si existia o no ese valor en la pila (opcional)
    return existe;
}

void eliminarTopedeOtraPila(Pila *dada, Pila *modelo){
    //dada => tiene los valores originales

    if(!pilavacia(modelo)){
        eliminarElemento(dada, tope(modelo));
    }
}


    //Ejercicio 6
void eliminarPiladePila(Pila *dada, Pila *modelo){
    //dada => tiene los valores originales

    while(!pilavacia(modelo)){
        eliminarElemento(dada, desapilar(modelo));
    }
}

    //Ejercicio 7
void dividirPila(Pila original, Pila *mayores, Pila *menores, int valor){

    while(!pilavacia(&original)){
        int dato = desapilar(&original);

        if(dato >= valor){
            apilar(mayores, dato);
        }else{
            apilar(menores, dato);
        }
    }

}

    //Ejercicio 8
int esPar(Pila p){

    int resultado = 1;

    // saco de a 2 para saber si es par
    while(!pilavacia(&p)){
        desapilar(&p);

        if(!pilavacia(&p)){
            desapilar(&p);
        }else{
            resultado = 0;
            break;
        }
    }

    return resultado;
}

    //Ejercicio 9
int pilaANumero(Pila pila){

    int numero = 0;

    while(!pilavacia(&pila)){
        int digito = desapilar(&pila);
        numero = numero * 10 + digito;
    }

    /*
        0*10 + 1 = 1
        1*10 + 4 = 14
    */

    return numero;
}

    //Ejercicio 10
int sumaValorPila(Pila p, int elementosASumar){
    //la consigna dice el tope y el anterior es decir 2 elementos pero lo dejo abierto para que mañana sean 5 elementos con la variable elementosASumar
    int suma = 0;

    for(int i=0; i<elementosASumar; i++){
        if(!pilavacia(&p)){
            suma = suma + desapilar(&p);
        }else{
            //si esta vacia termino el bucle for
            i = elementosASumar;
        }
    }

    return suma;
}

    //Ejercicio 11
int esCapicua(Pila pilaOrdenada){
    Pila invertida;
    Pila aux;
    inicpila(&invertida);
    inicpila(&aux);

    //copio a aux e invierto el orden
    while(!pilavacia(&pilaOrdenada)){
        int dato = desapilar(&pilaOrdenada);
        apilar(&aux, dato);
        apilar(&invertida, dato);
    }

    // Restaurar de aux a p
    while(!pilavacia(&aux))
    {
        apilar(&pilaOrdenada, desapilar(&aux));
    }

    //>>>>>Me queda pilaOrdenada en un orden e invertida en el otro

    //Utilizo la funcion del Ejercicio 4 que compara las dos pilas
    //Si son iguales es capicua si no NO

    //El return es de la funcion pq pilasIguales me devuelve un 1 si son iguales o un 0 si no son iguales
    //entonces si son iguales = esCapicual = 1 ||| no son iguales = no es capicua = 0
    return pilasIguales(pilaOrdenada, invertida);

}

    //Ejercicio 12
int existeEnPila(Pila p, int valor){

    int encontrado = 0;

    while(!pilavacia(&p)){

        if(desapilar(&p) == valor){
            encontrado = 1;
        }
    }

    return encontrado;
}

void eliminarRepetidos(Pila *p){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(p)){
        int dato = desapilar(p);

        if(existeEnPila(aux, dato) == 0){
            //si no existe en aux lo apilo
            apilar(&aux, dato);
        }
    }

    // guardo en p los valores unicos
    while(!pilavacia(&aux)){
        apilar(p, desapilar(&aux));
    }
}

Pila unirPilasValoresUnicos(Pila *a, Pila *b){

    Pila c;
    inicpila(&c);

    //Junto en C lo que tiene A y lo que tiene B
    while(!pilavacia(a)){
        apilar(&c, desapilar(a));
    }

    while(!pilavacia(a)){
        apilar(&c, desapilar(b));
    }

    //De C saco los valores repetidos con la funcion eliminar repetidos
    eliminarRepetidos(&c);

    return c;

}

    //Ejercicio 13
void juntarPilasOrdenadas(Pila a, Pila b, Pila *ordenadaFinal){

    Pila aux;
    inicpila(&aux);

    // mientras las dos pilas tengan elementos los ordeno fijandome cual va primero
    while(!pilavacia(&a) && !pilavacia(&b)){
        if(tope(&a) > tope(&b)){
            apilar(&aux, desapilar(&a));
        }else{
            //Si son iguales no importa el orden se pone primero b y despues a
            apilar(&aux, desapilar(&b));
        }
    }

    //Si alguna se queda sin elementos, paso los que restan pq ya estan en orden
    while(!pilavacia(&a)){
        apilar(&aux, desapilar(&a));
    }

    while(!pilavacia(&b)){
        apilar(&aux, desapilar(&b));
    }

    // invierto para que quede de forma creciente
    while(!pilavacia(&aux)){
        apilar(ordenadaFinal, desapilar(&aux));
    }

}

    //Ejercicio 14
int extraerMenor(Pila *p){
    Pila aux;
    inicpila(&aux);

    int menor = tope(p);

    // Buscar el menor
    while(!pilavacia(p)){
        int dato = desapilar(p);

        if(dato < menor){
            menor = dato;
        }
        apilar(&aux, dato);
    }

    // elimino el menor una sola vez de la pila original
    int eliminado = 0;

    while(!pilavacia(&aux)){
        int dato = desapilar(&aux);

        if(dato == menor && eliminado == 0){
            eliminado = 1; // lo elimino una sola vez
        }else{
            apilar(p, dato);
        }
    }

    return menor;
}

Pila ordenarPila(Pila *p){
    Pila copia, aux, ordenada;
    inicpila(&copia);
    inicpila(&aux);
    inicpila(&ordenada);

    // Copiar pila para no perder la original
    while(!pilavacia(p)){
        apilar(&aux, desapilar(p));
    }

    while(!pilavacia(&aux)){
        int dato = desapilar(&aux);
        apilar(p, dato);
        apilar(&copia, dato);
    }

    while(!pilavacia(&copia)){
        int menor = extraerMenor(&copia);
        apilar(&ordenada, menor);
    }

    return ordenada;
}

    //Ejercicio 15
void insertarDatoOrdenado(Pila *p, int valor){
    Pila aux;
    inicpila(&aux);

    //Despilo hasta encontrar la posicion
    while(!pilavacia(p) && tope(p) > valor){
        apilar(&aux, desapilar(p));
    }

    //le meto el valor a la pila
    apilar(p, valor);

    //Los valores que saque los vuelvo a meter en la pila original
    while(!pilavacia(&aux)){
        apilar(p, desapilar(&aux));
    }
}
