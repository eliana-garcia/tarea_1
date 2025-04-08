#!/bin/bash

echo "Compilando el programa..."
gcc -o tarea_1 main.c colaprioridad.c -I.

if [ $? -eq 0 ]; then
    echo "Compilación exitosa. Ejecutando el programa..."
    ./tarea_1
else
    echo "Error en la compilación."
fi
