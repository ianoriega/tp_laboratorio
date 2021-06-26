 #include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno devuelve idMaximo encontrado
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	char nombreAux[256];
	char idAux[256];
	char horasAux[256];
	char sueldoAux[256];
	Employee* pEmpleado;
	int idMaximo;
	int idAuxInt;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		i=0;

		ll_clear(pArrayListEmployee);

		do
		{

			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasAux,sueldoAux)==4)
			{

				if(i>0)
				{

					pEmpleado = employee_newParam(nombreAux, idAux, horasAux, sueldoAux);


					if(pEmpleado!=NULL)
					{

						ll_add(pArrayListEmployee, pEmpleado);

						idAuxInt = atoi(idAux);
						if(i==1)
						{
							idMaximo = idAuxInt;
						}
						else if(idMaximo < idAuxInt)
						{
							idMaximo = idAuxInt;
						}
					}
					else
					{
						printf("\nError");
						employee_delete(pEmpleado);
					}

				}
			}
			i++;

		}while(feof(pFile)==0);

		retorno = idMaximo;
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 *  \return int retorno devuelve idMaximo encontrado
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	Employee* pEmpleado;
	int flagId;
	int idEmpleado;
	int idMaximo;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		ll_clear(pArrayListEmployee);
		i=0;
		do
		{
			pEmpleado = employee_new();
			if(fread(pEmpleado,sizeof(Employee),1,pFile)==1)
			{

				ll_add(pArrayListEmployee,pEmpleado);
				idEmpleado = employee_getId(pEmpleado, &flagId);

				if(flagId ==0)
				{
					if(i==0)
					{
						idMaximo = idEmpleado;
					}
					else if(idMaximo < idEmpleado)
					{
						idMaximo = idEmpleado;
					}
				}

				i++;
			}
			else
			{
				employee_delete(pEmpleado);
				break;
			}


		}while(feof(pFile)==0);

		retorno = idMaximo;
	}
    return retorno;
}
























