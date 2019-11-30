#include "utn.h"
/*int validarEmail(char eMail[])
{
    int i;
    int largo;
    int r = -2;

    largo = strlen(eMail);
    for(i = 0;i<largo;i++)
    {
        if
    }
    return r;
}*/


int validarSexo(char sexo)
{
    int r = -2;
    if(sexo == 102 || sexo == 109)
    {
        r = 0;
    }
    return r;
}


char* enterString(char* string1)
{
    fflush(stdin);
    gets(string1);
    return string1;
}

int enterInt(char mensaje[])
{
    int num1;
    printf(mensaje);
    scanf("%d", &num1);
    return num1;
}

float enterFloat(char mensaje[])
{
    float num1;
    printf(mensaje);
    scanf("%f", &num1);
    return num1;
}

int onlyLetters(char string1[])
{
    int i;
    int largo;
    int r = 0;
    largo = strlen(string1);
    for(i=1; i<largo; i++)
    {
        if(string1[i]==32 || string1[i]==64)
        {
            continue;
        }
        if(string1[i]==64)
        {
            continue;
        }
        if(((string1[i]<97 && string1[i]>90) || string1[i]>122) || string1[i]<65)
        {
            r = -2;
            return r;
        }
    }
    return r;
}

int inicializarEquipos(sEquipos list[], int cant)
{
    int i;
    int r=-1;
    if(cant > 0 && list != NULL)
    {
        r = 0;
        for(i=0; i<cant; i++)
        {
            list[i].estado = LIBRE;
        }
    }
    return r;
}

int inicializarJugadores(sJugadores list[], int cant)
{
    int i;
    int r=-1;
    if(cant > 0 && list != NULL)
    {
        r = 0;
        for(i=0; i<cant; i++)
        {
            list[i].estado = LIBRE;
        }
    }
    return r;
}

int inicializarReferees(sReferi list[], int cant)
{
    int i;
    int r=-1;
    if(cant > 0 && list != NULL)
    {
        r = 0;
        for(i=0; i<cant; i++)
        {
            list[i].estado = LIBRE;
        }
    }
    return r;
}

int inicializarPartidos(sPartidos list[], int cant)
{
    int i;
    int r=-1;
    if(cant > 0 && list != NULL)
    {
        r = 0;
        for(i=0; i<cant; i++)
        {
            list[i].estado = LIBRE;
        }
    }
    return r;
}

