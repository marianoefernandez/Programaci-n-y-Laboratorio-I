#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1


typedef struct
{
    int dia;
    int mes;
    int anio;
} sFecha;

typedef struct
{
    int codigo;
    char nombre[51];
    char localidad[33];
    int estado;
} sEquipos;

typedef struct
{
    int codigo;
    char apellido[31];
    char nombre[31];
    int codigoDeEquipo;
    char sexo;
    sFecha fechaNacimiento;
    int estado;
} sJugadores;

typedef struct
{
    int codigo;
    char apellido[31];
    char nombre[31];
    char sexo;
    char eMail[31];
    sFecha fechaNacimiento;
    int estado;
} sReferi;

typedef struct
{
    int codigo;
    int codigoDeEquipoVisitante;
    int codigoDeEquipoLocal;
    int codigoDeReferi;
    sFecha fechaDePartido;
    int estado;
} sPartidos;


int onlyLetters(char []);
char* enterString(char*);
int enterInt(char []);
float enterFloat(char []);
int validarSexo(char);
int validarEmail(char []);
int relacionJugadorEquipo(sJugadores,sEquipos [],int);
int relacionPartidoEquipoLocal(sPartidos, sEquipos [], int);
int relacionPartidoEquipoVisitante(sPartidos, sEquipos [], int);
int relacionPartidoReferi(sPartidos, sReferi [], int);
int mostrarJugadoresPorEquipo(sJugadores [], sEquipos [], int,int);
int mostrarReferiConMasPartidos(sReferi [],sPartidos [],int, int);
int mostrarPartidosPorFecha(sPartidos [], int);
void promedioEdadesPorEquipo(sJugadores [],sEquipos [],int, int);

//Equipos
void hardcodeoEquipos(sEquipos [], int);
int inicializarEquipos(sEquipos [], int);
int cargarEquipo(sEquipos [], int, int);
int buscarLibreEquipos(sEquipos [], int);
void mostrarUnEquipo(sEquipos);
void mostrarListadoDeEquipos(sEquipos [], int);
int ordenarEquiposPorNombre(sEquipos [],int);
int flagEquipos(sEquipos [], int);
int modificarEquipo(sEquipos [],int);
int buscarEquipoPorCodigo(sEquipos [], int );
int bajarEquipo(sEquipos [], int);
void mostrarEquipoMasLargo(sEquipos [], int);


//Jugadores
void hardcodeoJugadores(sJugadores [], int);
int inicializarJugadores(sJugadores [], int);
int cargarJugador(sJugadores [],sEquipos[],int, int, int);
int buscarLibreJugadores(sJugadores [], int);
void mostrarUnJugador(sJugadores);
void mostrarListadoDeJugadores(sJugadores [], int);
int ordenarJugadoresPorApellido(sJugadores [],int);
int flagJugadores(sJugadores [], int);
int buscarJugadorPorCodigo(sJugadores [], int );
int bajarJugador(sJugadores [], int);
int mostrarJugadoresPorNombre(sJugadores [],int);



//Referees
void hardcodeoReferees(sReferi [], int);
int inicializarReferees(sReferi [], int);
int cargarReferi(sReferi [], int, int);
int buscarLibreReferees(sReferi [], int);
void mostrarUnReferee(sReferi);
void mostrarListadoDeReferees(sReferi [], int);
int flagReferees(sReferi [], int);




//Partidos
void hardcodeoPartidos(sPartidos [], int);
int inicializarPartidos(sPartidos [], int);
int cargarPartido(sPartidos [],sEquipos[],sReferi[],int,int,int, int);
int buscarLibrePartidos(sPartidos [], int);
void mostrarUnPartido(sPartidos);
void mostrarListadoDePartidos(sPartidos [], int);
int ordenarPartidosPorFecha(sPartidos [],int cant);
int flagPartidos(sPartidos [],int);
