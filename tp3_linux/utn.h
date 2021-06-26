
#ifndef UTN_H_
#define UTN_H_

/**
 * \brief recibe una cadena de caracteres ingresada por el usuario
 * \param char cadenaRecibida[] puntero a array para cargar la cadena ingresada
 * \param int limite limite de caracteres de la cadena a recibir
 * \param char* pTexto puntero que recibe el mensaje a mostrar
 * \param char* pError puntero que recibe el mensaje de error

 * \return int retorno -1 si no pudo validar y 0 si valido correctamente
 */
int utn_getCadena(char cadenaRecibida[], int limite, char* pTexto, char* pError);

/*
 * getNumero: le pide numeros al usuario con reintentos
 *
 */
int utn_getNumero(int* numeroObtenido,int limite, char* pTexto,char* pError,int minimo,int maximo,int reintento);

/*
 * getChar: le pide carcteres al usuario
 */
int utn_getString(char pAuxChar[],int limite,char* pTexto,char* pError,int reintento);

/*
 * getFloat: le pide un numero float al usuario
 */
int utn_getFloat(float* numeroObtenido,int limite, char* pTexto,char* pError,float minimo,float maximo,int reintento);

/**
 *\brief genera un numero random entre un minimo y un maximo
 * @param minimo
 * @param maximo
 * @return -1 si no pudo validar o bien numero generado
 */
int utn_getRandomNumber(int minimo, int maximo);


/*
 * valida que la cadena ingresada tenga numeros
 */
int utn_validarQueSeaNumero(char texto[]);

/*
 * valida que la cadena sea de char
 */
int utn_validarQueSeaChar(char texto[]);



int utn_validarQueSeaFloat(char texto[]);

/**
 * \brief Recibe un string y lo valida como Nombre
 * \param char array[] recibe la cadena de caracteres
 * \return retorna -1 si no pudo validar y 0 si pudo validar
 */
int utn_isValidName(char array[]);


/**
 *\brief verifica que un string sea un CUIT
 *\param char arra[] recibe la cadena
 *\param int lenght recibe el tamaño de la cadena
 *\return retorno devuelve 1 si valido
 */
int utn_esCuitValido(char array[], int lenght);

/**
 * \brief pide al usuario que ingrese su cuit
 */
int utn_getCUIT(char cadenaRecibida[], int limite, char* pTexto, char* pError);

/**
 * \brief Recibe un string y lo valida como DNI
 * \param char array[] recibe la cadena de caracteres
 * \return retorna -1 si no pudo validar y 0 si pudo validar

int utn_isValidDni(char array[]);
 */

/**
 *\brief Genera un id aleatorio no repetido
 *\param int array[] recibe el array
 *\param  int indiceArray recibe la posicion donde asignar el id
 *\param  int limite recibe el limite del array
 *\param  int minimo recibe el valor minimo del id
 *\param  int maximo recibe el valor maximo del id
 *\return retorno 0 si valido y -1 si no valido
 */
int utn_randomId(int array[], int indiceArray, int limite, int minimo, int maximo);


/**
 *\brief compra dos cadenas y determina la mayor alfabeticamente o su igualdad
 *\param char* cadenaUno recibe la cadena uno
 *\param int len recibe el limite de la cadena uno
 *\param char* cadenaDos recibe el limite de la cadena dos
 *\return retorno -1 si no pudo validar parametros
 * 				   1 si la cadena uno es mayor
 * 				   2 si la cadena dos es mayor
 * 				   0 si son iguales
 */
int utn_charMayorMenor(char* cadenaUno, int len, char* cadenaDos);

/**
 * \brief verifica que un numero sea un numero
 * @param this
 * @return
 */
int utn_isValidNumber(int this);

#endif /* UTN_H_ */
