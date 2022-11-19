#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "utn.h"
#include "parser.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int flag = 0;
    int flagGuardadoEnBinario=0;
    int flagGuardadoEnTexto;

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();


    do{
    	option = menu();
        switch(option)
        {
            case 1:
				if(flag == 0)
				{
					controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
					controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones);

					flag=1;
				}
				else
				{
					if(flag == 1)
					{
						printf("\nYa se realizo una carga de jugadores...\n\nRedirigiendo al menu principal\n");
					}
				}
			break;

            case 2://cargar datos bn
				if(controller_agregarJugador(listaJugadores)==0)
				{
					printf("\nYa se realizo una carga de jugadores...\n\nVolviendo al menu principal\n");
				}
				else
				{
					printf("\nEl pasajero no se ha podido añadir..\n\nPorfavor reintente..\n");
				}
				break;

            case 3:
				if(ll_isEmpty(listaJugadores) == 0)
				{
					//modificar jugador
					if(controller_editarJugador(listaJugadores)== 0)
					{
						printf("\nEl jugador se ha modificado exitosamente\n");
					}
					else
					{
						printf("\nEl  no se ha podido modificar..\n\nPorfavor reintente..\n");
					}
				}
				else
				{
					printf("\nPrimero cargar o dar de alta algun jugador..\n\nVolviendo al menu principal...\n");
				}
            	break;
            case 4:
            	//baja de jugadores
            	if(ll_isEmpty(listaJugadores) == 0)
				{
            		controller_removerJugador(listaJugadores);
				}
            	else
            	{
            		printf("\nPrimero cargar o dar de alta algun jugador..\n\nVolviendo al menu principal...\n");
            	}
            	break;
            case 5:
            	if(ll_isEmpty(listaJugadores) == 0)
            	{
            		switch(subMenuListar())
            		{
            			case 1:
            				controller_listarJugadores(listaJugadores);
            				break;
            			case 2:
            				controller_listarSelecciones(listaSelecciones);
            				break;
            			case 3:
            				controller_listarJugadoresConvocados(listaJugadores);
            				break;
            			default:
            				printf("\nIngreso una opcion valida\n");
            				break;
            		}
            	}
               	else
               	{
               		printf("\nPrimero cargar o dar de alta algun jugador..\n\nVolviendo al menu principal...\n");
               	}

            	break;
            case 6:

            	if(ll_isEmpty(listaJugadores) == 0)
            	{
            		switch(subMenuConvocados())
            		{
            			case 1:
            				controller_convocarJugadores(listaJugadores, listaSelecciones);
            				break;
            			case 2:
            				controller_desconvocarJugadores(listaJugadores, listaSelecciones);
            				break;
            		}
            	}
               	else
               	{
               		printf("\nPrimero cargar o dar de alta algun jugador..\n\nRedirigiendo al menu principal...\n");
               	}

            	break;
            case 7:
            	//Ordenar y listar
            		/*
            		 * Jugadores por nacionalidad
            		 * Selecciones por confederacion
            		 * Jugadores por edad
            		 * Jugadores por Nombre
            		 * */
            	if(flag == 1 || ll_isEmpty(listaJugadores) == 0)
            	{
            		switch(subMenu_ordenar())
					{
						case 1:
							controller_ordenarJugadores(listaJugadores);
							break;
						case 2:
							controller_ordenarSelecciones(listaSelecciones);
							break;
					}
            	}
            	else
            	{
            		printf("\nPrimero cargar o dar de alta algun jugador..\n\nVolviendo al menu principal...\n");
            	}
            	break;
            case 8:
            	//generar y guardar archivo binario
            	if(flag == 1)
            	{
            		controller_guardarJugadoresModoBinario("jugadores.bin",listaJugadores, listaSelecciones);
            		flagGuardadoEnBinario = 1;
            	}

            	else
            	{
            		printf("\nPrimero cargar la lista de jugadores..\n\nVolviendo al menu principal...\n");
            	}
            	break;
            case 9:
            	//cargar archivo binario
            	if(flag == 0)
				{
            		controller_cargarJugadoresDesdeBinario("jugadores.bin", listaJugadores);
            		controller_listarJugadores(listaJugadores);
            		flag = 1;
				}
            	else
				{
					if(flag == 1)
					{
						printf("\nYa se realizo una carga de jugadores...\n\nRedirigiendo al menu principal\n");
					}
				}
            	break;
            case 10:
            	//guardar archivos .csv
            	if(flag == 1)
            	{
            		controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
					controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones);
					flagGuardadoEnTexto = 1;
            	}
            	else
            	{
            		printf("\nPrimero cargar la lista de jugadores y selecciones..\n\nVolviendo al menu principal...\n");
            	}
            	break;
            case 11:
            	if(flagGuardadoEnTexto == 0 || flagGuardadoEnBinario == 0)
            	{
            		printf("\nAntes de salir del programa debe guardar en las opciones (8 y 10)\n\nVolviendo al menu principal...\n");
            	}
            	else
            	{
            		if(flagGuardadoEnTexto == 1 && flagGuardadoEnBinario == 1)
            		{
            			printf("\nSaliendo.....\n");
            		}
            	}
            	//salir
            	break;
        }
    }while(option != 11);

    return 0;
}

