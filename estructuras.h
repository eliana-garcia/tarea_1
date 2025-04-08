#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#define BAJO 0
#define MEDIO 1
#define ALTO 2

typedef struct Ticket {
    int id;
    char descripcion[100];
    int prioridad; 
    struct Ticket *siguiente;
} Ticket;

typedef struct colaPrioridad {
    Ticket *inicio;
} colaPrioridad;

#endif /* ESTRUCTURAS_H */