/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "miBiblioteca.h"
#define TRUE 1
#define FALSE 0

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;

	float hospedaje=0;
	float comida=0;
	float transporte=0;

	int arqueros=0;
	int defensores=0;
	int mediocampistas=0;
	int delanteros=0;

	int afc=0;
	int caf=0;
	int concacaf=0;
	int conmebol=0;
	int uefa=0;
	int ofc=0;

	float promediosAfc=0;
	float promediosCaf=0;
	float promediosConcacaf=0;
	float promediosConmebol=0;
	float promediosUefa=0;
	float promediosOfc=0;
	float porcentajeCostoDeMantenimiento=0;
	float costoDeMantenimiento=0;
	float totalCostoDeMantenimientoAumento;

	int todoOkGastos;
	int todoOkJugadores;
	int contadorJugadores=0;

	int flagCalculos;
	int flagAumentos;


	do
	{
		opcion=Menu(&hospedaje,&comida,&transporte, &arqueros, &defensores, &mediocampistas, &delanteros);

		switch(opcion)
				{
					case 1:
						todoOkGastos=SubMenuGastos(&hospedaje,&comida,&transporte);
						if(todoOkGastos==1)
						{
							printf("\n\nExcelente\n\n");
							flagCalculos=0;

						}
						else
						{
							printf("\n\nRecursa\n\n");
						}
						break;

					case 2:
						if(contadorJugadores < 22)
						{
							todoOkJugadores=SubMenuJugadores(&arqueros,&defensores,&mediocampistas,&delanteros,&afc,
													&caf,&concacaf,&conmebol,&uefa,&ofc, &contadorJugadores);
							if(todoOkJugadores==1)
							{
								printf("\n\nExcelente\n\n");
								contadorJugadores++;
								flagCalculos=0;
							}
							else
							{
								printf("\n\nRecursa\n\n");
							}
						}
						else
						{
							printf("\n\n Ya no hay espacio para mas jugadores, son 22/22\n\n");
						}
						break;
					case 3:
						if(contadorJugadores != 0)
						{
							if(hospedaje !=0 && comida !=0 && transporte !=0)
							{
								promediosAfc=CalcularPromedios(&afc,&contadorJugadores);
								promediosCaf=CalcularPromedios(&caf,&contadorJugadores);
								promediosConcacaf=CalcularPromedios(&concacaf,&contadorJugadores);
								promediosConmebol=CalcularPromedios(&conmebol,&contadorJugadores);
								promediosUefa=CalcularPromedios(&uefa,&contadorJugadores);
								promediosOfc=CalcularPromedios(&ofc,&contadorJugadores);

								costoDeMantenimiento=CalcularCostoDeMantenimiento(&hospedaje,&comida,&transporte);

								if(promediosUefa != 0 && ComparadorRegiones(promediosUefa,promediosAfc,promediosCaf,promediosConcacaf,promediosConmebol,promediosOfc))
								{
									porcentajeCostoDeMantenimiento=costoDeMantenimiento * 0.35;
									totalCostoDeMantenimientoAumento=costoDeMantenimiento + porcentajeCostoDeMantenimiento;
									flagAumentos=1;

								}

								printf("Se realizaron los calculos de forma efectiva");
								flagCalculos=1;
							}
							else
							{
								printf("Primero debe ingresar por lo menos, en cada uno de los campos un precio (hospedaje, comida, transporte) ");
								flagCalculos=0;
							}
						}
						else
						{
							printf("Primero debe ingresar un jugador por lo menos ");
							flagCalculos=0;
						}
						break;
					case 4:
						if(flagCalculos == 1)
						{
							printf("\nInformar todos los resultados"
									"\nPromedio de Uefa: %.2f"
									"\nPromedio de Conmebol: %.2f"
									"\nPromedio de Concacaf: %.2f"
									"\nPromedio de Afc: %.2f"
									"\nPromedio de Ofc: %.2f"
									"\nPromedio de Caf: %.2f"
									"\nEl costo de mantenimiento es: %.2f",
									promediosUefa, promediosConmebol, promediosConcacaf,
									promediosAfc,promediosOfc, promediosCaf,costoDeMantenimiento);
							if(flagAumentos==1)
							{
								printf(" Y recibio un aumento de %.2f, su nuevo valor es de: %.2f\n",
										porcentajeCostoDeMantenimiento, totalCostoDeMantenimientoAumento );
							}

						}
						else
						{
							printf("\nPrimero deberia hacer las cuentas antes de ingresas a esta opcion\n");
						}
						break;
					case 5:
						printf("Chau Chau");
						break;
					default:
						printf("Esta opcion no es valida...");
						break;
				}

	}while(opcion!=5);

	return EXIT_SUCCESS;
}



