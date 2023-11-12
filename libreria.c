#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int head(int N)
{
    char *input = (char *)malloc(512*sizeof(char)); //variable para almacenar las lineas que el usuario introduce por teclado.

    // este código coge la entrada que el usuario escribe y la muestra por pantalla. Se repite dependiendo del valor de lineas.
    for(int i=N; i>0; i--){
        fgets(input,sizeof(input),stdin);
        printf("%s",input);
    }
    // liberación de la memoria dinámica.
    free(input);
    return 0;
}