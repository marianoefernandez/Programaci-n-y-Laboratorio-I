#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Equipos.h"
#include "inputs.h"
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
    int opcionP;
    int opcionV;
    int codigoE=0;
    int codigoJ=0;
    int codigoR=0;
    int codigoP=0;
    int cantidadEquipos;
    int retorno;
    int cantidadJugadores;
    int cantidadReferis;
    int cantidadPropietariosOcupados;
    eEquipo equipos[TAM];
    eJugadores jugadores[TAM];
    eReferi referis[TAM];
    ePartido partidos[TAM];

        do
        {
            printf("----BIENVENIDO POR FAVOR SELECCIONE QUE OPCION DESEA----");
            printf("\n1-Equipo");
            printf("\n2-Jugadores");
            printf("\n3-Referi");
            printf("\n4-Partido");
            printf("\n5-Validaciones");
            printf("\n6-Salir");
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
                        //hardcodeoEquipos(equipos);
                        break;

                    case 2:
                        cantidadEquipos=cantidadEquiposOcupados(equipos,TAM);
                        if(cantidadEquipos>0)
                        {
                            retorno = bajaEquipo(equipos,TAM,getInt("Ingrese el codigo: "));
                            switch(retorno)
                            {
                            case 0:
                                printf("\nSe elimino el equipo\n");
                                break;
                            case 1:
                                printf("\nAccion cancelada por el usuario\n");
                                break;
                            case -1:
                                printf("\nNo se encontro el equipo\n");
                                break;
                            case 2:
                                printf("\nEl equipo se elimino anteriormente o no existe el equipo\n");
                                break;
                            }
                        }
                        else
                        {
                            printf("\nNo hay ningun equipo dado de alta, por favor primero realice una carga\n");
                        }
                        break;

                    case 3:
                        cantidadEquipos=cantidadEquiposOcupados(equipos,TAM);
                        if(cantidadEquipos>0)
                        {
                            retorno=modificarEquipo(equipos,TAM);
                            switch(retorno)
                            {
                            case 0:
                                printf("\nSe modifico el equipo\n");
                                break;
                            case -1:
                                printf("\nNo se pudo modificar el equipo\n");
                                break;
                            case -2:
                                printf("\nSaliendo...\n");
                                break;
                            }
                        }
                        else
                        {
                            printf("\nNo hay ningun equipo dado de alta, por favor primero realice una carga\n");
                        }
                        break;

                    case 4:
                        if (ordenarEquiposNombreYLocalidad(equipos,TAM,1)==0)
                        {
                            cantidadEquipos=cantidadEquiposOcupados(equipos,TAM);
                            if(cantidadEquipos>0)
                            {
                                printf("\nSe ordeno correctamente\n");
                                printEquipos(equipos,TAM);
                                system("pause");
                            }
                            else
                            {
                                printf("\nPor favor, primero cargue un dato");
                            }
                                opcionE=0;
                            }
                            else
                            {
                                printf("\nNo se pudo ordenar\n");
                                opcionE=0;
                            }
                        break;

                    case 5:
                        printf("\nSaliendo...");
                        break;

                    default:
                        printf("\nSeleccione una opcion valida \n");
                        break;
                    }

                    system("pause");
                    system("cls");
                }
                while(opcionE!=5);
        }
        else
        {
            printf("\nHubo un error");
        }
        break;


            case 2:
            if(inicializarJugadores(jugadores,TAM==0))
            {
            do
            {
                    mostrarMenuJ();
                    opcionJ=getInt("\nSu opcion: ");
                    switch(opcionJ)
                    {
                    case 1:
                       cantidadEquipos=cantidadEquiposOcupados(equipos,TAM);
                        //printf("\n%d",cantidadEquipos);
                            if(cantidadEquipos>0)
                            {
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
                        }
                        else
                        {
                            printf("\nPrimero por favor antes cargue un equipo.");
                        }
                        //hardcodeoJugadores(jugadores);
                        break;

                    case 2:
                        cantidadJugadores=cantidadJugadoresOcupados(jugadores,TAM);
                        if(cantidadJugadores>0)
                        {
                            retorno = bajaJugadores(jugadores,equipos,TAM,getInt("Ingrese el codigo: "));
                            switch(retorno)
                            {
                            case 0:
                                printf("\nSe elimino el jugador\n");
                                break;

                            case 1:
                                printf("\nAccion cancelada por el usuario\n");
                                break;

                            case -1:
                                printf("\nNo se encontro el jugador\n");
                                break;

                            case 2:
                                printf("\nEl jugador se elimino anteriormente o no existe el jugador\n");
                                break;
                            }
                        }
                        else
                        {
                            printf("\nNo hay ningun jugador dado de alta, por favor primero realice una carga\n");
                        }
                        break;

                    /*
                    case 3:
                        cantidadJugadores=cantidadJugadoresOcupados(jugadores,TAM);
                        if(cantidadEquipos>0)
                        {
                            retorno=modificarJugadores(jugadores,equipos,TAM);
                            switch(retorno)
                            {
                            case 0:
                                printf("\nSe modifico el jugador\n");
                                break;

                            case -1:
                                printf("\nNo se pudo modificar el jugador\n");
                                break;

                            case -2:
                                printf("\nSaliendo...\n");
                                break;

                            case -3:
                                printf("\nAccion cancelada por el usuario");
                                break;

                            case -4:
                                printf("\nLa fecha es invalida\n");
                                break;
                            }
                        }
                        else
                        {
                            printf("\nNo hay ningun jugador dado de alta, por favor primero realice una carga\n");
                        }
                        break;
                        */
                    case 3:
                        cantidadJugadores=cantidadJugadoresOcupados(jugadores,TAM);
                        if(cantidadJugadores>0)
                        {
                            if (ordenarJugadoresNombreYApellido(jugadores,TAM,1)==0)
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
                        }
                        else
                        {
                          printf("\nPrimero cargue a un jugador");
                        }

                    case 4:
                        printf("\nSaliendo...");
                        break;
                    /*
                    case 6:
                        printJugadoresPorEquipo(equipos,jugadores,TAM);
                        break;
                    */
                    default:
                        printf("\nSeleccione una opcion valida \n");
                        break;
                    }

                    system("pause");
                    system("cls");
                }
                while(opcionJ!=4);
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
                            opcionR=2;
                        }
                        else
                        {
                            opcionR--;
                            printf("\nNo hay espacio\n");
                            opcionR=2;
                        }
                        //hardcodeoReferis(referis);
                        break;
                        /*
                    case 2:
                        cantidadReferis=cantidadReferisOcupados(referis,TAM);
                        if(cantidadReferis>0)
                        {
                            retorno = bajaReferis(referis,TAM,getInt("Ingrese el codigo: "));
                            switch(retorno)
                            {
                            case 0:
                                printf("\nSe elimino el referi\n");
                                break;

                            case 1:
                                printf("\nAccion cancelada por el usuario\n");
                                break;

                            case -1:
                                printf("\nNo se encontro el referi\n");
                                break;

                            case 2:
                                printf("\nEl referi se elimino anteriormente o no existe el referi\n");
                                break;
                            }
                        }
                        else
                        {
                            printf("\nNo hay ningun referi dado de alta, por favor primero realice una carga\n");
                        }
                        break;

                    case 3:
                        cantidadReferis=cantidadReferisOcupados(referis,TAM);
                        if(cantidadReferis>0)
                        {
                            retorno=modificarReferis(referis,TAM);
                            switch(retorno)
                            {
                            case 0:
                                printf("\nSe modifico el referi\n");
                                break;

                            case -1:
                                printf("\nNo se pudo modificar el referi\n");
                                break;

                            case -2:
                                printf("\nSaliendo...\n");
                                break;

                            case -3:
                                printf("\nAccion cancelada por el usuario");
                                break;

                            case -4:
                                printf("\nLa fecha es invalida\n");
                                break;
                            }
                        }
                        else
                        {
                            printf("\nNo hay ningun referi dado de alta, por favor primero realice una carga\n");
                        }
                        break;
                    */
                    case 2:
                        printReferi(referis,TAM);
                        break;

                    case 3:
                        printf("\nSaliendo...");
                        break;


                    default:
                        printf("\nSeleccione una opcion valida \n");
                        break;
                    }

                    system("pause");
                    system("cls");
                }
                while(opcionR!=3);
        }
        else
        {
            printf("\nHubo un error");
        }
        break;

        case 4:
            if (inicializarPartidos(partidos,TAM==0))
            {
            do
            {
                mostrarMenuP();
                    opcionP=getInt("\nSu opcion: ");
                    switch(opcionP)
                    {
                    case 1:
                        cantidadEquipos=cantidadEquiposOcupados(equipos,TAM);
                        if(cantidadEquipos>0)
                        {
                            codigoP++;
                            if (agregarPartidos(partidos,TAM,codigoP)==0)
                            {
                                printf("\nSe agrego el partido\n");
                                opcionP=0;
                            }
                            else
                            {
                                opcionP--;
                                printf("\nNo hay espacio\n");
                                opcionP=0;
                            }
                        }
                        else
                        {
                            printf("\nTienen que haber al menos dos equipos cargados para poder cargar un partido");
                        }
                        //hardcodeoPartidos(partidos);
                        break;

                    case 2:
                        /*
                        cantidadEquipos=cantidadEquiposOcupados(equipos,TAM);
                        if(cantidadEquipos>=2)
                        {
                            retorno = bajaPartidos(partidos,equipos,referis,TAM,getInt("Ingrese el codigo: "));
                            switch(retorno)
                            {
                            case 0:
                                printf("\nSe elimino el partido\n");
                                break;

                            case 1:
                                printf("\nAccion cancelada por el usuario\n");
                                break;

                            case -1:
                                printf("\nNo se encontro el partido\n");
                                break;

                            case 2:
                                printf("\nEl partido se elimino anteriormente o no existe el referi\n");
                                break;
                            }
                        }
                        else
                        {
                            printf("\nNo hay ningun partido dado de alta, por favor primero realice una carga\n");
                        }
                        break;

                    case 3:
                        cantidadEquipos=cantidadEquiposOcupados(equipos,TAM);
                        if(cantidadEquipos>0)
                        {
                            retorno=modificarPartidos(partidos,referis,equipos,TAM);
                            switch(retorno)
                            {
                            case 0:
                                printf("\nSe modifico el partido\n");
                                break;

                            case -1:
                                printf("\nNo se pudo modificar el partido\n");
                                break;

                            case -2:
                                printf("\nSaliendo...\n");
                                break;

                            case -3:
                                printf("\nAccion cancelada por el usuario");
                                break;

                            case -4:
                                printf("\nLa fecha es invalida\n");
                                break;
                            }
                        }
                        else
                        {
                            printf("\nAntes de realizar algo con un partido tienen que haber al menos dos equipos\n");
                        }
                        break;
                        */

                    case 2:
                        if (ordenarPartidosPorFecha(partidos,TAM,1)==0)
                        {
                            printf("\nSe ordeno correctamente\n");
                            printPartidos(equipos,referis,partidos,TAM);
                            system("pause");
                            opcionP=0;
                        }
                        else
                        {
                            printf("\nNo se pudo ordenar\n");
                            opcionJ=0;
                        }
                        break;

                    case 3:
                        printf("\nSaliendo...");
                        break;

                    default:
                        printf("\nSeleccione una opcion valida \n");
                        break;
                    }

                    system("pause");
                    system("cls");
                }
                while(opcionP!=3);
        }
        else
        {
            printf("\nHubo un error");
        }
        break;

