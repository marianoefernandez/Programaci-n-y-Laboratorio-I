#include "alumno.h"


int inicializarAlumnos(eAlumno* lista,int cantidad)
{
    int i;
    int retorno=-1;

    if(lista!=NULL && cantidad>0)
    {
        for (i=0; i<cantidad; i++)
        {
            lista[i].estado = LIBRE;
        }
        retorno=0;
    }

    return retorno;
}

void mostrarAlumno (eAlumno miAlumno)
{
    printf("\n%d--%s--%d\n",miAlumno.legajo,miAlumno.nombre,miAlumno.nota);
}

eAlumno pedirAlumno()
{
    eAlumno miAlumno;
    printf("\nIngrese legajo: ");
    scanf("%d",&miAlumno.legajo);
    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(miAlumno.nombre);
    printf("\nIngrese nota: ",&miAlumno.nota);
    scanf("%d",&miAlumno.nota);

    miAlumno.estado = LIBRE;

    return miAlumno;
}

int pedirLegajo()
{
    int legajo;
    printf("Ingrese el legajo: ");
    scanf("%d", &legajo);
    return legajo;
}

int buscarAlumnoPorLegajo(eAlumno* lista,int cantidad,int legajo)
{
    int i;
    int retorno = -1;
    if(lista!=NULL && cantidad>0)
    {
        for(i=0;i<cantidad;i++)
        {
            if(lista[i].legajo == legajo)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int bajaAlumno(eAlumno* lista,int cantidad)
{
    //Hacer baja Lógica
    int retorno =-1;
    int legajo;
    int index;
    char respuesta;
    if (lista!=NULL && cantidad>0)
    {
        mostrarListadoAlumnos(lista,cantidad);

        legajo=pedirLegajo();

        index = buscarAlumnoPorLegajo(lista,cantidad,legajo);
        if(index!=-1) //CAMBIAMOS EL ESTADO DEL ALUMNO A LIBRE
        {
            mostrarAlumno(lista[index]);
            printf("Esta seguro de eliminar el dato s/n: ");
            respuesta = getche ();
            if (respuesta=='s')
            {
                lista[index].estado = LIBRE;
                retorno=0;//ACEPTO ACCION
            }
            else
            {
                retorno =1;//CANCELO ACCION
            }

        }


    }

    return retorno;
}

int compararAlumnoPorLegajo(eAlumno unAlumno, eAlumno otroAlumno)
{
    int comp = 0;
    if (unAlumno.legajo==otroAlumno.legajo)
    {
        comp = 1;
    }
    return comp;
}

int buscarLibre(eAlumno* lista,int cantidad)
{
    int i;
    int index = -1;//DEFINIMOS VALOR
    for (i=0;i<cantidad;i++)
    {
        if (lista[i].estado == LIBRE)
        {
            index = i;
            break;//SI DEVUELVE -1 NO HAY ESPACIO
        }
    }
    return index;
}


int cargarAlumnos(eAlumno* lista,int cantidad)
{
    int i;
    int retorno=0;
    i = buscarLibre(lista,cantidad);
    if (i != -1)
    {
        lista[i] = pedirAlumno();
        lista[i].estado==OCUPADO;
        retorno = 1;
    }

    return retorno;
}


void mostrarListadoAlumnos (eAlumno* lista,int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            mostrarAlumno(lista[i]);
        }
    }
}

void ordenarAlumnosPorNombres(eAlumno* lista ,int cantidad)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for (i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if (strcmp (lista[i].nombre,lista[j].nombre)>0) //Comparo cadenas ordenar por nombre > (MENOR A MAYOR) < (MAYOR A MENOR)
            {
                auxAlumno = lista[i];
                lista[i] = lista[j];
                lista[j] = auxAlumno;
            }
        }
    }
}

void hardcodearAlumnos(eAlumno* lista,int cantidad)
{
    int legajo [3] = {101,102,105};
    int nota[3] = {10,5,9};
    char nombre [3][50] = {"Juan","Maria","Jose"};
    int i;

    for (i=0;i<cantidad;i++)
    {
        lista[i].legajo=legajo[i];
        lista[i].nota=nota[i];
        strcpy(lista[i].nombre,nombre[i]);
        lista[i].estado = OCUPADO;
    }
}
