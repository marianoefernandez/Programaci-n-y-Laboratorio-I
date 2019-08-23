#include <stdio.h>
#include <stdlib.h>


//Edad es de 1 a 105, altura de 1.00cm a 2.00 cm y sexo sólo f y m
//Pedir sexo, edad y altura hasta que el usuario quiera
//Averiguar a) la altura de la mujer mayor b) altura de la persona más joven c)sexo de la persona más alta
//d)Edad del hombre más bajo e) Promedio de edades e)Promedio de alturas de los hombres.

//Promedio de edades y alturas de los hombres.

int main()
{
    int edad;
    float altura;
    char sexo;

    float alturaDeLaMujerMayor;
    int mayorEdad;
    int edadDelBajo;
    float alturaJoven;
    int menorEdad;
    char sexoDelAlto;
    char sexoDelMasAltoAux[15];
    int masAlto;
    float masBajo;
    float promedioEdades;
    float promedioAlturaHombres;
    int sumaEdades=0;
    int contador=0;
    int sumaAlturas=0;
    char seguir;
    int cantidadHombres=0;

    system("cls");

    printf("Bienvenido senior programador he aqui un ejercicio re basico que en clase no salia, este programa cargara personas por su edad , sexo y altura\n\n");

 while (seguir == 's')
 {
     do
    {
        printf("\nIngrese la edad: ");
        scanf("%d",&edad);

        if (edad < 1 || edad > 105)
        {
            printf("Por favor ingrese una edad de 1 a 105 anios\n\n");
        }
    }while (edad < 1 || edad > 105);

    do
    {
        fflush(stdin);
        printf("\nIngrese el sexo (f/m): ");
        scanf("%c",&sexo);

        if (sexo !='f' && sexo != 'm' && sexo != 'F' && sexo != 'M')
        {
            printf("Por favor ingrese un sexo valido, solo f o m\n\n");
        }
    }while (sexo !='f' && sexo != 'm' && sexo != 'F' && sexo != 'M');

    do
    {
        printf("\nIngrese el altura (cm): ");
        scanf("%f",&altura);

        if (altura<1 || altura > 2)
        {
            printf("Por favor ingrese una altura valida, solo de 1.00 cm a 2.00 cm\n\n");
        }
    }while (altura<1 || altura > 2);

    do
    {
        printf("\n¿Desea continuar? s/n");

        if (seguir != 'n' && seguir != 's')
        {
            printf("Por favor solo ingrese s/n");
        }
        scanf("%c", & seguir);
    }while (seguir != 'n' && seguir != 's');

    if (contador == 0)
		{
			menorEdad = edad;
			alturaJoven = altura;
		}
		else
		{
			if (menorEdad > edad)
			{
				menorEdad = edad;
                alturaJoven = altura;
			}
        }

        if (mayorEdad<edad && sexo == 'f')
        {
            mayorEdad = edad;
            alturaDeLaMujerMayor=altura;
        }

        if (contador == 0)
		{
			sexoDelAlto = sexo;
			masAlto = altura;
		}
		else
		{
			if (masAlto < altura)
			{
				sexoDelAlto = sexo;
                altura = altura;
			}
        }

        if (masBajo>altura && sexo == 'm')
        {
            edadDelBajo = edad;
            masBajo = altura;
        }

        if (sexo == 'm')
        {
            cantidadHombres++;
        }

        sumaEdades = sumaEdades + edad;
        sumaAlturas = sumaAlturas + altura;

        contador++;
 }

 promedioEdades = sumaEdades / contador;
 promedioAlturaHombres = sumaAlturas / cantidadHombres;

 if (sexoDelAlto == 'm')
 {
     sexoDelMasAltoAux = {"Masculino"};
 }else if (sexoDelAlto == 'f')
 {
     sexoDelMasAltoAux = {"Femenino"};
 }


 printf("\nLa altura de la mujer mayor es de: %.2f cm", alturaDeLaMujerMayor);
 printf("\nLa altura de la persona mas joven es de: %.2f cm", alturaJoven);
 printf("\nEl sexo de la persona mas alta es el sexo: %c", sexoDelMasAltoAux);
 printf("\nLa edad del hombre mas bajo es de: %d anios", edadDelBajo);
 printf("\nEl promedio de todas las edades es de: %.3f cm", promedioEdades);
 printf("\nEl promedio de todas las alturas de los hombres es de: %.3f cm", promedioAlturaHombres);



 return 0;

}










