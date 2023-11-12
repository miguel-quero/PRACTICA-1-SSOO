
#include "libreria.h"
#include <stdio.h> 

int main(int argc, char *argv[]){
    int lineas; //variable para guardar el número de lineas elegido por el usuario.

    if (argc == 1){ //si no se reciben argumentos entonces lineas es 10.
        lineas = 10;
    } else if (argc == 2) { //si se recibe un argumento n o -n se realiza el valor absoluto por si acaso.
        lineas = abs(atoi(argv[1]));
    } else{ //si se recibe más de 1 argumento se muestra este mensaje de error por pantalla.
        printf("Escribe un numero N despues del mandato para ver las N primeras lineas o nada para ver las 10 primeras lineas");
        return 1;
    }
    
    return head(lineas);
}