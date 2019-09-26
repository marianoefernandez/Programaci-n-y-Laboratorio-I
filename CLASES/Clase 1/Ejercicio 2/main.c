#include <stdio.h>
#include <stdlib.h>

//Pedir el precio y el porcentaje de descuento, mostrar el precio final con descuento.

int main()
{
    //Variables
    int precio;
    int descuento;

    //Pido Precio
    printf("\nIngrese precio($): ");
    scanf("%d", &precio);

    //Pido % de descuento
    printf("\nIngrese decuento (porciento): ");
    scanf("%d", &descuento);

    //Realizo operaciones.

    precio = precio - precio/100 * descuento;

    //Muestro

    printf("El precio final con el descuento del %d porciento es de %d $",descuento,precio);
    //C no puede mostrar el simbolo %.



    return 0;
}
