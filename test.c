
#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){


    int lineas; //variable para guardar el número de lineas elegido por el usuario.
    
    if (argc == 2){
        lineas = 10;
    } else if (argc == 3){
        if (atoi(argv[2]) <= 0){
            printf("El numero de lineas es un numero entero positivo mayor de 0. Este argumento es opcional, si no se le pasa ningun argumento, el numero de lineas sera 10.");
            return 1;
        } else {
            lineas = atoi(argv[2]);
        }
     
    }

    if (strcmp(argv[1], "-head") == 0) {
        return head(lineas);
    } else if (strcmp(argv[1], "-tail") == 0) {
        return tail(lineas);
    } else if (strcmp(argv[1], "-longlines") == 0) {
        return longlines(lineas);
    } else {
        printf("No se reconoce la funcion introducida");
        return 1;
    }
}