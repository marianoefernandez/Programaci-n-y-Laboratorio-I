#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Personas.h"

ePersona* newPersona()
{
    ePersona* persona;
    persona=(ePersona*)malloc(sizeof(ePersona*));

    if (persona!=NULL)
    {
        setId(persona,0);
        setEmail(persona,"");
    }

    return persona;
}

ePersona* newPersonaParametros(char* id, char* eMail)
{
    ePersona* persona;
    persona=newPersona();
    int idAux;

    idAux=atoi(id);

    if(persona!=NULL)
    {
        setId(persona,idAux);
        setEmail(persona,eMail);
    }

    return persona;
}

ePersona* getEmail(ePersona* persona,char* eMail)
{
    if(eMail!=NULL && persona!=NULL)
    {
        strcpy(eMail,persona->eMail);
    }
    return persona;
}

ePersona* setEmail(ePersona* persona,char* eMail)
{
    if(eMail!=NULL && persona!=NULL)
    {
        strcpy(persona->eMail,eMail);
    }
    return persona;
}
ePersona* getId(ePersona* persona,int* id)
{
    if(id!=NULL && persona!=NULL)
    {
        *id=persona->id;
    }
    return persona;
}

ePersona* setId(ePersona* persona,int id)
{
    if(persona!=NULL)
    {
        persona->id=id;
    }
    return persona;
}

int saveBinary(ePersona* persona,char* path)
{
    FILE* pArchivo;
    int ret=0;

    if(persona!=NULL)
    {
        pArchivo=fopen(path,"wb");
        //persona=newPersonaParametros("2","hola37@gmail.com");
        ///ME SALIO BIEN EL GUARDAR EN BINARIO EN UNA SOLA ESTRUCTURA

        if(pArchivo!=NULL)
        {
            fwrite(persona,sizeof(ePersona*),1,pArchivo);
        }
        ret=1;
    }

    fclose(pArchivo);

    return ret;
}

int loadBinary(ePersona* persona,char* path)
{
    FILE* pArchivo;
    int ret=0;

    if(persona!=NULL)
    {
        pArchivo=fopen(path,"rb");
        //persona=newPersonaParametros("2","hola37@gmail.com");
        while(!feof(pArchivo))
        {
            fread(persona,sizeof(ePersona*),1,pArchivo);
            ret=1;
            fprintf(pArchivo,"id %d,email %s");
        }
        fclose(pArchivo);
    }

    return ret;
}
