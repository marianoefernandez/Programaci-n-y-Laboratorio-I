#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE* pArchivo;
    char aux[50];
    char miNombre[50] = {"Lionel Messi"};
    int i=0;
    int a[3] = {3,8,9};

    //pArchivo = fopen("D:\\ARCHIVOS\\miNombre.txt","wb");
    //fwrite(a,sizeof(int),3,pArchivo);
    pArchivo = fopen("D:\\ARCHIVOS\\miNombre.txt","rb");
    fread(a,sizeof(int),3,pArchivo);

    for (i=0;i<3;i++)
    {
        printf("\n%d",a[i]);
    }

   //pArchivo = fopen("D:\\ARCHIVOS\\miNombre.txt","r");

  /* while(!feof(pArchivo))
   {
       fgets(miNombre,50,pArchivo);
       printf("%s",miNombre);
       i++
   }


   //fprintf(pArchivo, "Me llamo %s",miNombre);

   fclose(pArchivo);

   //printf("%s ", miNombre);
   //fwrite()

*/
    return 0;
}
