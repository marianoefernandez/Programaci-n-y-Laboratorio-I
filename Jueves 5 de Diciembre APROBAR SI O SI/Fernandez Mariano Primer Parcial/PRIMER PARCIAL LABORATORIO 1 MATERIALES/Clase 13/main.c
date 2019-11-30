#include "Estacionamiento.h"

int main()
{
    int opcion;
    int auxOption;
    int auxId;
    int id=1;
    int auxInt;
    ePropietario persona[LENP];
    eVehiculo vehiculo[LENA];

    initPropietarios(persona,LENP);
    initVehiculos(vehiculo,LENA);
    hardcodePropietarios(persona);
    ///No anda el Hardcode, revisar.
//    hardcodearPersonas(persona,LENP);
//    hardcodearVehiculo(vehiculo,LENA);


    do
    {
//        system("cls");
        opcion=showMenuGetOption("Ingrese la opcion deseada:\n\n1.Cargar un propietario.\n2.Eliminar un propietario.\n3.Modificar datos de un propietario.\n4.Ingresar un vehiculo.\n5.Egresar un vehiculo.\n6.Informar.\n7.Salir.\n\n",1,7);

        switch (opcion)
        {
        case 1:
            if(cargarPropietario(persona,LENP,id)==0)
            {
                showMessage("El empleado se cargo con exito.\n");
                id++;
            }else{
                showMessage("Hubo un error al cargar el empleado.\n");
            }
            break;
        case 2:
            system("cls");
            auxId=getPositiveInt("Ingrese el id del propietario que desea eliminar:\n");
            removeElement(persona,LENP,auxId);
            break;
        case 3:
            system("cls");
            auxId=getPositiveInt("Indique el ID del propietario a modificar:\n\n");
            auxInt=buscarIndicePropietario(persona,LENP,auxId);
            mostrarPersonaPorIndice(persona,auxInt);
            printf("\n");
            auxOption=showMenuGetOption("Se muestra el propietario. Indique el campo a modificar.\n\n1)Nombre.\n2)Dia de nacimiento.\n3)Mes de nacimiento.\n4)Anio de nacimiento.\n5)Cancelar.\n",1,5);
            switch(auxOption)
            {
            case 1:
                modName(persona,auxInt);
                break;
            case 2:
                modDay(persona,auxInt);
                break;
            case 3:
                modMonth(persona,auxInt);
                break;
            case 4:
                modYear(persona,auxInt);
                break;
            case 5:
                break;
            }
            break;
        case 4:
            cargarVehiculo(vehiculo,LENA);
            break;
        case 5:
            egresarVehiculo(vehiculo,LENA);
            break;
        case 6:
            auxOption=showMenuGetOption("1)Todos los propietarios ordenador por nombre y año de nacimiento\n2)Todos los vehiculos ordenados por duenio y patente.\n3)Cada auro con el nombre de su duenio.\n4).\n5).\n6).\n7)Mostrar cuanto debera pagar cada dueño por todos sus autos estacionados.\n8).\n9)Salir.\n\n",1,9);
            switch(auxOption)
            {
            case 1:
                sortElementsByStringAndInt(persona,LENP,1);
                mostrarPersonas(persona,LENP);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                mostrarTarifaPorDuenio(persona,vehiculo,LENA,LENP);
                break;
            case 8:
                break;
            case 9:
                break;
            }
            break;
        case 7:
            break;
        }
    }while (opcion!=7);

    return 0;
}

