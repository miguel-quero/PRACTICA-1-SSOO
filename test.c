
#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){ //función principal para reconocer los argumentos de entrada


    int lineas; //variable para guardar el número de lineas elegido por el usuario.
    
    if (argc == 2){ // Si el usuario no incluye un número de líneas, se establece a 10.
        lineas = 10;
    } else if (argc == 3){
        if (atoi(argv[2]) <= 0){ // Si el número es menor que 0 se muestra un mensaje de error por pantalla.
            printf("El numero de lineas es un numero entero positivo mayor de 0. Este argumento es opcional, si no se le pasa ningun argumento, el numero de lineas sera 10.");
            return 1;
        } else { // Si el número es válido, se almacena en la variable "lineas".
            lineas = atoi(argv[2]);
        }
     
    }

    if (strcmp(argv[1], "-head") == 0) { //Si la función escrita coincide con la función "-head" se ejecuta head, que se encuentra en "libreria.h".
        return head(lineas);
    } else if (strcmp(argv[1], "-tail") == 0) { //Si la función escrita coincide con la función "-tail" se ejecuta tail, que pertenece a "libreria.h".
        return tail(lineas);
    } else if (strcmp(argv[1], "-longlines") == 0) { //Si la función escrita coincide con la función "-longlines" se ejecuta longlines, que pertenece a "libreria.h".
        return longlines(lineas);
    } else { // Si la función no es ninguna de las tres anteriores, se muestra un mensaje de error por pantalla
        printf("No se reconoce la funcion introducida");
        return 1;
    }
}