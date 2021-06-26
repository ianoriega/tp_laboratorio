#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "arr.h"

/**
 * \brief recibe dos datos, los suma y entrega el resultado
 * \param float primerNum recibe el primer numero para operar
 * \param float segundoNum recibe el segundo numero para operar
 * \param float* pNumObtenido recibe puntero a variable donde se va a almacenar el resultado
 * \return retorna 0 para ok y -1 si no pudo validar argumentos
 */
int matOp_suma(float primerNum, float segundoNum, float* pNumObtenido)
{
	int retorno = -1;

	if(pNumObtenido != NULL)
	{
		*pNumObtenido =  primerNum + segundoNum;
		retorno =0;
	}

	return retorno;
}

/**
 * \brief recibe dos datos, los resta y entrega el resultado
 * \param float primerNum recibe el primer numero para operar
 * \param float segundoNum recibe el segundo numero para operar
 * \param float* pNumObtenido recibe puntero a variable donde se va a almacenar el resultado
 * \return retorna 0 para ok y -1 si no pudo validar argumentos
 */
int matOp_resta(float primerNum, float segundoNum, float* pNumObtenido)
{
	int retorno = -1;

	if(pNumObtenido != NULL)
	{
		*pNumObtenido =  primerNum - segundoNum;
		retorno =0;
	}
	return retorno;
}

/**
 * \brief recibe dos datos, los divide y entrega el resultado
 * \param float primerNum recibe el primer numero para operar
 * \param float segundoNum recibe el segundo numero para operar
 * \param float* pNumObtenido recibe puntero a variable donde se va a almacenar el resultado
 * \return retorna 0 para ok y -1 si no pudo validar argumentos, devuleve 1 si la division es por 0
 */
int matOp_division(float primerNum, float segundoNum, float* pNumObtenido)
{
	int retorno = -1;

	if(segundoNum == 0)
	{
		retorno = 1;
	}
	else
	{
		if(pNumObtenido != NULL)
		{
			*pNumObtenido =  primerNum / segundoNum;
			retorno =0;
		}
	}
	return retorno;
}

/**
 * \brief recibe dos datos, los multiplica y entrega el resultado
 * \param float primerNum recibe el primer numero para operar
 * \param float segundoNum recibe el segundo numero para operar
 * \param float* pNumObtenido recibe puntero a variable donde se va a almacenar el resultado
 * \return retorna 0 para ok y -1 si no pudo validar argumentos
 */
int matOp_multiplicacion(float primerNum, float segundoNum, float* pNumObtenido)
{
	int retorno = -1;

	if(pNumObtenido != NULL)
	{
		*pNumObtenido =  primerNum * segundoNum;
		retorno =0;
	}
	return retorno;
}

/**
 * \brief recibe el dato A, lo factoriza y entrega el resultado
 * \param float primerNum recibe el numero para operar
 * \param float* pNumObtenido recibe puntero a variable para almacenar el resultado del primer operando
 * \param float* pSegNumObtenido recibe puntero a variable para almacenar el resultado del segundo operando
 * \return retorna 0 para ok y -1 si no pudo validar argumentos
 */
int matOp_factorial(float primerNum, float segundoNum, float* pNumObtenido, float* pSegNumObtenido)
{
	int retorno = -1;
	int i;
	float bufferFactorialUno;
	float bufferFactorialDos;

		if(pNumObtenido != NULL && pSegNumObtenido!=NULL)
		{
			bufferFactorialUno = 1;
			for(i =1; i<primerNum+1; i++)
			{
				bufferFactorialUno= bufferFactorialUno *i;
			}
			*pNumObtenido = bufferFactorialUno;

			bufferFactorialDos = 1;
			for(i =1; i<segundoNum+1; i++)
			{
				bufferFactorialDos= bufferFactorialDos *i;
			}
			*pSegNumObtenido = bufferFactorialDos;

			retorno =0;
		}
		return retorno;
}



