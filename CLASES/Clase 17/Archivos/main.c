#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE* pArchivo;
    char miNombre[50] = {"Lionel Messi"};

    //pArchivo = fopen("D:\\ARCHIVOS\\miNombre.txt","w");

   pArchivo = fopen("D:\\ARCHIVOS\\miNombre.txt","r");

   fgets(miNombre,50,pArchivo);

   //fprintf(pArchivo, "Me llamo %s",miNombre);

   fclose(pArchivo);

   printf("%s ", miNombre);
   //fwrite()


    return 0;
}
