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

//0-MUESTRO MENUES (4 de 4)

void printFirstMenu();
/** \brief show main menu options
 *
 *
 */

void printSecondMenu();
/** \brief show main menu
 *
 *
 */

void printModificationMenu();
/** \brief show modification submenu
 *
 *
 */

 void printSortMenu();
/** \brief show sort submenu
 *
 *
 */



//FUNCIONES PARA INICIALIZAR (1 de 1)

int initEmployees(Employee*, int);
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/


//FUNCIONES PARA AÑADIR (2 de 2)

int addEmployees(Employee*,int,int);
/** \brief add in a existing list of employees the values received as parameters in the first empty position
 * \param list employee* Pointer to array of employees
 * \param len int Array length
 * \param id int auto-incremental id variable
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */


int getFree(Employee*,int);
/** \brief get free space in the content of employees array
 *
 * \param Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - array index if Ok
 *
 */

//3-BUSCAR EMPLEADO POR ID (1 de 1)
int findEmployeeById(Employee*,int,int);
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param Employee* Pointer of array of employees
 * \param len int Array length
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */

//4-MODIFICACION (1 de 1)
int modificationEmployee(Employee*, int);
/** \brief
 *
 * \param Employee* Pointer of array of employees
 * \param len int Array length
 * \return Return (0) if it´s ok or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */

//5-BAJA LÓGICA (1 de 1)

int removeEmployee(Employee*,int,int);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param Employee* Pointer of array of employees
 * \param len int Array length
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok,
 *         (1) if user say n in respuesta and (2) if the data has delated
 *
 */

//6-FUNCIONES DE ORDENAMIENTO (2 de 2)
int sortEmployeesByLastName(Employee* list, int len, int order);
 /** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param Employee* Pointer of array of employees
 * \param len int Array length
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int sortEmployeesBySector(Employee*, int);
 /** \brief Sort the elements in the array of sector
 *
 * \param Employee* Pointer of array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */


//7-FUNCIONES PARA MOSTRAR (2 de 2)
void printEmployee(Employee list);
/** \brief print only employee
 *
 * \param Employee* Pointer of array of employees
 *
 */

int printEmployees(Employee* list, int len);
/**\brief print the content of employees array
*
* \param Employee* Pointer of array of employees
* \param len int Array length
* \return int (0)
*
*/





//8-FUNCIONES DE HARDCODEO (1 de 1) LISTO

void hardcoded(Employee*, int); //TERMINADA
 /** \brief initialize employees with data
 *
 * \param Employee* Pointer to array of employees
 * \param len int Array length
 * \return void
 *
 */

//9-CALCULAR PROMEDIOS Y OTROS DATOS (3 de 3)

 float totalSalary(Employee*,int);
/** \brief Count employes not free and amount the salary
 *
 * \param Employee* Pointer of array of employees
 * \param len int Array length
 * \return return total salary amount
 *
 */

 float salaryAverage(Employee*,int,float);
/** \brief Count employees not free and calculate the average salary
 *
 * \param Employee* Pointer of array of employees
 * \param len int Array length
 * \param allSalay float total salary amount
 * \return return salary average
 *
 */

 int betterThanAverage(Employee*,int,float);
/** \brief counts the employees whose salary exceeds the average salary
 *
 * \param Employee* Pointer of array of employees
 * \param len int Array length
 * \param averageSalary float average salary
 * \return returns the number of employees whose salary is higher than average
 *
 */

 int employeesNotFree(Employee*,int);
/** \brief counts the employees not free
 *
 * \param Employee* Pointer of array of employees
 * \param len int Array length
 * \return returns len of employees not free
 *
 */




