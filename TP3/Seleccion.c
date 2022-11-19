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

Seleccion* selec_new()
{
	return malloc(sizeof(Seleccion));
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* unaSeleccion;
	int todoOk=0;
	unaSeleccion = selec_new();

	if(unaSeleccion != NULL && idStr != NULL && paisStr != NULL
	&& confederacionStr != NULL && convocadosStr != NULL)
	{
		unaSeleccion->id = atoi(idStr);
		strcpy(unaSeleccion->pais,paisStr);
		strcpy(unaSeleccion->confederacion,confederacionStr);
		unaSeleccion->convocados=atoi(convocadosStr);
		todoOk=1;

	}
	else
	{
		printf("\nNo se pudo asignar memoria..\n");
	}

	if(!todoOk)
	{
		free(unaSeleccion);
		unaSeleccion=NULL;
	}

	return unaSeleccion;
}

void selec_delete(Seleccion* this)
{
	if(this != NULL)
	{
		free(this);
	}
}


int selec_getId(Seleccion* this,int * id)
{
	int retorno=-1;

	if(this != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}
int selec_getPais(Seleccion* this,char* pais)
{
	int retorno=-1;

	if(this != NULL && pais != NULL)
	{
		strcpy(pais,this->pais);
		retorno = 0;
	}

	return retorno;
}
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno=-1;

	if(this != NULL && confederacion != NULL)
	{
		strcpy(confederacion,this->confederacion);
		retorno = 0;
	}
	return retorno;
}

int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno=-1;

	if(this != NULL && convocados >= 0 )
	{
		retorno = 0;
		this->convocados = convocados;
	}

	return retorno;

}
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno=-1;

	if(this != NULL)
	{
		*convocados = this->convocados;
		retorno = 0;
	}

	return retorno;
}



void Seleccion_mostrar(Seleccion* unaSeleccion)
{
	int auxId;
	char auxPais[50];
	char auxConfederacion[30];
	int auxConvocados;



	selec_getId(unaSeleccion, &auxId);
	selec_getPais(unaSeleccion,auxPais);
	selec_getConfederacion(unaSeleccion, auxConfederacion);
	selec_getConvocados(unaSeleccion, &auxConvocados);


	if(unaSeleccion != NULL)
	{
		printf("|%4d  | %20s|  %20s|           %4d |\n",
				auxId,auxPais,auxConfederacion, auxConvocados);
	}
	else
	{
		printf("\nError\n");
	}

}

int Seleccion_buscarPorId(LinkedList* pArrayListSeleccion, int buscadorId)
{
	int tam;
	int retorno=-1;
	Seleccion* auxSeleccion = NULL;
	if(pArrayListSeleccion!=NULL)
	{
		tam = ll_len(pArrayListSeleccion);
		for(int i=0;i<tam;i++)
		{
			auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);

			if(auxSeleccion->id == buscadorId)
			{
				retorno = ll_indexOf(pArrayListSeleccion, auxSeleccion);
			}
		}
	}
	return retorno;
}
int Seleccion_cantidadConvocados(Seleccion* unaSeleccion)
{
	int retorno=-1;
	int cantConvocados;

	selec_getConvocados(unaSeleccion, &cantConvocados);
	if(cantConvocados<22)
	{
		cantConvocados++;
		selec_setConvocados(unaSeleccion, cantConvocados);
		retorno=0;
	}

	return retorno;
}
int Seleccion_restarConvocados(Seleccion* unaSeleccion)
{
	int retorno=-1;
	int cantConvocados;
	if(unaSeleccion!=NULL)
	{
		selec_getConvocados(unaSeleccion, &cantConvocados);
		cantConvocados--;
		selec_setConvocados(unaSeleccion, cantConvocados);
	}

	return retorno;
}

int Seleccion_ordenaPorConfederacion(void* pSeleccionUno , void* pSeleccionDos)
{
	int retorno = -1;
	char confederacionSeleccionUno[50];
	char confederacionSeleccionDos[50];
	Seleccion* seleccionUno = NULL;
	Seleccion* seleccionDos = NULL;

	if(pSeleccionUno != NULL && pSeleccionDos != NULL)
	{
		seleccionUno = (Seleccion*)pSeleccionUno;
		seleccionDos =  (Seleccion*)pSeleccionDos;

		if(seleccionUno != NULL && seleccionDos != NULL)
		{
			selec_getConfederacion(seleccionUno, confederacionSeleccionUno);
			selec_getConfederacion(seleccionDos, confederacionSeleccionDos);
			retorno = strcmp(confederacionSeleccionUno,confederacionSeleccionDos);
		}
	}

	return retorno;
}
int Seleccion_ConfeInt(int confederacion,char* confederacionStr)
{
	int retorno = -1;

	if(confederacionStr != NULL)
	{
		switch(confederacion)
		{
		case 1:
			strcpy(confederacionStr,"AFC");
		break;
		case 2:
			strcpy(confederacionStr,"CAF");
		break;
		case 3:
			strcpy(confederacionStr,"CONCACAF");
		break;
		case 4:
			strcpy(confederacionStr,"CONMEBOL");
		break;
		case 5:
			strcpy(confederacionStr,"UEFA");
		break;
		default:
			printf("error");
		break;
		}
	}
	return retorno;
}
