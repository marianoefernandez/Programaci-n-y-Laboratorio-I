#include "Estacionamiento.h"

void hardcodearVehiculo (eVehiculo vehiculo[], int lenA)
{
    int i;
    int id[]={1,6,6,7,5,4,4,3,3,4};
    char patente[][15]={"AAA111", "BBB222", "AAA222","WWW777","AKK222","EEE111","UUU777","YYY778","ABC123","QQQ128"};
    int horaEntrada[]={10,9,8,11,10,11,9,7,7,14};
    int horaSalida[]={11,11,11,12,14,15,12,10,11,17};
    int dia[]={26,26,26,26,26,26,26,26,26,26};
    int mes[]={9,9,9,9,9,9,9,9,9,9};
    int anio[]={2019,2019,2019,2019,2019,2019,2019,2019,2019,2019};

    for(i=0;i<lenA;i++)
    {
        vehiculo[i].idPropietario=id[i];
        vehiculo[i].fechaIngreso.dia=dia[i];
        vehiculo[i].fechaIngreso.mes=mes[i];
        vehiculo[i].fechaIngreso.anio=anio[i];
        vehiculo[i].horaIngreso=horaEntrada[i];
        vehiculo[i].horaSalida=horaSalida[i];
        strcpy(vehiculo[i].patente,patente[i]);
    }
    return;
}


void mostrarPersonas (ePropietario persona[], int lenP)
{
    int i;
    system("cls");
    printf("Datos del titular:\n\nID\t\tNombre\t\tFecha de Nacimiento.\n\n");
    for(i=0;i<lenP;i++)
    {
        if(persona[i].estaVacio==0)
        {
            mostrarPersonaPorIndice(persona,i);
        }
    }
    system("pause");
    return;
}

void mostrarPersonaPorIndice (ePropietario persona[], int i)
{
    printf("%04d\t",persona[i].idPropietario);
    printf("%14s\t\t",persona[i].nombre);
    printf("%02d/",persona[i].fechaNac.dia);
    printf("%02d/",persona[i].fechaNac.mes);
    printf("%4d\n\n",persona[i].fechaNac.anio);
    return;
}

///Funciona pero no se utiliza.-
//void mostrarPersonaPorID (ePropietario persona[], int lenP,int id)
//{
//    int i;
//    i=buscarIndicePropietario(persona,lenP,id);
//    mostrarPersonaPorIndice(persona,i);
//    return;
//}

void mostrarPersonasYSusVehiculos (ePropietario persona[], eVehiculo vehiculo[],int lenP,int lenA)
{
    int i;
    int j;
    for(i=0;i<lenP;i++)
    {
        printTabP();
        mostrarPersonaPorIndice(persona,i);
        printTabA();
        for(j=0;j<lenA;j++)
        {
            if(persona[i].idPropietario==vehiculo[j].idPropietario)
            {
                mostrarVehiculoPorIndice(vehiculo,j);
            }
        }
        printSeparation();
    }
    system("pause");
    return;
}

void mostrarVehiculoPorIndice (eVehiculo vehiculo[], int i)
{
    printf("%04d\t",vehiculo[i].idPropietario);
    printf("%8s\t",vehiculo[i].patente);
    printf("%02d/",vehiculo[i].fechaIngreso.dia);
    printf("%02d/",vehiculo[i].fechaIngreso.mes);
    printf("%4d\t\t",vehiculo[i].fechaIngreso.anio);
    printf("%02d:00\t\t",vehiculo[i].horaIngreso);
    printf("%02d:00\t\n\n",vehiculo[i].horaSalida);
    return;
}

void mostrarVehiculoPorID(ePropietario persona[], eVehiculo vehiculo[],int lenP,int lenA,int id)
{
    int i;
    int j;
    i=buscarIndicePropietario(persona,lenP,id);
    printTabP();
    mostrarPersonaPorIndice(persona,i);
    printTabA();
    for(j=0;j<lenA;j++)
    {
        if(vehiculo[j].idPropietario==id)
        {
            mostrarVehiculoPorIndice(vehiculo,j);
        }
    }
    system("pause");
    return;
}

