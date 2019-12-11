
typedef struct{
    int id_cachorro;
    char nombre[20];
    int dias;
    char raza[20];
    char reservado[3];
    char genero;
}eCachorro;

eCachorro* newCachorro();
///NEW PARAMETROS SON TODOS CHAR, DESPUES CASTEA CON ATOI A LOS CARACTERES
eCachorro* newCachorro_Parametros(char* id,char* nombre,char* dias, char* raza , char* reservado,char* genero);

///EL SET MODIFICA EL ELEMENTO, EL GET OBTIENE Y CARGA

void showCachorro(eCachorro* cachorro);///
void showCachorros(LinkedList* pArrayLinkedCachorro);///

int eCachorro_setId(eCachorro* listaCachorro,int id);///GET ID INT ENTEROS
int eCachorro_getId(eCachorro* listaCachorro,int* id);///SET ID INT ENTEROS

int eCachorro_setNombre(eCachorro* listaCachorro, char* nombre);///SET NOMBRE CADENA DE CARACTERES
int eCachorro_getNombre(eCachorro* listaCachorro,char* nombre);///GET NOMBRE CADENA DE CARACTERES

int eCachorro_getDias(eCachorro* listaCachorro,int* dias);///GET DIAS INT ENTEROS
int eCachorro_setDias(eCachorro* listaCachorro,int dias);///SET DIAS INT ENTEROS

int eCachorro_setRaza(eCachorro* listaCachorro, char* raza);///SET RAZA CADENA DE CARACTERES
int eCachorro_getRaza(eCachorro* listaCachorro,char* raza); ///GET RAZA CADENA DE CARACTERES

int eCachorro_setGenero(eCachorro* listaCachorro,char* genero);///set genero UN CARACTER
int eCachorro_getGenero(eCachorro* listaCachorro,char* genero); ///Get genero UN CARACTER

int eCachorro_setReservado(eCachorro* listaCachorro,char* reservado);///reservado
int eCachorro_getReservado(eCachorro* listaCachorro,char* reservado);

///FILTER DE CACHORROS
int filter_45dias(void* aux);
int filter_machos(void* aux);
int filter_callejeros(void* aux) ;
int filter_reservado(void* aux); ///la funcion que despues es pasada como pFUNC a ll_filter con filtro de CARACTERES


///FILTER DE DOMINIOS

int setearTipo(eCachorro* cacho);///aca setear 45 dias??? y setear machos, y listado callejeros
void* seteaTipo(eCachorro* e);

int filterTipo(void* e);
