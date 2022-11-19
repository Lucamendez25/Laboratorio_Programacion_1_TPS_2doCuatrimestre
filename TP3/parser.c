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



/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{

	int retorno = -1;
	char auxIdStr[4];
	char nombreCompletoStr[50];
	char edadStr[30];
	char posicionStr[20];
	char nacionalidadStr[20];
	char idSelccionStr[20];

	Jugador* unJugador = NULL;


	if(pFile != NULL && pArrayListJugador !=NULL)
	{

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
				,auxIdStr,nombreCompletoStr,edadStr,posicionStr,nacionalidadStr,idSelccionStr);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
				,auxIdStr,nombreCompletoStr,edadStr,posicionStr,nacionalidadStr,idSelccionStr);

			unJugador = jug_newParametros(auxIdStr, nombreCompletoStr, edadStr, posicionStr, nacionalidadStr, idSelccionStr);

			if(unJugador != NULL)
			{
				ll_add(pArrayListJugador, unJugador);
			}
		}
	}
	retorno = 0;
	return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	Jugador* aux;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		do
		{
			aux = jug_new();

			if(aux != NULL && fread(aux,sizeof(Jugador),1,pFile) == 1)
			{
				ll_add(pArrayListJugador, aux);
			}

		}while(!feof(pFile));

		retorno = 0;
	}

    return retorno;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{

	int retorno = -1;
	char auxIdStr[4];
	char paisStr[50];
	char confederacionStr[30];
	char convocadosStr[50];

	Seleccion* unaSeleccion = NULL;


	if(pFile != NULL && pArrayListSeleccion !=NULL)
	{

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n"
				,auxIdStr,paisStr,confederacionStr,convocadosStr);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n"
				,auxIdStr,paisStr,confederacionStr,convocadosStr);

			unaSeleccion = selec_newParametros(auxIdStr, paisStr, confederacionStr, convocadosStr);

			if(unaSeleccion != NULL)
			{
				ll_add(pArrayListSeleccion, unaSeleccion);
			}
		}
	}
	retorno = 0;
	return retorno;
}

int parser_guardarTextoJugador(FILE* pFile , LinkedList* pArrayListJugadores)
{
	int retorno = -1;
	int i;
	int tam = ll_len(pArrayListJugadores);
	Jugador* aux;
	int auxId;
	char auxNombreCompleto[100];
	int auxEdad=0;
	char auxPosicion[30];
	char auxNacionalidad[30];
	int auxIdSeleccion;

	if(pFile != NULL && pArrayListJugadores != NULL)
	{
		fprintf(pFile,"id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion\n");

		for(i=0;i<tam;i++)
		{
			aux = (Jugador*)ll_get(pArrayListJugadores, i);
			if(aux != NULL)
			{
				jug_getId(aux, &auxId);
				jug_getNombreCompleto(aux, auxNombreCompleto);
				jug_getEdad(aux, &auxEdad);
				jug_getPosicion(aux, auxPosicion);
				jug_getNacionalidad(aux, auxNacionalidad);
				jug_getSIdSeleccion(aux, &auxIdSeleccion);

				fprintf(pFile, "%d,%s,%d,%s,%s,%d\n",
				auxId,auxNombreCompleto,auxEdad,auxPosicion, auxNacionalidad,auxIdSeleccion);
				retorno = 0;
			}
		}
	}
	return retorno;
}


int parser_guardarBinarioJugador(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int i;
	int tam = ll_len(pArrayListJugador);
	Jugador* auxJugador;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		for(i=0;i<tam;i++)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador, i);

			if(auxJugador != NULL)
			{
				fwrite(auxJugador,sizeof(Jugador),1,pFile);
			}
		}

		retorno = 0;
	}
	return retorno;
}


int parser_guardarTextoSeleccion(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int i;
	int tam = ll_len(pArrayListSeleccion);
	Seleccion* aux;
	int auxId;
	char auxPais[50];
	char auxConfederacion[30];
	int auxIdConvocados;

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		fprintf(pFile,"id,pais,confederacion,convocados\n");

		for(i=0;i<tam;i++)
		{
			aux = (Seleccion*)ll_get(pArrayListSeleccion, i);
			if(aux != NULL)
			{
				selec_getId(aux, &auxId);
				selec_getPais(aux, auxPais);
				selec_getConfederacion(aux, auxConfederacion);
				selec_getConvocados(aux, &auxIdConvocados);

				fprintf(pFile, "%d,%s,%s,%d\n",
				auxId,auxPais,auxConfederacion,auxIdConvocados);
				retorno = 0;
			}
		}
	}
	return retorno;
}


