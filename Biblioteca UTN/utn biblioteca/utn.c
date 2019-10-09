//CLASE TRES
//SUMA Y PEDIDA DE DATOS
float sumar (int n1,int n2)
{
    float suma = (float)n1+n2; //Se recibe el valor y lo muestra
    return suma; //Lo retorna
}

float restar (int n1,int n2)
{
    float resta = (float)n1-n2; //Se recibe el valor y lo muestra
    return resta; //Lo retorna
}

float multiplicar (int n1,int n2)
{
    float multiplica = (float)n1*n2; //Se recibe el valor y lo muestra
    return multiplica; //Lo retorna
}

float dividir (int n1,int n2)
{
    float division = (float)n1/n2; //Se recibe el valor y lo muestra
    return division; //Lo retorna
}

void mostrar(float r)
{
    printf("\n\nEl resultado es: %.f",r);
}

int pedirDato();
{
    scanf("%d",&dato);
    return (dato);
}

//CLASE CUATRO
//FUNCIONES PARA PEDIR DATOS
float getFloat (char mensaje[])
{
    int x;
    printf("Ingrese %s: ",nombre);
    scanf("%f",&x);
    return x;
}

int getInt (char mensaje[])
{
    int x;
    printf("Ingrese %s: ",mensaje);
    scanf("%d",&x);
    return x;
}

char getChar (char mensaje[])
{
    int x;
    printf("Ingrese %s: ",mensaje);
    gets(x);
    return x;
}

//CLASE CINCO
//BURBUJEO Y PROMEDIO

void mostrarArray(int miArray[],int cantidad)
{
    int i;
    for (i=0;i<cantidad;i++)
    {
        printf("%d\n",miArray[i]);
    }
}

int dameMax(int miArray[],int cantidad)
{
    int i;
    int max;
    for (i=0;i<cantidad;i++)
    {
        if (miArray[i]>max||i==0)
        {
            max = miArray[i];
        }
    }
    return max;
}

int dameMin(int miArray[],int cantidad)
{
    int i;
    int min;
    for (i=0;i<cantidad;i++)
    {
        if (miArray[i]<min||i==0)
        {
            min = miArray[i];
        }
    }
    return min;
}

void inicializarArray(int miArray[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        miArray[i]=0;
    }
}

void cargaSecuencialArray(int miArray[],int cantidad,char mensaje[])
{
    int i;
    for (i=0;i<cantidad;i++)
    {
        printf("Ingrese %s: ",mensaje);
        scanf("%d",&miArray[i]);
    }
}

float darmePromedio (int miArray[],int cantidad)
{
    int i;
    float acumulador=0;

    for (i=0;i<cantidad;i++)
    {
        acumulador = acumulador + miArray[i];
    }

    return acumulador/cantidad;
}

void ordenarBurbujeo (int miArray[],int cantidad)
{
    int i;
    int j;
    int aux;

    for (i=0;i<cantidad-1;i++)
    {
        for (j=i+1;j<cantidad;j++)
        {
            if (miArray [i]>miArray[j])
            {
            aux = miArray[i];
            miArray[i] = miArray[j];
            miArray[j] = aux;
            }
        }
    }
}

void burbujeoMejorado (int* miArray,int cantidad)
{
    int j;
    int aux;
    int flag = 1;
    while (flag==1)
    {
        flag = 0;
        for (j = 1; j < cantidad; j++)
        {
            if (miArray[j] < miArray[j - 1])
            {
                aux = miArray[j];
                miArray[j] = miArray[j - 1];
                miArray[j - 1] = aux;
                flag = 1;
            }
        }
    }
}


void insersion (int miArray[],int cantidad)
{
    int i
    int j;
    int temp;
    for(i=1; i<cantidad; i++)
    {
        temp = miArray[i];
        j=i-1;
        while(j>=0 && temp<miArray[j]) // temp<miArray[j] o temp>miArray[j]
        {
            miArray[j+1] = miArray[j];
            j--;
        }
        miArray[j+1]=temp; // inserción
    }
}

//CLASE SEIS
//OPERACIONES SOBRE ARRAYS

void cargarVector(int miVector[], int tam)
{
    int i;
      printf("\tCARGA DE DATOS\n");
    for(i=0; i<tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &miVector[i]);
    }
}

void mostrarVector(int miVector[], int tam)
{
    int i;
    printf("\tMUESTRO EL VECTOR\n");
    for(i=0; i<tam; i++)
    {
        printf("%d\n", miVector[i]);
    }
}

void mostrarNegativos(int miVector[],int tam)
{
    int i;
    printf("\n\n\tMUESTRO SOLO LOS NEGATIVOS\n");
    for(i=0; i<tam; i++)
    {
        if(miVector[i]<0)
        {
           printf("%d\n", miVector[i]);
        }

    }
}

