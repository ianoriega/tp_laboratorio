#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno devuelve el id maximo encontrado
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	FILE* pArchivoTexto;
	int idMaximo;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pArchivoTexto = fopen(path,"r");
		if(pArchivoTexto!=NULL)
		{
			idMaximo = parser_EmployeeFromText(pArchivoTexto, pArrayListEmployee);
			if(idMaximo >0)
			{
				fclose(pArchivoTexto);
				printf("\nDATOS IMPORTADOS");
			}
			else
			{
				printf("\nError loadFromText\n id maximo:%d",idMaximo);
				fclose(pArchivoTexto);
			}

		}

		retorno = idMaximo;
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno devuelve el id maximo encontrado
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	FILE* pArchivoTexto;
	int idMaximo;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		retorno =0;
		pArchivoTexto = fopen(path,"rb");
		if(pArchivoTexto!=NULL)
		{
			idMaximo =  parser_EmployeeFromBinary(pArchivoTexto, pArrayListEmployee);
			if(idMaximo >0)
			{
				fclose(pArchivoTexto);
				printf("\nDATOS IMPORTADOS");
			}
			else
			{
				printf("\nError loadFromText\n id maximo:%d",idMaximo);
				fclose(pArchivoTexto);
			}
		}
		retorno = idMaximo;
	}

	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \param int idMaximo recibe el idMaximo global
 * \return int retorno devuelve el id maximo generado
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int idMaximo)
{
    int retorno=-1;
    Employee* pEmpleadoAux;
    char idAux[6];
    char nombreAux[128];
    char horasAux[5];
    char sueldoAux[6];

    if(pArrayListEmployee!=NULL && idMaximo>0)
    {

    	sprintf(idAux,"%d",idMaximo+1);


     	if(utn_getCadena(nombreAux,128, "\nIngrese el nombre: ", "Error")==0 &&
    	   utn_getCadena(horasAux, 5, "\nIngrese las horas: ", "Error")==0 &&
    	   utn_getCadena(sueldoAux, 6, "\nIngrese el sueldo: ", "Error")==0    )
    	{
     		pEmpleadoAux = employee_newParam(nombreAux,idAux,horasAux,sueldoAux);
     		if(pEmpleadoAux != NULL)
     		{
    			ll_add(pArrayListEmployee, pEmpleadoAux);
    			printf("\nEMPLEADO CREADO EXITOSAMENTE");
    			retorno =atoi(idAux);
     		}
    	}

    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno devuelve 0 si salio ok
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int opcionElegida;
    int idElegido;
    int indiceModificar;
    Employee* pEmpleadoAux;
    int caseElegido;
    char nombreAux[128];
    int horasAux;
    int sueldoAux;

    if(pArrayListEmployee!=NULL)
    {
    	utn_getNumero(&opcionElegida,2,"\nDesea imprimir la lista?\n[1]SI\n[2]NO","Error",1,2,2);

    	if(opcionElegida ==1)
    	{
    		controller_ListEmployee(pArrayListEmployee);
    	}
    	utn_getNumero(&idElegido, 5, "\nIngrese el Id a modificar: ", "Error", 1, 9999, 3);

    	indiceModificar = controller_indexById(pArrayListEmployee, idElegido);
    	pEmpleadoAux =  ll_get(pArrayListEmployee, indiceModificar);

    	do
    	{
        	printf("\n\nIngrese el campo que desea modificar:");
        	printf("\n[1]Nombre\n[2]Horas trabajadas\n[3]Sueldo\n[4]Dejar de modificar");
        	utn_getNumero(&caseElegido, 2, "\n", "Error", 1, 5, 2);

        	switch(caseElegido)
        	{
    			case 1:
    				if(utn_getCadena(nombreAux, 128, "\nIngrese el nombre: ", "Error")==0)
    					if(employee_setNombre(pEmpleadoAux, nombreAux)==0)
    						printf("\nNombre modificado");
    				break;

    			case 2:
    				if(utn_getNumero(&horasAux, 5, "\nIngrese las horas", "Error", 1, 9999, 2)==0)
    					if(employee_setHorasTrabajadas(pEmpleadoAux, horasAux)==0)
    						printf("\nHoras modificadas");
    				break;

    			case 3:
    				if(utn_getNumero(&sueldoAux, 6, "\nIngrese el sueldo", "Error", 1, 99999, 2)==0)
    					if(employee_setSueldo(pEmpleadoAux, sueldoAux)==0)
    						printf("\nSueldo modificado");
    				break;
        	}

    	}while(caseElegido != 4);

    	retorno =0;
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno devuelve 0 si borro el empleado
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno =-1;
    int opcionElegida;
    int idElegido;
    int indiceBorrar;
    Employee* pEmpleadoAux;

    if(pArrayListEmployee!=NULL)
    {
    	retorno=0;
    	utn_getNumero(&opcionElegida,2,"\nDesea imprimir la lista?\n[1]SI\n[2]NO","Error",1,2,2);

		if(opcionElegida ==1)
		{
			controller_ListEmployee(pArrayListEmployee);
		}
		utn_getNumero(&idElegido, 5, "\nIngrese el Id a borrar: ", "Error", 1, 9999, 3);

		indiceBorrar = controller_indexById(pArrayListEmployee, idElegido);
		pEmpleadoAux =  ll_get(pArrayListEmployee, indiceBorrar);

		if(pEmpleadoAux!=NULL)
		{
			if(employee_delete(pEmpleadoAux)==0)
			{
				ll_remove(pArrayListEmployee, indiceBorrar);
				printf("\nEMPLEADO BORRADO");
				retorno=0;
			}
		}
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno 0 si valido parametros
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	int i;
	Employee* pEmpleadoAux;
	int idAux;
	int flagId;
	char* nombreAux;
	int flagNombre;
	int horasAux;
	int flagHoras;
	int sueldoAux;
	int flagSueldo;

	if(pArrayListEmployee!=NULL)
	{
		printf("\n-Id    - Nombre          - HsTrabajdas - Sueldo");

		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			pEmpleadoAux = ll_get(pArrayListEmployee, i);
			idAux = employee_getId(pEmpleadoAux, &flagId);
			nombreAux = employee_getNombre(pEmpleadoAux, &flagNombre);
			horasAux = employee_getHorasTrabajadas(pEmpleadoAux, &flagHoras);
			sueldoAux = employee_getSueldo(pEmpleadoAux, &flagSueldo);

			if(flagId!=-1 && flagNombre!=-1 && flagHoras!=-1 && flagSueldo!=-1)
			{
				printf("\n-%-4d  - %-15s - %-12d- %d",idAux,nombreAux,horasAux,sueldoAux);
			}

		}
		retorno =0;
	}

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno 0 si pudo procesar
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int opcionElegida;
	int order;


	if(pArrayListEmployee!=NULL)
	{
		retorno =0;
		printf("\nSeleccione la opcion deseada:\nOrdenar de:");
		utn_getNumero(&opcionElegida,2,"\nMayor a Menor[1]\nMenor a Mayor[2]","Error",1,2,2);

		switch(opcionElegida)
		{
			case 1:
				order = 2;
				break;
			case 2:
				order = 1;
				break;
		}
		printf("\n\nESPERE: INTERCAMBIANDO POSICIONES...\n");

		if(controller_sort(pArrayListEmployee, order)==0)
		{
			printf("\nPROCESO FINALIZADO\n");
			retorno=0;
		}

	}

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno 0 si pudo salvar
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	FILE* pArchivo;
	Employee* pAuxEmpleado;
	int idAux;
	int flagId;
	char* nombreAux;
	int flagNombre;
	int horasAux;
	int flagHoras;
	int sueldoAux;
	int flagSueldo;


	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pArchivo = fopen(path,"w");
		if(pArchivo != NULL)
		{
			fprintf(pArchivo,"Id,Nombre,Horas Trabajadas,Sueldo\n");
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				pAuxEmpleado = ll_get(pArrayListEmployee, i);
				idAux = employee_getId(pAuxEmpleado, &flagId);
				nombreAux = employee_getNombre(pAuxEmpleado, &flagNombre);
				horasAux = employee_getHorasTrabajadas(pAuxEmpleado, &flagHoras);
				sueldoAux = employee_getSueldo(pAuxEmpleado, &flagSueldo);

				if(flagId!=-1 && flagNombre!=-1 && flagHoras!=-1 && flagSueldo!=-1)
				{
					fprintf(pArchivo,"%d,%s,%d,%d\n",idAux,nombreAux,horasAux,sueldoAux);
				}

			}

			printf("\nDATOS GUARDADOS MODO TEXTO");
			fclose(pArchivo);
			retorno =0;
		}
	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno 0 si pudo salvar
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
   int retorno =-1;
   int i;
   FILE* pArchivo;
   Employee* pAuxEmpleado;
   if(path!=NULL && pArrayListEmployee!=NULL)
   {
	   pArchivo = fopen(path,"w+");
	   if(pArchivo != NULL)
	   {
		   for(i=0;i<ll_len(pArrayListEmployee);i++)
		   {
			   pAuxEmpleado = ll_get(pArrayListEmployee, i);
			   fwrite(pAuxEmpleado,sizeof(Employee),1,pArchivo);
		   }
	   }
	   printf("\n DATOS GUARDADOS EN MODO BINARIO");
	   fclose(pArchivo);
	   retorno =0;
   }


   return retorno;
}

/**
 * \brief Imprime el Menu de opciones
 */
void controller_imprimirMenu(void)
{
	printf("\n");
	printf("\n Menu:");
	printf("\n	1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
	printf("\n	2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
	printf("\n	3. Alta de empleado");
	printf("\n	4. Modificar datos de empleado");
	printf("\n	5. Baja de empleado");
	printf("\n	6. Listar empleados");
	printf("\n	7. Ordenar empleados");
	printf("\n	8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
	printf("\n	9. Guardar los datos de los empleados en el archivo data.csv (modo binario).");
	printf("\n 	10. Salir");
	printf("\n");
}

/**
 * \brief encuentra el indice a partir del id del elemento
 * @param pArrayListEmployee recibe linkedList
 * @param int id recibe el id a buscar
 * @return int retorno devuelve la posicion buscada
 */
int controller_indexById(LinkedList* pArrayListEmployee, int id)
{
	int retorno=-1;
	Employee* pAuxEmpleado;
	int i;

	if(pArrayListEmployee!=NULL && id>0)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			pAuxEmpleado = ll_get(pArrayListEmployee, i);

			if(controller_compararId(pAuxEmpleado, id)==1)
			{
				retorno =i;
				break;
			}
		}
	}

	return retorno;
}

/**
 * \brief compara un id con el id de un elemento
 * @param Employee* this recibe puntero al elemento employee
 * @param int idBuscado recibe el id del elemento buscado
 * @return int retorno devuelve 1 si conicide el elemento, de lo contrario 0
 */
int controller_compararId(Employee* this,int idBuscado)
{
	int retorno =-1;
	int idAux;
	int flagId;

	if(this!=NULL && idBuscado>0)
	{
		idAux = employee_getId(this, &flagId);
		if(idAux == idBuscado && !flagId)
		{
			retorno =1;
		}
		else
		{
			retorno =0;
		}
	}

	return retorno;
}

/**
 * \brief ordena los elementos de la linkedList
 * @param LinkedList* this recibe linkedList
 * @param int order recibe el orden de ordenamiento
 * @return int retorno retorna 0 si pudo procesar datos
 */
int controller_sort(LinkedList* this,int order)
{
	int retorno =-1;
	char* nombreUno;
	int flagUno;
	char* nombreDos;
	int flagDos;
	int i;
	Employee* pElementoUno;
	Employee* pElementoDos;
	int flagSwap;


	if(this!=NULL && order>=0)
	{
		retorno=0;
		do
		{
			flagSwap =0;

			for(i=0;i<ll_len(this);i++)
			{
				pElementoUno = ll_get(this, i);
				pElementoDos = ll_get(this, i+1);

				nombreUno = employee_getNombre(pElementoUno, &flagUno);
				nombreDos = employee_getNombre(pElementoDos, &flagDos);

				if(utn_charMayorMenor(nombreUno, strlen(nombreUno), nombreDos) == order)
				{

					controller_intercambiarNodos(this, i);
					flagSwap = 1;
				}
			}

		}while(flagSwap);

	}

	return retorno;
}

/**
 * \brief intercambia la posicion de un nodo con la del siguiente
 * @param LinkedList* this recibe la linkedlist
 * @param int position recibe la posicion de un nodo para intercambiar
 * @return int retorno 0 si pudo procesar
 */
int controller_intercambiarNodos(LinkedList* this,int position)
{
	int retorno =-1;
	Node* pNodoActual;
	Node* pNodoSiguiente;
	void* pBuffer;

	int i=0;


	if(this!=NULL && position>=0)
	{
		do
		{
			if(i==0)
			{
				pNodoActual = this->pFirstNode;
				pNodoSiguiente  = pNodoActual->pNextNode;
				if(position==0)
				{
					break;
				}
			}
			else
			{
				pNodoActual = pNodoSiguiente;
				pNodoSiguiente = pNodoActual->pNextNode;
			}

			i++;
		}while(i <= position);

		pBuffer = pNodoSiguiente->pElement;
		pNodoSiguiente->pElement = pNodoActual->pElement;
		pNodoActual->pElement = pBuffer;

		retorno=0;
	}

	return retorno;
}

































