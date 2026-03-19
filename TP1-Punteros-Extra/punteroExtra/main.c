#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 10;
    int *puntero = &numero; //puntero va a guardar la direccion de variable

    printf("Yo soy una variable 'numero' y mi valor es: %d \n", numero);

    printf("Yo soy la direccion de memoria de la variable anterior %p\n\n", &numero);

    printf("Yo soy un puntero que almacena la direccion de memoria de una variable, NO SU VALOR. Puntero: %p\n", puntero);
    printf("Pero si al puntero le agrego (*puntero) me devuelve el contenido almacenado en: %p , que es: %d\n\n", puntero, *puntero);

    *puntero = 15;

    printf("Si hago (*puntero = 15) estoy modificando el contenido de la direccion de memoria: %p.\nSu contenido pasa a ser: %d\n\n", puntero, *puntero);


    printf("Entonces, 'numero' tiene la direccion de memoria: %p y puntero almacena la misma direccion: %p\n", &numero, puntero);
    printf("\nSi yo con (*puntero = 15) cambie el contenido en la direccion %p.\nEl valor de la variable 'numero' es ahora: %d\n", puntero, numero);

}
