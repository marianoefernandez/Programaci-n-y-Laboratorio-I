#include <stdio.h>
#include <stdlib.h>

/** \brief Pide un numero y devuelve un resultado
 *
 * \param mensaje que se mostrara
 * \return numero ingresado
 */
int getInt(char mensaje[]);


/** \brief Pide un numero y devuelve un resultado
 *
 * \param mensaje que ser� mostrado
 * \return numero ingresado
 */
float getFloat(char mensaje[]);


/** \brief Pide un caracter y devuelve un resultado
 *
 * \param mensaje que ser� mostrado
 * \return caracter ingresado
 */
char getChar(char mensaje[]);


/** \brief Devuelve la suma de dos numeros ingresados
 *
 * \param float pide el primer numero
 * \param float pide el segundo numero
 * \return retorna la suma
 *
 */
float funcionSuma(float, float);


/** \brief Devuelve la resta de dos numeros ingresados
 *
 * \param float pide el primer numero
 * \param float pide el segundo numero
 * \return retorna la resta
 *
 */
float funcionResta(float, float);


/** \brief Devuelve la division de dos numeros ingresados
 *
 * \param float pide el primer numero
 * \param float pide el segundo numero
 * \return retorna la division
 *
 */
float funcionDividir(float, float);


/** \brief Devuelve la multiplicacion de dos numeros ingresados
 *
 * \param float pide el primer numero
 * \param float pide el segundo numero
 * \return retorna la multiplicacion
 *
 */
float funcionMultiplicar(float, float);


/** \brief Devuelve el factorial de un numero ingresado
 *
 * \param float Pide un numero
 * \return float Retorna el factorial
 *
 */
float funcionFactorial(float);
