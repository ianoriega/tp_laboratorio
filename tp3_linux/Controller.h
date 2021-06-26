#include "Employee.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno devuelve el id maximo encontrado
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno devuelve el id maximo encontrado
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \param int idMaximo recibe el idMaximo global
 * \return int retorno devuelve el id maximo generado
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int idMaximo);

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno devuelve 0 si salio ok
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno devuelve 0 si borro el empleado
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno 0 si valido parametros
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno 0 si pudo procesar
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno 0 si pudo salvar
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorno 0 si pudo salvar
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);



/**
 * \brief Imprime el Menu de opciones
 */
void controller_imprimirMenu(void);

/**
 * \brief encuentra el indice a partir del id del elemento
 * @param pArrayListEmployee recibe linkedList
 * @param int id recibe el id a buscar
 * @return int retorno devuelve la posicion buscada
 */
int controller_indexById(LinkedList* pArrayListEmployee, int id);

/**
 * \brief compara un id con el id de un elemento
 * @param Employee* this recibe puntero al elemento employee
 * @param int idBuscado recibe el id del elemento buscado
 * @return int retorno devuelve 1 si conicide el elemento, de lo contrario 0
 */
int controller_compararId(Employee* this,int idBuscado);

/**
 * \brief ordena los elementos de la linkedList
 * @param LinkedList* this recibe linkedList
 * @param int order recibe el orden de ordenamiento
 * @return int retorno retorna 0 si pudo procesar datos
 */
int controller_sort(LinkedList* this,int order);

/**
 * \brief intercambia la posicion de un nodo con la del siguiente
 * @param LinkedList* this recibe la linkedlist
 * @param int position recibe la posicion de un nodo para intercambiar
 * @return int retorno 0 si pudo procesar
 */
int controller_intercambiarNodos(LinkedList* this,int position);
