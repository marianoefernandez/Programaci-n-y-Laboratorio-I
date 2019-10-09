#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define LENP 100
#define LENA 1000

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idPropietario;
    char nombre[51];
    int estaVacio;
    eFecha fechaNac;
}ePropietario;

typedef struct
{
    char patente[8];
    eFecha fechaIngreso;
    int horaIngreso;
    int horaSalida;
    int idPropietario;
    int estaEstacionado;
    int isEmpty;
}eVehiculo;

void hardcodearPersonas(ePropietario*,int);

void hardcodearVehiculo(eVehiculo*,int);



//void mostrarPersonas (ePropietario*,int);

int buscarIndicePropietario(ePropietario*,int,int);

void mostrarPersonaPorIndice (ePropietario*,int);

//void mostrarPersonaPorID (ePropietario*,int,int);



void mostrarVehiculoPorIndice(eVehiculo*,int);

void mostrarVehiculoPorID(ePropietario*,eVehiculo*,int,int,int);

//void mostrarVehiculoPorPatente(ePropietario*, eVehiculo*,int,int);

int calcularTarifaAuto(eVehiculo*,int,int);

void mostrarTodasLasTarifas (eVehiculo*, int);


void mostrarTarifaPorDuenio (ePropietario*,eVehiculo*,int,int);

void mostrarPersonasYSusVehiculos (ePropietario*, eVehiculo*, int, int);

void mostrarVehiculosYDuenios(ePropietario*,eVehiculo*,int,int);

void mostrarPersonaConMasAutos(ePropietario*,eVehiculo*,int,int);

int cargarPropietario(ePropietario*,int,int);

int getAlphabeticalString (char[],char[],int);

void showMessage(char message[]);

int initPropietarios(ePropietario* persona, int len);

int getPositiveInt(char message[]);

void printTab ();

int findElementById(ePropietario* list, int len,int id);

int removeElement(ePropietario* list, int len, int id);

int getConfirm();

int showMenuGetOption(char message[], int min, int max);

int modName(ePropietario* persona, int i);

int modDay(ePropietario* persona, int i);

int modMonth(ePropietario* persona, int i);

int modYear(ePropietario* persona, int i);

void cargarVehiculo(eVehiculo* vehiculo,int len);

int initVehiculos(eVehiculo* vehiculo, int len);

int getAlphanumericalString (char message[],char string[],int maxLen);

void egresarVehiculo(eVehiculo*,int);

void hardcodePropietarios (ePropietario* list);

int sortElementsByStringAndInt(ePropietario* list, int len, int order);

void mostrarPersonas (ePropietario persona[], int lenP);


void printSeparation();
void printTabP();
void printTabA();


///ordenarPorPatente
///ordenarPorNombreDuenio
