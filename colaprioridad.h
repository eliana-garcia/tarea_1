#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H
#include "estructuras.h"

colaPrioridad *crearColaPrioridad();

void registrarTicket(ColaPrioridad *cola, int id, char *descripcion);

void mostrarTickets(ColaPrioridad *cola);

#endif /* COLAPRIORIDAD_H */
