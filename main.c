#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colaprioridad.h"

// Función para mostrar el menú de opciones
void mostrarMenu() {
    printf("Sistema de gestión de tickets\n");
    printf("1. Registrar ticket\n");
    printf("2. Modificar prioridad de ticket\n");
    printf("3. Mostrar tickets pendientes\n");
    printf("4. Procesar siguiente ticket\n");
    printf("5. Buscar ticket por ID\n");
    printf("6. Salir\n");
    printf("Seleccione una opción: ");
}
int main() {
    colaPrioridad *cola = crearColaPrioridad();
    int opcion;

    do {
        mostrarMenu();
        scanf("%d", &opcion);
        getchar();  

        switch (opcion) {
            case 1: {
                int id;
                char descripcion[1000];
                printf("Ingrese el ID del ticket: ");
                scanf("%d", &id);
                getchar();  

                printf("Ingrese descripción del problema: ");
                scanf("%[^\n]", descripcion);
                registrarTicket(cola, id, descripcion);
                break;
            }
            case 2: {
                int id;
                int prioridad;
                printf("Ingrese el ID del ticket a modificar: ");
                scanf("%d", &id);
                printf("Ingrese la nueva prioridad (0 = Bajo, 1 = Medio, 2 = Alto): ");
                scanf("%d", &prioridad);
                if (prioridad < 0 || prioridad > 2) {
                    printf("Prioridad no válida.\n");
                } else {
                    modificarPrioridad(cola, id, prioridad);
                }
                break;
            }
            case 3: {
                mostrarTickets(cola);
                break;
            }
            case 4: {
                procesarSiguienteTicket(cola);
                break;
            }
            case 5: {
                int id;
                printf("Ingrese el ID del ticket: ");
                scanf("%d", &id);
                buscarTicketPorID(cola, id);
                break;
            }
            case 6: {
                printf("Programa terminado\n");
                break;
            }
            default: {
                printf("La opcion ingresada no es valida\n");
                printf("INTENTE NUEVAMENTE\n");
                break;
            }
        }
    } while (opcion != 6);

    return 0;
}