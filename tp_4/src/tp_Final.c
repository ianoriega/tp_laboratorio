#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

#define RUTA_ARCHIVO "/home/inaki/eclipse-workspace/tp_Final/src/data.csv"


int main(void)
{
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    int idMaximo;

    do{

    	controller_imprimirMenu();

    	utn_getNumero(&option, 3, "\nIngrese la opcion deseada", "Error", 1, 10, 2);

        switch(option)
        {
            case 1:
				idMaximo = controller_loadFromText(RUTA_ARCHIVO,listaEmpleados);
            	break;
            case 2:
               	idMaximo = controller_loadFromBinary(RUTA_ARCHIVO, listaEmpleados);
            	break;
            case 3:
            	idMaximo = controller_addEmployee(listaEmpleados, idMaximo);
               	break;
            case 4:
            	controller_editEmployee(listaEmpleados);
                break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
             	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
                break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
            	break;
            case 8:
            	controller_saveAsText(RUTA_ARCHIVO, listaEmpleados);
               	break;
            case 9:
            	controller_saveAsBinary(RUTA_ARCHIVO, listaEmpleados);
                break;
        }

    }while(option != 10);

    ll_deleteLinkedList(listaEmpleados);

    printf("Gracias por utilizar la aplicacion!!!");
    return 0;
}










