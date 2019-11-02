#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;



/** \brief Construye un nuevo empleado.
 *
 * \param  void
 * \return NULL si no hay memoria, y el empleado si todo ok
 */
Employee* employee_new();



/** \brief Construye un nuevo empleado - carga los campos con datos.
 *
 * \param idStr char* contiene id
 * \param nombreStr char* contiene nombre
 * \param horasTrabajadasStr char* contiene sueldo
 * \param sueldoStr char* contiene horas trabajadas
 * \return NULL si no hay memoria, y el empleado si todo ok
 *
 */
Employee* employee_newParametros(char*, char*, char*, char*);


/** \brief Elimina empleado.
 *
 * \param Employee* nuevoEmpleado a eliminar
 * \return void
 */
void employee_delete(Employee*);



/** \brief Crea id de empleado.
 *
 * \param Employee* nuevoEmpleado.
 * \param id int Crea el id
 * \return int 1 si todo ok y 0 si hay error
 *
 */
int employee_setId(Employee*,int);



/** \brief Obtiene el id de empleado.
 *
 * \param Employee* nuevoEmpleado.
 * \param id int* obtiene id
 * \return int 1 si todo ok y 0 si hay error
 *
 */
int employee_getId(Employee*,int*);



/** \brief Crea el nombre de empleado.
 *
 * \param Employee* nuevoEmpleado.
 * \param nombre char* Crea nombre
 * \return int 1 si todo ok y 0 si hay error
 *
 */
int employee_setNombre(Employee*,char*);



/** \brief Obtiene el nombre de empleado.
 *
 * \param Employee* nuevoEmpleado.
 * \param nombre char* Obtiene nombre
 * \return int 1 si todo ok y 0 si hay error
 *
 */
int employee_getNombre(Employee*,char*);



/** \brief Crea las horas trabajadas de empleado.
 *
 * \param Employee* nuevoEmpleado.
 * \param horasTrabajadas int Crea las horas trabajadas
 * \return int 1 si todo ok y 0 si hay error
 *
 */
int employee_setHorasTrabajadas(Employee*,int);



/** \brief Obtiene las horas trabajadas de un empleado.
 *
 * \param Employee* nuevoEmpleado.
 * \param horasTrabajadas int* Obtiene las horas trabajadas
 * \return int 1 si todo ok y 0 si hay error
 *
 */
int employee_getHorasTrabajadas(Employee*,int*);



/** \brief Crea sueldo de empleado.
 *
 * \param Employee* nuevoEmpleado.
 * \param sueldo int Crea sueldo
 * \return int 1 si todo ok y 0 si hay error
 *        .
 */
int employee_setSueldo(Employee*,int);



/** \brief Obtiene sueldo de un empleado.
 *
 * \param Employee* nuevoEmpleado.
 * \param sueldo int* Obtiene el sueldo
 * \return int 1 si todo ok y 0 si hay error
 *
 */
int employee_getSueldo(Employee*,int*);



/** \brief Ordena la lista de empleados.
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados.
 * \return int 1 si todo ok y 0 si hay error
 *
 */
int employee_sortEmployee(LinkedList*);



/** \brief Ordena la lista de empleados por sueldo.
 *
 * \param uno void* objeto generico uno
 * \param dos void* objeto generico dos
 * \return int 1 si todo ok y 0 si hay error
 *
 */
int employee_ordenarPorSueldo(void*, void*);



/** \brief Ordena la lista de empleados por nombre.
 *
 * \param uno void* objeto generico uno
 * \param dos void* objeto generico dos
 * \return int 1 si todo ok y 0 si hay error
 *
 */
int employee_ordenarPorNombre(void*, void*);



/** \brief Ordena la lista de empleados por horas trabajadas.
 *
 * \param uno void* objeto generico uno
 * \param dos void* objeto generico dos
 * \return int 1 si todo ok y 0 si hay error
 *
 */
int employee_ordenarPorHoras(void*, void*);


#endif // employee_H_INCLUDED
