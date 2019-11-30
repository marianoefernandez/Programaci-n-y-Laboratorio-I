#include "utn.h"
#define E 10
#define J 35
#define R 6
#define P 25


int main()
{
    sJugadores listJugadores[J];
    sEquipos listEquipos[E];
    sReferi listReferees[R];
    sPartidos listPartidos[P];
    int opcion;
    int idJugadores= 1;
    int idEquipos = 1;
    int idReferee = 1;
    int idPartidos = 1;
    int r;

    if((inicializarEquipos(listEquipos, E)==0 && inicializarJugadores(listJugadores, J)==0) &&
            (inicializarReferees(listReferees, R)==0 && inicializarPartidos(listPartidos, P)==0))
    {
        do
        {
            printf("Que desea hacer\n\n");
            printf("1.ALTA EQUIPO\n");
            printf("2.LISTAR EQUIPOS\n");
            printf("3.ALTA JUGADOR\n");
            printf("4.LISTAR JUGADORES\n");
            printf("5.ALTA REFEREE\n");
            printf("6.ALTA PARTIDO\n");
            printf("7.LISTAR PARTIDOS\n");
            printf("8.MODIFICAR EQUIPO\n");
            printf("9.BAJA EQUIPO\n");
            printf("10.BAJA JUGADOR\n");
            printf("11.LISTAR JUGADORES POR EQUIPO\n");
            printf("12.REFERI CON MAS PARTIDOS DIRIGIDOS\n");
            printf("13.LISTAR JUGADORES POR NOMBRE\n");
            printf("14.LISTAR EQUIPOS CON NOMBRE MAS LARGO.\n");
            printf("15.LISTAR PARTIDOS POR FECHA\n");
            printf("16.LISTAR EQUIPO MAS JOVEN\n");
            printf("17. SALIR\n");
            printf("Ingrese una opcion : ");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                /*r=cargarEquipo(listEquipos, E,idEquipos);
                if(r==0)
                {
                    printf("Equipo cargado.\n");
                    idEquipos ++;
                }
                else
                {
                    printf("No hay mas espacio de equipos.\n");
                }*/
                hardcodeoEquipos(listEquipos, E);
                break;
            case 2:
                if(flagEquipos(listEquipos, E)==0)
                {
                    ordenarEquiposPorNombre(listEquipos, E);
                    mostrarListadoDeEquipos(listEquipos, E);
                }
                else
                {
                    printf("No hay equipos cargados.\n");
                }
                break;
            case 3:
                /*r=cargarJugador(listJugadores,listEquipos,J,E,idJugadores);
                if(r==0)
                {
                    printf("Jugador cargado exitosamente.\n\n");
                    idJugadores++;

                }
                else
                {
                    printf("No hay mas espacio de jugadores\n\n");
                }*/
                hardcodeoJugadores(listJugadores, J);


                break;
            case 4:
                if(flagJugadores(listJugadores, J)==0)
                {
                    ordenarJugadoresPorApellido(listJugadores, J);
                    mostrarListadoDeJugadores(listJugadores,J);
                }
                else
                {
                    printf("No hay jugadores cargados\n");
                }

                break;
            case 5:
                /*r= cargarReferi(listReferees, R,idReferee);
                 if(r==0)
                 {
                     printf("Referi cargado\n");
                     idReferee ++;
                 }
                 else
                 {
                     printf("No hay mas espacio de referees\n");
                 }*/
                hardcodeoReferees(listReferees, R);
                break;
            case 6:
                /*r = cargarPartido(listPartidos,listEquipos,listReferees, P,E,R,idPartidos);
                if(r==0)
                {
                    printf("Partido cargado\n");
                    idPartidos ++;
                }
                else
                {
                    printf("No hay mas espacio de partidos.\n");
                }*/
                hardcodeoPartidos(listPartidos, P);
                break;
            case 7:
                if(flagPartidos(listPartidos, P)==0)
                {
                    ordenarPartidosPorFecha(listPartidos, P);
                    mostrarListadoDePartidos(listPartidos, P);
                }
                else
                {
                    printf("No hay partidos cargados.\n");
                }
                break;
            case 8:
                if(flagEquipos(listEquipos, E)==0)
                {
                    r = modificarEquipo(listEquipos, E);
                    if(r == 0)
                    {
                        printf("Equipo modificado.\n");
                    }
                    else if(r==1)
                    {
                        printf("Accion cancelada.\n");
                    }
                    else
                    {
                        printf("No se encontro al equipo.\n");
                    }
                }
                else
                {
                    printf("No hay equipos cargados.\n");
                }
                break;
            case 9:
                if(flagEquipos(listEquipos, E)==0)
                {
                    r = bajarEquipo(listEquipos, E);
                    if(r == 0)
                    {
                        printf("Equipo eliminado.\n");
                    }
                    else if(r==1)
                    {
                        printf("Accion cancelada.\n");
                    }
                    else
                    {
                        printf("No se encontro al equipo.\n");
                    }
                }
                else
                {
                    printf("No hay equipos cargados.\n");
                }
                break;
            case 10:
                if(flagJugadores(listJugadores, J)==0)
                {
                    r = bajarJugador(listJugadores, J);
                    if(r == 0)
                    {
                        printf("Jugador eliminado.\n");
                    }
                    else if(r==1)
                    {
                        printf("Accion cancelada.\n");
                    }
                    else
                    {
                        printf("No se encontro al Jugador.\n");
                    }
                }
                else
                {
                    printf("No hay jugadores cargados.\n");
                }
                break;
            case 11:
                if(flagJugadores(listJugadores, J)==0 && flagEquipos(listEquipos, E)==0)
                {
                    r = mostrarJugadoresPorEquipo(listJugadores,listEquipos, J,E);
                    if(r == 0)
                    {
                        printf("Jugadores listados exitosamente.\n");
                    }
                    else
                    {
                        printf("No se encontro al Jugador.\n");
                    }
                }
                else
                {
                    printf("Faltan jugadores o equipos a cargar.\n");
                }
                break;
            case 12:
                if(flagReferees(listReferees,R)==0)
                {
                    mostrarReferiConMasPartidos(listReferees,listPartidos,R,P);
                }
                else
                {
                    printf("No hay referees cargados.\n");
                }
                break;
            case 13:
                if(flagJugadores(listJugadores, J)==0)
                {
                    r = mostrarJugadoresPorNombre(listJugadores, J);
                    if(r==0)
                    {
                        printf("Jugadores mostrados exitosamente.\n");
                    }
                    else
                    {
                        printf("Ningun jugador con ese nombre encontrado.\n");
                    }
                }
                else
                {
                    printf("No hay jugadores cargados.\n");
                }
                break;
            case 14:

                break;
            case 15:
                if(flagPartidos(listPartidos,P)==0)
                {
                    r=mostrarPartidosPorFecha(listPartidos,P);
                    if(r==0)
                    {
                        printf("Partidos listados exitosamente.\n");
                    }
                    else
                    {
                        printf("No se encontro ningun partido con esa fecha.\n");
                    }
                }
                else
                {
                    printf("No hay partidos cargados.\n");
                }
                break;
            case 16:
                promedioEdadesPorEquipo(listJugadores,listEquipos,J,E);
                break;

            default:
                printf("\nNo has elegido una opcion valida.\n\n");
                break;

            }
            system("pause");
            system("cls");
        }
        while(opcion != 15);
    }
    else
    {
        printf("\nNo se pudo iniciar el menu\n");
    }

    return 0;
}