int buscarLibreEquipos(sEquipos list[],int cant)
{
    int i;
    int index = -1;
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarLibreJugadores(sJugadores list[],int cant)
{
    int i;
    int index = -1;
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarLibreReferees(sReferi list[],int cant)
{
    int i;
    int index = -1;
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarLibrePartidos(sPartidos list[],int cant)
{
    int i;
    int index = -1;
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int cargarPartido(sPartidos listP[],sEquipos listE[],sReferi listR[],int cantP,int cantE,int cantR,int idNumber)
{
    int i;
    int r = -1;
    i = buscarLibrePartidos(listP, cantP);

    if(i != -1)
    {
        listP[i].codigoDeEquipoLocal = enterInt("Ingrese el codigo del equipo local : ");
        r = relacionPartidoEquipoLocal(listP[i],listE,cantE);
        while(r==-2)
        {
            listP[i].codigoDeEquipoLocal = enterInt("El codigo no pertenece a un equipo valido, reingrese el codigo : ");
            r = relacionPartidoEquipoLocal(listP[i],listE,cantE);
        }

        listP[i].codigoDeEquipoVisitante = enterInt("Ingrese el codigo del equipo visitante : ");
        r = relacionPartidoEquipoVisitante(listP[i],listE,cantE);
        while(r==-2 || listP[i].codigoDeEquipoVisitante == listP[i].codigoDeEquipoLocal)
        {
            listP[i].codigoDeEquipoVisitante = enterInt("El codigo no pertenece a un equipo valido, reingrese el codigo : ");
            r = relacionPartidoEquipoVisitante(listP[i],listE,cantE);
        }

        listP[i].codigoDeReferi = enterInt("Ingrese el codigo del referi : ");
        r = relacionPartidoReferi(listP[i], listR, cantR);
        while(r==-2)
        {
            listP[i].codigoDeReferi = enterInt("El codigo no pertenece a un equipo valido, reingrese el codigo : ");
            r = relacionPartidoReferi(listP[i], listR, cantR);
        }

        printf("Ingrese la fecha del partido \n");
        listP[i].fechaDePartido.dia = enterInt("Dia : ");
        while(listP[i].fechaDePartido.dia > 31 || listP[i].fechaDePartido.dia < 1)
        {
            listP[i].fechaDePartido.dia = enterInt("Dia invalido, reingrese : ");
        }

        listP[i].fechaDePartido.mes = enterInt("Mes : ");
        while(listP[i].fechaDePartido.mes > 12 || listP[i].fechaDePartido.mes < 1)
        {

            listP[i].fechaDePartido.mes = enterInt("Mes invalido, reingrese : ");
        }

        listP[i].fechaDePartido.anio = enterInt("Anio : ");
        while(listP[i].fechaDePartido.anio > 2019 || listP[i].fechaDePartido.anio < 1910)
        {
            listP[i].fechaDePartido.anio = enterInt("Anio invalido, reingrese : ");
        }
        listP[i].codigo = idNumber;
        listP[i].estado = OCUPADO;
        r = 0;
    }

    return r;
}

int cargarEquipo(sEquipos list[],int cant,int idNumber)
{
    int i;
    int r = -1;
    i = buscarLibreEquipos(list, cant);

    if(i != -1)
    {
        printf("Ingrese el nombre del equipo : ");
        enterString(list[i].nombre);
        r = onlyLetters(list[i].nombre);
        while(r==-2)
        {
            printf("Solo se aceptan letras y espacios, reingrese nombre: ");
            enterString(list[i].nombre);
            r = onlyLetters(list[i].nombre);
        }
        printf("Ingrese la localidad del equipo : ");
        enterString(list[i].localidad);
        r = onlyLetters(list[i].localidad);
        while(r==-2)
        {
            printf("Solo se aceptan letras y espacios, reingrese localidad: ");
            enterString(list[i].localidad);
            r = onlyLetters(list[i].localidad);
        }
        r = 0;
        list[i].codigo = idNumber;
        list[i].estado = OCUPADO;
    }

    return r;
}

int cargarJugador(sJugadores listJ[],sEquipos listE[],int cantJ,int cantE,int idNumber)
{
    int i;
    int r = -1;
    i = buscarLibreJugadores(listJ, cantJ);

    if(i != -1)
    {
        printf("\nIngrese el apellido del jugador : ");
        enterString(listJ[i].apellido);
        r = onlyLetters(listJ[i].apellido);
        while(r==-2)
        {
            printf("\nSolo se aceptan letras, reingrese apellido: ");
            enterString(listJ[i].apellido);
            r = onlyLetters(listJ[i].apellido);
        }

        printf("\nIngrese el nombre del jugador : ");
        enterString(listJ[i].nombre);
        r = onlyLetters(listJ[i].nombre);
        while(r==-2)
        {
            printf("\nSolo se aceptan letras, reingrese nombre: ");
            enterString(listJ[i].nombre);
            r = onlyLetters(listJ[i].nombre);
        }

        printf("\nIngrese el codigo de su equipo : ");
        scanf("%d", &listJ[i].codigoDeEquipo);
        r = relacionJugadorEquipo(listJ[i],listE,cantE);
        while(r==-2)
        {
            listJ[i].codigoDeEquipo = enterInt("El codigo no pertenece a un equipo valido, reingrese el codigo : ");
            r = relacionJugadorEquipo(listJ[i],listE,cantE);
        }

        fflush(stdin);
        printf("\nIngrese su sexo : ");
        listJ[i].sexo = getchar();
        r = validarSexo(listJ[i].sexo);
        while(r==-2)
        {
            fflush(stdin);
            printf("\nSexo invalido, reingrese : ");
            listJ[i].sexo = getchar();
            r = validarSexo(listJ[i].sexo);
        }

        printf("\nIngrese su fecha de nacimiento \n");
        listJ[i].fechaNacimiento.dia = enterInt("Dia : ");
        while(listJ[i].fechaNacimiento.dia > 31 || listJ[i].fechaNacimiento.dia < 1)
        {
            listJ[i].fechaNacimiento.dia = enterInt("Dia invalido, reingrese : ");
        }

        listJ[i].fechaNacimiento.mes = enterInt("Mes : ");
        while(listJ[i].fechaNacimiento.mes > 12 || listJ[i].fechaNacimiento.mes < 1)
        {

            listJ[i].fechaNacimiento.mes = enterInt("Mes invalido, reingrese : ");
        }

        listJ[i].fechaNacimiento.anio = enterInt("Anio : ");
        while(listJ[i].fechaNacimiento.anio > 2019 || listJ[i].fechaNacimiento.anio < 1910)
        {
            listJ[i].fechaNacimiento.anio = enterInt("Anio invalido, reingrese : ");
        }

        listJ[i].codigo = idNumber;
        listJ[i].estado = OCUPADO;
        r = 0;
    }

    return r;
}

int cargarReferi(sReferi list[],int cant,int idNumber)
{
    int i;
    int r = -1;
    i = buscarLibreReferees(list, cant);

    if(i != -1)
    {
        printf("Ingrese el apellido del referi : ");
        enterString(list[i].apellido);
        r = onlyLetters(list[i].apellido);
        while(r==-2)
        {
            printf("Solo se aceptan letras, reingrese apellido: ");
            enterString(list[i].apellido);
            r = onlyLetters(list[i].apellido);
        }

        printf("Ingrese el nombre del referi : ");
        enterString(list[i].nombre);
        r = onlyLetters(list[i].nombre);
        while(r==-2)
        {
            printf("Solo se aceptan letras, reingrese nombre: ");
            enterString(list[i].nombre);
            r = onlyLetters(list[i].nombre);
        }

        fflush(stdin);
        printf("\nIngrese su sexo : ");
        list[i].sexo = getchar();
        r = validarSexo(list[i].sexo);
        while(r==-2)
        {
            fflush(stdin);
            printf("\nSexo invalido, reingrese : ");
            list[i].sexo = getchar();
            r = validarSexo(list[i].sexo);
        }

        printf("Ingrese su eMail : ");
        enterString(list[i].eMail);

        printf("Ingrese su fecha de nacimiento \n");

        list[i].fechaNacimiento.dia = enterInt("Dia : ");
        while(list[i].fechaNacimiento.dia > 31 || list[i].fechaNacimiento.dia < 1)
        {
            list[i].fechaNacimiento.dia = enterInt("Dia invalido, reingrese : ");
        }

        list[i].fechaNacimiento.mes = enterInt("Mes : ");
        while(list[i].fechaNacimiento.mes > 12 || list[i].fechaNacimiento.mes < 1)
        {
            list[i].fechaNacimiento.mes = enterInt("Mes invalido, reingrese : ");
        }

        list[i].fechaNacimiento.anio = enterInt("Anio : ");
        while(list[i].fechaNacimiento.anio > 2019 || list[i].fechaNacimiento.anio < 1910)
        {
            list[i].fechaNacimiento.anio = enterInt("Anio invalido, reingrese : ");
        }

        list[i].codigo = idNumber;
        list[i].estado = OCUPADO;
    }

    return r;
}

void mostrarUnEquipo(sEquipos unEquipo)
{
    printf("%03d %20s \t %20s \n"
           , unEquipo.codigo
           , unEquipo.nombre
           , unEquipo.localidad);
}


void mostrarListadoDeEquipos(sEquipos list[], int cant)
{
    int i;
    printf("CODIGO \t\tNOMBRE   \t\t     LOCALIDAD\n\n");
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            mostrarUnEquipo(list[i]);
        }

    }
}

void mostrarUnJugador(sJugadores unJugador)
{
    printf("%03d %20s \t %20s \t %03d \t\t %c  %02d/%02d/%4d\n", unJugador.codigo
           , unJugador.nombre
           , unJugador.apellido
           , unJugador.codigoDeEquipo
           , unJugador.sexo
           , unJugador.fechaNacimiento.dia
           , unJugador.fechaNacimiento.mes
           , unJugador.fechaNacimiento.anio);
}
void mostrarListadoDeJugadores(sJugadores list[], int cant)
{
    int i;
    printf("CODIGO \t\t  NOMBRE  \t\t   APELLIDO  \t COD EQUIPO \t SEXO          FECHA NACIMIENTO \n\n");
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            mostrarUnJugador(list[i]);
        }

    }
}

