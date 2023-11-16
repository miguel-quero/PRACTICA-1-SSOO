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

int tail(int N)
{
    //creamos un puntero al array de strings que vamos a usar
    char **entrada = NULL;
    int numLineas = 0;
    char *input = (char *)malloc(512*sizeof(char)); //variable para almacenar las lineas que el usuario introduce por teclado.

    while (fgets(input,sizeof(input),stdin) != NULL){
        //quitamos el carácter de nueva linea
        input[strcspn(input, "\n")] = '\0';
        char *nuevaLinea = (char *)malloc(512*sizeof(char));
        //reservamos espacio para cada linea y la copiamos
        strcpy(nuevaLinea, input);
        //redimensionamos el array para que entre la nueva linea
        numLineas++;
        entrada = realloc(entrada, numLineas*sizeof(char *));
        //guardamos la linea
        entrada[numLineas] = nuevaLinea;
    }

    int indice = numLineas - N;
    if (indice < 0){
        N = numLineas;
        indice = 0;
    }

    // este código coge la entrada que el usuario escribe y la muestra por pantalla. Se repite dependiendo del valor de lineas.
    for(int i=0; i<N; i++){
        printf("%s",entrada[indice + i]);
    }
    // liberación de la memoria dinámica.
    for(int i=0;i<numLineas;i++){
        free(entrada[i]);
    }
    free(input);
    
    return 0;
}