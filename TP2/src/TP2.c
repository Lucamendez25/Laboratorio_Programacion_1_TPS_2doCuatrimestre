/*
 ============================================================================
 Name        : TP2.c
 Author      : Luca Méndez
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
#include "jugadores.h"
#include "confederaciones.h"
#include "output.h"
#include "input.h"


#define TAM_J 3000
#define TAM_C 6

int main(void)
{
	setbuf(stdout, NULL);

	eJugador listaJugadores[TAM_J];
	eConfederacion listaConfederaciones[TAM_C];

	int todoOkInciazadosJugadores;
	int todoOkIncializadosConfederaciones;
	int nextLegajoJugadores=1;//, nextLegajoJugadores;
	int nextLegajoConfederaciones=100;//, nextLegajoJugadores;
	int seguir;
	int opcionAlta,opcionBaja,opcionModificar;

	todoOkInciazadosJugadores=inicializarJugadores(listaJugadores, TAM_J);
	todoOkIncializadosConfederaciones=inicializarConfederaciones(listaConfederaciones, TAM_C);

	if(todoOkInciazadosJugadores==1 && todoOkIncializadosConfederaciones == 1 )
	{
		//SACAR COMENTADO; PARA TENER LOS DATOS HARDCODEADOS :)
		hardcodearJugadores(&nextLegajoJugadores, listaJugadores, TAM_J, 15);
		hardcodearConfederaciones(&nextLegajoConfederaciones, listaConfederaciones, TAM_C, 6);
		do
		{
			systemCls();
			seguir=menu();
			switch(seguir)
			{
				case 1:
					systemCls();
					opcionAlta=subMenuAlta();
					switch(opcionAlta)
					{
						case 1:
							altaJugadores(&nextLegajoJugadores,listaJugadores,listaConfederaciones, TAM_J, TAM_C);
							printf("\n\n");
							systemPause();
							break;

						case 2:
							altaConfederaciones(&nextLegajoConfederaciones, listaConfederaciones, TAM_C);
							printf("\n\n");
							systemPause();
							break;
					}

					break;
				case 2:
					systemCls();
					opcionBaja=subMenuBaja();
					switch(opcionBaja)
					{
						case 1:
							bajaJugadores(listaJugadores,listaConfederaciones, TAM_J, TAM_C);
							printf("\n\n");
							systemPause();
							break;

						case 2:
							bajaConfederacion(listaConfederaciones, TAM_C);
							printf("\n\n");
							systemPause();
							break;
					}
					break;
				case 3:
					systemCls();
					opcionModificar=subMenuModificar();
					switch(opcionModificar)
					{
						case 1:
							modificarJugadores(listaJugadores,listaConfederaciones, TAM_J, TAM_C);
							printf("\n\n");
							systemPause();
							break;

						case 2:
							modificarConfederaciones(listaConfederaciones, TAM_C);
							printf("\n\n");
							systemPause();
							break;
					}


					break;
				case 4:
					ordenarJugadores(listaJugadores, listaConfederaciones, TAM_J, TAM_C);
					printf("\n\n");
					systemPause();
					break;
				case 5:
					systemCls();
					cerrandoMenu();
					break;
				default:
					//Esta opcion no es valida
					break;

			}
		}while(seguir!=5);
	}
	return EXIT_SUCCESS;
}
