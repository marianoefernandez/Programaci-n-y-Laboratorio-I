#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dinero;
		char tipo;
		int contador;
		int maximoImporteENDolares;
		int esElPrimerDolar;
		int acumuladorDePositivos;
		int contadorDePositivos;
		float promedioDePositivos;

		contador=0;
		esElPrimerDolar=0;
		acumuladorDePositivos=0;
		contadorDePositivos=0;

			while(contador<4){
				contador++;
				printf("Ingrese Dinero:");
				scanf("%d",&dinero);
				printf("Ingrese tipo:");
				fflush(stdin);
				scanf("%c",&tipo);

					if(tipo =='d'){
						if(esElPrimerDolar ==1){
							maximoImporteENDolares=dinero;
							esElPrimerDolar=0;
						}else{
							if(dinero>maximoImporteENDolares){
							maximoImporteENDolares=dinero;
							}
						}
					}
					if(dinero>0){

                        acumuladorDePositivos = acumuladorDePositivos + dinero;
                        contadorDePositivos++;
					}
					promedioDePositivos =(float)acumuladorDePositivos/(float)contadorDePositivos;
					//promedioDePositivos =(float)(acumuladorDePositivos/contadorDePositivos);MAL
			}

		printf("Importe mayor en dolares es: %d",maximoImporteENDolares);
		printf("Promedio de positivos es: %f",promedioDePositivos);
		return 0;
}
