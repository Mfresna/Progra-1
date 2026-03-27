#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

int main()
{
    system("title mi nombre");  // Cambia el nombre de la ventana de ejecucion

    system("pause");    //Espera que el usuario presione una tecla

    system("cls"); //limpia la pantalla


    //COLORES

        //system("color XY");   X= color Fondo | Y= color Texto
    system("color 04");
    printf("HOLA");

        /*
            | Código |    Color         |
            | ------ | ---------------- |
            | 0      | Negro            |
            | 1      | Azul             |
            | 2      | Verde            |
            | 3      | Aqua             |
            | 4      | Rojo             |
            | 5      | Púrpura          |
            | 6      | Amarillo         |
            | 7      | Blanco           |
            | 8      | Gris             |
            | 9      | Azul claro       |
            | A      | Verde claro      |
            | B      | Aqua claro       |
            | C      | Rojo claro       |
            | D      | Rosa             |
            | E      | Amarillo claro   |
            | F      | Blanco brillante |

        */


    //BEEP

        //Debo incluir la libreria windows
        //#include <windows.h>

    Beep(1500, 300);
        //750 la frecuencia en Hz, cuanto mas alto mas agudo el sonido
        //300 la duracion en ms se estila entre 150 - 600

    return 0;
}
