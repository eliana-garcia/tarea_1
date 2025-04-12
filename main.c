#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colaprioridad.h"
//mostramos el menu de opciones al usuario
void mostrarMenu() {
    printf("Sistema de Gestión de Tickets\n");
    printf("1. Registrar ticket\n");
    printf("2. Modificar prioridad de ticket\n");
    printf("3. Mostrar tickets pendientes\n");
    printf("4. Procesar siguiente ticket\n");
    printf("5. Buscar ticket por ID\n");
    printf("6. Salir\n");
    printf("-------------------------------------------\n\n");
    printf("Seleccione una opción: ");
}
int main() {
    //creamos la cola de prioridad
    colaPrioridad *cola = crearColaPrioridad();
    int opcion;
    //bucle para mostrar el menu y recibir la opcion del usuario
    do {
        mostrarMenu();
        scanf("%d", &opcion);//leemos opcion del usuario
        getchar();//limpiamos el buffer
        switch (opcion) {
            case 1: {
                int id;
                char descripcion[1000];
                //registramos un ticket
                printf("Ingrese el ID del ticket: ");
                scanf("%d", &id);
                getchar();
                printf("Ingrese descripción del problema: ");
                scanf("%[^\n]", descripcion);//leemos toda la linea hasta saltar la linea
                registrarTicket(cola, id, descripcion);
                break;
            }
            case 2: {
                int id, prioridad;
                //modificamos la prioridad de un ticket
                printf("Ingrese el ID del ticket a modificar: ");
                scanf("%d", &id);
                printf("Ingrese la nueva prioridad (0 = Bajo, 1 = Medio, 2 = Alto): ");
                scanf("%d", &prioridad);
                if (prioridad < 0 || prioridad > 2) {
                    printf("Prioridad no válida.\n");
                    printf("-------------------------------------------\n\n");
                } else {
                    modificarPrioridad(cola, id, prioridad);
                }
                break;
            }
            case 3:
                // mostramos los tickets pendientes 
                mostrarTickets(cola);
                break;
            case 4:
                //procesamos el siguiente ticket
                procesarSiguienteTicket(cola);
                break;
            case 5: {
                int id;
                //buscamos un ticket por ID
                printf("Ingrese el ID del ticket: ");
                scanf("%d", &id);
                buscarTicketPorID(cola, id);
                break;
            }
            case 6:
                //salimos del programa
                printf("\nPrograma terminado.\n");
                break;
            default:
                // si la opcion no es valida mostramos un mensaje de error
                printf("\nOpción inválida. Intente nuevamente.\n");
                printf("-------------------------------------------\n\n");
        }
    } while (opcion != 6);

    return 0;
}