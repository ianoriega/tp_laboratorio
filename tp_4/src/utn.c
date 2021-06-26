
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "arr.h"
#include "ctype.h"

/**
 * \brief recibe una cadena de caracteres ingresada por el usuario
 * \param char cadenaRecibida[] puntero a array para cargar la cadena ingresada
 * \param int limite limite de caracteres de la cadena a recibir
 * \param char* pTexto puntero que recibe el mensaje a mostrar
 * \param char* pError puntero que recibe el mensaje de error

 * \return int retorno -1 si no pudo validar y 0 si valido correctamente
 */
int utn_getCadena(char cadenaRecibida[], int limite, char* pTexto, char* pError)
{
	int retorno =-1;

	if(cadenaRecibida !=NULL && limite >=0)
	{
		retorno =0;

		printf("%s", pTexto);

		__fpurge(stdin);
		fgets(cadenaRecibida,limite,stdin);
		if(cadenaRecibida[strlen(cadenaRecibida)-1]==10)
		{
			cadenaRecibida[strlen(cadenaRecibida)-1] = 0;
		}

	}

	return retorno;
}


int utn_getNumero(int* numeroObtenido,int limite, char* pTexto,char* pError,int minimo,int maximo,int reintento)
{
	int retorno = -1;
	char bufferNumeros[limite];
	int bufferInt;

	if(numeroObtenido != NULL && pTexto != NULL && pError != NULL && minimo <= maximo && reintento >= 0)
	{
		retorno = -2;

		do
		{
			printf("%s", pTexto);
			__fpurge(stdin);
			fgets(bufferNumeros,limite,stdin);

			if(bufferNumeros[strlen(bufferNumeros)-1]==10)
			{
				bufferNumeros[strlen(bufferNumeros)-1] = 0;
			}

			if(utn_validarQueSeaNumero(bufferNumeros)==1)
			{
				bufferInt = atoi(bufferNumeros);

				if(bufferInt <= maximo && bufferInt >= minimo)
				{
					*numeroObtenido = bufferInt;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s\n",pError);
				}
			}
			else
			{
				printf("\ncaracteres no numericos\n");
			}

			reintento--;
		}while(reintento>= 0);
	}

	return retorno;
}

int utn_getString(char pAuxChar[],int limite,char* pTexto,char* pError,int reintento)
{
	int retorno = -1;


	if(pAuxChar != NULL && pTexto != NULL && pError != NULL && reintento >= 0 && limite >0)
	{
		retorno = -2;

		do
		{
			printf("%s", pTexto);

			__fpurge(stdin);
			fgets(pAuxChar,limite,stdin);
			if(pAuxChar[strlen(pAuxChar)-1]==10)
			{
				pAuxChar[strlen(pAuxChar)-1] = 0;
			}

			if(utn_validarQueSeaChar(pAuxChar)==1)
			{
				retorno =0;
				break;
			}
			else
			{
				printf("\n El caracter ingresado no es una letra");
			}

			reintento--;

		}while(reintento>= 0);
	}

	return retorno;
}

/*
 * le pide al usuario un numero float
 */
int utn_getFloat(float* numeroObtenido,int limite, char* pTexto,char* pError,float minimo,float maximo,int reintento)

{
	int retorno = -1;
	char bufferNumeros[limite];
	float bufferFloat;

	if(numeroObtenido != NULL && limite >=0 && pTexto != NULL && pError != NULL && minimo <= maximo && reintento >= 0)
	{
		retorno = -2;

		do
		{
			printf("%s", pTexto);

			__fpurge(stdin);
			fgets(bufferNumeros,limite,stdin);
			if(bufferNumeros[strlen(bufferNumeros)-1]==10)
			{
				bufferNumeros[strlen(bufferNumeros)-1] = 0;
			}

			if(utn_validarQueSeaFloat(bufferNumeros)==1)
			{
				bufferFloat = atof(bufferNumeros);

				if(bufferFloat <= maximo && bufferFloat >= minimo)
				{
					*numeroObtenido = bufferFloat;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s\n",pError);
				}
			}
			else
			{
				printf("\ncaracteres no numericos\n");
			}

			reintento--;
		}while(reintento>= 0);
	}

	return retorno;
}


/**
 *\brief genera un numero random entre un minimo y un maximo
 * @param minimo
 * @param maximo
 * @return -1 si no pudo validar o bien numero generado
 */
int utn_getRandomNumber(int minimo, int maximo)
{
	int retorno = -1;
	int numeroCreado;

	if(minimo<maximo)
	{
		do
		{
			srand(time(NULL));
			numeroCreado = minimo + (rand() % maximo +1 - minimo);

		}while(numeroCreado < minimo || numeroCreado > maximo);

		retorno = numeroCreado;
	}

	return retorno;;
}


/*
 * valida que la cadena ingresada tenga numeros
 */
int utn_validarQueSeaNumero(char texto[])
{
	int i=0;
	int retorno;

	if(texto != NULL)
	{
		retorno =1;
		while(texto[i]!=0)
		{
			if(texto[i] < 48 || texto[i] >57)
			{
				retorno = -1;
				break;
			}

			i++;
		}
	}
	return retorno;

}

