#include "libreria.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int head(int N)
{
    char *input = (char *)malloc(1024*sizeof(char)); //variable para almacenar las lineas que el usuario introduce por teclado.
    int lineasmostradas = 0;

    // este código coge la entrada que el usuario escribe y la muestra por pantalla. Se repite dependiendo del valor de lineas.
    while (lineasmostradas < N && fgets(input, 1024, stdin) != NULL) {
        printf("%s", input);
        lineasmostradas++;
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
    char *input = (char *)malloc(1024*sizeof(char)); //variable para almacenar las lineas que el usuario introduce por teclado.

    while (fgets(input,1024,stdin) != NULL){
        char *nuevaLinea = malloc((strlen(input) + 1) * sizeof(char));
        //reservamos espacio para cada linea y la copiamos
        strcpy(nuevaLinea, input);
        //redimensionamos el array para que entre la nueva linea
        numLineas++;
        entrada = realloc(entrada, numLineas*sizeof(char *));
        //guardamos la linea
        entrada[numLineas-1] = nuevaLinea;
    }

    //pequeño calculo para leer las N ultimas lineas y restringir la lectura si hay menos lineas en la entrada que las pedidas
    int indice = numLineas - N;
    if (indice < 0){
        N = numLineas;
        indice = 0;
    }

    // imprimimos por pantalla las N ultimas lineas
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

int longlines(int N)
{
    //creamos un puntero al array de strings que vamos a usar
    char **entrada = NULL;
    int numLineas = 0;
    char *input = (char *)malloc(1024*sizeof(char)); //variable para almacenar las lineas que el usuario introduce por teclado.

    while (fgets(input,1024,stdin) != NULL){
        char *nuevaLinea = malloc((strlen(input) + 1) * sizeof(char));
        //reservamos espacio para cada linea y la copiamos
        strcpy(nuevaLinea, input);
        //redimensionamos el array para que entre la nueva linea
        numLineas++;
        entrada = realloc(entrada, numLineas*sizeof(char *));
        //guardamos la linea
        entrada[numLineas-1] = nuevaLinea;
    }

    //array de indices para no mover los elementos del array
    int indexArray [numLineas];
    for(int i=0;i<numLineas;i++){
        indexArray[i] = i;
    }

    //algoritmo de la burbuja
    bool cambio;
    for(int i=0;i<numLineas-1;i++){
        cambio = false;
        for(int j=0;j<numLineas-i-1;j++){
            if (strlen(entrada[indexArray[j]]) < strlen(entrada[indexArray[j+1]])){
                int temp = indexArray[j];
                indexArray[j] = indexArray[j+1];
                indexArray[j+1] = temp;
                cambio=true;
            }            
        }
        //optimizacion del algoritmo de la burbuja, si el bucle interno no cambia ningun elemento, se puede salir del bucle
        if (cambio == false){break;}
    }

    //pequeño calculo para restringir la lectura si hay menos lineas en la entrada que las pedidas
    if (numLineas < N){
        N = numLineas;
    }

    // imprimimos por pantalla las N ultimas lineas
    for(int i=0; i<N; i++){
        printf("%s",entrada[indexArray[i]]);
    }

    // liberación de la memoria dinámica.
    for(int i=0;i<numLineas;i++){
        free(entrada[i]);
    }
    free(input);
    
    return 0;
}