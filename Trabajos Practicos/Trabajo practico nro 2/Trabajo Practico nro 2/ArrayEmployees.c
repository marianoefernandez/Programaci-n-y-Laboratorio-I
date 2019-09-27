#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "inputs.h"



//0-MUESTRO MENUES (3 de 3)
void printFirstMenu()
{
    printf("-----BIENVENIDO POR FAVOR INGRESE UNA OPCION-----\n");
    printf("\n1-Dar de alta a un empleado: ");
    printf("\n2-Modificar empleado: ");
    printf("\n3-Dar de baja a un empleado: ");
    printf("\n4-Informar: ");
}

void printSecondMenu()
{
    printf("\n\n1-Ordenar empleados por apellido y sector: ");
    printf("\n\n2-Calcular total de salarios, el salario promedio y cuantos empleados superan el salario promedio: ");
}

//MENU DE MODIFICACION
void printModificationMenu()
{
    printf("¿Qué desea modificar?\n");
    printf("1.Nombre\n");
    printf("2.Apellido\n");
    printf("3.Salario\n");
    printf("4.Sector\n");
}

//SWITCH DEL PRIMER MENU (FALTA) QUE MUESTRE MENU Y LUEGO SWITCH CON DO/WHILE (FUNCION PRINCIPAL POR ESTA PASA TODO)
void opcionesMenuPrincipal(eEmpleado* empleados ,int seCargo)
{
    int opcion;
    int retorno;

    do
        {
            menuPrincipal();
            opcion=getInt("\nSu opcion: ");

            switch(opcion)
            {
            case 1:
                if (agregarEmpleados(empleados,TAM)== 0)
                {
                    printf("\nSe cargo el empleado\n");
                }
                else
                {
                    printf("\nNO HAY ESPACIO\n");
                }
                /*hardcodeoEmpleados(empleados,1);
                printf("\nSe hardcodearon empleados");
                */
                seCargo=1;

                break;

            case 2:
                if (seCargo==1)
                {
                    //MODIFICAREMPLEADO
                }else
                {
                    printf("\nSe elimino el empleado\n");
                }
                break;

            case 3:
                if (seCargo==1)
                {
                    retorno = bajaEmpleado(empleados,TAM);
                    switch(retorno)
                    {
                    case 0:
                        printf("\nSe elimino el empleado\n");
                        break;
                    case 1:
                        printf("\nAccion cancelada por el usuario\n");
                        break;
                    case -1:
                        printf("\nNo se encontro el dato\n");
                        break;
                    }
                }
                else
                {
                    printf("Por favor primero realice una carga");
                }
                    break;

            case 4:
                if (seCargo==1)
                {
                    opcionesMenuSecundario(empleados);
                }
                else
                {
                    printf("Por favor primero realice una carga");
                }
                break;
            default:
                printf("Seleccione una opcion valida ");

            }
            system("pause");
            system("cls");
        }while(opcion!=0);
}

//SWITCH DEL SEGUNDO MENU (FALTA)
void opcionesMenuSecundario(eEmpleado* empleados)
{
    int opcion;
    int retorno;

    do
        {
            menuSecundario();
            opcion=getInt("\nSu opcion: ");

            switch(opcion)
            {
            case 1:
                ordenarEmpleadosApellido(empleados,TAM,1);
                ordenarEmpleadosSector(empleados,TAM);
                mostrarListadoDeEmpleados(empleados,TAM);
                system("pause");
                opcionesMenuPrincipal(empleados,1);
                break;

            case 2:
                //SACAR PROMEDIO Y LO OTRO (FALTA)
                break;

            default:
                printf("Seleccione una opcion valida ");

            }
            system("pause");
            system("cls");
        }while(opcion!=0);
}

//SWITCH DEL MENU DE MODIFICACION (FALTA)

//1-FUNCIONES PARA INICIALIZAR (1.5 de 2) //LA DEL ID NO SE SI FUNCIONA
int initEmployees(Employee* list, int len)
{
    int i;
    int retorno=-1;

    if(list!=NULL && len>0)
    {
        for (i=0; i<len; i++)
        {
            list[i].isEmpty = FREE;
        }
        retorno=0;
    }

    return retorno;
}

