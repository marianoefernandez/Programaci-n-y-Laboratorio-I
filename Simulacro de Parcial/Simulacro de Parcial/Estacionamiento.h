#include <stdio.h>
#include <string.h>
#define NOTFREE 1
#define FREE 0
#define HARDCODING 10



//ESTRUCTURAS
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idPropietario;
    char nombre[51];
    eFecha fechaNac;
    int isEmpty;
}ePropietario;

typedef struct {
    char patente[51];
    eFecha fechaIngreso;
    int horaEntrada;
    int horaSalida;
    int idPropietario;
    int estaEstacionado;
}eVehiculo;

//0-MUESTRO MENUES (4 de 4)

void printFirstMenu();
/** \brief show main menu options
 *
 *
 */

void printSecondMenu();
/** \brief show 'Informar' menu
 *
 *
 */

void printModificationMenu();
/** \brief show modification submenu
 *
 *
 */

 void printInformar();
 /** \brief show modification submenu
 *
 *
 */


//FUNCIONES PARA INICIALIZAR (1 de 1)

int inicializarPropietarios(ePropietario*, int);
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list ePropietario* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int inicializarVehiculos(eVehiculo*, int);                                                                                        ///2.1 Función initEmployees:



//FUNCIONES PARA AÑADIR (2 de 2)

int agregarPropietario(ePropietario*,int,int);
/** \brief add in a existing list of employees the values received as parameters in the first empty position
 * \param list ePropietario* Pointer to array of employees
 * \param len int Array length
 * \param id int auto-incremental id variable
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */

 //int validarFecha (ePropietario*,eVehiculo*,int);//1-año,2-dia,3-mes(Propietario),4-5-6(Vehículo)
 //BUSCA FECHA DE VEHICULO O PROPETARIO Y DEPENDIENDO DE QUE ORDEN ESTABLEZCAMOS HARA DICHA VALIDACION
 //0 SI EL NUM SE PASA DEL LIMITE
 //-1 SI EL NUM NO EXISTE EN CALENDARIO
 //1 SI TODO ESTA BIEN



int getFree(ePropietario*,int);
/** \brief get free space in the content of employees array
 *
 * \param Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - array index if Ok
 *
 */

 int agregarVehiculo(eVehiculo*,int);

 int egresarVehiculo(eVehiculo*,int);

//3-BUSCAR EMPLEADO POR ID (1 de 1)
int buscarPropietarioPorId(ePropietario*,int,int);
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param Employee* Pointer of array of employees
 * \param len int Array length
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */

//4-MODIFICACION (1 de 1)
int modificarPropietario(ePropietario*, int);
/** \brief
 *
 * \param Employee* Pointer of array of employees
 * \param len int Array length
 * \return Return (0) if it´s ok or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */

//5-BAJA LÓGICA (1 de 1)

int eliminarPropietario(ePropietario*,int,int);
/** \brief Remove a ePropietario by Id (put isEmpty Flag in 1)
 *
 * \param ePropietario* Pointer of array of employees
 * \param len int Array length
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok,
 *         (1) if user say n in respuesta and (2) if the data has delated
 *
 */

//6-FUNCIONES DE ORDENAMIENTO (2 de 2)
int ordenarPropietariosNombreAnio(ePropietario*,int,int);
 /** \brief Sort the elements in the array of propietarios, the argument order indicate UP or DOWN order
 *
 * \param ePropietario* Pointer of array of propietarios
 * \param len int Array length
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

 int ordenarPropietariosDuenioPatente(eVehiculo*,int,int);


//7-FUNCIONES PARA MOSTRAR (2 de 2)
void printPropietario(ePropietario);
/** \brief print only employee
 *
 * \param Employee* Pointer of array of employees
 *
 */

int printPropietarios(ePropietario*,int);
/**\brief print the content of employees array
*
* \param Employee* Pointer of array of employees
* \param len int Array length
* \return int (0)
*
*/

int printVehiculos(ePropietario*,eVehiculo*,int);




//8-FUNCIONES DE HARDCODEO (2 de 2) LISTO

//void hardcoded(Employee*, int); //TERMINADA
 /** \brief initialize employees with data
 *
 * \param Employee* Pointer to array of employees
 * \param len int Array length
 * \return void
 *
 */

void hardcodeoPropietarios(ePropietario*,int);

void hardcodeoVehiculos(eVehiculo*,int);

//9-CALCULAR PROMEDIOS Y OTROS DATOS (3 de 3)

 //float totalSalary(Employee*,int);
/** \brief Count employes not free and amount the salary
 *
 * \param Employee* Pointer of array of employees
 * \param len int Array length
 * \return return total salary amount
 *
 */

 //float salaryAverage(Employee*,int,float);
/** \brief Count employees not free and calculate the average salary
 *
 * \param Employee* Pointer of array of employees
 * \param len int Array length
 * \param allSalay float total salary amount
 * \return return salary average
 *
 */

 //int betterThanAverage(Employee*,int,float);
/** \brief counts the employees whose salary exceeds the average salary
 *
 * \param Employee* Pointer of array of employees
 * \param len int Array length
 * \param averageSalary float average salary
 * \return returns the number of employees whose salary is higher than average
 *
 */

 int propietariosOcupados(ePropietario*,int);
/** \brief counts the propietarios not free
 *
 * \param Employee* Pointer of array of propietarios
 * \param len int Array length
 * \return returns len of propietarios not free
 *
 */




