#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pEntero = (int*)calloc(sizeof(int),5);
    int i;

    for (i=0;i<5;i++)
    {
        printf("%d-", *(pEntero+i));
    }

    free(pEntero);

    return 0;
}
