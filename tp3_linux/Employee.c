#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/**
 * \brief crea espacio en memoria y devuelve un nuevo Employee*
 * @return retorna el empleado creado
 */
Employee* employee_new(void)
{
	return (Employee*) malloc(sizeof(Employee));
}

/**
 *\brief crea un nuevo employee con los parametros incluidos
 * @param char* Nombre recibe el nombre del empleado
 * @param char* Id
 * @param char* HorasTrabajadas
 * @param char* Sueldo
 * @return retorna el empleado creado
 */
Employee* employee_newParam(char* Nombre,char* Id,char* HorasTrabajadas,char* Sueldo)
{
	int horasAux;
	int idAux;
	int sueldoAux;

	Employee* auxemployee = employee_new();

	if(Nombre!=NULL && Id!=NULL && HorasTrabajadas!=NULL && Sueldo!=NULL)
	{
		horasAux = atoi(HorasTrabajadas);
		idAux = atoi(Id);
		sueldoAux = atoi(Sueldo);


		if(
		employee_setNombre(auxemployee,Nombre) < 0 	||
		employee_setId(auxemployee,idAux) < 0 	||
		employee_setHorasTrabajadas(auxemployee,horasAux) < 0 	||
		employee_setSueldo(auxemployee,sueldoAux) < 0)
		{
			printf("problemon");
			employee_delete(auxemployee);
			auxemployee = NULL;
		}
	}
	else
	{
		printf("\nError Validacion");
	}

	return auxemployee;
}

/**
 * \brief permite borrar un empleado
 * @param Employee* this recibe puntero al empleado
 * @return retorno 0 si pudo borrar
 */
int employee_delete(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief setea el nombre del empleado
 * @param Employee* this recibe el puntero al empleado
 * @param char* Nombre recibe el nombre a setear
 * @return int retorno 0 si pudo setear
 */
int employee_setNombre(Employee* this,char* Nombre)
{
	int retorno = -1;

	if(this != NULL && Nombre != NULL && employee_isValidNombre(Nombre))
	{
		strcpy(this->nombre,Nombre);
		retorno =0;
	}
	return retorno;
}

/**
 * \brief retorna nombre de un empleado
 * @param Employee* this recibe el puntero al empleado
 * @param int* flagError puntero a variable para indicar error
 * @return char* auxNombre valor del nombre obtenido
 */
char* employee_getNombre(Employee* this,int* flagError)
{
	*flagError = -1;
	char* auxNombre = NULL;
	if(this != NULL && flagError != NULL)
	{
		auxNombre = this->nombre;
		*flagError = 0;
	}
	return auxNombre;
}

/**
 * \brief valida si un nombre es compatible
 * @param char* Nombre nombre a comprobar
 * @return int retorno retorna 1 si pudo validar
 */
int employee_isValidNombre(char* Nombre)
{
	int retorno=-1;

	if(Nombre!=NULL)
	{
		if(utn_validarQueSeaChar(Nombre)==1)
			retorno = 1;
	}
	return retorno;
}

/**
 * \brief setea el id del empleado
 * @param Employee* this recibe el puntero al empleado
 * @param int id recibe el parametro a setear
 * @return int retorno 0 si pudo setear
 */
int employee_setId(Employee* this,int Id)
{
	int retorno = -1;
	if(this != NULL && employee_isValidId(Id))
	{
		this->id = Id;
		retorno =0;
	}
	return retorno;
}

/**
 * \brief retorna id de un empleado
 * @param Employee* this recibe el puntero al empleado
 * @param int* flagError puntero a variable para indicar error
 * @return char* auxNombre valor del parametro obtenido
 */
int employee_getId(Employee* this,int* flagError)
{
	*flagError = -1;
	int auxId = -1;
	if(this != NULL && flagError != NULL)
	{
		auxId = this->id;
		*flagError = 0;
	}
	return auxId;
}

/**
 * \brief valida si un id es compatible
 * @param int id parametro a comprobar
 * @return int retorno retorna 1 si pudo validar
 */
int employee_isValidId(int Id)
{
	int retorno=-1;

	if(utn_isValidNumber(Id)==0)
		retorno =1;
	return retorno;
}

/**
 * \brief setea las horas del empleado
 * @param Employee* this recibe el puntero al empleado
 * @param int horasTrabajadas recibe el parametro a setear
 * @return int retorno 0 si pudo setear
 */
int employee_setHorasTrabajadas(Employee* this,int HorasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && employee_isValidHorasTrabajadas(HorasTrabajadas))
	{
		this->horasTrabajadas = HorasTrabajadas;
		retorno =0;
	}
	return retorno;
}

