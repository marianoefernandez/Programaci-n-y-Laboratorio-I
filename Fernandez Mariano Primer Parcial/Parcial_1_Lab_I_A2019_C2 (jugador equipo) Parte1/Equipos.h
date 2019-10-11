#include <stdio.h>
#include <string.h>
#define NOTFREE 1
#define FREE 0
#define HARDCODING 10

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


//2-ALTAS
int agregarEquipo(eEquipo*,int,int);
/** \brief Agrega todos los equipos que el usuario quiera
 *
 * \param puntero a estructura eEquipo
 * \param longitud array
 * \return retorna -1 si hay error y 0 si todo ok
 *
 */


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

int printEquipos(eEquipo* equipo, int len);
/** \brief Imprime info de una lista de equipos
 *
 * \param Puntero de la estructura eEquipo
 * \param longitud del array
 * \return retorna 0
 *
 */


