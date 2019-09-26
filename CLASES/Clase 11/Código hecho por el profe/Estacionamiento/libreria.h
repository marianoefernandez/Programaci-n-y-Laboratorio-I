
typedef struct {
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct {
    int id;
    char nombre[50];
    eFecha fechaNac;
}ePersona;


typedef struct {
    char patente[50];
    eFecha fechaIngreso;
    int horaIngreso;
    int horaSalida;
    int idDuenio;
}eVehiculo;

 void cargarPersonas(ePersona pesonas[], int cantidad);
 void mostrarPersonas(ePersona pesonas[], int cantidad);
 int buscarIndicePersona(ePersona personas[], int cant, int id);
void mostrarVehiculos(ePersona pesonas[],eVehiculo vehiculos[], int cantidad, int cantPersonas);
ePersona buscarPersona(ePersona personas[], int cant, int id);
