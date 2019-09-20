#include "funciones.h"

float sumar(float x, float y)
{
    return x+y;
}

float restar(float x, float y)
{
    return x-y;
}

float multiplicar(float x, float y)
{
    return x*y;
}

float dividir(float x, float y)
{
    return x/y;
}

int factorial(int x)
{
    int r;

    if (x==0)
    {
        r=1;
    }
    else
    {
        r=x*factorial(x-1);
    }

    return r;
}
