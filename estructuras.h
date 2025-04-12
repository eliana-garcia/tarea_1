#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include <time.h>
// definimos la prioridad de los tickets como constantes 
#define BAJO 0
#define MEDIO 1
#define ALTO 2
// definimos la estructura de un ticket
typedef struct Ticket {
    int id;
    char descripcion[100];
    int prioridad;
    time_t horaIngreso;
    struct Ticket *siguiente;
} Ticket;
//estructura de la cola de prioridad 
typedef struct colaPrioridad {
    Ticket *inicio;
} colaPrioridad;

#endif /* ESTRUCTURAS_H */