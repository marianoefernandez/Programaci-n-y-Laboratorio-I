#include <stdio.h>
#include <stdlib.h>

int main()
{
    char palabra[10];
    printf("Ingrese una palabra: ");
    gets(palabra);
    printf("%s", palabra);
    return 0;
}
