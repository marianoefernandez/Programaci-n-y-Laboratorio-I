

typedef struct
{
    int legajo;
    int edad;
    //char nombre[50];
    float altura;
}ePersona;

ePersona* new_Persona();//RETORNA PUNTERO---Es un constructos por defecto inicializa en 0
int mostrarPersona(ePersona*);
int delate_Persona(ePersona*);
ePersona* new_Persona_Parametros(int,int,float);
