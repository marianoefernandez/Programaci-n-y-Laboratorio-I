#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* miVector;
    int i;
    int* auxVector;

    miVector = (int*) malloc(sizeof(int)*5);

    if (miVector!=NULL)
    {
        for(i=0;i<5;i++)
        {
            *(miVector+i) = i+1;
        }
        for(i=0;i<5;i++)
        {
            printf("%d\n",*(miVector+i));
        }

    }
       auxVector = (int*) realloc(miVector,sizeof(int)*10);
       printf("\nPido mas espacio:\n\n");

       if(auxVector!=NULL) //ESTO VERIFICA SI HAY ESPACIO EN MEMORIA O NO.
       {
           miVector=auxVector;
           for(i=5;i<10;i++)
           {
                *(miVector+i) = i+1;
           }
            for(i=0;i<10;i++)
            {
                printf("%d\n",*(miVector+i));
            }
       }
       else
       {
            printf("No hay mas espacio en memoria");
       }

    return 0;
}
