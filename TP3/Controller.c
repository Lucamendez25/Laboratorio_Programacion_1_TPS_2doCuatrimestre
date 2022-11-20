#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;

	FILE* pArchivo = NULL;

	if(pArrayListJugador != NULL && path != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			parser_JugadorFromText(pArchivo,pArrayListJugador);
			printf("\nCarga exitosa de Jugadores.\n");
			retorno = 0;
		}
		else
		{
			printf("\nError con la carga de Jugadores\n");

		}
		fclose(pArchivo);
	}
    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;

	FILE* pArchivo=NULL;

	if(pArrayListJugador != NULL && path != NULL)
	{
		pArchivo = fopen(path,"rb");
		if(pArchivo != NULL)
		{
			parser_JugadorFromBinary(pArchivo, pArrayListJugador);
			printf("\nCarga exitosa del archivo binario...\n");
			systemPause();
		}
		else
		{
			printf("\nError con la carga del archivo binario\n");
			systemPause();
		}
		fclose(pArchivo);
		retorno = 0;
	}
    return retorno;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno = - 1;

	if(pArrayListJugador != NULL)
	{
		Jugador_add(pArrayListJugador);

		retorno = 0;
	}
	return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = - 1;
	int buscadorId;
	int index;
	Jugador* auxJugador = NULL;

	if(pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);

		utn_getNumero(&buscadorId, "\nIngrese el ID a modificar:", "\nError,reingrese un ID valido", 1, 2000, 3);

		index = Jugador_buscarPorId(pArrayListJugador, buscadorId);

		if(index != -1)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador, index);
			if(auxJugador!=NULL)
			{
				Jugador_mostrar(auxJugador, pArrayListSeleccion);
				Jugador_modificar(auxJugador);
			}
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList*pArrayListSeleccion)
{
	int retorno = - 1;
	int index;
	int buscadorId;
	Jugador* auxJugador;

	if(pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador,pArrayListSeleccion);
		utn_getNumero(&buscadorId, "\nIngrese el ID del jugador a eliminar:", "\nError,reigrese un ID valido\n", 1, 2000, 3);
		index = Jugador_buscarPorId(pArrayListJugador, buscadorId);

		if(index != -1)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador, index);
			ll_remove(pArrayListJugador, index);
			Jugador_delete(auxJugador);

			printf("\nLa baja se ha realizado con exito\n");
			retorno = 0;
		}
		else
		{
			printf("\n◉Error en la baja,reintentar..\n");
		}
	}
    return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int i;
	int tam = ll_len(pArrayListJugador);
	Jugador* auxJugador;

	if(pArrayListJugador != NULL)
	{
	  printf("\n|==================================================LISTA JUGADORES======================================================|\n");
		printf("|ID                   NOMBRE           EDAD                   POSICION             NACIONALIDAD          CONVOCADO      |\n");
		printf("|=======================================================================================================================|\n");
		for(i=0;i<tam;i++)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador, i);
			Jugador_mostrar(auxJugador, pArrayListSeleccion);
		}
		retorno = 0;
	}
	else
	{
		printf("\nError\n");
	}
	printf("|========================================================================================================================|\n");

    return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int opcion;
	int orden;
	do
	{
		opcion = subMenu_ordenarListaJugadores();
		if(opcion!=4)
		{
			utn_getNumero(&orden, "\nIngrese si lo desea en orden Ascendente (1), o en Descendente(0):", "\nError,reigrese una opcion valida, (ASC=1 / DESC=0)\n", 0, 1, 3);
		}

		switch(opcion)
		{
		case 1:
			ll_sort(pArrayListJugador,Jugador_ordenaPorNacionalidad,orden);
			printf("\nPara ver los cambios listar los jugadores (Opcion 5 del menu principal)\n");
		break;
		case 2:
			ll_sort(pArrayListJugador,Jugador_ordenaPorEdad,orden);
			printf("\nPara ver los cambios listar las selecciones(Opcion 5 del menu principal)\n");
		break;
		case 3:
			ll_sort(pArrayListJugador,Jugador_ordenaNombre,orden);
			printf("\nPara ver los cambios listar los pasajeros (Opcion 5 del menu principal)\n");
		break;
		case 4:
			printf("\nSaliendo del menu de ordenamiento...\n");
			printf("\nRedirigiendo al menu principal..\n");
		break;
		default:
			printf("\nOpcion incorrecta...\n");
		break;

		}

	}while(opcion != 4);


    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			parser_guardarTextoJugador(pFile, pArrayListJugador);
			printf("\nSe guardo correctamente en texto..\n");

			fclose(pFile);
		}

		retorno = 0;
	}
    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	FILE* pFile=NULL;
	LinkedList* listaJugadoresConvocados = ll_newLinkedList();

	if(path != NULL && pArrayListJugador != NULL)
	{
		controller_jugadoresConfederacionConvocados(pArrayListJugador, listaJugadoresConvocados, pArrayListSeleccion);
		pFile = fopen(path,"wb");
		if(pFile != NULL)
		{
			parser_guardarBinarioJugador(pFile, listaJugadoresConvocados);
			printf("\nSe guardo correctamente en bin..\n");
			fclose(pFile);
			printf("\nPara poder ver esta nueva lista, dirigase a la opcion listar del menu(opcion 5) \n");
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief Crea la nueva lista con jugadores de confederacion elegida por el usuario
 *
 * @param pArrayListJugador
 * @param pArrayListJugadorConvocados
 * @param pArrayListSeleccion
 * @return
 */
int controller_jugadoresConfederacionConvocados(LinkedList* pArrayListJugador, LinkedList * pArrayListJugadorConvocados, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int tam = ll_len(pArrayListJugador);
	int confeEntero;
	int idSeleccion;
	int indiceSeleccion;
	Jugador *auxJugador=NULL;
	Seleccion*auxSeleccion=NULL;
	char auxConfederacion[20];
	char confederacion[20];

	confeEntero=subMenu_confederacion(); //2
	Seleccion_ConfeInt(confeEntero,auxConfederacion); //CAF

	for(int i=0; i<tam; i++)
	{

		auxJugador=(Jugador*)ll_get(pArrayListJugador, i);
		jug_getSIdSeleccion(auxJugador, &idSeleccion);

		indiceSeleccion=Seleccion_buscarPorId(pArrayListSeleccion, idSeleccion);
		auxSeleccion=(Seleccion*)ll_get(pArrayListSeleccion, indiceSeleccion);
		selec_getConfederacion(auxSeleccion, confederacion);
		if(strcmp(confederacion,auxConfederacion)==0)
		{
			ll_add(pArrayListJugadorConvocados, auxJugador);
		}
	}
	return retorno;
}


/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;

	FILE* pArchivo = NULL;

	if(pArrayListSeleccion != NULL && path != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			parser_SeleccionFromText(pArchivo, pArrayListSeleccion);
			printf("\nCarga exitosa de Seleccion\n\n");
			systemPause();
			retorno = 0;
		}
		else
		{
			printf("\n\nError con la carga de la seleccion\n\n");
			systemPause();
		}
		fclose(pArchivo);
	}
    return retorno;
}

