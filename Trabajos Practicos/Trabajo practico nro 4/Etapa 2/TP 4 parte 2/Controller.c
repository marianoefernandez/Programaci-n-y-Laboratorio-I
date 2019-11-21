#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "inputs.h"

//Carga el texto abriendo el archivo en modo lectura, path se usa para el nombre del archivo a usar, se parsea y lee
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;

    int ret = 0;

    if(pArchivo!=NULL)
    {
        pArchivo=fopen(path, "r");
        parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        ret = 1;
    }
    fclose(pArchivo);

    return ret;
}

//Carga en modo binario abriendo el archivo en modo lectura, path se usa para el nombre del archivo a usar, se parsea y lee
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int ret = 0;

    if(pArchivo != NULL)
    {
        pArchivo = fopen(path, "rb");
        parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
        ret = 1;
    }
    fclose(pArchivo);

    return ret;
}

/*Crea un puntero a empleado, lo construye y lo va agregando, al final si el puntero es distinto de null, setea todos los archivos
que cargamos anteriormente y lo agrega a la LinkedList respectivamente.
*/
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    pEmpleado = new_Employee();

    int ret= 0;

    char nombre[50];
    char sueldo[30];
    char horas[20];

    int idAux;
    int horasAux;
    int sueldoAux;

    if(pArrayListEmployee != NULL)
    {
        idAux = controller_getID(pArrayListEmployee);
        printf("Ingrese un nombre: ");
        fflush(stdin);
        gets(nombre);
        while(isOnlyLetters(nombre)==0)
        {
            printf("POR FAVOR SOLO INGRESE LETRAS\n Ingrese un nombre nuevamente: ");
            fflush(stdin);
            gets(nombre);
        }
        stringToUpper(nombre);


        printf("Ingrese un nuevo sueldo: ");
        fflush(stdin);
        gets(sueldo);
        while(isNumeric(sueldo)==0)
        {
            printf("POR FAVOR SOLO INGRESE NUMEROS\n Ingrese un nombre nuevamente: ");
            fflush(stdin);
            gets(sueldo);
        }
        sueldoAux = atoi(sueldo);


        printf("Ingrese las horas: ");
        fflush(stdin);
        gets(horas);
        while(isNumeric(horas)==0)
        {
            printf("POR FAVOR SOLO INGRESE NUMEROS\n Ingrese las horas nuevamente: ");
            fflush(stdin);
            gets(horas);
        }
        horasAux=atoi(horas);

        if(pEmpleado != NULL)
        {
            employee_setId(pEmpleado, idAux);
            employee_setNombre(pEmpleado, nombre);
            employee_setSueldo(pEmpleado, sueldoAux);
            employee_setHorasTrabajadas(pEmpleado, horasAux);
            ll_add(pArrayListEmployee, pEmpleado);
            ret = 1;
        }
    }
    return ret;
}

/*
Permite al usuario modificar el empleado, se pide el id y se guarda en una variable char que con un atoi se convierte en entero
se recorre con un for la lista, obteniendo cada id de cada indice, si el id corresponde al id ingresado se puede modificar el usuario
pisando el valor elegido de ese indice.
*/
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;

    int ret = -1;
    int idAux;
    int idConseguido;
    int opcionAux;
    int sueldoAux;
    int horasAux;
    int i;

    char id[20];
    char opcion[20];
    char nombre[50];
    char sueldo[30];
    char horas[20];

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese ID: ");
        fflush(stdin);
        gets(id);

        while(isNumeric(id)==0)
        {
            printf("Usted ha ingresado un ID incorrecto\nIngrese el id nuevamente: ");
            fflush(stdin);
            gets(id);
        }
        idAux=atoi(id);

        for(i = 0; i< ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee,i);
            employee_getId(empleado,&idConseguido);

            if(idConseguido == idAux)
            {
                printf("\n\n ¿QUE DESEA MODIFICAR?\n:");
                printf("\n 1- Nombre");
                printf("\n 2- Sueldo");
                printf("\n 3- Horas trabajadas");
                printf("\n 4- Salir!");
                printf("\n\n Su opcion: ");
                fflush(stdin);
                gets(opcion);

                while(isNumeric(opcion)==0)
                {
                    printf("Usted ha ingresado una opcion incorrecta\nIngrese su opcion de nuevo: ");
                    fflush(stdin);
                    gets(opcion);
                }
                opcionAux=atoi(opcion);

                switch(opcionAux)
                {
                case 1:
                    printf("Ingrese un nuevo nombre: ");
                    fflush(stdin);
                    gets(nombre);

                    while(isOnlyLetters(nombre)==0)
                    {
                        printf("POR FAVOR SOLO USE LETRAS\nIngrese el nombre de nuevo: ");
                        fflush(stdin);
                        gets(nombre);
                    }
                    stringToUpper(nombre);
                    employee_setNombre(empleado, nombre);
                    ret = 1;
                    break;

                case 2:
                    printf("Ingrese un nuevo sueldo: ");
                    fflush(stdin);
                    gets(sueldo);

                    while(isNumeric(sueldo)==0)
                    {
                        printf("POR FAVOR SOLO USE NUMEROS\nIngrese el sueldo de nuevo: ");
                        fflush(stdin);
                        gets(sueldo);
                    }

                    sueldoAux= atoi(sueldo);
                    employee_setSueldo(empleado, sueldoAux);
                    ret = 1;
                    break;

                case 3:
                    printf("Ingrese las nuevas horas: ");
                    fflush(stdin);
                    gets(horas);
                    while(isNumeric(horas)==0)
                    {
                        printf("POR FAVOR SOLO USE NUMEROS\nIngrese las horas de nuevo:");
                        fflush(stdin);
                        gets(horas);
                    }
                    horasAux= atoi(horas);
                    employee_setHorasTrabajadas(empleado, horasAux);
                    ret = 1;
                    break;

                case 4:
                    opcionAux=4;
                    printf("\nCancelando...\n\n");
                    break;

                default:
                    printf("Opcion invalida.\n");
                }
            }
        }
    }
    return ret;
}

