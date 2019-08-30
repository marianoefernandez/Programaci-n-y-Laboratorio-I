#include <stdio.h>
#include <stdlib.h>
float sumar (int n1,int n2);
float restar(int n1,int n2);
float multiplicar(int n1,int n2);
float dividir(int n1,int n2);
void calcular (int n1,int n2,int op);
void mostrar (float r);
int pedirDato ();

int main()
{

    printf("\nIngrese num de operacion(1-Suma,2-Resta,3-Multiplicacion,4-Division: ");
    int op = pedirDato(op);
    printf("\nIngrese primer num: ");
    int n1 = pedirDato(n1);
    printf("\nIngrese segundo num: ");
    int n2 = pedirDato(n2);
    calcular(n1,n2,op);
    return 0;
}

float sumar (int n1,int n2)
{
    float suma = (float)n1+n2; //Se recibe el valor y lo muestra
    return suma; //Lo retorna
}

float restar (int n1,int n2)
{
    float resta = (float)n1-n2; //Se recibe el valor y lo muestra
    return resta; //Lo retorna
}

float multiplicar (int n1,int n2)
{
    float multiplica = (float)n1*n2; //Se recibe el valor y lo muestra
    return multiplica; //Lo retorna
}

float dividir (int n1,int n2)
{
    float division = (float)n1/n2; //Se recibe el valor y lo muestra
    return division; //Lo retorna
}

void calcular (int n1,int n2,int op)
{
    float r;

    if (op == 1)
    {
        r=sumar(n1,n2); //Hago llamada
    }

    if (op == 2)
    {
        r=restar(n1,n2); //Hago llamada
    }

    if (op == 3)
    {
        r=multiplicar(n1,n2); //Hago llamada
    }

    if (op == 4)
    {
        r=dividir(n1,n2); //Hago llamada
    }
    mostrar (r);
}

    void mostrar(float r)
    {
        printf("\n\nEl resultado es: %.f",r);
    }

    int pedirDato();
    {
        scanf("%d",&dato);
        return (dato);
    }

