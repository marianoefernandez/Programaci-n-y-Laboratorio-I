#include <stdio.h>
#include <string.h>
#define NOTFREE 1
#define FREE 0
#define HARDCODING 10



typedef struct
{
    int id;
    char name [51];
    char lastName [51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

//0-MUESTRO MENUES (3 de 3)

void printFirstMenu();
/** \brief show main menu options
 *
 *
 */

void printSecondMenu();
/** \brief show case 4 of switch in main.c
 *
 *
 */

void printModificationMenu();
/** \brief show case 2 of switch in main.c modification menu
 *
 *
 */

//FUNCIONES PARA INICIALIZAR (1 de 2)

int initEmployees() (eEmpleado*, int);
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

//int generarID (HACER)

int generarId(eEmpleado*, int);

int autoincrementar (int* n);
/** \brief Funcion que va sumando de a uno el id
 *
 * \param 1 Se le pasa la estructura eEmpleado
 * \param 2 Se le pasa el tama�o del array
 * \return retorna el id nuevo
 *
 */

//FUNCIONES PARA A�ADIR (2 de 4)

 eEmpleado pedirEmpleado(); //FALTA TERMINAR
/** \brief Funci�n que pide los datos de los empleados para luego ser usada por la funci�n que da de alta al empleado.
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
 * \return Devuelve (-1) si hay error, devuelve la pos del array si todo est� bien
 *
 */

 int agregarEmpleados (eEmpleado*,int);//TERMINADA
 /** \brief Agrega los empleados al array verificando si hay o no espacio y validando.
  *
  * \param 1 Recibe un puntero de la estructura eEmpleados
  * \param 2 Recibe la cantidad de elementos del array
  * \return Devuelve (-1) si hay error, devuelve 0 si todo est� bien
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

//4-MODIFICACION (0/1) NO ENTIENDO TANTO EL CODIGO, Y NO QUIERO COPIAR C�DIGO

//5-BAJA L�GICA (0.5/1) NO SE SI ESTA BIEN

int bajaEmpleado(eEmpleado*,int);
/** \brief Funci�n para dar de baja a un empleado, mediante la baja l�gica poniendo al vector en OCUPADO
 *
 * \param 1 Se le pasa la estructura eEmpleado
 * \param 2 Se le pasa el maximo largo del array
 * \return Retorna -1 si sale algo mal, retorna 0 si todo esta bien
 *
 */

//6-FUNCIONES DE ORDENAMIENTO
int ordenarEmpleadosApellido(eEmpleado*, int, int);
/** \brief Funci�n para ordenar los empleados por apellido
 *
 * \param 1 Se le pasa la estructura eEmpleado
 * \param 2 Se le pasa el maximo largo del array
 * \param 3 Se le pasa 1 si se quiere ordenar ascendentemente y 0 si se quiere ordenar descendentemente
 * \return Retorna -1 si da error y 0 si esta bien
 *
 */

int ordenarEmpleadosSector(eEmpleado*, int);
/** \brief Funci�n para ordenar a los empleados por sector
 *
 * \param 1 Se le pasa la estructura eEmpleado
 * \param 2 Se le pasa el maximo largo del array
 * \return Retorna -1 si da error y 0 si esta bien
 *
 */


//7-FUNCIONES PARA MOSTRAR
void mostrarEmpleado(eEmpleado);
/** \brief Funcion para mostrar un s�lo empleado
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
 /** \brief Funci�n que hardcodea los datos de 5 personas y las pasa a la estructura por referencia
 *
 * \param 1 Recibe un puntero de la estructura eEmpleados
 * \param 2 Recibe la cantidad de elementos del array
 *
 */

 //9-CALCULAR PROMEDIOS Y OTROS DATOS