void mostrarPromedio(int miVector[],int tam)
{
    int i;
    int contadorDePositivos = 0;
    int sumaDePositivos;
    float promedioPositivos;

   sumaDePositivos = sumarPositivos(miVector, tam);
   contadorDePositivos = contarPositivos(miVector,tam);

   promedioPositivos =calcularPromedio(sumaDePositivos,contadorDePositivos);

   //printf("Suma: %d -- Cantidad %d\n\n", sumaDePositivos, contadorDePositivos);


     printf("\n\n\PROMEDIO DE POSITIVOS: %f\n\n", promedioPositivos);

}

int sumarPositivos(int miVector[],int tam)
{
    int suma = 0;
    int i;
    for(i=0; i<tam; i++)
    {
        if(miVector[i]>0)
        {
            suma += miVector[i];
        }
    }

    return suma;
}

int contarPositivos(int miVector[],int tam)
{
    int contador = 0;
    int i;
    for(i=0; i<tam; i++)
    {
        if(miVector[i]>0)
        {
            contador++;
        }
    }

    return contador;
}
float calcularPromedio(int suma,int contador)
{
    float retorno;
    retorno = (float)suma/contador;
    return retorno;
}

//CLASE SIETE
//MÁS OPRACIONES CON ARRAYS

void cargarVector(int miVector[], int tam)
{
    int i;
      printf("\tCARGA DE DATOS\n");
    for(i=0; i<tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &miVector[i]);
    }
}

void mostrarVector(int miVector[], int tam)
{
    int i;
    printf("\tMUESTRO EL VECTOR\n");
    for(i=0; i<tam; i++)
    {
        printf("%d\n", miVector[i]);
    }
}

void mostrarNegativos(int miVector[],int tam)
{
    int i;
    printf("\n\n\tMUESTRO SOLO LOS NEGATIVOS\n");
    for(i=0; i<tam; i++)
    {
        if(miVector[i]<0)
        {
           printf("%d\n", miVector[i]);
        }

    }
}

void mostrarPromedio(int miVector[],int tam)
{
    int i;
    int contadorDePositivos = 0;
    int sumaDePositivos;
    float promedioPositivos;

   sumaDePositivos = sumarPositivos(miVector, tam);
   contadorDePositivos = contarPositivos(miVector,tam);

   promedioPositivos =calcularPromedio(sumaDePositivos,contadorDePositivos);

   //printf("Suma: %d -- Cantidad %d\n\n", sumaDePositivos, contadorDePositivos);


     printf("\n\n\PROMEDIO DE POSITIVOS: %f\n\n", promedioPositivos);

}

int sumarPositivos(int miVector[],int tam)
{
    int suma = 0;
    int i;
    for(i=0; i<tam; i++)
    {
        if(miVector[i]>0)
        {
            suma += miVector[i];
        }
    }

    return suma;
}

int contarPositivos(int miVector[],int tam)
{
    int contador = 0;
    int i;
    for(i=0; i<tam; i++)
    {
        if(miVector[i]>0)
        {
            contador++;
        }
    }

    return contador;
}
float calcularPromedio(int suma,int contador)
{
    float retorno;
    retorno = (float)suma/contador;
    return retorno;
}

//CLASE OCHO ESTRUCTURAS

void mostrarAlumno (eAlumno miAlumno)
{
    printf("\n%d--%s--%d",miAlumno.legajo,miAlumno.nombre,miAlumno.nota);
}

eAlumno pedirAlumno()
{
    eAlumno miAlumno;
    printf("\nIngrese legajo: ");
    scanf("%d",&miAlumno.legajo);
    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(miAlumno.nombre);
    printf("\nIngrese nota: ",&miAlumno.nota);
    scanf("%d",&miAlumno.nota);

    return miAlumno;
}

int compararAlumnoPorLegajo(eAlumno unAlumno, eAlumno otroAlumno)
{
    int comp = 0;
    if (unAlumno.legajo==otroAlumno.legajo)
    {
        comp = 1;
    }
    return 0;
}

void cargarAlumnos(eAlumno lista[],int cantidad)
{
    int i;
    for (i=0;i<cantidad;i++)
    {
        lista[i] = pedirAlumno();
    }
}

void mostrarListadoAlumnos (eAlumno lista[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        mostrarAlumno(lista[i]);
    }
}

void ordenarAlumnosPorNombres(eAlumno lista [],int cantidad)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for (i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if (strcmp (lista[i].nombre,lista[j].nombre)<0) //Comparo cadenas ordenar por nombre
            {
                auxAlumno = lista[i];
                lista[i] = lista[j];
                lista[j] = auxAlumno;
            }
        }
    }
}

void hardcodearAlumnos(eAlumno lista[],int cantidad)
{
    int legajo [3] = {101,102,105};
    int nota[3] = {10,5,9};
    char nombre [3][50] = {"Juan","Maria","Jose"};
    int i;

    for (i=0;i<cantidad;i++)
    {
        lista[i].legajo=legajo[i];
        lista[i].nota=nota[i];
        strcpy(lista[i].nombre,nombre[i]);
    }
}





