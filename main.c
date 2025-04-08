#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "colaprioridad.h"

void mostrarMenu(){
    printf ("Sistema de gestión de tickets\n");
    printf ("1. Registrar ticket\n");
    printf ("2. Tickets pendientes\n");
    printf ("3. Salir\n");
    printf ("Seleccione una opción:  ");
}

int main(){
    colaPrioridad *cola = crearColaPrioridad();
    int opcion;
    
    do{
        mostrarMenu();
        scanf("%d",&opcion);
        getchar();

        switch(opcion){
            case 1 : {
                int id;
                char descripcion[1000];

                printf("Ingrese el ID del ticket: ");
                scanf("%d", &id);;
                getchar();

                printf("Ingrese descripcion del problema: ");
                scanf("%[^\n]", descripcion);
                registrarTicket(cola,id,descripcion);
                break;
            }
            case 2 :{
                mostrarTickets(cola);
                break;
            }
            case 3:{
                printf("TERMINANDO PROGRAMA \n");
                break;
            }
            default:{
                printf("La opcion ingresada no es valida\n");
                printf("INTENTE NUEVAMENTE\n")
            }
        } while (opcion != 3);
        return 0;
    }

}