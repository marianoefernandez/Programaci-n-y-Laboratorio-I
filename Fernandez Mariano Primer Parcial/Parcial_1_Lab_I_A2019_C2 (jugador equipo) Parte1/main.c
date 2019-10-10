#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Equipos.h"
#include "Jugadores.h"
//#include "Referi.h"
//#include "Partido.h"
#define TAM 1000
#define NOTFREE 1
#define FREE 0
#define HARDCODING 10
int main()
{
    int opcion;
    int opcionE;
    int codigoE=1;
    int retorno;
    int cantidadPropietariosOcupados;
    eEquipo equipos[TAM];

        do
        {
            printf("----BIENVENIDO POR FAVOR SELECCIONE QUE OPCION DESEA----");
            printf("\n1-Equipo");
            printf("\n2-Jugadores");
            printf("\n3-Referi");
            printf("\n4-Partido");
            opcion=getInt("\nSu opcion: ");

        switch(opcion)
        {
        case 1:
            if (inicializarEquipos(equipos,TAM==0))
        {
            do
            {
                mostrarMenu();
                    opcionE=getInt("\nSu opcion: ");
                    switch(opcionE)
                    {
                    case 1:
                        if (agregarEquipo(equipos,TAM,codigoE)==0)
                        {
                            codigoE++;
                            printf("\nSe agrego el equipo\n");
                        }
                        else
                        {
                            printf("\nNo hay espacio\n");
                        }
                        break;

                    case 2:
                        if (ordenarEquiposNombreYLocalidad(equipos,TAM,1)==0)
                        {
                            printf("\nSe ordeno correctamente\n");
                            printEquipos(equipos,TAM);
                            system("pause");
                            opcionE=0;
                        }
                            else
                            {
                                printf("\nNo se pudo ordenar\n");
                            }
                    break;

                    default:
                        printf("\nSeleccione una opcion valida \n");
                        break;
                    }

                    system("pause");
                    system("cls");
                }
                while(opcionE!=0);
        }
        else
        {
            printf("\nHubo un error");
        }
        break;

    default:
        printf("\nSeleccione una opcion valida \n");
        break;
    }

    system("pause");
    system("cls");
} while(opcion!=0);
    return 0;
}
