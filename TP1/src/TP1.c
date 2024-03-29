/*
 ============================================================================
 Name        : TP1.c
 Author      : Luca M�ndez
 Version     : Division A
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
							printf("\n\nSe pudieron guardar los valores ingresados\n\n\n");
							flagCalculos=0;
							system("pause");
						}
						else
						{
							printf("\n\nNo se pudieron guardar los valores ingresados\n\n\n");
							system("pause");
						}
						break;

					case 2:
						if(contadorJugadores < 22)
						{
							todoOkJugadores=SubMenuJugadores(&arqueros,&defensores,&mediocampistas,&delanteros,&afc,
													&caf,&concacaf,&conmebol,&uefa,&ofc, &contadorJugadores);
							if(todoOkJugadores==1)
							{
								printf("\n\nSe ha guardado el ingreso de su jugador, y su region correctamente.\n\n\n");
								contadorJugadores++;
								flagCalculos=0;
								system("pause");
							}
							else
							{
								printf("\n\nNo pudo guardarse correctamente, ni el jugador, ni su region. Por favor, ingrese nuevamente los datos.\n\n\n");
								system("pause");
							}
						}
						else
						{
							printf("\n\nYa no hay espacio para mas jugadores, son 22/22\n\n\n");
							system("pause");
						}
						break;
					case 3:
						if(contadorJugadores != 0)
						{
							if(hospedaje !=0 && comida !=0 && transporte !=0)
							{
								promediosAfc=CalcularPromedios(afc,contadorJugadores);
								promediosCaf=CalcularPromedios(caf,contadorJugadores);
								promediosConcacaf=CalcularPromedios(concacaf,contadorJugadores);
								promediosConmebol=CalcularPromedios(conmebol,contadorJugadores);
								promediosUefa=CalcularPromedios(uefa,contadorJugadores);
								promediosOfc=CalcularPromedios(ofc,contadorJugadores);

								costoDeMantenimiento=CalcularCostoDeMantenimiento(hospedaje,comida,transporte);

								if(promediosUefa != 0 && ComparadorRegiones(promediosUefa,promediosAfc,promediosCaf,promediosConcacaf,promediosConmebol,promediosOfc))
								{
									porcentajeCostoDeMantenimiento=costoDeMantenimiento * 0.35;
									totalCostoDeMantenimientoAumento=costoDeMantenimiento + porcentajeCostoDeMantenimiento;
									flagAumentos=1;
								}
								else
								{
									flagAumentos=0;
								}

								printf("\nSe realizaron los calculos de forma efectiva\n\n\n");
								flagCalculos=1;
								system("pause");
							}
							else
							{
								printf("\n\nPrimero debe ingresar por lo menos, en cada uno de los campos un precio (hospedaje, comida, transporte)\n\n\n");
								flagCalculos=0;
								system("pause");
							}
						}
						else
						{
							printf("\n\nPrimero debe ingresar un jugador por lo menos...\n\n\n");
							flagCalculos=0;
							system("pause");
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
									"\nEl costo de mantenimiento es: %.2f\n",
									promediosUefa, promediosConmebol, promediosConcacaf,
									promediosAfc,promediosOfc, promediosCaf,costoDeMantenimiento);
							if(flagAumentos==1)
							{
								printf("Y recibio un aumento de %.2f, su nuevo valor es de: %.2f\n\n\n",
										porcentajeCostoDeMantenimiento, totalCostoDeMantenimientoAumento );
							}
							system("pause");
						}
						else
						{
							printf("\n\nPrimero deberia hacer las cuentas antes de ingresas a esta opcion\n\n\n");
							system("pause");
						}
						break;
					case 5:
						printf(	"\n\nCHAU CHAU\n\n");
						break;
					default:
						printf("Esta opcion no es valida...");
						system("pause");
						break;
				}

	}while(opcion!=5);

	return EXIT_SUCCESS;
}



