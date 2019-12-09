#include <stdio.h>
#include <stdlib.h>
#define QTY 8
#include "entidades.h"
#include "utn.h"

int main()
{
    int opcion=0;
    ePersona persona[QTY];
    eLlamada llamada[QTY];

    inicializarLlamada(llamada,QTY);
    inicializarAutor(persona,QTY);


    autor_hardcore(persona);

    do
    {
          switch(menuAutores())
    {
    case 'A':
         if( altaAutor(persona,QTY))
                {
                    printf("ALTA CON EXITO\n");
                    system("pause");
                }
                else
                {
                    printf("ERROR DE ALTA\n");
                    system("pause");
                }
        break;
         case 'B':
              if(bajaAutor(persona,QTY))
                {
                    printf("BAJA CON EXITO\n");
                    system("pause");
                }
                else
                {
                    printf("ERROR AL DAR BAJA\n");
                    system("pause");
                }
        break;
         case 'C':
             if(modificarAutor(persona,QTY))
                {
                    printf("MODIFICADO CON EXITO\n");
                    system("pause");
                }
                else
                {
                    printf("ERROR AL MODIFICAR\n");
                    system("pause");
                }

        break;
         case 'D':
              if( altaLlamada(llamada,QTY,persona))
                {
                    printf("ALTA CON EXITO\n");
                    system("pause");
                }
                else
                {
                    printf("ERROR DE ALTA\n");
                    system("pause");
                }
        break;
         case 'S':
             opcion=1;
        break;
    }

    }while(!opcion);


    return 0;
}