/** \brief Modificar datos de seleccion
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
	return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int i;
	int tam = ll_len(pArrayListSeleccion);
	Seleccion* auxOneSeleccion;

	if(pArrayListSeleccion != NULL)
	{
	  printf("\n|============================LISTA SELECCION=========================|\n");
		printf("|ID             PAIS          CONFEDERACION        CONVOCADOS(22:MAX)|\n");
		printf("|====================================================================|\n");
		for(i=0;i<tam;i++)
		{
			auxOneSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
			Seleccion_mostrar(auxOneSeleccion);
		}
		retorno = 0;
	}
	else
	{
		printf("\nError\n");
	}
	printf("|====================================================================|\n");

    return retorno;
    return 1;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int opcion;
	int orden;
	do
	{
		opcion = subMenu_ordenarListaSelecciones();
		if(opcion!=2)
		{
			utn_getNumero(&orden, "\nIngrese si lo desea en orden Ascendente (1), o en Descendente(0):", "\nError,reigrese una opcion valida, (ASC=1 / DESC=0)\n", 0, 1, 3);
		}

		switch(opcion)
		{
		case 1:
			ll_sort(pArrayListSeleccion,Seleccion_ordenaPorConfederacion,orden);
			printf("\nPara ver los cambios listar los jugadores (Opcion 5 del menu principal)\n");
		break;
		case 2:
			printf("\nSaliendo del menu de ordenamiento...\n");
			printf("\nRedirigiendo al menu principal..\n");
		break;
		default:
			printf("\nOpcion incorrecta...\n");
		break;

		}

	}while(opcion != 2);


	return retorno;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListSeleccion != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			parser_guardarTextoSeleccion(pFile, pArrayListSeleccion);
			printf("\nSe guardo correctamente en texto..\n");
			fclose(pFile);
		}

		retorno = 0;
	}
    return retorno;
}


/**
 * @brief Listar Jugadores solo Convocados
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return
 */
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int i;
	int tam = ll_len(pArrayListJugador);
	int flag=1;
	Jugador* auxOneJugador;

	if(pArrayListJugador != NULL)
	{
		flag=0;
	  printf("\n|=============================================LISTA JUGADORES===========================================================|\n");
		printf("|ID                       NOMBRE           EDAD                   POSICION             NACIONALIDAD          CONVOCADO  |\n");
		printf("|=======================================================================================================================|\n");
		for(i=0;i<tam;i++)
		{
			if(!ll_isEmpty(pArrayListJugador))
			{
				auxOneJugador = (Jugador*)ll_get(pArrayListJugador, i);
				Jugador_mostrarConvocado(auxOneJugador,pArrayListSeleccion);
				flag=0;
			}

		}
		if(flag)
		{
			 printf("\n=============================NO HAY JUGADORES EN EL SISTEMA=================================\n\n");
		}
		retorno = 0;
	}
	else
	{
		printf("\nError\n");
	}
	printf("|=======================================================================================================================|\n");

    return retorno;
}

