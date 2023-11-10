#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int head(int argc, char *argv[])
{
    int lineas;     //variable para guardar el número de lineas elegido por el usuario.
    char input[1024]; //variable para almacenar las lineas que el usuario introduce por teclado.

    if (argc == 1){ //si no se reciben argumentos entonces lineas es 10.
        lineas = 10;
    } else if (argc == 2) { //si se recibe un argumento n o -n se realiza el valor absoluto por si acaso.
        lineas = abs(atoi(argv[1]));
    } else { //si se recibe más de 1 argumento se muestra este mensaje de error por pantalla.
        printf("Escribe un número N después del mandato para ver las N primeras líneas o nada para ver las 10 primeras líneas");
        return 1;
    }
    // este código coge la entrada que el usuario escribe y la muestra por pantalla. Se repite dependiendo del valor de lineas.
    for(int i=lineas; i>0; i--){
        fgets(input,sizeof(input),stdin);
        printf("%s",input);
    }
    return 0;
}