/*
int getId (int* n)
{
    *n=*n+1;
    return &n;
}
*/

int getId(Employee* list, int len)
{
    int retorno=0;
    int i;
    if(len > 0 && list != NULL)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == NOTFREE)
            {
                if(list[i].id > retorno)
                {
                    retorno = list[i].id;
                }
            }
        }
    }
    return retorno+1;
}

//2-FUNCIONES PARA AÑADIR (2 de 3)

eEmpleado pedirEmpleado(void) //FALTA PROBAR BIEN
{
    eEmpleado empleados;
    int sector;
    float salario;
    char auxsector [30];
    char auxsalario [30];

    //int* n=0;//ID AUTOINCRMENTAL PARA QUE NUNCA SE PISE EN NINGUNA FUNCION, POR ESO ES PUNTERO

    //LLAMAMOS A GENERAR ID EN ID

    //empleados.id=id;//NO SE SI SIRVE

    empleados.id = getInt("Ingrese id: ");

    getString("Ingrese nombre: ",empleados.nombre);//NOMBRE
    while(isOnlyLetters(empleados.nombre) == 0)
    {
        getString("\nPOR FAVOR SOLO INGRESE LETRAS\n\n Ingrese el nombre nuevamente: ",empleados.nombre);//VALIDACION
    }
    stringToUpper(empleados.nombre);

    getString("Ingrese apellido: ",empleados.apellido);//APELLIDO
    while(isOnlyLetters(empleados.apellido) == 0)
    {
        getString("\nPOR FAVOR SOLO INGRESE LETRAS\n\n Ingrese el nombre nuevamente: ",empleados.apellido);//VALIDACION
    }
    stringToUpper(empleados.apellido);

    getString("Ingrese salario: ",auxsalario);//SALARIO
    while(isNumeric(auxsalario) == 0)
    {
        getString("\nPOR FAVOR SOLO INGRESE NUMEROS\n\n Ingrese el salario nuevamente: ",auxsalario);//SALARIO

    }
    salario=atoi(auxsalario);//ARREGLAR
    empleados.salario = salario;//ARREGLAR

    getString("Ingrese sector: ",auxsector);//SECTOR
    while(isNumeric(auxsector) == 0)
    {
        getString("\nPOR FAVOR SOLO INGRESE NUMEROS\n\n Ingrese el sector nuevamente: ",auxsector);//SECTOR

    }
    sector=atoi(auxsector);//ARREGLAR
    empleados.sector = sector;//ARREGLAR

    empleados.estado = LIBRE;
    return empleados;
}

int buscarLibre(eEmpleado* empleado,int cantidad) //TERMINADA
{
    int i;
    int index = -1;//DEFINIMOS VALOR
    for (i=0;i<cantidad;i++)
    {
        if (empleado[i].estado == LIBRE)
        {
            index = i;
            break;//SI DEVUELVE -1 NO HAY ESPACIO
        }
    }
    return index;
}

int agregarEmpleados (eEmpleado* empleados,int cantidad) //TERMINADA
{
    int i;
    //int id;
    int retorno=-1;
    //id=generarId(empleados,TAM);
    i = buscarLibre(empleados,cantidad);
    printf("%d",i);
    if (i!=-1)//Hay lugar
    {
        empleados[i] = pedirEmpleado();
        //empleados[i].id = id;
        empleados[i].estado==OCUPADO;
        printf("%d\n%s\n%s\n%.1f\n%d\n",empleados[i].id,empleados[i].nombre,empleados[i].apellido,empleados[i].salario,empleados[i].sector);
        retorno = 0;
    }
    return retorno;
}