/**
 * @brief Convoca JUgador
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return
 */
int controller_convocarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int buscadorIdJugador;
	int buscadorIdSeleccion;
	int indexJugador;
	int indexSeleccion;

	Jugador* auxJugador=NULL;
	Seleccion* auxSeleccion=NULL;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL )
	{
		controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
		utn_getNumero(&buscadorIdJugador, "\nIngrese el ID del jugador que quiera convocar:", "\nError,reingrese un ID valido", 1, 2000, 3);
		indexJugador=Jugador_buscarPorId(pArrayListJugador, buscadorIdJugador);
		if(indexJugador!=-1)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador, indexJugador);
			if(Jugador_thisConvocado(auxJugador)!=-1)
			{
				Jugador_mostrar(auxJugador, pArrayListSeleccion);
				systemPause();
				controller_listarSelecciones(pArrayListSeleccion);
				utn_getNumero(&buscadorIdSeleccion, "\nIngrese el ID de la seleccion que quiera convocar a su jugador:", "\n◉Error,reingrese un ID valido", 1, 2000, 3);
				indexSeleccion=Seleccion_buscarPorId(pArrayListSeleccion, buscadorIdSeleccion);

				if(indexSeleccion!=-1)
				{
					auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, indexSeleccion);
					if(Seleccion_cantidadConvocados(auxSeleccion)!=1)
					{
						Jugador_cambiarSeleccion(auxJugador,buscadorIdSeleccion);
						Seleccion_mostrar(auxSeleccion);
					}
					else
					{
						Seleccion_mostrar(auxSeleccion);
						printf("No hay más espacio en esta seleccion (El max es 22.)\n");
					}
				}
				else
				{
					printf("No hay ninguna seleccion con ese ID\n");
				}
			}
			else
			{
				printf("Este jugador esta convocado\n");
			}
		}
		else
		{
			printf("No hay ningun jugador con ese ID\n");
		}
	}
	return retorno;
}

/**
 * @brief Da de baja a una convocatoria
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return
 */
int controller_desconvocarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int buscadorIdJugador;
	int indexJugador;
	int indexSeleccion;
	int idSeleccion;

	Jugador* auxJugador=NULL;
	Seleccion* auxSeleccion=NULL;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL )
	{
		controller_listarJugadoresConvocados(pArrayListJugador,pArrayListSeleccion);
		utn_getNumero(&buscadorIdJugador, "\nIngrese el ID del jugador que quiera sacar de la convocatoria:", "\nError,reingrese un ID valido", 1, 2000, 3);
		indexJugador=Jugador_buscarPorId(pArrayListJugador, buscadorIdJugador);
		if(indexJugador!=-1)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador, indexJugador);
			if(Jugador_thisConvocado(auxJugador)!=-1)
			{
				jug_getSIdSeleccion(auxJugador, &idSeleccion);
				printf("%d\n", idSeleccion);
				indexSeleccion=Seleccion_buscarPorId(pArrayListSeleccion, idSeleccion);
				if(indexSeleccion!=-1)
				{
					auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, indexSeleccion);
					if(auxSeleccion!=NULL)
					{
						Jugador_anularConvocatoria(auxJugador);
						Seleccion_restarConvocados(auxSeleccion);
						Jugador_mostrar(auxJugador, pArrayListSeleccion);
					}
				}
			}
		}
	}
	return retorno;
}
