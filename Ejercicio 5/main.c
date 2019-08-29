#include <stdio.h>
#include <stdlib.h>

/*

Pedir edad (1-105), altura (1.00 cm-2.00 cm) y sexo (f/m) hasta que el usuario quiera mostrar.

a) Altura de la mujer más vieja
b) Altura de la persona más joven
c) Sexo de la persona más alta
d) Edad del hombre más bajo
e) Promedio de edades
f) Promedio de altura de los hombres

*/


int main()
{
    //Variables de entrada
    int edad;
    float altura;
    char sexo;
    char seguir = 's';

    //Punto a
    float alturaMVieja;
    int mujerVieja;
    int flagMVieja=0;

    //Punto b
    float alturaJoven;
    int menorEdad;

    //Punto c
    char sexoPersonaAlta;
    float personaAlta;

    //Punto d
    int edadHombreBajo;
    float hombreBajo;
    int flagHombreBajo=0;

    //Punto e
    float promedioEdades;
    int sumaEdades=0;
    int contador=0;

    //punto f
    float promedioAlturaH;
    float sumaAlturasH=0;
    int cantidadH=0;

    //Inicio pidiendo datos
    while (seguir == 's')
    {
        do
        {
            printf("\n\nIngrese una edad entre 1 y 105 anios: ");
            scanf("%d", &edad);
            if (1>edad||edad>105)
            {
                printf("\nERROR, por favor solo ingrese una edad de 1 a 105 anios");
            }
        }
        while (1>edad||edad>105);

        do
        {
            printf("\n\nIngrese una altura entre 1.00 y 2.00 cm: ");
            scanf("%f", &altura);
            if (1>altura||altura>2)
            {
                printf("\nERROR, por favor solo ingrese una altura entre 1.00 y 2.00 cm");
            }
        }
        while (1>altura||altura>2);

        do
        {
            fflush(stdin);
            printf("\n\nIngrese un sexo (f/m): ");
            sexo = getche();
            sexo = tolower(sexo);

            if (sexo != 'f' && sexo != 'm')
            {
                printf("\nERROR, por favor solo ingrese f o m");
            }
        }
        while (sexo != 'f' && sexo != 'm');

        do
        {
            printf("\n\n¿Desea continuar? (s/n): ");
            seguir = getche();

            if (seguir != 's' && seguir != 'n')
            {
                printf("\nERROR, por favor solo ingrese s o n");
            }

        }
        while (seguir != 's' && seguir != 'n');


        //a) Altura de la mujer más vieja

        if (sexo == 'f')
        {
            if (flagMVieja == 0 || mujerVieja<edad)
            {
                mujerVieja = edad;
                alturaMVieja = altura;
                flagMVieja = 1;
            }
        }

        //b) Altura de la persona más joven

        if (contador == 0)
        {
            alturaJoven = altura;
            menorEdad = edad;
        }
        else if (menorEdad>edad)
        {
            alturaJoven = altura;
            menorEdad = edad;
        }

        //c) Sexo de la persona más alta

        if (contador == 0)
        {
            personaAlta = altura;
            sexoPersonaAlta = sexo;
        }
        else if (personaAlta<altura)
        {
            personaAlta = altura;
            sexoPersonaAlta = sexo;
        }

        //d) Edad del hombre más bajo

        if (sexo == 'm')
        {
            if (flagHombreBajo==0 || hombreBajo>altura)
            {
                edadHombreBajo = edad;
                hombreBajo = altura;
                flagHombreBajo = 1;
            }
        }

        //e) Promedio de edades

        contador++;
        sumaEdades=sumaEdades+edad;

        //f) Promedio de altura de los hombres

        if (sexo == 'm')
        {
            cantidadH++;
            sumaAlturasH=sumaAlturasH+altura;
        }

    }
    //calculo los promedios previamente
    promedioEdades = (float)sumaEdades/contador;
    promedioAlturaH = sumaAlturasH/cantidadH;

    //muestro los resultados

    //a) Altura de la mujer más vieja
    if (flagMVieja==0)
    {
        printf("\n\na)No se ingreso ninguna mujer por ende no existen datos de la altura de la mujer mas vieja ");
    }
    else
    {
        printf("\n\na)La altura de la mujer mas vieja es de: %.2f cm",alturaMVieja);
    }

    //b) Altura de la persona más joven
    printf("\n\nb)La altura de la persona mas joven es de: %.2f cm",alturaJoven);

    //c) Sexo de la persona más alta
    if (sexoPersonaAlta == 'm')
    {
        printf("\n\nc)El sexo de la persona mas alta es el sexo: masculino");
    }
    else
    {
        printf("\n\nc)El sexo de la persona mas alta es el sexo: femenino");
    }

    //d) Edad del hombre más bajo
    if (flagHombreBajo==0)
    {
        printf("\n\nd)No se ingreso ningun masculino por ende no existen datos de la edad del hombre mas bajo");
    }
    else
    {
        printf("\n\nd)La edad del hombre mas bajo es de: %d anios", edadHombreBajo);
    }

    //e) Promedio de edades
    printf("\n\ne)El promedio de edades total es de: %.2f anios", promedioEdades);

    //f) Promedio de altura de los hombres
    printf("\n\nf)El promedio de la altura de los hombres total es de: %.2f cm", promedioAlturaH);

    return 0;
}
