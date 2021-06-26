#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/**
 * \brief crea espacio en memoria y devuelve un nuevo Employee*
 * @return retorna el empleado creado
 */
Employee* employee_new(void);

/**
 *\brief crea un nuevo employee con los parametros incluidos
 * @param char* Nombre recibe el nombre del empleado
 * @param char* Id
 * @param char* HorasTrabajadas
 * @param char* Sueldo
 * @return retorna el empleado creado
 */
Employee* employee_newParam(char* Nombre,char* Id,char* HorasTrabajadas,char* Sueldo);

/**
 * \brief permite borrar un empleado
 * @param Employee* this recibe puntero al empleado
 * @return retorno 0 si pudo borrar
 */
int employee_delete(Employee* this);

/**
 * \brief setea el nombre del empleado
 * @param Employee* this recibe el puntero al empleado
 * @param char* Nombre recibe el nombre a setear
 * @return int retorno 0 si pudo setear
 */
int employee_setNombre(Employee* this,char* Nombre);

/**
 * \brief retorna nombre de un empleado
 * @param Employee* this recibe el puntero al empleado
 * @param int* flagError puntero a variable para indicar error
 * @return char* auxNombre valor del nombre obtenido
 */
char* employee_getNombre(Employee* this,int* flagError);

/**
 * \brief valida si un nombre es compatible
 * @param char* Nombre nombre a comprobar
 * @return int retorno retorna 1 si pudo validar
 */
int employee_isValidNombre(char* Nombre);

/**
 * \brief setea el id del empleado
 * @param Employee* this recibe el puntero al empleado
 * @param int id recibe el parametro a setear
 * @return int retorno 0 si pudo setear
 */
int employee_setId(Employee* this,int Id);

/**
 * \brief retorna id de un empleado
 * @param Employee* this recibe el puntero al empleado
 * @param int* flagError puntero a variable para indicar error
 * @return int id valor del parametro obtenido
 */
int	employee_getId(Employee* this,int* flagError);

/**
 * \brief valida si un id es compatible
 * @param int id parametro a comprobar
 * @return int retorno retorna 1 si pudo validar
 */
int employee_isValidId(int Id);

/**
 * \brief setea las horas del empleado
 * @param Employee* this recibe el puntero al empleado
 * @param int horasTrabajadas recibe el parametro a setear
 * @return int retorno 0 si pudo setear
 */
int employee_setHorasTrabajadas(Employee* this,int HorasTrabajadas);

/**
 * \brief retorna horas de un empleado
 * @param Employee* this recibe el puntero al empleado
 * @param int* flagError puntero a variable para indicar error
 * @return int  auxHorasTrabajadas valor del parametro obtenido
 */
int	employee_getHorasTrabajadas(Employee* this,int* flagError);

/**
 * \brief valida si un HorasTrabajadas es compatible
 * @param int HorasTrabajadas parametro a comprobar
 * @return int retorno retorna 1 si pudo validar
 */
int employee_isValidHorasTrabajadas(int HorasTrabajadas);

/**
 * \brief setea  Sueldo del empleado
 * @param Employee* this recibe el puntero al empleado
 * @param int Sueldo recibe el parametro a setear
 * @return int retorno 0 si pudo setear
 */
int employee_setSueldo(Employee* this,int Sueldo);

/**
 * \brief retorna sueldo de un empleado
 * @param Employee* this recibe el puntero al empleado
 * @param int* flagError puntero a variable para indicar error
 * @return int  auxSueldo valor del parametro obtenido
 */
int	employee_getSueldo(Employee* this,int* flagError);

/**
 * \brief valida si un Sueldo es compatible
 * @param int Sueldo parametro a comprobar
 * @return int retorno retorna 1 si pudo validar
 */
int employee_isValidSueldo(int Sueldo);

/**
 * \brief establece si un elemento es mas grande que el otro
 * @param pElementoUno puntero al primer elemeno
 * @param pElementoDos puntero al segundo elemento
 * @return in retorno valor que indica que elemento es mas grande
 */
int employee_criterio(void* pElementoUno, void* pElementoDos);



#endif // employee_H_INCLUDED