/*
        case 5:
            do
            {
                printf("\nIngrese una validacion: ");
                printf("\n1-Listar jugadores por equipo ");
                printf("\n2-Informar referi que mas partidos dirigio ");
                printf("\n3-Listar jugadores con nombre a eleccion ");
                printf("\n4-Listar equipo/s con nombre mas largo ");
                printf("\n5-Listar referi/partidos con x fecha ");
                printf("\n6-Listar equipo mas joven");
                printf("\n7-Listar partidos ordenados por arbitro: ");
                printf("\n8-Listar todos los arbitros que estan en mas de 4 partidos");
                printf("\n9-Jugadores ordenados por sexo: ");
                opcionV=getInt("\nSu opcion: ");

                switch(opcionV)
                {
                    case 1:
                        printJugadoresPorEquipo(equipos,jugadores,TAM);
                        break;

                    case 2:
                        referiMasPartidos(referis,partidos,TAM);
                        break;

                    case 3:
                        if(listarNombres(equipos,jugadores,TAM)==1)
                        {
                            //TODO OK
                        }
                        else
                        {
                            printf("\nNo se encontraron jugadores con el nombre ingresado");
                        }
                        break;

                    case 4:
                        listarEquiposNombreMasLargo(equipos,TAM);
                        break;

                    case 5:
                        if(listarPorFechaPartido(equipos,partidos,referis,TAM)==1)
                        {
                            //TODO OK
                        }
                        else
                        {
                            printf("\nNo se encontro un partido con esa fecha");
                        }
                        break;

                    case 6:
                        equipoMasJoven(equipos,jugadores,TAM);
                        break;

                    case 7:
                        ordenarReferisNombreyApellido(referis,TAM,1);
                        printPartidosPorArbitro(partidos,referis,equipos,TAM);
                        break;

                    case 8:
                        if(arbitrosqueEstanMas4Partidos(referis,partidos,TAM)==1)
                        {
                            //TODO OK
                        }
                        else
                        {
                            printf("\nNingun arbitro dirigio mas de 4 partidos");
                        }
                        break;

                    case 9:
                        if(ordenarJugadoresPorSexo(jugadores,TAM)==1)
                        {
                            printf("Se ordeno");
                            printJugadores(equipos,jugadores,TAM);
                        }
                        else
                        {
                            printf("\nNo se pudo ordenar");
                        }
                        printf("\nEN DESARROLLO");
                        break;

                    default:
                        printf("\nSeleccione una opcion valida \n");
                        break;

                }
                    system("pause");
                    system("cls");
            }
            while(opcionE!=5);
            break;
*/
        case :
            printf("Saliendo...");
            break;


    default:
        printf("\nSeleccione una opcion valida \n");
        break;
    }

    system("pause");
    system("cls");
} while(opcion!=5);

    return 0;
}
