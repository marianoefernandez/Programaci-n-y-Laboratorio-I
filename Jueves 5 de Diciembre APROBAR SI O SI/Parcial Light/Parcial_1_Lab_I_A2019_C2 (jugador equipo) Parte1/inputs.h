//ESTAS BIBLIOTECAS TIENEN INPUTS Y ALGUNAS FUNCIONES EXTRAS GENERICAS POR SI SE LAS NECESITA

/** \brief Pide un numero y lo devuelve.
 * \param  Es el mensaje que escribe el usuario y muestra la función.
 * \return Es el numero ingresado.
 */
int getInt (char*);

int validarDia (char*);
int validarMes (char*);
int validarAnio (char*);

//int* validarFecha(char*)
int isADate(char*);



/** \brief Pide un numero y lo devuelve.
 *
 * \param Es el mensaje que escribe el usuario y muestra la función.
 * \return Es el numero ingresado.
 */
float getFloat (char*);



/** \brief Pide un caracter y lo devuelve.
 *
 * \param Es el mensaje que escribe el usuario y muestra la función.
 * \return Es el caracter ingresado.
 */
char getChar(char*);



/** \brief Pide una cadena y la devuelve
 *
 * \param 1 Es el mensaje que escribe el usuario y lo muestra la función.
 * \param 2 Es la cadena a usar
 *
 */
void getString (char*,char*);



/** \brief Hace mayuscula la primer letra del dato ingresado.
 *
 * \param char string que sera modificado.
 */
void stringToUpper(char*);


/** \brief Verifica si el valor ingresado es un celular.
 *
 * \param Array con la cadena que sera analizada.
 * \return 1 si es un telefono y 0 si no lo es.
 */
int isCellphone(char*);

/** \brief Verifica si el valor ingresado es un telefono.
 *
 * \param Array con la cadena que sera analizada.
 * \return 1 si es un telefono y 0 si no lo es.
 */
int isPhone (char*);



/** \brief Verifica si el valor ingresado contiene solo letras.
 *
 * \param Array con la cadena que sera analizada.
 * \return 1 si contiene solo espacios y letras y 0 si contiene numero, etc.
 */
int isOnlyLetters (char*);

/** \brief Verifica si el valor ingresado es numerico o no.
 *
 * \param Array con la cadena que sera analizada.
 * \return 1 si es num y 0 si no lo es .
 */
int isNumeric (char*);


/** \brief Verifica si el valor ingresado contiene sólo letras y numeros.
 *
 * \param Array con la cadena que sera analizada.
 * \return 1 si contiene solo espacio o letras y numeros y 0 si no.
 */
int isAlphaNumeric (char*);

int dameMax(int*,int);

int dameMin(int*,int);

void mostrarArray(int*,int);

void cargaSecuencialArray(int*,int,char*);

float darmePromedio (int*,int);

void burbujeoMejorado (int*,int);

void insersion (int*,int);

void cargarVector(int*,int);

void mostrarVector(int*,int);

void mostrarNegativos(int*,int);

void mostrarPromedio(int*,int);

int sumarPositivos(int*,int);

int contarPositivos(int*,int);

float calcularPromedio(int,int);





