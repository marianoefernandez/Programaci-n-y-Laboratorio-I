#include <stdio.h>
#include <stdlib.h>

int main()
{
    int entero=10;
    int* puntero=NULL;
    int* otroPuntero;

    puntero = &entero;//SIEMPRE TIENE QUE ESTAR REFERENCIADO EL PUNTERO!

    printf("\nIngrese un numero: \n");
    scanf("%d",puntero);

    if(puntero!=NULL)
    {
    otroPuntero=puntero;
    printf("%d\n",entero);//10
    printf("%d\n",*puntero);//10
    printf("%d\n",&entero);//0x40
    printf("%d\n",puntero);//0x40
    printf("%d\n",&puntero);//0x75
    printf("%d\n",*otroPuntero);//0x75
    }
    else
    {
        printf("\nApunta a nada\n");
    }
    return 0;
}
