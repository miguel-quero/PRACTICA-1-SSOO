
#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int lineas; //variable para guardar el número de lineas elegido por el usuario.
    
    if (argc = 1){
        lineas = 10;
    } else if (argc = 2){
        lineas = abs(atoi(argv[1]));
    }
 
   
    return tail(lineas);
}