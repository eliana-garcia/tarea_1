#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H


typedef struct Ticket {
    int id;
    char descrpcio[100];
    struct Ticket *siguiente;
}Ticket;

typedef struct colaPrioridad{
    Ticket *inicio;
}colaPrioridad;

#endif /* ESTRUCTURAS_H */