#include <stdio.h>
#include <stdlib.h>
#define TAM 4

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    char patente [50];
    eFecha fechaIngreso;
    int horaIngreso;
    int horaSalida;
    int idDuenio;
}eVehiculo;

typedef struct
{
    int id;
    char nombre[31];
    eFecha fechaNac;
}ePersona;

void hardcodeoPersonas(ePersona*,int);
void mostrarPersona(ePersona);
void mostrarListadoDePersonas(ePersona*,int);
void hardcodeoVehiculos(eVehiculo*,int);
void buscarIndicePersona (ePersona*,int,int);//HACER
void mostrarListadoDeVehiculos(ePersona*,eVehiculo*,int);
ePersona cargarPersonas (int);




int main()
{
    ePersona persona[TAM];
    eVehiculo vehiculo[TAM];
    hardcodeoPersonas(persona,TAM);
    mostrarListadoDePersonas(persona,TAM);
    hardcodeoVehiculos(vehiculo,TAM);
    mostrarListadoDeVehiculos(persona,vehiculo,TAM);
    return 0;
}

ePersona cargarPersonas(int cantidad)
{
    ePersona persona[cantidad];
    int i;
    int id=0;
    for (i=0;i<cantidad;i++)
    {
       id++;
       persona[i].id = id;
       strcpy(persona[i].nombre,getString("\nIngrese un nombre: ",cantidad));
       persona[i].fechaNac.anio,getInt("\nIngrese un anio: ",cantidad);
       persona[i].fechaNac.mes,getInt("\nIngrese un mes: ",cantidad);
       persona[i].fechaNac.dia,getInt("\nIngrese un dia ",cantidad);
    }
    return *persona;
}

void hardcodeoPersonas(ePersona* persona, int cantidad) //TERMINADA
{
    int id[4] = {1,2,3,4};
    char nombre[4][31] = {"Maria","Ezequiel","German","Yanina"};
    int anio[4] = {1990,1980,2000,1995};
    int mes[4] = {3,4,12,11};
    int dia[4] = {33,22,25,11};
    int i;

    for (i=0; i<cantidad; i++)
    {
        persona[i].id = id[i];
        strcpy(persona[i].nombre, nombre[i]);
        persona[i].fechaNac.anio = anio[i];
        persona[i].fechaNac.mes = mes[i];
        persona[i].fechaNac.dia = dia[i];
    }
}

void hardcodeoVehiculos(eVehiculo* vehiculo, int cantidad) //TERMINADA
{
    int id[4] = {1,2,2,4};
    char patente[4][31] = {"AAA111","BBB222","AA111BB","DJ222BB"};
    int anio[4] = {2019,2019,2019,2019};
    int mes[4] = {9,9,9,9};
    int dia[4] = {26,26,26,26};
    int horaIngreso[4] = {10,9,8,11};
    int horaSalida[4] = {11,11,11,12};
    int i;

    for (i=0; i<cantidad; i++)
    {
        vehiculo[i].idDuenio = id[i];
        strcpy(vehiculo[i].patente, patente[i]);
        vehiculo[i].fechaIngreso.anio = anio[i];
        vehiculo[i].fechaIngreso.mes = mes[i];
        vehiculo[i].fechaIngreso.dia = dia[i];
        vehiculo[i].horaIngreso = horaIngreso[i];
        vehiculo[i].horaSalida = horaSalida[i];
    }
}

void mostrarPersona(ePersona persona)
{
    printf("%d -- %10s %15d %20d %10d\n\n", persona.id, persona.nombre, persona.fechaNac.anio, persona.fechaNac.mes, persona.fechaNac.dia);
}

void buscarIndicePersona (ePersona* persona, int cantidad, int id)//HACER
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        if (id == persona[i].id)
            return i;
    }
    return -1;
}


void mostrarListadoDePersonas(ePersona* persona , int cantidad)
{
    int i;
    printf("ID --     NOMBRE           ANIO                   MES        DIA\n\n");
    for(i=0; i<cantidad; i++)
    {
        //if de estado
        mostrarPersona(persona[i]);
    }
}

void mostrarListadoDeVehiculos(ePersona* persona , eVehiculo* vehiculo,int cantidad)
{
    int i;
        for (i=0;i<cantidad;i++)
        {
            printf("\nNombre: %s", persona[buscarIndicePersona(persona,cantidad,vehiculo[i].idDuenio)].nombre);
            printf("\nDia: %d",vehiculo[i].fechaIngreso.dia);
            printf("\nMes: %d",vehiculo[i].fechaIngreso.mes);
            printf("\nAnio: %d",vehiculo[i].fechaIngreso.anio);
            printf("\nHora de ingreso: %d",vehiculo[i].fechaIngreso.dia);
            printf("\nHora de salida: %d",vehiculo[i].horaIngreso);
            printf("\nPatente: %s",vehiculo[i].patente);
        }
}