int buscarIndicePropietario(ePropietario persona[],int lenP,int id)
{
    int i;
    for(i=0;i<lenP;i++)
    {
        if (id==persona[i].idPropietario)
        {
            return i;
        }
    }
    return -1;
}

///Funciona pero no se utiliza.-
//void mostrarVehiculoPorPatente(ePropietario persona[], eVehiculo vehiculo[],int lenP,int lenA)
//{
//    int i;
//    char patente[8];
//
//    printf("Ingrese la patente del vehiculo a mostrar:\n\n");
//    scanf("%s",patente);
//    system("cls");
//
//    for(i=0;i<lenA;i++)
//    {
//        if(stricmp(patente,vehiculo[i].patente)==0)
//        {
//            printf("Datos del vehiculo:\n\nID \tPat.\tDia\tMes\tAnio\tHora ing.\tHora egr.\n");
//            mostrarVehiculoPorIndice(vehiculo,i);
//
//            i=buscarIndicePropietario(persona,lenP,vehiculo[i].idPropietario);
//            printf("Datos del titular:\n\nID\t\tNombre\t\tFecha de Nacimiento.\n\n");
//            mostrarPersonaPorIndice(persona,i);
//            break;
//        }
//    }
//    system("pause");
//    return;
//}

int calcularTarifaAuto(eVehiculo vehiculo[],int lenA,int index)
{
    int tarifa;
    tarifa=(vehiculo[index].horaSalida-vehiculo[index].horaIngreso)*100;
    return tarifa;
}

void mostrarTodasLasTarifas (eVehiculo vehiculo[], int lenA)
{
    int i;
    int total;
    system("cls");
    for(i=0;i<lenA;i++)
    {
        mostrarVehiculoPorIndice(vehiculo, i);
        total=calcularTarifaAuto(vehiculo,lenA,i);
        printf("Debe pagar $%d\n\n---------------------\n",total);
    }
    system("pause");
    return;
}

void printSeparation()
{
    printf("\n------------------\n\n");
}
void printTabP()
{
    printf("Datos del titular:\n\nID\t\tNombre\t\tFecha de Nacimiento.\n\n");
}
void printTabA()
{
    printf("\n\nDatos del/los vehiculos:\n\nID\t  Patente\tFecha de Ingreso\tHora ing.\tHora Egr.\n\n");
}


///----------------------------------------------------------------REPARAR



void mostrarTarifaPorDuenio (ePropietario persona[],eVehiculo vehiculo[],int lenA,int lenP)
{
    int i;
    int j;
    int total=0;
    system("cls");
    for(i=0;i<lenP;i++)
    {
        if(persona[i].estaVacio==0)
        {
            printTabP();
            mostrarPersonaPorIndice(persona,i);
            printTabA();
            for(j=0;j<lenA;j++)
        {
            if((persona[i].idPropietario==vehiculo[j].idPropietario)&&(vehiculo[i].isEmpty==0))
            {
                total+=calcularTarifaAuto(vehiculo,lenA,j);
                mostrarVehiculoPorIndice(vehiculo,j);
            }
        }
        printf("\n%s debe en total %d por todos sus vehiculos.\n",persona[i].nombre,total);
        printSeparation();
        total=0;
        }
    }
    system("pause");
    return;
}

///----------------------------------------------------------------REPARAR

void mostrarVehiculosYDuenios (ePropietario persona[],eVehiculo vehiculo[],int lenp,int lena)
{
    int i;
    int j;
    system("cls");

    for(i=0;i<lena;i++)
    {
        printTabA();
        mostrarVehiculoPorIndice(vehiculo,i);
        for(j=0;j<lenp;j++)
        {
            if (vehiculo[i].idPropietario==persona[j].idPropietario)
            {
                printTabP();
                mostrarPersonaPorIndice(persona,j);
                break;
            }
        }
        printSeparation();
    }
    system("pause");
    return;
}

