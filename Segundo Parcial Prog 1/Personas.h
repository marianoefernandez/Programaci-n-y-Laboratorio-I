#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    int id;
    char eMail[41];
}ePersona;

ePersona* newPersona();
ePersona* newPersonaParametros(char* id, char* eMail);
ePersona* getEmail(ePersona*,char* eMail);
ePersona* setEmail(ePersona*,char* eMail);
ePersona* getId(ePersona*,int* id);
ePersona* setId(ePersona*,int id);
int saveBinary(ePersona*,char*);
int loadBinary(ePersona*,char*);