void mostrarUnReferee(sReferi unReferi)
{
    printf("%03d %20s \t %20s \t %c \t %20s \t %02d/%02d/%4d\n", unReferi.codigo
           , unReferi.nombre
           ,unReferi.apellido
           ,unReferi.sexo
           ,unReferi.eMail
           , unReferi.fechaNacimiento.dia
           , unReferi.fechaNacimiento.mes
           , unReferi.fechaNacimiento.anio);
}

void mostrarListadoDeReferees(sReferi list[], int cant)
{
    int i;
    printf("CODIGO \t   NOMBRE  \t APELLIDO  \t SEXO    EMAIL \t   FECHA DE NACIMIENTO\n\n");
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            mostrarUnReferee(list[i]);
        }

    }
}

void mostrarUnPartido(sPartidos unPartido)
{
    printf("%03d \t\t %03d \t\t %03d \t\t %03d \t\t %02d/%02d/%4d\n", unPartido.codigo
           ,unPartido.codigoDeEquipoLocal
           ,unPartido.codigoDeEquipoVisitante
           ,unPartido.codigoDeReferi
           , unPartido.fechaDePartido.dia
           , unPartido.fechaDePartido.mes
           , unPartido.fechaDePartido.anio);
}

void mostrarListadoDePartidos(sPartidos list[], int cant)
{
    int i;
    printf("CODIGO \t   CODIGO LOCAL    CODIGO VISITANTE     CODIGO REFEREE     FECHA \n\n");
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            mostrarUnPartido(list[i]);
        }

    }
}