//3-BUSCAR EMPLEADO POR ID (1 de 1)
int buscarEmpleadoPorId(eEmpleado* empleados, int cantidad, int id)
{
    int i;
    int retorno = -1;
    if(empleados!=NULL && cantidad>0)
    {
        for(i=0; i<cantidad; i++)
        {
            if(empleados[i].id==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

//4-MODIFICACION (0/1) NO ENTIENDO TANTO EL CODIGO, Y NO QUIERO COPIAR CÓDIGO

//5-BAJA LÓGICA (0.5/1) NO SE SI ESTA BIEN

int bajaEmpleado(eEmpleado* empleados,int cantidad)
{
    //Hacer baja Lógica
    int retorno =-1;
    int id;
    int index;
    char respuesta;
    if (empleados!=NULL && cantidad>0)
    {
        mostrarListadoDeEmpleados(empleados,cantidad);

        id=getInt("Ingrese el id: ");

        index = buscarEmpleadoPorId(empleados,cantidad,id);
        if(index!=-1) //CAMBIAMOS EL ESTADO DEL ALUMNO A LIBRE
        {
            mostrarEmpleado(empleados[index]);
            printf("Esta seguro de eliminar el dato s/n: ");
            respuesta = getche ();
            if (respuesta=='s')
            {
                empleados[index].estado = LIBRE;
                retorno=0;//ACEPTO ACCION
            }
            else
            {
                retorno =1;//CANCELO ACCION
            }
        }
    }
    return retorno;//SI RETORNA -1 NO FUNCIONO
}

//6-FUNCIONES DE ORDENAMIENTO (2 de 2) LISTO

int ordenarEmpleadosApellido(eEmpleado* empleados, int cantidad, int orden)
{
    eEmpleado auxEmpleados;
    int i;
    int j;
    int retorno =-1;

    for(i=0; i<cantidad-1; i++)
    {
        for(j=i+1; j<cantidad; j++)
        {
            if(strcmp(empleados[i].apellido,empleados[j].apellido) > orden)//1 ASC y 0-DESC
            {
                auxEmpleados=empleados[i];
                empleados[i]=empleados[j];
                empleados[j]=auxEmpleados;
                retorno=0;
            }
        }
    }
    return retorno;
}

int ordenarEmpleadosSector(eEmpleado* empleados, int cantidad)
{
    eEmpleado auxEmpleados;
    int i;
    int j;
    int retorno =-1;

    for(i=0; i<cantidad-1; i++)
    {
        for(j=i+1; j<cantidad; j++)
        {
            if(empleados[i].sector>empleados[j].sector)
            {
                auxEmpleados=empleados[i];
                empleados[i]=empleados[j];
                empleados[j]=auxEmpleados;
            }
        }
    }
    return retorno;
}

//7-FUNCIONES PARA MOSTRAR (2 de 2) LISTO
void mostrarEmpleado(eEmpleado empleados)
{
    printf("\n%d -- %10s %15s %20f %10d\n\n", empleados.id, empleados.nombre, empleados.apellido, empleados.salario, empleados.sector);
}

void mostrarListadoDeEmpleados(eEmpleado* empleados, int cantidad)
{
    int i;
    printf("ID        Nombre        Apellido          Salario            Sector\n");
    for(i=0; i<cantidad; i++)
    {
        if(empleados[i].estado==OCUPADO)
        {
            mostrarEmpleado(empleados[i]);
        }
    }
}

//8-FUNCIONES DE HARDCODEO (1 de 1) LISTO

void hardcodeoEmpleados(eEmpleado* empleados, int cantidad) //TERMINADA
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombre[10][51] = {"Jorge","Mauro","Diego","Daniela","Juliana","Victoria","Carmen","Tomas","Damaris","Julian"};
    char apellido[10][51] = {"Rios","Zarate","Perez","Gonzalez","Lopez","Rodriguez","Fernandez","Fidalgo","Tevez","Riquelme"};
    float salario[10] = {2850,4425,3250,5785,6900,3450,777,2320,1400,11450};
    int sector[10] = {8,33,11,11,8,8,7,7,33,13};

    int i;
    for (i=0; i<cantidad; i++)
    {
        empleados[i].id = id[i];
        strcpy(empleados[i].nombre, nombre[i]);
        strcpy(empleados[i].apellido, apellido[i]);
        empleados[i].salario = salario[i];
        empleados[i].sector = sector[i];
        empleados[i].estado = OCUPADO;
    }

}

 //9-CALCULAR PROMEDIOS Y OTROS DATOS
