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

char continuar (char mensaje[])
{
    int x;
    printf("¿Desea continuar? s/n %s: ",mensaje);
    getchar(x);
    //validarchar
    return x;
}

char getLetras (char mensaje[])
{
    int x;
    printf("%s",mensaje);
    gets (x);
    //VALIDAMOS
    return x;
}

//CALCULOS

//ORDENAMIENTO

void burbujeo(int miArray[],int cantidad)
{
    //DESARROLLO
}

void burbujeoEficiente(int miArray[],int cantidad)
{
    //DESARROLLO
}

void insersion(int miArray[],int cantidad)
{
    //DESARROLLO
}