int ordenarJugadoresPorApellido(sJugadores list[],int cant)
{
    sJugadores auxJugador;
    int i;
    int j;
    int r = -1;
    if(cant > 0 && list != NULL)
    {
        for(i=0; i<cant-1; i++)
        {
            for(j=i+1; j<cant; j++)
            {
                if(strcmp(list[i].apellido, list[j].apellido) > 0)
                {
                    //De A - Z
                    auxJugador = list[i];
                    list[i] = list[j];
                    list[j] = auxJugador;
                }
            }

        }
        r = 0;
    }
    return r;
}

int ordenarEquiposPorNombre(sEquipos list[],int cant)
{
    sEquipos auxEquipo;
    int i;
    int j;
    int r = -1;
    if(cant > 0 && list != NULL)
    {
        for(i=0; i<cant-1; i++)
        {
            for(j=i+1; j<cant; j++)
            {
                if(strcmp(list[i].nombre, list[j].nombre) > 0)
                {
                    //De A - Z
                    auxEquipo = list[i];
                    list[i] = list[j];
                    list[j] = auxEquipo;
                }
            }

        }
        r = 0;
    }
    return r;
}

int ordenarPartidosPorFecha(sPartidos list[],int cant)
{
    sPartidos auxPartido;
    int i;
    int j;
    int r = -1;
    if(cant > 0 && list != NULL)
    {
        for(i=0; i<cant-1; i++)
        {
            for(j=i+1; j<cant; j++)
            {
                if(list[i].fechaDePartido.anio > list[j].fechaDePartido.anio)
                {
                    //De A - Z
                    auxPartido = list[i];
                    list[i] = list[j];
                    list[j] = auxPartido;
                }
            }

        }

        r = 0;
    }
    return r;
}

int relacionJugadorEquipo(sJugadores unJugador,sEquipos listE[],int cantE)
{
    int i;
    int r=-2;
    for(i=0; i<cantE; i++)
    {
        if(listE[i].estado == OCUPADO && unJugador.codigoDeEquipo == listE[i].codigo)
        {
            r = 0;
            break;
        }
    }
    return r;
}

