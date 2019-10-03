#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

 void cargarPersonas(ePersona personas[], int cantidad){
     int dias[]= {33,22,25,11 };
     int mes[]= {3,4,12,11 };
     int anios[] = {1990,1980,2000,1995};
     char nombres[][50] = {"Maria","Ezequiel","German","Yanina"};
     int i;
     int id[]={100,101,105,106};
     for (i=0;i< cantidad;i++)
     {
        personas[i].fechaNac.anio = anios[i];
        personas[i].fechaNac.mes = mes[i];
        personas[i].fechaNac.dia = dias[i];
        strcpy(personas[i].nombre,nombres[i]);
        personas[i].id=id[i];
     }
 }
 void cargarVehiculos(ePersona personas[], int cantidad){
     int dias[]= {33,22,25,11 };
     int mes[]= {3,4,12,11 };
     int anios[] = {1990,1980,2000,1995};
     char nombres[][50] = {"Maria","Ezequiel","German","Yanina"};
     int i;
     for (i=0;i< cantidad;i++)
     {
        personas[i].fechaNac.anio = anios[i];
        personas[i].fechaNac.mes = mes[i];
        personas[i].fechaNac.dia = dias[i];
        strcpy(personas[i].nombre,nombres[i]);
        personas[i].id = i+1;
     }
 }
 void mostrarPersonas(ePersona personas[], int cantidad){
    int i;
    printf("DUE%cOS",165);
     for (i=0;i< cantidad;i++)
     {
        printf("%04d %20s %02d/%02d/%4d\n",personas[i].id,personas[i].nombre,personas[i].fechaNac.dia,personas[i].fechaNac.mes,personas[i].fechaNac.anio);
     }
 }

 void mostrarVehiculos(ePersona personas[],eVehiculo vehiculos[], int cantidad, int cantPersonas){
    int i;
     for (i=0;i< cantidad;i++)
     {
        printf("\nNombre :%s \t",buscarPersona
            (personas,cantPersonas,vehiculos[i].idDuenio).nombre);
        printf(" dia :%d \t", vehiculos[i].fechaIngreso.dia) ;
        printf(" mes  :%d \t", vehiculos[i].fechaIngreso.mes) ;
        printf(" ano :%d \n", vehiculos[i].fechaIngreso.anio) ;
        printf(" Hora Ingreso :%d \t", vehiculos[i].horaIngreso) ;
        printf(" Hora Salida :%d \t", vehiculos[i].horaSalida) ;
        printf(" patente :%s \t", vehiculos[i].patente) ;
     }
 }
ePersona buscarPersona(ePersona personas[], int cantidad, int id){
    int i;
     for (i=0;i< cantidad;i++)
     {
       if(id == personas[i].id)
        return personas[i];
     }
     return ;
}
 int buscarIndicePersona(ePersona personas[], int cantidad, int id){
     int i;
     for (i=0;i< cantidad;i++)
     {
       if(id == personas[i].id)
        return i;
     }
     return -1;
 }


