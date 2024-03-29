/*
 * miBiblioteca.c
 *
 *  Created on: 19 sep. 2022
 *      Author: Luca
 *      Division A
 */
#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"

/////////////////////////////////////////////////////MENU PRINCIPAL/////////////////////////////////////////////////////////////////////////////////
int Menu(float *pHospedaje, float *pComida, float *pTransporte, int *pArqueros, int *pDefensores, int *pMediocampitas, int *pDelanteros)
{
	int opcion;

	if(pHospedaje != NULL && pComida != NULL && pTransporte != NULL && pArqueros != NULL && pDefensores != NULL && pMediocampitas != NULL && pDelanteros != NULL)
	{
		printf( "MENU PRINCIPAL				\n"
				"1. Ingreso de los costos de Mantenimiento.\n"
				"Costo de hospedaje -> $%.2f\n"
				"Costo de comida -> $%.2f\n"
				"Costo de transporte -> $%.2f\n"
				"2. Carga de jugadores:\n"
				"Arqueros -> %d\n"
				"Defensores -> %d\n"
				"Mediocampistas -> %d\n"
				"Delanteros -> %d\n"
				"3. Realizar todos los c�lculos.\n"
				"4. Informar todos los resultados.\n"
				"5. Salir\n\n"
				"�Qu� opci�n elige?:",
				*pHospedaje, *pComida, *pTransporte, *pArqueros, *pDefensores, *pMediocampitas, *pDelanteros);
			scanf("%d", &opcion);
	}
	return opcion;
}

//////////////////////////////////////////////////////SUBMENU//////////////////////////////////////////////////////////////////////////////////////
int SubMenuGastos(float *pHospedaje, float *pComida, float *pTransporte)
{
	int retorno=0;
	int opcion;
	float dinero=0;
	if(pHospedaje != NULL && pComida != NULL && pTransporte != NULL)
	{
		printf("Elegir opcion:\n"
				"1-Costo de hospedaje -> $%.2f\n"
				"2-Costo de comida -> $%.2f\n"
				"3-Costo de transporte -> $%.2f\n"
				"Que opcion elige?: ",
				*pHospedaje, *pComida, *pTransporte);
		scanf("%d", &opcion);

		if(opcion>0 && opcion <4)
		{
			switch(opcion)
				{
					case 1:
						printf("Cuanto es la cantidad a sumar?\n"
								"Cantidad: ");
						scanf("%f", &dinero);
						while(dinero < 0 || dinero >100000)
						{
							printf("Ingrese una cantidad valida(Del 1 al 100.000)\n"
									"Cantidad: ");
							scanf("%f", &dinero);
						}
						*pHospedaje=dinero;
						break;
					case 2:
						printf("Cuanto es la cantidad a sumar?\n"
								"Cantidad: ");
						scanf("%f", &dinero);
						while(dinero < 0 || dinero >100000)
						{
							printf("Ingrese una cantidad valida(Del 1 al 100.000)\n"
									"Cantidad: ");
							scanf("%f", &dinero);
						}
						*pComida=dinero;
						break;
					case 3:
						printf("Cuanto es la cantidad a sumar?\n"
								"Cantidad: ");
						scanf("%f", &dinero);
						while(dinero < 0 || dinero >100000)
						{
							printf("Ingrese una cantidad valida(Del 1 al 100.000)\n"
									"Cantidad: ");
							scanf("%f", &dinero);
						}
						*pTransporte=dinero;
						break;
				}
			retorno=1;
		}
		else
		{
			printf("Opcion no valida\n");
			retorno=0;
		}

	}
	return retorno;
}

