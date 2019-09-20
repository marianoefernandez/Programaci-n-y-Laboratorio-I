/*
2)Crear una función que permita ingresar un numero al usuario y lo retorne.
Crear una función que reciba el radio de un círculo y retorne su área.
Utilizar las funciones de los puntos 1 y 2 para hacer un programa
que calcule el área de un círculo cuyo radio es ingresado por el usuario.
Documentar las funciones al estilo Doxygen.
*/
#include <stdio.h>
#include <stdlib.h>

/** \brief Función que pide dato al usuario y retorna lo que el usuario puso.
 *
 * \param 1 es el flotante que guarda el valor que el usuario pondra y sera el que retorne es float por si se ingresa num con coma
 * \param 2 el mensaje de que es lo que pide
 * \return retorna el numero que el usuario ingreso
 *
 */
float ingresarN (float x,char nombre[]);

/** \brief Función a la que se le pasa el radio de un circulo y devuelve su área
 *
 * \param Se le pasa el radio de un circulo cuanto mide en cm
 * \return Retorna el area de dicho circulo
 *
 */
float circulo (float radio);

int main()
{
    float radio;
    float area;
    radio = ingresarN(radio,"el radio de un circulo (cm)");
    area = circulo(radio);
    printf("\n\nEl area del circulo es de: %.2f centimetros.",area);
    return 0;
}

float ingresarN (float x,char nombre[])
{
    printf("Ingrese %s: ",nombre);
    scanf("%f",&x);
    return x;
}

float circulo (float radio)
{
    return (radio * radio) * 3.1416;
}
