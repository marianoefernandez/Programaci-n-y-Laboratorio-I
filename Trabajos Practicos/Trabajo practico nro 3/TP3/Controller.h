/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 1 si todo ok o sino 0 si no funciona
 *
 */

int controller_loadFromText(char*,LinkedList*);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 1 si todo ok o sino 0 si no funciona
 *
 */

int controller_loadFromBinary(char*,LinkedList*);

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 1 si todo ok o sino 0 si no funciona
 *
 */

int controller_addEmployee(LinkedList*);

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 1 si todo ok o sino 0 si no funciona
 *
 */

int controller_editEmployee(LinkedList*);

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 1 si todo ok o sino 0 si da error, -1 si el usuario cancela la accion y -2 si elije una opcion incorrecta
 *
 */

int controller_removeEmployee(LinkedList*);

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 1 si todo ok o sino 0 si no funciona
 *
 */

int controller_ListEmployee(LinkedList*);

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 1 si todo ok o sino 0 si no funciona
 *
 */

int controller_sortEmployee(LinkedList*);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 1 si todo ok o sino 0 si no funciona
 *
 */
int controller_saveAsText(char*,LinkedList*);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 1 si todo ok o sino 0 si no funciona
 *
 */

int controller_saveAsBinary(char*,LinkedList*);

/** \brief Incremento el id
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados.
 * \return int retorna el id
 *
 */

int controller_getID(LinkedList*);

