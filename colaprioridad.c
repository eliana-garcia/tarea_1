#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "colaprioridad.h"

// crea una nueva cola de prioridad
colaPrioridad *crearColaPrioridad() {
    // reserva memoria para la cola de prioridad
    colaPrioridad *cola = (colaPrioridad *)malloc(sizeof(colaPrioridad));
    // dejamos el puntero inicio en nulo para indicar que la cola está vacia
    cola->inicio = NULL;
    // retornamos la cola creada
    return cola;
}

// incerta un ticket en la cola de prioridad mantenirdo el orden por prioridad y hora de ingreso
void insertarOrdenado(colaPrioridad *cola, Ticket *nuevo) {
    // si la cola está vacia o el nuevo ticket tiene mayor prioridad que el primero 
    // o igual prioridad pero ingreso antes, la insertamos al inicio
    if (!cola->inicio || nuevo->prioridad > cola->inicio->prioridad ||
       (nuevo->prioridad == cola->inicio->prioridad && nuevo->horaIngreso < cola->inicio->horaIngreso)) {
        nuevo->siguiente = cola->inicio;
        cola->inicio = nuevo;
        return;
    }
    // buscamos el lugar correcto para insertar el nuevo ticket
    Ticket *actual = cola->inicio;
    while (actual->siguiente &&
           (actual->siguiente->prioridad > nuevo->prioridad ||
           (actual->siguiente->prioridad == nuevo->prioridad &&
            actual->siguiente->horaIngreso <= nuevo->horaIngreso))) {
        actual = actual->siguiente;
    }
    // insertamos el nuevo ticket en la posición correcta
    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
}

// Crea un nuevo ticket y la insertamos en la cola de prioridad baja por defecto
void registrarTicket(colaPrioridad *cola, int id, char *descripcion) {
    // reservamos memoria para el nuevo ticket
    Ticket *nuevo = (Ticket *)malloc(sizeof(Ticket));
    // asignamos los datos al ticket
    nuevo->id = id;
    strcpy(nuevo->descripcion, descripcion);
    nuevo->prioridad = BAJO; //parten con prioridad baja
    nuevo->horaIngreso = time(NULL);//guardamos la hora actula de ingreso
    nuevo->siguiente = NULL;
    
    // insertamos el ticket en la cola de prioridad 
    insertarOrdenado(cola, nuevo);

    // mostrar mensaje de exito
    printf("\nTicket registrado con éxito.\n");
    printf("-------------------------------------------\n\n");
}

// muestra todos los tickets en la cola 
void mostrarTickets(colaPrioridad *cola) {
    //si no hay tickets en la cola mostramos un mensaje y retornamos
    if (!cola->inicio) {
        printf("\nNo hay tickets pendientes.");
        printf("\n-------------------------------------------\n\n");
        return;
    }
    Ticket *actual = cola->inicio;
    printf("\nTickets pendientes:\n");
    // recorremos la cola de tickets y mostramos los datos de cada ticket
    while (actual) {
        char horaStr[26];
        struct tm *tm_info = localtime(&(actual->horaIngreso));
        strftime(horaStr, 26, "%Y-%m-%d %H:%M:%S", tm_info); //convertimos la hora a un formato legible
        printf("ID: %d\n", actual->id);
        printf("Descripción: %s\n", actual->descripcion);
        // mostramos la prioridad del ticket
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

// cambia la prioridad de un ticket segun el ID en la cola de prioridad
void modificarPrioridad(colaPrioridad *cola, int id, int nuevaPrioridad) {
    Ticket *anterior = NULL;
    Ticket *actual = cola->inicio;
    //buscamos el ticket por el ID en la cola de prioridad
    while (actual) {
        if (actual->id == id) {
            // lo encontramos lo sacamos de la cola
            if (anterior){
                anterior->siguiente = actual->siguiente;
            } else {
                cola->inicio = actual->siguiente;
            }
            // le cambiamos la prioridad 
            actual->prioridad = nuevaPrioridad;
            // lo insertamos de nuevo en la cola otra vez
            insertarOrdenado(cola, actual);
            printf("\nPrioridad del ticket con ID %d actualizada.", id);
            printf("\n-------------------------------------------\n\n");
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    // si no lo encontramos mostramos un mensaje
    printf("\nNo se encontró el ticket con ID %d.", id);
    printf("\n-------------------------------------------\n\n");
}

// procesa el ticket mas urgente de la cola (el primero)
void procesarSiguienteTicket(colaPrioridad *cola) {
    // si no hay tickets en la cola mostramos un mensaje y retornamos
    if (!cola->inicio) {
        printf("\nNo hay más tickets pendientes. ¡Felicidades!\n");
        printf("-------------------------------------------\n\n");
        return;
    }
    //tomamos el ticket mas urgente (el primero) 
    Ticket *procesado = cola->inicio;
    cola->inicio = cola->inicio->siguiente;//lo sacamos de la cola
    // arregamos la hora de ingreso para que sea mas legible
    char horaStr[26];
    struct tm *tm_info = localtime(&(procesado->horaIngreso));
    strftime(horaStr, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    //mostramos los datos del ticket procesado
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
    // liberamos la menoria del ticket procesado
    free(procesado);
}

// buscamos un ticket por su ID y lo mostramos
void buscarTicketPorID(colaPrioridad *cola, int id) {
    Ticket *actual = cola->inicio;
    // recorremos la cola de tickets por el ID
    while (actual) {
        if (actual->id == id) {
            //si lo encontramos mostramos su informacion
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
    // si no lo encontramos mostramos un mensaje
    printf("\nNo se encontró ticket con ID %d.",id);
    printf("\n-------------------------------------------\n\n");
}