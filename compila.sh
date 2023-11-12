#!bin/bash

#Este mandato sirve para obtener el fichero .o de la libreria creada
gcc -c libreria.c -o libreria.o

#Este mandato crea la libreria liblibreria.a, indicando que se quiere intertar los ficheros objeto en la libreria, o reemplazarlos si ya están en ella.
ar -rv liblibreria.a libreria.o 

#Este mandato compila el código de test.c y se indica que se va a utilizar la libreria liblibreria.a
gcc test.c -o test -L. liblibreria.a
