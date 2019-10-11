#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* puntero;
    int i;
    int vector[5] = {5,7,9,8,3};
    //int entero;

    //puntero=&entero;

    //puntero=&vector;
    puntero=vector;
    //puntero=&vector[0];

    for (i=0;i<5;i++)
    {
        printf("%d\n", *(puntero+i));
    }



    /*
    printf("%p\n",puntero);
    printf("%p\n",puntero-1);
    printf("%p\n",puntero+1);
    printf("%p\n",puntero+2);
    printf("%p\n\n\n",puntero+3);

    puntero=puntero+1;
    system("pause");
    printf("%p\n",puntero);
    */
    return 0;
}