int utn_validarQueSeaChar(char texto[])
{
	int i=0;
	int retorno;

	if(texto != NULL)
	{
		retorno =1;
		while(texto[i]!=0)
		{
			texto[i] = toupper(texto[i]);
			if(texto[i] < 65 || texto[i] >90)
			{
				retorno = -1;
				break;
			}

			i++;
		}
	}
	return retorno;
}

int utn_validarQueSeaFloat(char texto[])
{
	int i=0;
	int retorno;

	if(texto != NULL)
	{
		retorno =1;
		while(texto[i]!=0)
		{
			if(texto[i] < 46 || texto[i] >57)
			{
				retorno = -1;
				break;
			}

			i++;
		}
	}
	return retorno;

}


/**
 * \brief Recibe un string y lo valida como Nombre
 * \param char array[] recibe la cadena de caracteres
 * \return retorna -1 si no pudo validar y 0 si pudo validar
 */
int utn_isValidName(char array[])
{
	int retorno = -1;

	if(array != NULL)
	{
		if(utn_validarQueSeaChar(array)==1)
		{
			retorno =0;
		}
	}

	return retorno;
}

/**
 *\brief verifica que un string sea un CUIT
 *\param char arra[] recibe la cadena
 *\param int lenght recibe el tamaño de la cadena
 *\return retorno devuelve 1 si valido
 */
int utn_esCuitValido(char array[], int lenght)
{
	int retorno=-1;

	if(array!=NULL && lenght>=0)
	{
		if(strlen(array) == 12)
		{
			if(utn_validarQueSeaNumero(array)==1)
			{
				if(array[0]>'1' && array[0]<'4')
				{
					retorno =1;
				}
			}
		}
	}

	return retorno;
}

/**
 * \brief Recibe un string y lo valida como DNI
 * \param char array[] recibe la cadena de caracteres
 * \return retorna -1 si no pudo validar y 0 si pudo validar
 */
/*int utn_isValidDni(char array[])
{
	int retorno =-1;

	if(array != NULL)
	{
		if(strlen(array) < 10 && strlen(array)>7)
		{
			if(utn_validarQueSeaNumero(array)==0)
			{
				retorno =0;
			}
		}
	}

	return retorno;
}*/

/**
 *\brief Genera un id aleatorio no repetido
 *\param int array[] recibe el array
 *\param  int indiceArray recibe la posicion donde asignar el id
 *\param  int limite recibe el limite del array
 *\param  int minimo recibe el valor minimo del id
 *\param  int maximo recibe el valor maximo del id
 *\return retorno 0 si valido y -1 si no valido
 */
int utn_randomId(int array[], int indiceArray, int limite, int minimo, int maximo)
{
	int retorno = -1;
	int flagIdRepetido;
	int nuevoId;
	int i;

	if(array != NULL && minimo<maximo)
	{
		//ID
		do
		{
			flagIdRepetido =1;

			do
			{
				srand(time(NULL));
				nuevoId = minimo + (rand() % maximo +1 - minimo);

			}while(nuevoId < minimo || nuevoId > maximo);

			for(i=0;i<limite;i++)
			{
				if(array[i] == nuevoId)
				{
					break;
				}

				flagIdRepetido =0;
			}

		}while(flagIdRepetido);

		array[indiceArray] = nuevoId;

		retorno =0;
	}

	return retorno;
}

/**
 * \brief pide al usuario que ingrese su cuit
 */
int utn_getCUIT(char cadenaRecibida[], int limite, char* pTexto, char* pError)
{
	int retorno =-1;


	if(cadenaRecibida !=NULL && limite >=0)
	{
		retorno =0;

		printf("%s", pTexto);

		__fpurge(stdin);
		fgets(cadenaRecibida,limite,stdin);
		if(cadenaRecibida[strlen(cadenaRecibida)-1]==10)
		{
			cadenaRecibida[strlen(cadenaRecibida)-1] = 0;
		}

		if(utn_validarQueSeaNumero(cadenaRecibida)==1)
		{
			retorno =0;
		}

	}
	else
	{
		printf("%s", pError);
	}

	return retorno;
}


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
int utn_charMayorMenor(char* cadenaUno, int len, char* cadenaDos)
{
	int retorno =-1;
	int i;

	if(cadenaUno!=NULL && len>=0 && cadenaDos!=NULL)
	{
		retorno =0;

		for(i=0;i<len-1;i++)
		{
			if(cadenaUno[i] < cadenaDos[i])
			{
				retorno = 2;
				break;
			}
			else if(cadenaUno[i] > cadenaDos[i])
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

/**
 * \brief verifica que un numero sea un numero
 * @param this
 * @return
 */
int utn_isValidNumber(int this)
{
	int retorno =-1;

	char buffer[128];

	sprintf(buffer,"%d",this);

	if(utn_validarQueSeaNumero(buffer)!=-1)
		retorno =0;

	return retorno;
}

























