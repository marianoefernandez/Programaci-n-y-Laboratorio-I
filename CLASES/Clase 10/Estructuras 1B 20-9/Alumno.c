#include "Alumno.h"

int inicializarAlumnos(eAlumno* listaDeAlumnos, int cant)
{
    int i;
    int retorno = -1;

    if(listaDeAlumnos!=NULL && cant>0)
    {
        for(i=0; i<cant; i++)
        {
            listaDeAlumnos[i].estado = LIBRE;
        }
        retorno = 0;
    }

    return retorno;
}


void mostrarAlumno(eAlumno unAlumno)
{
    printf("%d----%d--%s--%d\n",unAlumno.estado, unAlumno.legajo,
           unAlumno.nombre,
           unAlumno.nota);
}

eAlumno pedirAlumno(void)
{
    eAlumno miAlumno;//={1000,"Pepe",7};

    printf("Ingrese legajo: ");
    scanf("%d", &miAlumno.legajo);
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(miAlumno.nombre);
    printf("Ingrese nota: ");
    scanf("%d", &miAlumno.nota);

    miAlumno.estado = LIBRE;

    return miAlumno;
}

int buscarAlumnoPorLegajo(eAlumno* lista, int cant, int legajo)
{
    int i;
    int retorno = -1;
    if(lista!=NULL && cant>0)
    {
        for(i=0; i<cant; i++)
        {
            if(lista[i].legajo== legajo)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;

}

int compararAlumnoPorLegajo(eAlumno unAlumno,eAlumno otroAlumno)
{
    int comp = 0;
    if(unAlumno.legajo==otroAlumno.legajo)
    {
        comp = 1;
    }
    return comp;
}

int buscarAlumnoLibre(eAlumno* lista, int cant)
{
    int i;
    int index = -1;
    for(i=0; i<cant; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int cargarAlumnos(eAlumno lista[], int cant)
{
    int i;
    int retorno = 0;
    i = buscarAlumnoLibre(lista,cant);
    if(i!=-1)//Hay lugar
    {
        lista[i] = pedirAlumno();
        lista[i].estado = OCUPADO;
        retorno = 1;
    }

    return retorno;

}

void mostrarListadoDeAlumnos(eAlumno lista[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            mostrarAlumno(lista[i]);
        }

    }
}

void ordenarAlumnosPorNombre(eAlumno lista[], int cant)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(strcmp(lista[i].nombre,
                      lista[j].nombre)<0)
            {
                auxAlumno = lista[i];
                lista[i] = lista[j];
                lista[j] =  auxAlumno ;

            }
        }
    }
}

void hardcoderAlumnos(eAlumno lista[], int cant)
{
    int legajo[]= {101,102,105,100,103};
    int nota[]= {10,5,9,7,8};
    char nombre[][20]= {"Juan","Maria","Jose","Mateo","Rocio"};
    int i;

    for(i=0; i<cant; i++)
    {
        lista[i].legajo=legajo[i];
        lista[i].nota=nota[i];
        strcpy(lista[i].nombre,nombre[i]);
        lista[i].estado = OCUPADO;
    }

}