void mostrarPersonaConMasAutos(ePropietario persona[],eVehiculo vehiculo[],int lenP, int lenA)
{
    int i;
    int j;
    int t;
    int maxA=0;
    int cont;
    int hora;
    int flagMaxEncontrado=0;
    system("cls");
    printf("Ingrese la hora:\n");
    scanf("%d",&hora);
    printf("\nPropietario/s con mas autos estacionados:\n\n");
    for(t=0;t<2;t++)
    {

        for(i=0;i<lenP;i++)
        {
            cont=0;
            for(j=0;j<lenA;j++)
            {
                if((persona[i].idPropietario==vehiculo[j].idPropietario)&&(hora>=vehiculo[j].horaIngreso&&hora<vehiculo[j].horaSalida))
                {
                    cont++;
                }
            }
            if(cont>maxA&&flagMaxEncontrado==0)
            {
                maxA=cont;
            }
            if(cont==maxA&&flagMaxEncontrado==1)
            {
                printf("%s con %d auto/s\n",persona[i].nombre,maxA);
            }
        }
        flagMaxEncontrado=1;
    }
    system("pause");
    return;
}


int cargarPropietario(ePropietario* persona,int len,int id)
{
    int i;
    int ret=-1;
    int dia;
    int mes;
    int anio;
    char name[51];
    getAlphabeticalString("Ingrese el nombre del propietario:\n",name,50);
    dia=getPositiveInt("Ingrese dia de nacimiento:\n");
    mes=getPositiveInt("Ingrese mes de nacimiento:\n");
    anio=getPositiveInt("Ingrese anio de nacimiento:\n");
    if(persona!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(persona[i].estaVacio==1)
            {
                persona[i].idPropietario = id;
                strcpy(persona[i].nombre,name);
                persona[i].estaVacio=0;
                persona[i].fechaNac.dia=dia;
                persona[i].fechaNac.mes=mes;
                persona[i].fechaNac.anio=anio;
                return 0;
            }
        }
    }
    return ret;
}


int getPositiveInt(char message[])
{
    int i=0;
    char string[10]; ///Almacena hasta el 2147483647.
    int ret;
    do
    {
        printf(message);
        scanf("%s",string);
        fflush(stdin);
        ret=0;
        for(i=0;string[i]!='\0';i++)
        {
            if(string[i]<48||string[i]>57)
            {
                showMessage("Ingrese un valor numerico valido. (Solo numeros enteros positivos).\n\n");
                ret=-1;
                break;
            }
        }
    }while(ret==-1);
    ret=atoi(string);
    return ret;
}


int getAlphabeticalString (char message[],char string[],int maxLen)
{
    int i;
    int len;
    int ret;
    do
    {
        printf(message);
        gets(string);
        fflush(stdin);
        len=strlen(string);
        ret=1;
        if(len>maxLen)
        {
            system("cls");
            printf("Se supero el maximo de caracteres permitidos para este campo (%d).\n",maxLen);
            system("pause");
            system("cls");
            ret=0;
        }
        else
        {
            for(i=0; i<len; i++)
            {
                if (!((string[i]==32)||(string[i]==39)||(string[i]>64&&string[i]<91)||(string[i]>96&&string[i]<123)))
                {
                    showMessage("Ingreso caracteres no validos, verifique e intente nuevamente.\n\n");
                    ret=0;
                    break;
                }
            }
        }

    }while(len==0||ret==0);


    return ret;
}


void showMessage(char message[])
{
    system("cls");
    printf(message);
    system("pause");
    system("cls");
}


int initPropietarios(ePropietario* persona, int len)                                                                                             ///2.1 Función initEmployees:
{
    int i;
    int ret;
    if(persona!=NULL && len>0)
    {
        for (i=0; i<len; i++)
        {
            persona[i].estaVacio=1;
        }
        ret=0;
    }
    else
    {
        ret=-1;
    }
    return ret;
}



int removeElement(ePropietario* list, int len, int id)                                                                                     ///2.4 Función removeEmployee:
{
    int i;
    int ret=-1;
    i=findElementById(list, len, id);
    if (i!=-1)
    {
        printf("Esta a punto de dar de baja al siguiente propietario:\n\n");
        printTab();
        mostrarPersonaPorIndice(list, i);
        printf("\ns/n\n");

        if(getConfirm()==1)
        {
            list[i].estaVacio = 1;
            showMessage("El propietario se dio de baja con exito.\n");
            ret=0;
        }
        else
        {
            showMessage("Se cancelo la baja del usuario.\n");
            ret=0;
        }
    }
    return ret;
}


