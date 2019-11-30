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



/** \brief Construye nuevo empleado.
 *
 * \param  void
 * \return NULL si no hay memoria o puntero a Employee* si todo ok
 *
 */
Employee* employee_new();



/** \brief Carga los campos con datos al construir el empleado.
 *
 * \param idStr char* tiene id
 * \param nombreStr char* tiene nombre
 * \param horasTrabajadasStr char* tiene sueldo
 * \param sueldoStr char* tiene horas trabajadas
 * \return NULL si no hay memoria o puntero a Employee* si todo ok
 *
 */
Employee* employee_newParametros(char*, char*, char*, char*);



/** \brief Elimina empleado.
 *
 * \param this Employee* es el empleado a eliminar
 * \return void
 */
void employee_delete(Employee*);



/** \brief Setea el id para empleado.
 *
 * \param this Employee* empleado.
 * \param id int Crea id
 * \return 0 si da error y 1 si todo ok
 *
 */
int employee_setId(Employee*,int);



/** \brief Obtiene id de empleado.
 *
 * \param this Employee* empleado.
 * \param id int* obtiene id
 * \return 0 si da error y 1 si todo ok
 *
 */
int employee_getId(Employee*,int*);



/** \brief Setea el nombre de un empleado.
 *
 * \param this Employee* empleado.
 * \param nombre char* Crea nombre
 * \return 0 si da error y 1 si todo ok
 *
 */
int employee_setNombre(Employee*,char*);



/** \brief Obtiene nombre de empleado.
 *
 * \param this Employee* empleado.
 * \param nombre char* Obtiene nombre
 * \return 0 si da error y 1 si todo ok
 *
 */
int employee_getNombre(Employee*,char*);



/** \brief Setea las horas trabajadas de empleado.
 *
 * \param this Employee* empleado.
 * \param horasTrabajadas int Crea las horas trabajadas
 * \return 0 si da error y 1 si todo ok
 *
 */
int employee_setHorasTrabajadas(Employee*,int);



/** \brief Obtiene las horas trabajadas de empleado.
 *
 * \param this Employee* empleado.
 * \param horasTrabajadas int* Obtiene las horas trabajadas
 * \return 0 si da error y 1 si todo ok
 *
 */
int employee_getHorasTrabajadas(Employee*,int*);



/** \brief Setea sueldo de empleado.
 *
 * \param this Employee* empleado.
 * \param sueldo int Crea el sueldo
 * \return 0 si da error y 1 si todo ok
 *
 */
int employee_setSueldo(Employee*,int);



/** \brief Obtiene sueldo de empleado.
 *
 * \param this Employee* empleado.
 * \param sueldo int* Obtiene el sueldo
 * \return 0 si da error y 1 si todo ok
 *
 */
int employee_getSueldo(Employee*,int*);



/** \brief Ordena los empleados.
 *
 * \param pArrayListEmployee LinkedList* Es un puntero a la lista de empleados.
 * \return 0 si da error y 1 si todo ok
 *
 */
int employee_sortEmployee(LinkedList*);



/** \brief Ordena los empleados por sueldo.
 *
 * \param thisA void* objeto generico A
 * \param thisB void* objeto generico B
 * \return 0 si da error y 1 si todo ok
 *
 */
int employee_ordenarPorSueldo(void*, void*);



/** \brief Ordena los empleados por nombre.
 *
 * \param thisA void* objeto generico A
 * \param thisB void* objeto generico B
 * \return 0 si da error y 1 si todo ok
 *
 */
int employee_ordenarPorNombre(void*, void*);



/** \brief Ordena los empleados por horas trabajadas.
 *
 * \param thisA void* objeto generico A
 * \param thisB void* objeto generico B
 * \return 0 si da error y 1 si todo ok
 *
 */
int employee_ordenarPorHoras(void*, void*);


#endif // employee_H_INCLUDED
