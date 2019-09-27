#include <stdio.h>
#include <string.h>
#define OCUPADO 1
#define LIBRE 0
#define HARDCODEO 5
#include "inputs.h"


typedef struct
{
    int id;
    char nombre [51];
    char apellido [51];
    float salario;
    int sector;
    int estado;
}eEmpleado;


//0-MENUES (2 de 6)

void menuPrincipal();
/** \brief Muestra menu de opciones.
 *
 *
 */

void menuSecundario();
/** \brief Muestra el menu de ordenamientos y promedios.
 *
 *
 */

 //MENU DE MODIFICACION (FALTA)

//SWITCH DEL PRIMER MENU (FALTA) QUE MUESTRE MENU Y LUEGO SWITCH CON DO/WHILE (FUNCION PRINCIPAL POR ESTA PASA TODO)
void opcionesMenuPrincipal(eEmpleado*,int);
/** \brief Hace un switch de todas las opciones del menu principal!
 *
 * \param Se le pasa la estrucutra eEmpleado.
 * \param Se le pasa un valor para verificar que si no se hace la alta por primera vez no se puedan acceder a las otras opciones
 *
 */

//SWITCH DEL SEGUNDO MENU (FALTA)
void opcionesMenuSecundario(eEmpleado*);
/** \brief Hace un switch de todas las opciones del menu de promedios y ordenamiento.
 *
 * \param Se le pasa la estructura eEmpleado.
 *
 */



//FUNCIONES PARA INICIALIZAR (1 de 2)

int inicializarEmpleados (eEmpleado*, int);
/** \brief Verifica si todas las posiciones del array estan vacias, pone una flag si esta en true para verificarlo.
 *
 * \param 1 Recibe un puntero de la estructura eEmpleados
 * \param 2 Recibe la cantidad de elementos del array
 * \return Retorna (-1) si hay error y 0 si todo está bien
 *
 */

//int generarID (HACER)

int generarId(eEmpleado*, int);
/** \brief Funcion que va sumando de a uno el id
 *
 * \param 1 Se le pasa la estructura eEmpleado
 * \param 2 Se le pasa el tamaño del array
 * \return retorna el id nuevo
 *
 */

//FUNCIONES PARA AÑADIR (2 de 4)

 eEmpleado pedirEmpleado(int); //FALTA TERMINAR
/** \brief Función que pide los datos de los empleados para luego ser usada por la función que da de alta al empleado.
 *
 *
* \return Retorna una estructura de empleado con los nombres cargados
 */

//int validarEmpleado (HACER)

 int buscarLibre(eEmpleado*,int);//TERMINADA
/** \brief Busca si hay espacio libre en el array.
 *
 * \param 1 Recibe un puntero de la estructura eEmpleados
 * \param 2 Recibe la cantidad de elementos del array
 * \return Devuelve (-1) si hay error, devuelve la pos del array si todo está bien
 *
 */

 int agregarEmpleados (eEmpleado*,int);//TERMINADA
 /** \brief Agrega los empleados al array verificando si hay o no espacio y validando.
  *
  * \param 1 Recibe un puntero de la estructura eEmpleados
  * \param 2 Recibe la cantidad de elementos del array
  * \return Devuelve (-1) si hay error, devuelve 0 si todo está bien
  *
  */

//3-BUSCAR EMPLEADO POR ID (1 de 1)
int buscarEmpleadoPorId(eEmpleado*, int, int);
/** \brief Funcion que busca en todo el array al indice que tenga el id que hayamos puesto
 *
 * \param Se le pasa la estructura eEmpleado
 * \param Se le pasa el maximo largo del array
 * \param Se le pasa el id previamente pedido en la funcion getInt
 * \return retorna el indice del id ingresado, o -1 si da error.
 *
 */

//4-MODIFICACION (0/1) NO ENTIENDO TANTO EL CODIGO, Y NO QUIERO COPIAR CÓDIGO

//5-BAJA LÓGICA (0.5/1) NO SE SI ESTA BIEN

int bajaEmpleado(eEmpleado*,int);
/** \brief Función para dar de baja a un empleado, mediante la baja lógica poniendo al vector en OCUPADO
 *
 * \param 1 Se le pasa la estructura eEmpleado
 * \param 2 Se le pasa el maximo largo del array
 * \return Retorna -1 si sale algo mal, retorna 0 si todo esta bien
 *
 */

//6-FUNCIONES DE ORDENAMIENTO
int ordenarEmpleadosApellido(eEmpleado*, int, int);
/** \brief Función para ordenar los empleados por apellido
 *
 * \param 1 Se le pasa la estructura eEmpleado
 * \param 2 Se le pasa el maximo largo del array
 * \param 3 Se le pasa 1 si se quiere ordenar ascendentemente y 0 si se quiere ordenar descendentemente
 * \return Retorna -1 si da error y 0 si esta bien
 *
 */

int ordenarEmpleadosSector(eEmpleado*, int);
/** \brief Función para ordenar a los empleados por sector
 *
 * \param 1 Se le pasa la estructura eEmpleado
 * \param 2 Se le pasa el maximo largo del array
 * \return Retorna -1 si da error y 0 si esta bien
 *
 */


//7-FUNCIONES PARA MOSTRAR
void mostrarEmpleado(eEmpleado);
/** \brief Funcion para mostrar un sólo empleado
 *
 * \param Se le pasa la estructura eEmpleado
 *
 */

 void mostrarListadoDeEmpleados(eEmpleado*, int);
 /** \brief Recorre en un for y muestra todos los empleados cargados
  *
  * \param 1 Se le pasa la estructura eEmpleado
  * \param 2 Se le pasa el maximo largo del array
  *
  */





//8-FUNCIONES DE HARDCODEO (1 de 1) LISTO

  void hardcodeoEmpleados(eEmpleado*, int); //TERMINADA
 /** \brief Función que hardcodea los datos de 5 personas y las pasa a la estructura por referencia
 *
 * \param 1 Recibe un puntero de la estructura eEmpleados
 * \param 2 Recibe la cantidad de elementos del array
 *
 */

 //9-CALCULAR PROMEDIOS Y OTROS DATOS