int relacionPartidoEquipoLocal(sPartidos unPartido, sEquipos listE[], int cantE)
{
    int i;
    int r=-2;
    for(i=0; i<cantE; i++)
    {
        if(listE[i].estado == OCUPADO && unPartido.codigoDeEquipoLocal == listE[i].codigo)
        {
            r = 0;
            break;
        }
    }
    return r;
}

int relacionPartidoEquipoVisitante(sPartidos unPartido, sEquipos listE[], int cantE)
{
    int i;
    int r=-2;
    for(i=0; i<cantE; i++)
    {
        if(listE[i].estado == OCUPADO && unPartido.codigoDeEquipoVisitante == listE[i].codigo)
        {
            r = 0;
            break;
        }
    }
    return r;
}

int relacionPartidoReferi(sPartidos unPartido, sReferi listR[], int cantR)
{
    int i;
    int r=-2;
    for(i=0; i<cantR; i++)
    {
        if(listR[i].estado == OCUPADO && unPartido.codigoDeReferi == listR[i].codigo)
        {
            r = 0;
            break;
        }
    }
    return r;
}

int flagJugadores(sJugadores list[], int cant)
{
    int r = -1;
    int i;

    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            r = 0;
            break;
        }
    }

    return r;
}

int flagEquipos(sEquipos list[], int cant)
{
    int r = -1;
    int i;

    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            r = 0;
            break;
        }
    }

    return r;
}


int flagPartidos(sPartidos list[], int cant)
{
    int r = -1;
    int i;

    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            r = 0;
            break;
        }
    }

    return r;
}

void hardcodeoEquipos(sEquipos list[], int cant)
{
    int i;
    char equipos[][51] = {"Cambios FC","Camboya","Dep Muy Caliente","Hacha y Birra","Bidon de Branco","Real Coholicos","Suc. Congreso","Sucursal Flores","Los Isotopos","Ornad + 4"};
    char localidades[][33] = {"Lanus","Banfield","Avellaneda","CABA","Lanus","Banfield","Avellaneda","CABA","Lanus","Banfield","Avellaneda","CABA"};
    for(i=0; i<cant; i++)
    {
        strcpy(list[i].nombre, equipos[i]);
        strcpy(list[i].localidad, localidades[i]);
        list[i].codigo = i;
        list[i].estado = OCUPADO;
    }
}