/**
 * \brief retorna horas de un empleado
 * @param Employee* this recibe el puntero al empleado
 * @param int* flagError puntero a variable para indicar error
 * @return int  auxHorasTrabajadas valor del parametro obtenido
 */
int employee_getHorasTrabajadas(Employee* this,int* flagError)
{
	*flagError = -1;
	int auxHorasTrabajadas = -1;
	if(this != NULL && flagError != NULL)
	{
		auxHorasTrabajadas = this->horasTrabajadas;
		*flagError = 0;
	}
	return auxHorasTrabajadas;
}

/**
 * \brief valida si un HorasTrabajadas es compatible
 * @param int HorasTrabajadas parametro a comprobar
 * @return int retorno retorna 1 si pudo validar
 */
int employee_isValidHorasTrabajadas(int HorasTrabajadas)
{
	int retorno=-1;

	if(utn_isValidNumber(HorasTrabajadas)==0)
		retorno =1;
	return retorno;
}

/**
 * \brief setea  Sueldo del empleado
 * @param Employee* this recibe el puntero al empleado
 * @param int Sueldo recibe el parametro a setear
 * @return int retorno 0 si pudo setear
 */
int employee_setSueldo(Employee* this,int Sueldo)
{
	int retorno = -1;
	if(this != NULL && employee_isValidSueldo(Sueldo))
	{
		this->sueldo = Sueldo;
		retorno =0;
	}
	return retorno;
}

/**
 * \brief retorna sueldo de un empleado
 * @param Employee* this recibe el puntero al empleado
 * @param int* flagError puntero a variable para indicar error
 * @return int  auxSueldo valor del parametro obtenido
 */
int employee_getSueldo(Employee* this,int* flagError)
{
	*flagError = -1;
	int auxSueldo = -1;
	if(this != NULL && flagError != NULL)
	{
		auxSueldo = this->sueldo;
		*flagError = 0;
	}
	return auxSueldo;
}

/**
 * \brief valida si un Sueldo es compatible
 * @param int Sueldo parametro a comprobar
 * @return int retorno retorna 1 si pudo validar
 */
int employee_isValidSueldo(int Sueldo)
{
	int retorno=-1;

	if(utn_isValidNumber(Sueldo)==0)
		retorno =1;
	return retorno;
}

/**
 * \brief establece si un elemento es mas grande que el otro
 * @param pElementoUno puntero al primer elemeno
 * @param pElementoDos puntero al segundo elemento
 * @return in retorno valor que indica que elemento es mas grande
 */
int employee_criterio(void* pElementoUno, void* pElementoDos)
{
	int retorno=-1;
	Employee* pEmpleadoUno;
	Employee* pEmpleadoDos;

	char* nombreUno;
	int flagNombreUno;
	char* nombreDos;
	int flagNombreDos;

	if(pElementoUno!=NULL && pElementoDos!=NULL)
	{
		pEmpleadoUno = (Employee*)pElementoUno;
		pEmpleadoDos = (Employee*)pElementoDos;

		nombreUno = employee_getNombre(pEmpleadoUno, &flagNombreUno);
		nombreDos = employee_getNombre(pEmpleadoDos, &flagNombreDos);

		retorno = strcmp(nombreUno,nombreDos);
	}

	return retorno;
}


























