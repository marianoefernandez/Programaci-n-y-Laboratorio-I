#include <stdio.h>
#include <string.h>
#define NOTFREE 1
#define FREE 0
#define HARDCODING 10
#include "Jugadores.h"
#include "Referi.h"
#include "Partido.h"


//ESTRUCTURAS
typedef struct
{
    int codigo;
    char nombre[52];
    char localidad[34];
    int isEmpty;
}eEquipo;


//0-MENUS
void mostrarMenuE();
/** \brief Muestra menu
 *
 *
 */

void printModificationMenuE();

//1-INICIALIZAR
int inicializarEquipos(eEquipo*,int);
/** \brief Inicializa todos los equipos en la variable los pone libre
 *
 * \param puntero a estructura eEquipo
 * \param longitud array
 * \return retorna -1 si hay error y 0 si todo ok
 *
 */

int getFreeE(eEquipo*,int); //TERMINADA
/** \brief Busca pos libre del array
 *
 * \param puntero a estructura eEquipo
 * \param longitud array
 * \return retorna -1 si hay error y indice del array si todo ok
 *
 */

 int buscarEquipoPorCodigo(eEquipo*, int, int);




//2-ALTAS/BAJAS/MODIFICACION
int agregarEquipo(eEquipo*,int,int);
/** \brief Agrega todos los equipos que el usuario quiera
 *
 * \param puntero a estructura eEquipo
 * \param longitud array
 * \return retorna -1 si hay error y 0 si todo ok
 *
 */

int modificarEquipo(eEquipo*,int);

int modificarJugadores(eJugadores*,eEquipo*,int);

int modificarPartidos(ePartido*,eReferi*,eEquipo*,int);

int bajaEquipo(eEquipo*,int,int);

int bajaJugadores(eJugadores*,eEquipo*,int,int);

int bajaPartidos(eReferi*,eEquipo*,eReferi*,int,int);


//3-ORDENAR

int ordenarEquiposNombreYLocalidad(eEquipo*,int,int);
/** \brief Ordena los equipos por nombre y localidad
 *
 * \param puntero a estructura eEquipo
 * \param longitud array
 * \return retorna -1 si hay error y 0 si todo ok
 *
 */

//4- MOSTRAR

void printEquipo(eEquipo equipo);
/** \brief Imprime info de un equipo
 *
 * \param estructura eEquipo
 *
 */

int printJugadores(eEquipo*,eJugadores*, int);


int printEquipos(eEquipo* equipo, int len);
/** \brief Imprime info de una lista de equipos
 *
 * \param Puntero de la estructura eEquipo
 * \param longitud del array
 * \return retorna 0
 *
 */

 int printPartidos(eEquipo*,eReferi*,ePartido*,int);

 //5-EXTRAS

int cantidadEquiposOcupados(eEquipo*,int);
void hardcodeoEquipos(eEquipo*);

//6-VALIDACIONES

int printJugadoresPorEquipo(eEquipo*,eJugadores*,int);
int referiMasPartidos(eReferi*, ePartido*, int);
int listarNombres(eEquipo*,eJugadores*,int);
int listarEquiposNombreMasLargo(eEquipo*,int);
int listarPorFechaPartido(eEquipo*,ePartido*,eReferi*,int);
int equipoMasJoven(eEquipo*,eJugadores*,int);
int printPartidosPorArbitro(ePartido*,eReferi*,eEquipo*,int);
int arbitrosqueEstanMas4Partidos(eReferi*,ePartido*,int);