/*
Permite al usuario eliminar el empleado, se pide el id y se guarda en una variable char que con un atoi se convierte en entero
se recorre con un for la lista, obteniendo cada id de cada indice, si el id corresponde al id ingresado se puede eliminar o
no el empleado dependiendo de si el usuario dice que si o no
*/

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;

    int ret = 0;
    char id[20];
    int idAux;
    int idConseguido;
    int i;

    char continuar;

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese ID: ");
        fflush(stdin);
        gets(id);

        while(isNumeric(id)==0)
        {
            printf("Usted ha ingresado un ID incorrecto\nIngrese el id nuevamente: ");
            fflush(stdin);
            gets(id);
        }
        idAux=atoi(id);

        for(i=0; i< ll_len(pArrayListEmployee); i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado, &idConseguido);

            if(idConseguido == idAux)
            {
                printf("\n\n Desea dar de baja al usuario? s/n");
                fflush(stdin);
                continuar=getche();

                if (continuar == 's')
                {
                    delate_employee(pEmpleado);
                    ll_remove(pArrayListEmployee,i);
                    ret = 1;
                }
                if (continuar =='n')
                {
                    ret = -1;
                }
                if (continuar!='s' && continuar != 'n')
                {
                    ret=-2;
                }
            }
        }
    }
    return ret;
}

/*
Si la lista es distinta de null, la recorre con un for, obtiene la lista LinkedList de cada indice, obtiene cada dato de cada
indice y va imprimiendo cada dato
*/

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;

    int ret = 0;
    int i;
    int id;
    int sueldo;
    int horasTrabajadas;

    char nombre[128];

    if(pArrayListEmployee != NULL)
    {
        printf("\n\nID-- \t\t   NOMBRE \t\t SUELDO \t\tHORAS \n\n");
        ret =1;

        for(i=0; i < ll_len(pArrayListEmployee); i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getNombre(pEmpleado, nombre);
            employee_getId(pEmpleado,&id);
            employee_getSueldo(pEmpleado,&sueldo);
            employee_getHorasTrabajadas(pEmpleado,&horasTrabajadas);
            printf("%d -- %20s %20d %20d \n\n", id, nombre, sueldo, horasTrabajadas);
        }
    }
    return ret;
}

//Pregunta si la lista es distinta de null y ejecuta el ordenar empleado

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ret = 0;

    if(pArrayListEmployee != NULL)
    {
        sortEmployee(pArrayListEmployee);
        ret = 1;
    }
    return ret;

}

/*
Creamos un archivo, y un puntero a empleadoaux, si la lista es distinta de NULL, y el archivo tambien
hacemos un malloc de cada puntero a aux, recorremos la lista con un null hacemos un get de cada dato en cada indice
por último hacemos un fprintf para guardarlo en el archivo y obviamente, liberamos las variables y cerramos el archivo
*/
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* empleadoAux;

    int ret = 0;
    int* idAux;
    char* nombreAux;
    int* sueldoAux;
    int* horasAux;
    int i;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        idAux = malloc(sizeof(int));
        nombreAux = malloc(sizeof(char)*50);
        sueldoAux = malloc(sizeof(int));
        horasAux = malloc(sizeof(int));

        pArchivo = fopen(path, "w");
        fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");

        for(i=0; i< ll_len(pArrayListEmployee); i++)
        {
            empleadoAux = ll_get(pArrayListEmployee,i);
            employee_getId(empleadoAux,idAux);
            employee_getSueldo(empleadoAux,sueldoAux);
            employee_getNombre(empleadoAux, nombreAux);
            employee_getHorasTrabajadas(empleadoAux,horasAux);
            fprintf(pArchivo,"%d,%s,%d,%d\n",*idAux,nombreAux,*sueldoAux,*horasAux);
        }

        free(nombreAux);
        free(idAux);
        free(sueldoAux);
        free(horasAux);
        fclose(pArchivo);
        ret = 1;
    }
    return ret;
}

/*
Guarda en un archivo binario abriendolo en modo wb si la lista y el archivo no son NULL luego hace un ll_get y un fwrite y
lo escribe en binario
*/
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* empleadoAux;

    int ret = 0;
    int i = 0;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pArchivo = fopen(path,"wb");

        for(i=0; i< ll_len(pArrayListEmployee); i++)
        {
            empleadoAux = (Employee*)ll_get(pArrayListEmployee,i);
            fwrite(empleadoAux, sizeof(Employee),1,pArchivo);
        }
        fclose(pArchivo);
        ret=1;
    }
    return ret;
    }

int controller_getID(LinkedList* pArrayListEmployee)
{
    Employee* empleadoAux;

    int aux;
    int len;
    int i;
    int id=0;
    int idAnterior;

    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        if(len > 0)
        {
            for(i = 0; i<len; i++)
            {
                empleadoAux = (Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(empleadoAux,&aux);
                if(aux > id)
                {
                    idAnterior = id;
                    id = aux;
                    if(idAnterior + 1 != id)
                    {
                        id = idAnterior;
                        break;
                    }
                }
            }
            id++;
        }
        else
        {
            id = 1;
        }
    }
    return id;
}

