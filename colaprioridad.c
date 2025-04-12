#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "colaprioridad.h"

colaPrioridad *crearColaPrioridad() {
    colaPrioridad *cola = (colaPrioridad *)malloc(sizeof(colaPrioridad));
    cola->inicio = NULL;
    return cola;
}

void insertarOrdenado(colaPrioridad *cola, Ticket *nuevo) {
    if (!cola->inicio || nuevo->prioridad > cola->inicio->prioridad ||
       (nuevo->prioridad == cola->inicio->prioridad && nuevo->horaIngreso < cola->inicio->horaIngreso)) {
        nuevo->siguiente = cola->inicio;
        cola->inicio = nuevo;
        return;
    }

    Ticket *actual = cola->inicio;
    while (actual->siguiente &&
           (actual->siguiente->prioridad > nuevo->prioridad ||
           (actual->siguiente->prioridad == nuevo->prioridad &&
            actual->siguiente->horaIngreso <= nuevo->horaIngreso))) {
        actual = actual->siguiente;
    }

    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
}

void registrarTicket(colaPrioridad *cola, int id, char *descripcion) {
    Ticket *nuevo = (Ticket *)malloc(sizeof(Ticket));
    nuevo->id = id;
    strcpy(nuevo->descripcion, descripcion);
    nuevo->prioridad = BAJO;
    nuevo->horaIngreso = time(NULL);
    nuevo->siguiente = NULL;

    insertarOrdenado(cola, nuevo);
    printf("\nTicket registrado con éxito.\n-------------------------------------------\n\n");
}

void mostrarTickets(colaPrioridad *cola) {
    if (!cola->inicio) {
        printf("\nNo hay tickets pendientes.\n-------------------------------------------\n\n");
        return;
    }

    Ticket *actual = cola->inicio;
    printf("\nTickets pendientes:\n");

    while (actual) {
        char horaStr[26];
        struct tm *tm_info = localtime(&(actual->horaIngreso));
        strftime(horaStr, 26, "%Y-%m-%d %H:%M:%S", tm_info);

        printf("ID: %d\n", actual->id);
        printf("Descripción: %s\n", actual->descripcion);
        printf("Prioridad: ");
        if (actual->prioridad == ALTO){
            printf("ALTO\n");
        }else{
            if(actual->prioridad == MEDIO){
                printf("MEDIO\n");
            }else{
                printf("BAJO\n");
            }
        }
        printf("Hora de ingreso: %s\n", horaStr);
        printf("-------------------------------------------\n");
        actual = actual->siguiente;
    }

    printf("\n");
}

void modificarPrioridad(colaPrioridad *cola, int id, int nuevaPrioridad) {
    Ticket *anterior = NULL;
    Ticket *actual = cola->inicio;

    while (actual) {
        if (actual->id == id) {
            if (anterior){
                anterior->siguiente = actual->siguiente;
            } else {
                cola->inicio = actual->siguiente;
            }
            actual->prioridad = nuevaPrioridad;
            insertarOrdenado(cola, actual);

            printf("\nPrioridad del ticket con ID %d actualizada.\n-------------------------------------------\n\n", id);
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }

    printf("\nNo se encontró el ticket con ID %d.\n-------------------------------------------\n\n", id);
}

void procesarSiguienteTicket(colaPrioridad *cola) {
    if (!cola->inicio) {
        printf("\nNo hay más tickets pendientes. ¡Felicidades!\n-------------------------------------------\n\n");
        return;
    }

    Ticket *procesado = cola->inicio;
    cola->inicio = cola->inicio->siguiente;

    char horaStr[26];
    struct tm *tm_info = localtime(&(procesado->horaIngreso));
    strftime(horaStr, 26, "%Y-%m-%d %H:%M:%S", tm_info);

    printf("\nProcesando ticket:\n");
    printf("ID: %d\n", procesado->id);
    printf("Descripción: %s\n", procesado->descripcion);
    printf("Prioridad: ");
        if (procesado->prioridad == ALTO){
            printf("ALTO\n");
        }else{
            if(procesado->prioridad == MEDIO){
                printf("MEDIO\n");
            }else{
                printf("BAJO\n");
            }
        }
    printf("Hora de ingreso: %s\n", horaStr);
    printf("-------------------------------------------\n\n");

    free(procesado);
}

void buscarTicketPorID(colaPrioridad *cola, int id) {
    Ticket *actual = cola->inicio;

    while (actual) {
        if (actual->id == id) {
            char horaStr[26];
            struct tm *tm_info = localtime(&(actual->horaIngreso));
            strftime(horaStr, 26, "%Y-%m-%d %H:%M:%S", tm_info);

            printf("\nTicket encontrado:\n");
            printf("ID: %d\n", actual->id);
            printf("Descripción: %s\n", actual->descripcion);
            printf("Prioridad: ");
            if (actual->prioridad == ALTO){
                printf("ALTO\n");
            }else{
                if(actual->prioridad == MEDIO){
                    printf("MEDIO\n");
                }else{
                    ("BAJO\n");
                }
            }
            printf("Hora de ingreso: %s\n", horaStr);
            printf("-------------------------------------------\n\n");
            return;
        }
        actual = actual->siguiente;
    }

    printf("\nNo se encontró ticket con ID %d.\n-------------------------------------------\n\n", id);
}