int findElementById(ePropietario* list, int len,int id)                                                                                    ///2.3 Función findEmployeeById
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(list[i].idPropietario==id && list[i].estaVacio==0)
        {
            ret=i;
            break;
        }
    }
    return ret;
}


void printTab ()
{
    printf("ID\tSECTOR\t\t\t\tAPELLIDO\t\t\tNOMBRE\t\tSALARIO\n\n");
    return;
}


int getConfirm()
{
    int ret=-1;
    do
    {
        ret=getche();
        fflush(stdin);
        if((ret==83)||(ret==115))
        {
            ret=1;
        }
        else if((ret==78)||(ret==110))
        {
            ret=0;
        }
        else
        {
            printf("\n\nIngrese s para confirmar, n para cancelar.\n");
        }
    }
    while(ret!=0&&ret!=1);

    return ret;
}



int showMenuGetOption(char message[], int min, int max)
{
    int option;
    do
    {
        printf(message);
        scanf("%d", &option);
        fflush(stdin);
        system("cls");
        if(option<min||option>max)
        {
            system("cls");
            printf("Indique una opcion valida entre %d y %d.\n\n",min,max);
        }
    }
    while(option <min||option>max);
    return option;
}

int modName (ePropietario* persona, int i)
{
    char name[51];
    getAlphabeticalString("Ingrese el nuevo nombre:\n",name,50);
    strcpy(persona[i].nombre,name);
    return 0;
}

int modDay (ePropietario* persona, int i)
{
    int auxInt;
    auxInt=getPositiveInt("Ingrese nuevo dia de nacimiento:\n");
    persona[i].fechaNac.dia=auxInt;
    return 0;
}

int modMonth (ePropietario* persona, int i)
{
    int auxInt;
    auxInt=getPositiveInt("Ingrese nuevo mes de nacimiento:\n");
    persona[i].fechaNac.mes=auxInt;
    return 0;

}

int modYear (ePropietario* persona, int i)
{
    int auxInt;
    auxInt=getPositiveInt("Ingrese nuevo anio de nacimiento:\n");
    persona[i].fechaNac.anio=auxInt;
    return 0;
}


int initVehiculos(eVehiculo* vehiculo, int len)                                                                                             ///2.1 Función initEmployees:
{
    int i;
    int ret;
    if(vehiculo!=NULL && len>0)
    {
        for (i=0; i<len; i++)
        {
            vehiculo[i].estaEstacionado=0;
            vehiculo[i].isEmpty=1;
            vehiculo[i].horaSalida=-1;
        }
        ret=0;
    }
    else
    {
        ret=-1;
    }
    return ret;
}


void cargarVehiculo(eVehiculo* vehiculo,int len)
{
    int i;
    int dia;
    int mes;
    int anio;
    int hora;
    int id;
    char patente[8];
    getAlphanumericalString("Ingrese la patente del vehículo:\n",patente,7);
    dia=getPositiveInt("Ingrese dia de nacimiento:\n");
    mes=getPositiveInt("Ingrese mes de nacimiento:\n");
    anio=getPositiveInt("Ingrese anio de nacimiento:\n");
    hora=getPositiveInt("Indique la hora de Ingreso del vehiculo:\n");
    id=getPositiveInt("Indique el ID del propietario del vehículo:\n");
    if(vehiculo!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(vehiculo[i].estaEstacionado==0&&vehiculo[i].isEmpty==1)
            {
                vehiculo[i].idPropietario = id;
                strcpy(vehiculo[i].patente,patente);
                vehiculo[i].estaEstacionado=1;
                vehiculo[i].fechaIngreso.dia=dia;
                vehiculo[i].fechaIngreso.mes=mes;
                vehiculo[i].fechaIngreso.anio=anio;
                vehiculo[i].horaIngreso=hora;
                vehiculo[i].isEmpty=0;
                break;
            }
        }
    }
    return;
}