int SubMenuJugadores(int *pArqueros, int *pDefensores, int *pMediocampitas, int *pDelanteros, int *pAfc,
		int *pCaf, int *pConcacaf, int *pConmebol, int *pUefa, int *pOfc, int *pContadorJugadores)
{
	int retorno=0;
	int opcion;
	int region;
	int flagRegion;

	if(pArqueros != NULL && pDefensores != NULL && pMediocampitas != NULL && pDelanteros != NULL && pContadorJugadores !=NULL)
	{
		printf(	"\nHay %d jugadores, de 22 disponibles\n"
				"1-Arqueros -> %d\n"
				"2-Defensores -> %d\n"
				"3-Mediocampistas -> %d\n"
				"4-Delanteros -> %d\n"
				"Que opci�n elige?: ",
				*pContadorJugadores,*pArqueros, *pDefensores, *pMediocampitas, *pDelanteros);
		scanf("%d", &opcion);

		while(opcion <1 || opcion >4)
		{
			printf(	"\nIngrese una opcion valida por favor\n"
					"\nHay %d jugadores, de 22 disponibles\n"
					"1-Arqueros -> %d\n"
					"2-Defensores -> %d\n"
					"3-Mediocampistas -> %d\n"
					"4-Delanteros -> %d\n"
					"Que opci�n elige?: ",
					*pContadorJugadores,*pArqueros, *pDefensores, *pMediocampitas, *pDelanteros);
			scanf("%d", &opcion);

		}
	}
	switch(opcion)
	{
	 	 case 1:
	 		 if(*pArqueros < 2)
	 		 {
	 			 *pArqueros=*pArqueros+1;
	 			 flagRegion=1;
	 		 }
	 		 else
	 		 {
	 			 printf("Esta lleno los arqueros...");
	 			flagRegion=0;
	 		 }
	 		 break;

	 	 case 2:
	 		 if(*pDefensores < 8)
			 {
	 			*pDefensores=*pDefensores+1;
	 			 flagRegion=1;
			 }
			 else
			 {
				 printf ("Esta lleno los defensas...");
				 flagRegion=0;
			 }

	 		 break;
	 	 case 3:
	 		 if(*pMediocampitas < 8)
			 {
	 			*pMediocampitas=*pMediocampitas+1;
	 			 flagRegion=1;
			 }
			 else
			 {
				 printf("Esta lleno los mediocampistas...");
				 flagRegion=0;

			 }
	 		 break;
	 	 case 4:
	 		 if(*pDelanteros < 4)
			 {
				 *pDelanteros=*pDelanteros+1;
	 			 flagRegion=1;
			 }
			 else
			 {
				 printf ("Esta lleno los delanteros...");
				 flagRegion=0;
			 }
	 		 break;
	}

	if(flagRegion == 1)
	{
		region=SubMenuJugadoresRegion();

		switch(region)
		{
			case 0:
				break;
			case 1:
				*pAfc=*pAfc+1;
				break;
			case 2:
				*pCaf=*pCaf+1;
				break;
			case 3:
				*pConcacaf=*pConcacaf+1;
				break;
			case 4:
				*pConmebol=*pConmebol+1;
				break;
			case 5:
				*pUefa=*pUefa+1;
				break;
			case 6:
				*pOfc=*pOfc+1;
				break;
		}
		retorno = 1;
	}

	return retorno;
}

int SubMenuJugadoresRegion()
{
	int camiseta;
	int region;

	printf("Ingrese numero de camiseta: ");
	scanf("%d", &camiseta);

	while(camiseta < 1 || camiseta >99 )
	{
		printf("Reingrese numero de camiseta(del 1 al 99): ");
		scanf("%d", &camiseta);
	}


	printf("Ingrese region: \n"
			"1-AFC\n"
			"2-CAF\n"
			"3-CONCACAF\n"
			"4-CONMEBOL\n"
			"5-UEFA\n"
			"6-OFC\n"
			"Que opcion elige: ");
	scanf("%d", &region);

	while(region <1 || region >6)
	{
		printf("Ingrese region valida:\n"
					"1-AFC\n"
					"2-CAF\n"
					"3-CONCACAF\n"
					"4-CONMEBOL\n"
					"5-UEFA\n"
					"6-OFC\n");
		scanf("%d", &region);
	}

	return region;
}

/////////////////////////////////////////////////////PROMEDIOS//////////////////////////////////////////////////////////////////////////////////////
float CalcularPromedios(int region, int contadorJugadores)
{
	float promedio;
	promedio= (float)region/(contadorJugadores);
	return promedio;
}
///////////////////////////////////////////////////CALCULOS////////////////////////////////////////////////////////////////////////////////////////
float CalcularCostoDeMantenimiento(float hospedaje, float comida, float transporte)
{
	float total;
	total=hospedaje+comida+transporte;
	return total;
}
/////////////////////////////////////////////////COMPARADORES////////////////////////////////////////////////////////////////////////////////
int ComparadorRegiones(float uefa,float afc,float caf,float concacaf,float conmebol,float ofc)
{
	int retorno=0;

	if( uefa > afc && uefa > caf && uefa > concacaf && uefa > conmebol && uefa > ofc)
	{
		retorno = 1;
	}

	return retorno;
}




