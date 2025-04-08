#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colaprioridad.h"

colaPrioridad *crearColaPrioridad(){
    colaPrioridad *cola  = (colaPrioridad * )malloc(sizeof(colaPrioridad));
    cola->inicio = NULL;
    return cola;
}

void registrarTicket(colaPrioridad *cola, int id, char *descripcion){
    Ticket * nuevoTicket = (Ticket*)malloc(sizeof(Ticket));
    nuevoTicket->id = id;
    strcpy(nuevoTicket->descripcion, descripcion);
    nuevoTicket->prioridad = BAJO;
    nuevoTicket->siguiente = NULL;

    if (cola->inicio == NULL){
        cola->inicio = nuevoTicket;
    }else{
        Ticket *temporal = cola->inicio;
        while(temporal->siguiente != NULL){
            temporal = temporal->siguiente;
        }
        temporal->siguiente = nuevoTicket;
    }
    printf("El ticket fue registrado con éxito\n");
}

void mostrarTickets(colaPrioridad *cola){

}

void modificarPrioridad(colaPrioridad *cola, int id, int nuevaPrioridad){

}

void procesarSiguienteTicket(colaPrioridad *cola){
    if(cola->inicio == NULL){
        printf("Ya no hay mas tickets pendientes, por lo que ya terminaste tu trabajo\n");
        printf("ahora a tener un merecido descanso\n");
        printf("¡¡ FELICIDADES !!");
        return;
    }
    Ticket *ticketprocesado = cola->inicio;
    cola->inicio = cola->inicio->siguiente;
    printf("Ticket ingresado:\n");
    printf("ID: %d\n", ticketprocesado->id);
    printf("Descripcion: %s\n",ticketprocesado->descripcion);
    printf("Prioridad: ");
    if (ticketprocesado->prioridad == ALTO){
        printf("ALTO\n");
    }else {
        if(ticketprocesado->prioridad == MEDIO){
            printf("MEDIO\n");
        }else {
            printf("BAJO\n");
        }
    }
    free(ticketprocesado);
}

void buscarTicketPorID(colaPrioridad *cola, int id){

}