int getAlphanumericalString (char message[],char string[],int maxLen)
{
    int i;
    int len;
    int ret;
    do
    {
        printf(message);
        gets(string);
        fflush(stdin);
        len=strlen(string);
        ret=1;
        if(len>maxLen)
        {
            system("cls");
            printf("Se supero el maximo de caracteres permitidos para este campo (%d).\n",maxLen);
            system("pause");
            system("cls");
            ret=0;
        }
        else
        {
            for(i=0; i<len; i++)
            {
                if (!((string[i]==32)||(string[i]==39)||(string[i]>64&&string[i]<91)||(string[i]>96&&string[i]<123)||(string[i]>47&&string[i]<58)))
                {
                    showMessage("Ingreso caracteres no validos, verifique e intente nuevamente.\n\n");
                    ret=0;
                    break;
                }
            }
        }

    }while(len==0||ret==0);


    return ret;
}

void egresarVehiculo(eVehiculo* vehiculo,int len)
{
    char patente[8];
    int hora;
    getAlphanumericalString("Ingrese la patente del vehiculo que se retira:\n",patente,7);
    hora=getPositiveInt("\nIngrese la hora de salida del vehículo:\n");
    int i;

    for(i=0;i<len;i++)
    {
        if(stricmp(patente,vehiculo[i].patente))
        {
            vehiculo[i].estaEstacionado=0;
            vehiculo[i].isEmpty=1;
            vehiculo[i].horaSalida=hora;
        }
    }
    return;
}

int sortElementsByStringAndInt(ePropietario* list, int len, int order)                                                            ///2.5 Función sortEmployees:
{
    int i;
    int j;
    int ret=-1;
    ePropietario aux[1];

    if(list!=NULL||len<0||order<0||order>1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=1; j<len; j++)
            {
                switch(order)
                {
                case 0:
                    if (stricmp(list[i].nombre,list[j].nombre)>0)
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    if((stricmp(list[i].nombre,list[j].nombre)==0) && (list[i].fechaNac.anio>list[j].fechaNac.anio))
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    break;
                case 1:
                    if (stricmp(list[i].nombre,list[j].nombre)<0)
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    if((stricmp(list[i].nombre,list[j].nombre)==0) && (list[i].fechaNac.anio<list[j].fechaNac.anio))
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    break;
                }
            }
        }
        ret=0;
    }
    return ret;
}


void hardcodePropietarios (ePropietario* list)
{
    int id[10]= {1,2,3,4,5,6,7,8,9,10};
//    char name[10][51]= {"Homero","Bob","Moe","Apu","Rafa","Juan","Hank","Barney","Lenny","Carl"};
    char name[10][51]= {"Homero","Homero","Homero","Homero","Homero","Homero","Homero","Homero","Homero","Homero"};
    int dia[10]= {7,21,4,30,1,17,1,19,7,11};
    int mes[10]= {7,4,4,3,1,3,1,1,7,7};
    int anio[10]= {1991,1992,2001,2000,1964,1955,1958,1976,1984,1990};
    int i;

    for(i=0; i<10; i++)
    {
        list[i].idPropietario=id[i];
        strcpy(list[i].nombre,name[i]);
        list[i].fechaNac.dia=dia[i];
        list[i].fechaNac.mes=mes[i];
        list[i].fechaNac.anio=anio[i];
        list[i].estaVacio=0;
    }
    return;
}


int sortElementsBy(ePropietario* list, int len, int order)                                                            ///2.5 Función sortEmployees:
{
    int i;
    int j;
    int ret=-1;
    ePropietario aux[1];

    if(list!=NULL||len<0||order<0||order>1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=1; j<len; j++)
            {
                switch(order)
                {
                case 0:
                    if (stricmp(list[i].nombre,list[j].nombre)>0)
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    if((stricmp(list[i].nombre,list[j].nombre)==0) && (list[i].fechaNac.anio>list[j].fechaNac.anio))
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    break;
                case 1:
                    if (stricmp(list[i].nombre,list[j].nombre)<0)
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    if((stricmp(list[i].nombre,list[j].nombre)==0) && (list[i].fechaNac.anio<list[j].fechaNac.anio))
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    break;
                }
            }
        }
        ret=0;
    }
    return ret;
}
