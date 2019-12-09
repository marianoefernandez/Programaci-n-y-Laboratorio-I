typedef struct{
int id;
char descripcion[256];
int precio;
int idtipo;
}eComputer;



eComputer* computer_new();

eComputer* computer_newParametros(char* idStr,char* descripcionStr,char* precioStr,char* tipoStr);

int computer_setId(eComputer* this,int id);

int computer_setDescripcion(eComputer* this,char* descripcion);

int computer_setPrecio(eComputer* this,int precio);

int computer_setTipo(eComputer* this,int tipo);

int computer_comparacionPorTipo(void* ComputerA, void* ComputerB);

int computer_getComputer(eComputer* this,int* precio);

void computer_mapTipo(void* pElement);

int computer_filtrarLaptop(void* p);
