typedef struct{
int id;
char dominio[10];
int anio;
char tipo;
}eDominio;

eDominio* dominio_new();

eDominio* dominio_newParametros(char* idStr,char* dominio,char* anioStr);

int dominio_setId(eDominio* this,int id);

int dominio_setDominio(eDominio* this,char* dominio);

int dominio_setAnio(eDominio* this,int anio);

int dominio_getDominio(eDominio* this,char* dominio);

void dominio_mapTipo(void* pElement);

int dominio_setTipo(eDominio* this,char tipo);

int dominio_filtrarAutos(void* p);

int dominio_filtrarMotos(void* p);
