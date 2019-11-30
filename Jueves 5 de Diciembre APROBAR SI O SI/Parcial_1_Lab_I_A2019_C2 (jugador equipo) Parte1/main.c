#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Equipos.h"
#include "Referi.h"
//#include "Partido.h"
#define TAM 1000
#define NOTFREE 1
#define FREE 0
#define HARDCODING 10
int main()
{
    int opcion;
    int opcionE;
    int opcionJ;
    int opcionR;
    int codigoE=0;
    int codigoJ=0;
    int codigoR=0;
    int retorno;
    int cantidadPropietariosOcupados;
    eEquipo equipos[TAM];
    eJugadores jugadores[TAM];
    eReferi referis[TAM];

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
                mostrarMenuE();
                    opcionE=getInt("\nSu opcion: ");
                    switch(opcionE)
                    {
                    case 1:
                        codigoE++;
                        if (agregarEquipo(equipos,TAM,codigoE)==0)
                        {
                            printf("\nSe agrego el equipo\n");
                            opcionJ=0;
                        }
                        else
                        {
                            codigoE--;
                            printf("\nNo hay espacio\n");
                            opcionJ=0;
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
                                opcionE=0;
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


            case 2:
            if (inicializarJugadores(jugadores,TAM==0))
            {
            do
            {
                mostrarMenuJ();
                    opcionJ=getInt("\nSu opcion: ");
                    switch(opcionJ)
                    {
                    case 1:
                        codigoJ++;
                        if (agregarJugadores(jugadores,TAM,codigoJ)==0)
                        {
                            printf("\nSe agrego el jugador\n");
                            opcionJ=0;
                        }
                        else
                        {
                            codigoJ--;
                            printf("\nNo hay espacio\n");
                            opcionJ=0;
                        }
                        break;

                    case 2:
                        if (ordenarJugadoresNombreYApellido(equipos,TAM,1)==0)
                        {
                            printf("\nSe ordeno correctamente\n");
                            printJugadores(equipos,jugadores,TAM);
                            system("pause");
                            opcionJ=0;
                        }
                            else
                            {
                                printf("\nNo se pudo ordenar\n");
                                opcionJ=0;
                            }
                    break;

                    default:
                        printf("\nSeleccione una opcion valida \n");
                        break;
                    }

                    system("pause");
                    system("cls");
                }
                while(opcionJ!=0);
        }
        else
        {
            printf("\nHubo un error");
        }
        break;

            case 3:
            if (inicializarReferis(referis,TAM==0))
            {
            do
            {
                mostrarMenuR();
                    opcionR=getInt("\nSu opcion: ");
                    switch(opcionR)
                    {
                    case 1:
                        codigoR++;
                        if (agregarReferis(referis,TAM,codigoR)==0)
                        {
                            printf("\nSe agrego el referi\n");
                            opcionR=0;
                        }
                        else
                        {
                            opcionR--;
                            printf("\nNo hay espacio\n");
                            opcionR=0;
                        }
                        break;

                    case 2:
                        printReferi(referis,TAM);
                    break;

                    default:
                        printf("\nSeleccione una opcion valida \n");
                        break;
                    }

                    system("pause");
                    system("cls");
                }
                while(opcionJ!=0);
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
