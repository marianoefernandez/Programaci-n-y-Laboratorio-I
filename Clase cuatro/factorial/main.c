#include <stdio.h>
#include <stdlib.h>

int factorial (int n);

int main()
{
    int r;
    r = factorial(5);
    printf("El factorial es: %d", r);
    return 0;
}

int factorial(int n)
{
    int r;

    if (n==0)
    {
        r=1;
    }
    else
    {
        r=n*factorial(n-1);
    }

    return r;
}
