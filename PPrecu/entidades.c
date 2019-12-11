#include "entidades.h"
int inicializarAutor(ePersona arrayAutores[], int len)
{
    for(int i=0; i<len; i++)
        arrayAutores[i].idPersona = -1;
    return 1;
}

void autor_hardcore(ePersona y[])
{

    ePersona x[]=
    {
        {1,  "Emilio", 4789589 },
        {2,  "juana", 45789612},
        {3,  "Pedrito", 45576133 },
        {4,  "Juliana", 45163316 },


    };

    for(int i=0; i<4; i++)
        y[i] = x[i];
}

int buscarLibreAutor(ePersona arrayAutor[],int len)
{
    int i;
    for(i=0; i < len; i++)
    {
        if(arrayAutor[i].idPersona==-1)
        {

            return i;

        }
    }
    return -1;
}


char menuAutores()
{
    system("cls");

    printf(">> Menu de Opciones\n");
    printf("\nA_  ALTA PERSONA");
    printf("\nB_  BAJA PERSONA ");
    printf("\nC_  MODIFICAR TELEFONO ");
    printf("\nD_  ALTA LLAMADA ");


    printf("\nS_  SALIR");

    fflush(stdin);
    int opt = getChar("\n\nINGRESE OPCION: ");
    printf("\n\n");
    opt = toupper(opt);
    return opt;

}

int altaAutor(ePersona arrayAutores[],int len)
{
    int pos;
    char auxNombre[30];
    int auxNumeroTelefono;
    pos = buscarLibreAutor(arrayAutores,len);


    if(pos!=-1)
    {
        getInformationAutor(auxNombre,&auxNumeroTelefono);

        arrayAutores[pos].idPersona = pos+1;

        strcpy(arrayAutores[pos].nombre,auxNombre);

        arrayAutores[pos].telefono = auxNumeroTelefono;
        return 1;
    }
    return 0;
}



void getInformationAutor(char auxName[],int* auxTelefono)
{
    char telefono[31];
    getString("INGRESE NOMBRE: ",auxName);
    while(!esSoloLetras(auxName))
    {
        getString("INGRESE NOMBRE (SOLO LETRAS): ",auxName);
    }

    getString("INGRESE TELEFONO: ",telefono);
    while(!esNumerico(telefono))
    {
        getString("INGRESE TELEFONO (SOLO NUMEROS): ",telefono);
    }
    *auxTelefono = atoi(telefono);
}

int bajaAutor(ePersona arrayAutores[],int len)
{
    char auxiliarPos[5];
    int pos;

    printAutores(arrayAutores,len);

    getString("INGRESE CODIGO QUE DESEA DAR DE BAJA: ",auxiliarPos);
    while(!esNumerico(auxiliarPos))
    {
        getString("INGRESE SOLO NUMEROS: ",auxiliarPos);
    }

    pos = atoi(auxiliarPos);


    for(int i=0; i<len; i++)
    {
        if(arrayAutores[i].idPersona!=-1)
        {

            arrayAutores[pos-1].idPersona= -1;
            return 1;

        }
    }


    return 0;


}


void printAutores(ePersona lista[], int cant)
{
    printf("%4s%20s%20s","COD", "NOMBRE","TELEFONO\n");
    int i;

    for(i=0; i<cant; i++)
    {
        if(lista[i].idPersona!=-1)
        {
            printAutor(lista[i]);
        }



    }
    printf("\n\n");
    system("pause");
    printf("\n\n");

}

void printAutor(ePersona unAutor)
{
    printf("%4d%20s%20d\n",unAutor.idPersona,
           unAutor.nombre,
           unAutor.telefono);
}



int modificarAutor(ePersona arrayAutores[],int len)
{
    char auxiliarPos[5];
    char telefono[31];
    int codAutor,pos;
    int auxTelefono;




    printAutores(arrayAutores,len);
    getString("INGRESE CODIGO QUE DESEA MODIFICAR: ",auxiliarPos);
    while(!esNumerico(auxiliarPos))
    {
        getString("INGRESE SOLO NUMEROS: ",auxiliarPos);
    }
    codAutor = atoi(auxiliarPos);

    pos=buscarPosAutor(arrayAutores,len,codAutor);

    if(pos!=-1)
    {
        getString("INGRESE TELEFONO: ",telefono);
        while(!esNumerico(telefono))
        {
            getString("INGRESE TELEFONO (SOLO NUMEROS): ",telefono);
        }
        auxTelefono = atoi(telefono);

        arrayAutores[pos].telefono=auxTelefono;
        return 1;

    }

    return 0;

}


int buscarPosAutor(ePersona arrayAutores[],int len,int codAutor)
{
    int i;
    for(i=0; i < len; i++)
    {
        if(arrayAutores[i].idPersona==codAutor)
        {
            return i;
        }
    }
    return -1;
}





















int inicializarLlamada(eLlamada arrayAutores[], int len)
{
    for(int i=0; i<len; i++)
        arrayAutores[i].idPersona = -1;
    return 1;
}

int buscarLibreLlamada(eLlamada arrayAutor[],int len)
{
    int i;
    for(i=0; i < len; i++)
    {
        if(arrayAutor[i].idPersona==-1)
        {

            return i;

        }
    }
    return -1;
}

void getInformationLlamada(int*auxLlamador,int*auxIdDestino, char auxtipo[],char auxEstado[])
{
    char destino[31];
    char llamador[31];

    getString("INGRESE LLAMADOR: ",llamador);
    while(!esNumerico(llamador))
    {
        getString("INGRESE LLAMADOR (SOLO NUMEROS): ",llamador);
    }
    *auxLlamador = atoi(llamador);


    getString("INGRESE DESTINO: ",destino);
    while(!esNumerico(destino))
    {
        getString("INGRESE DESTINO (SOLO NUMEROS): ",destino);
    }
    *auxIdDestino = atoi(destino);



    getString("INGRESE TIPO: ",auxtipo);
    while(!esSoloLetras(auxtipo))
    {
        getString("INGRESE TIPO (SOLO LETRAS): ",auxtipo);
    }



    getString("INGRESE ESTADO: ",auxEstado);
    while(!esSoloLetras(auxEstado))
    {
        getString("INGRESE ESTADPO (SOLO LETRAS): ",auxEstado);
    }

}


int altaLlamada(eLlamada arrayAutores[],int len,ePersona arrayPersona[])
{
    int pos;
    char auxEstado[30];
    char auxTipo[30];
    int destino;
    int llamador;
    pos = buscarLibreLlamada(arrayAutores,len);


    if(pos!=-1)
    {
        getInformationLlamada(&llamador,&destino,auxTipo,auxEstado);
    for(int i=0; i<len; i++)
    {
        if(arrayPersona[i].idPersona==llamador)
        {
            for(int j=0;j<len;j++)
            {
                   if(arrayPersona[j].idPersona==destino)
        {

            arrayAutores[pos].idPersona = pos+1;

            strcpy(arrayAutores[pos].tipo,auxTipo);
            strcpy(arrayAutores[pos].estado,auxEstado);
            arrayAutores[pos].idDestino = destino;

            return 1;

        }

            }


        }
    }

    }

return 0;
}



