#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H

#include "estructuras.h"

colaPrioridad *crearColaPrioridad();
void registrarTicket(colaPrioridad *cola, int id, char *descripcion);
void mostrarTickets(colaPrioridad *cola);
void modificarPrioridad(colaPrioridad *cola, int id, int nuevaPrioridad);
void procesarSiguienteTicket(colaPrioridad *cola);
void buscarTicketPorID(colaPrioridad *cola, int id);

#endif /* COLAPRIORIDAD_H */
