//ESTRUCTURAS

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int codigo;
    char nombre[52];
    char localidad[34];
    int isEmpty;
}eEquipo;

typedef struct
{
    int codigo;
    char apellido[32];
    char nombre[32];
    char sexo;
    char email[32];
    char localidad[34];
    eFecha fechaNac;
    int isEmpty;
}eJugadores;

typedef struct
{
    int codigo;
    int codigoVisitante;
    int codigoLocal;
    int codigoReferi;
    eFecha fechaNac;
    int isEmpty;
}ePartido;

typedef struct
{
    int codigo;
    char apellido[32];
    char nombre[32];
    char sexo;
    char email[32];
    char localidad[34];
    eFecha fechaNac;
    int isEmpty;
}eReferi;


