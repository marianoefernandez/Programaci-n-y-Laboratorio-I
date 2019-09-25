#include <stdio.h>
#include <string.h>
#define OCUPADO 1
#define LIBRE 0
#define HARDCODEO 5
#include "imputs.h"

typedef struct
{
    int id;
    char nombre [51];
    char apellido [51];
    float salario;
    int sector;
    int estado;
}eEmpleado;


//MENUES (1 de 4)

void menuPrincipal();
/** \brief Muestra menu de opciones
 *
 *
 */

//SEGUNDO MENU (FALTA)

//SWITCH DEL PRIMER MENU (FALTA)

//SWITCH DEL SEGUNDO MENU (FALTA)


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

int autoincrementar (int*);
/** \brief Funcion que va sumando de a uno el id
 *
 * \param se le pasa el puntero con el dato anterior
 * \return retorna el nuevo id
 *
 */

//FUNCIONES PARA AÑADIR (2 de 4)

 eEmpleado pedirEmpleado(); //FALTA TERMINAR
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

//3-BUSCAR EMPLEADO POR ID

//4-BAJA LÓGICA

//5-FUNCIONES DE ORDENAMIENTO

//6-FUNCIONES PARA MOSTRAR

//7-FUNCIONES DE HARDCODEO (1 de 1) LISTO

  void hardcodeoEmpleados(Employee*, int); //TERMINADA
 /** \brief Función que hardcodea los datos de 5 personas y las pasa a la estructura por referencia
 *
 * \param 1 Recibe un puntero de la estructura eEmpleados
 * \param 2 Recibe la cantidad de elementos del array
 *
 */
