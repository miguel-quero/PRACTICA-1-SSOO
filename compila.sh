#!bin/bash

gcc -c libreria.c -o libreria.o
ar rcs liblibreria.a libreria.o 
gcc test.c -o test -L. liblibreria.a
