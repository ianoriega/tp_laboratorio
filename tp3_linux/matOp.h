/*
 * matOp.h
 *
 *  Created on: 16 abr. 2021
 *      Author: inoriega
 */

#ifndef MATOP_H_
#define MATOP_H_

/**
 * \brief recibe dos datos, los suma y entrega el resultado
 * \param float primerNum recibe el primer numero para operar
 * \param float segundoNum recibe el segundo numero para operar
 * \param float* pNumObtenido recibe puntero a variable donde se va a almacenar el resultado
 * \return retorna 0 para ok y -1 si no pudo validar argumentos
 */
int matOp_suma(float primerNum, float segundoNum, float* pNumObtenido);


/**
 * \brief recibe dos datos, los resta y entrega el resultado
 * \param float primerNum recibe el primer numero para operar
 * \param float segundoNum recibe el segundo numero para operar
 * \param float* pNumObtenido recibe puntero a variable donde se va a almacenar el resultado
 * \return retorna 0 para ok y -1 si no pudo validar argumentos
 */
int matOp_resta(float primerNum, float segundoNum, float* pNumObtenido);


/**
 * \brief recibe dos datos, los divide y entrega el resultado
 * \param float primerNum recibe el primer numero para operar
 * \param float segundoNum recibe el segundo numero para operar
 * \param float* pNumObtenido recibe puntero a variable donde se va a almacenar el resultado
 * \return retorna 0 para ok y -1 si no pudo validar argumentos
 */
int matOp_division(float primerNum, float segundoNum, float* pNumObtenido);


/**
 * \brief recibe dos datos, los multiplica y entrega el resultado
 * \param float primerNum recibe el primer numero para operar
 * \param float segundoNum recibe el segundo numero para operar
 * \param float* pNumObtenido recibe puntero a variable donde se va a almacenar el resultado
 * \return retorna 0 para ok y -1 si no pudo validar argumentos
 */
int matOp_multiplicacion(float primerNum, float segundoNum, float* pNumObtenido);


/**
 * \brief recibe el dato A, lo factoriza y entrega el resultado
 * \param float primerNum recibe el numero para operar
 * \param float* pNumObtenido recibe puntero a variable para almacenar el resultado del primer operando
 * \param float* pSegNumObtenido recibe puntero a variable para almacenar el resultado del segundo operando
 * \return retorna 0 para ok y -1 si no pudo validar argumentos
 */
int matOp_factorial(float primerNum, float segundoNum, float* pNumObtenido, float* pSegNumObtenido);


#endif /* MATOP_H_ */