void hardcodeoJugadores(sJugadores list[], int cant)
{
    int i;

    char Nombres[][50]= {"JUAN","JOSE LUIS","JOSE","MARIA GUADALUPE","JOSE","GUADALUPE","MARIA","JUANA","ANTONIO","JESUS","MIGUEL ANGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARIA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTIN","RAUL","DAVID","JOSEFINA","JOSE ANTONIO","ARTURO","MARCO ANTONIO","JOSE MANUEL","JUAN","JOSE LUIS","JOSE","MARIA GUADALUPE","FRANCISCO","GUADALUPE","MARIA","JUANA","ANTONIO","JESUS","MIGUEL ANGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARIA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTIN","RAUL","DAVID","JOSEFINA","JOSE ANTONIO","ARTURO","MARCO ANTONIO","JOSE MANUEL","JUAN","JOSE LUIS","JOSE","MARIA GUADALUPE","FRANCISCO","GUADALUPE","MARIA","JUANA","ANTONIO","JESUS","MIGUEL ANGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARIA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTIN","RAUL","DAVID","JOSEFINA","JOSE ANTONIO","ARTURO","MARCO ANTONIO","JOSE MANUEL","JUAN","JOSE LUIS","JOSE","MARIA GUADALUPE","FRANCISCO","GUADALUPE","MARIA","JUANA","ANTONIO","JESUS","MIGUEL ANGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARIA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTIN","RAUL","DAVID","JOSEFINA","JOSE ANTONIO","ARTURO","MARCO ANTONIO","JOSE MANUEL","JUAN","JOSE LUIS","JOSE","MARIA GUADALUPE","FRANCISCO","GUADALUPE","MARIA","JUANA","ANTONIO","JESUS","MIGUEL ANGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARIA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTIN","RAUL","DAVID","JOSEFINA","JOSE ANTONIO","ARTURO","MARCO ANTONIO","JOSE MANUEL","JUAN","JOSE LUIS","JOSE","MARIA GUADALUPE","FRANCISCO","GUADALUPE","MARIA","JUANA","ANTONIO","JESUS","MIGUEL ANGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARIA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTIN","RAUL","DAVID","JOSEFINA","JOSE ANTONIO","ARTURO","MARCO ANTONIO","JOSE MANUEL","JUAN","JOSE LUIS","JOSE","MARIA GUADALUPE","FRANCISCO","GUADALUPE","MARIA","JUANA","ANTONIO","JESUS","MIGUEL ANGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARIA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTIN","RAUL","DAVID","JOSEFINA","JOSE ANTONIO","ARTURO","MARCO ANTONIO","JOSE MANUEL"};
    char Sexo[]= {'m','m','m','f','m','f','f','f','m','m','m','m','m','m','f','f','m','m','m','m','m','m','m','m','m','m','m','m','m','m','f','m','m','m','m','m','m','m','f','m','f','f','f','m','m','m','m','m','m','f','f','m','m','m','m','m','m','m','m','m','m','m','m','m','m','f','m','m','m','m','m','m','m','f','m','f','f','f','m','m','m','m','m','m','f','f','m','m','m','m','m','m','m','m','m','m','m','m','m','m','f','m','m','m','m'};
    char Apellido[][50]= {"Gonzalez","Rodriguez","Gomez","Fernandez","Lopez","Diaz","Martinez","Perez","Romero","Sanchez","Garcia","Sosa","Torres","Ramirez","Alvarez","Benitez","Acosta","Flores","Medina","Ruiz","Gonzalez","Rodriguez","Gomez","Fernandez","Lopez","Diaz","Martinez","Perez","Romero","Sanchez","Garcia","Sosa","Torres","Ramirez","Alvarez","Benitez","Acosta","Flores","Medina","Ruiz","Gonzalez","Rodriguez","Gomez","Fernandez","Lopez","Diaz","Martinez","Perez","Romero","Sanchez","Garcia","Sosa","Torres","Ramirez","Alvarez","Benitez","Acosta","Flores","Medina","Ruiz"};
    int codigoEquipos[] = { 1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10,10,10,10,10};
    int anios[]= { 2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995};
    int mes[]= { 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1};
    int dia[]= { 25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22};
    for(i=0; i<cant; i++)
    {
        strcpy(list[i].nombre, Nombres[i]);
        list[i].sexo = Sexo[i];
        strcpy(list[i].apellido, Apellido[i]);
        list[i].codigoDeEquipo = codigoEquipos[i];
        list[i].fechaNacimiento.anio = anios[i];
        list[i].fechaNacimiento.mes = mes[i];
        list[i].fechaNacimiento.dia = dia[i];
        list[i].codigo = i;
        list[i].estado = OCUPADO;
    }
}

void hardcodeoReferees(sReferi list[], int cant)
{
    int i;
    char Nombres[][50]= {"Nicolas","Nazareno","Dario","Fernando","Gisella","Yael"};
    char Apellido[][50]= {"Lamolina","Arasa","Herrera","Espinoza","Trucco","Falcon Perez"};
    char Sexo[]= {'m','m','m','m','f','f'};
    int anios[]= {1980,1981,1975,1970,1986,1989};
    int mes[]= {8,10,5,6,6,2};
    int dia[]= {15,5,20,22,12,1};

    for(i=0; i<cant; i++)
    {
        strcpy(list[i].nombre, Nombres[i]);
        list[i].sexo = Sexo[i];
        strcpy(list[i].apellido, Apellido[i]);
        list[i].fechaNacimiento.anio = anios[i];
        list[i].fechaNacimiento.mes = mes[i];
        list[i].fechaNacimiento.dia = dia[i];
        list[i].codigo = i;
        list[i].estado = OCUPADO;
    }
}

