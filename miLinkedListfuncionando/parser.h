
/** \brief Parsea los datos desde el archivo data.csv (modo texto).
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados.
 * \return int 1 si todo ok, 0 si error
 */
int parser_EmployeeFromText(FILE*,LinkedList*);



/** \brief Parsea los datos desde el archivo data.bin (modo binario).
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados.
 * \return int 1 si todo ok, 0 si error
 *
 */
int parser_EmployeeFromBinary(FILE*,LinkedList*);