void hardcodeoPartidos(sPartidos list[], int cant)
{
    int i;
    int visitante[] = {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5};
    int local[]= {10,9,8,7,6,4,3,2,1,5,8,7,6,10,9,2,1,5,4,3,6,10,9,8,7};
    int dia[]= {21,21,21,21,21,28,28,28,28,28,5,5,5,5,5,12,12,12,12,12,19,19,19,19,19 };
    int mes[]= {9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    int anio[]= {2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019};
    int referi[]= {1,2,6,4,5,1,2,3,4,6,6,2,3,4,5,1,6,3,4,5,1,2,3,6,5};


    for(i=0; i<cant; i++)
    {
        list[i].codigoDeEquipoLocal = local[i];
        list[i].codigoDeEquipoVisitante = visitante[i];
        list[i].fechaDePartido.dia = dia[i];
        list[i].fechaDePartido.mes = mes[i];
        list[i].fechaDePartido.anio = anio[i];
        list[i].codigoDeReferi = referi[i];
        list[i].codigo = i;
        list[i].estado = OCUPADO;
    }
}

int modificarEquipo(sEquipos list[],int cant)
{
    int i;
    int opcion;
    int r = -1;
    mostrarListadoDeEquipos(list, cant);
    i = buscarEquipoPorCodigo(list, cant);
    if(i != -1)
    {
        mostrarUnEquipo(list[i]);
        printf("\n\n¿Que desea modificar?\n\n");
        printf("1. Nombre.\n");
        printf("2. Localidad\n");
        printf("Elija una opcion : ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("\nIngrese el nuevo nombre : ");
            enterString(list[i].nombre);
            r = 0;
            break;
        case 2:
            printf("Ingrese la nueva localidad : ");
            enterString(list[i].localidad);
            r = 0;
            break;
        default:
            r = 1;
        }
    }
    return r;
}

int buscarEquipoPorCodigo(sEquipos list[],int cant)
{
    int i;
    int index = -1;
    int codigo;
    codigo = enterInt("\nIngrese el codigo del equipo : ");
    for(i=0; i<cant; i++)
    {
        if(list[i].codigo == codigo)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarJugadorPorCodigo(sJugadores list[], int cant)
{
    int i;
    int index = -1;
    int codigo;
    codigo = enterInt("\nIngrese el codigo del jugador : ");
    for(i=0; i<cant; i++)
    {
        if(list[i].codigo == codigo)
        {
            index = i;
            break;
        }
    }
    return index;
}

int bajarEquipo(sEquipos list[], int cant)
{
    int r = -1;
    int i;
    char respuesta;
    mostrarListadoDeEquipos(list, cant);
    i = buscarEquipoPorCodigo(list, cant);
    if(i != -1)
    {
        mostrarUnEquipo(list[i]);
        printf("\nIngrese s para confirmar la accion : ");
        fflush(stdin);
        respuesta = getchar();
        if(respuesta == 's')
        {
            list[i].estado=LIBRE;
            r = 0;
        }
        else
        {
            r = 1;
        }
    }
    return r;
}

int bajarJugador(sJugadores list[], int cant)
{
    int r = -1;
    int i;
    char respuesta;
    mostrarListadoDeJugadores(list, cant);
    i = buscarJugadorPorCodigo(list, cant);
    if(i != -1)
    {
        mostrarUnJugador(list[i]);
        printf("\nIngrese s para confirmar la accion : ");
        fflush(stdin);
        respuesta = getchar();
        if(respuesta == 's')
        {
            list[i].estado=LIBRE;
            r = 0;
        }
        else
        {
            r = 1;
        }
    }
    return r;
}

int mostrarJugadoresPorEquipo(sJugadores listJ[], sEquipos listE[], int cantJ,int cantE)
{
    int i;
    int r = -1;
    int j;
    mostrarListadoDeEquipos(listE, cantE);
    j = buscarEquipoPorCodigo(listE, cantE);
    if(j!=-1)
    {
        for(i=0; i<cantJ; i++)
        {
            if(listJ[i].codigoDeEquipo == listE[j].codigo)
            {
                mostrarUnJugador(listJ[i]);
            }
        }
        r = 0;
    }
    return r;
}

/*int mostrarReferiConMasPartidos(sReferi listR[],sPartidos listP[],int cantR, int cantP)
{
    int i;

    for(i=0;i<cantP;i++)
    {
        for(j=0;j<cantR;j++)
        {
            if(listR[j].codigo == )
        }

    }
}*/


int mostrarJugadoresPorNombre(sJugadores list[],int cant)
{
    int i;
    char nombre[51];
    int r = -1;
    int r1;
    printf("Ingrese nombre del jugador : ");
    enterString(nombre);
    r1 = onlyLetters(nombre);
    while(r1==-2)
    {
        printf("\nSolo se aceptan letras, reingrese nombre: ");
        enterString(nombre);
        r1 = onlyLetters(nombre);
    }
    for(i=0; i<cant; i++)
    {
        if(stricmp(list[i].nombre, nombre)==0)
        {
            mostrarUnJugador(list[i]);
            r = 0;
        }
    }
    return r;
}

/*void mostrarEquipoMasLargo(sEquipos list[], int cant)
{
    int largo;
    int maximo;
    int j;
    int flag = 0;
    int i;

    for(i=0; i<cant-1; i++)
    {

        if(flag == 0 || largo[i] > largo)
        {
            flag = 1;
        }
    }
}*/

int mostrarPartidosPorFecha(sPartidos list[], int cant)
{
    int dia;
    int mes;
    int anio;
    int i;
    int r=-1;
    printf("Ingresar fecha del partido\n");
    dia = enterInt("Dia : ");
    mes = enterInt("Mes : ");
    anio = enterInt("Anio : ");

    for(i=0; i<cant; i++)
    {
        if(list[i].fechaDePartido.dia == dia && list[i].fechaDePartido.mes == mes && list[i].fechaDePartido.anio == anio)
        {
            mostrarUnPartido(list[i]);
            r = 0;
        }
    }
    return r;
}

void promedioEdadesPorEquipo(sJugadores listJ[],sEquipos listE[],int cantJ, int cantE)
{
    int i;
    int j;
    int contador = 0;
    int acumulador = 0;
    int maximoCodigo = 0;
    float promedio = 0;
    float maximoPromedio = 0;
    int flag = 0;
    for(i=0; i<cantE; i++)
    {
        acumulador = 0;
        contador = 0;
        promedio = 0;
        for(j=0; j<cantJ; j++)
        {
            if(listE[i].codigo == listJ[j].codigoDeEquipo)
            {
                acumulador = acumulador + listJ[j].fechaNacimiento.anio;
                contador ++;
            }
        }
        promedio = acumulador / contador;
        if(flag == 0 || promedio > maximoPromedio)
        {
            maximoCodigo = i;
            maximoPromedio = promedio;
            flag = 1;
        }
    }
    printf("El equipo mas joven es %20s\n",listE[maximoCodigo].nombre);

}

int mostrarReferiConMasPartidos(sReferi listR[],sPartidos listP[],int cantR, int cantP)
{
    int i;
    int j;
    int contador;
    int flag = 0;
    int maxPartidos = 0;
    int maxIndex;

    for(i=0;i<cantR;i++)
    {
        contador = 0;
        if(listR[i].estado == OCUPADO)
        {
            for(j=0;j<cantP;j++)
            {
                if(listP[j].estado == OCUPADO && listP[j].codigoDeReferi == listR[i].codigo)
                {
                    contador ++;
                }
            }
        }
        if(flag == 0 || contador > maxPartidos)
        {
            maxIndex = i;
            maxPartidos = contador;
            flag = 1;
        }
    }
    printf("El referi con mas partidos dirigidos es %s %s \n\n",listR[maxIndex].nombre,listR[maxIndex].apellido);
}

int flagReferees(sReferi list[], int cant)
{
    int r = -1;
    int i;

    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            r = 0;
            break;
        }
    }

    return r;
}
