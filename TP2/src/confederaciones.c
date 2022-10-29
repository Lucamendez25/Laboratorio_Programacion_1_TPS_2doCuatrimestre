/*
 * confederaciones.c
 *
 *  Created on: 27 oct. 2022
 *      Author: Luca
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


int inicializarConfederaciones(eConfederacion vec[], int tam)
{
	int todoOk = 0;
		if(vec != NULL && tam > 0)
		{
			for(int i = 0 ; i < tam ; i++)
			{
				vec[i].isEmpty = 1;
			}
			todoOk = 1;
		}
		return todoOk;
}


int buscarLibreConfederaciones(int* pIndice, eConfederacion vec[], int tam)
{
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if( vec[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
        todoOk = 1;
    }
    return todoOk;
}


int altaConfederaciones(int* pLegajo,eConfederacion vecConfederacion[], int tamConfederaciones)
{
	char seguir;
    int todoOk = 0;
    int indice;
    eConfederacion auxConfederacion;

    if(pLegajo != NULL && vecConfederacion != NULL  && tamConfederaciones )
    {
    	do
    	{
    		printf("\n\n**** Alta Confederacion ****\n\n");
    		buscarLibreConfederaciones(&indice, vecConfederacion, tamConfederaciones);
			if(indice == -1)
			{
				printf("\nNo hay lugar en el sistema.\n");
			}
			else
			{
				cargarConfederacion(&auxConfederacion,vecConfederacion,tamConfederaciones);
				auxConfederacion.id = *pLegajo;
				*pLegajo = *pLegajo + 1;
				vecConfederacion[indice] = auxConfederacion;
				todoOk = 1;
			}
			utn_getCharSeguir(&seguir, "\nLe gustaria ingresar otra confederacion: ", "\nError, ingrese una opcion valida s/n (si/no): ", 4);

    	}while(seguir != 'n');


    }
    return todoOk;
}

int cargarConfederacion(eConfederacion * pConfederacion, eConfederacion vecConfederacion[], int tamConfederaciones)
{
	systemCls();
    int todoOk = 0;
    int idRegion;
    eConfederacion auxConfederacion;
    if(pConfederacion != NULL)
	{
		utn_getString(auxConfederacion.nombre, "\nIngrese nombre de su confederacion: ", "\nError\n");
		strcpy(pConfederacion->nombre, auxConfederacion.nombre);

		systemCls();
		mostrarRegiones();
		utn_getInt(&idRegion, "\nIngrese region de su confederacion: ", "\nError\n", 1, 4, 3);
		cargarDescripcionRegion(idRegion, &auxConfederacion);
		strcpy(pConfederacion->region, auxConfederacion.region);

		systemCls();

		utn_getInt(&auxConfederacion.anioCreacion, "\nIngrese anios de creacion: ", "\nError\n", 1700, 2023, 3);
		pConfederacion->anioCreacion=auxConfederacion.anioCreacion;

		pConfederacion->isEmpty = 0;

		todoOk = 1;
	}

    return todoOk;
}


int cargarDescripcionRegion(int idRegion, eConfederacion * vec)
{
	int todoOk=0;
	if(vec !=NULL && idRegion>0)
	{
		switch(idRegion)
		{
			case 1:
				strcpy(vec->region, "SUDAMERICA");
				break;
			case 2:
				strcpy(vec->region, "EUROPA");
				break;
			case 3:
				strcpy(vec->region, "ASIA");
				break;
			case 4:
				strcpy(vec->region, "AFRICA");
				break;
			case 5:
				strcpy(vec->region, "NORTE Y CENTRO AMERICA");
				break;
			case 6:
				strcpy(vec->region, "OCEANIA");
				break;

		}
		todoOk=1;
	}
	return todoOk;
}


int buscarConfederacion(eConfederacion * vec, int id, int tam)
{
    int indice = -1;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if(!vec[i].isEmpty && vec[i].id == id )
            {

                indice = i;
                break;
            }
        }
    }
    else
    {
    	indice =-1;
    }
    return indice;
}
int buscarConfederacionPorId(int* pIndice, int legajo, eConfederacion vec[], int tam)
{
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if( !vec[i].isEmpty && vec[i].id == legajo )
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
        todoOk = 1;
    }
    return todoOk;
}

int bajaConfederacion(eConfederacion vecConfederaciones[], int tamConfederaciones)
{
	systemCls();
    int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    int flag;//para ver si hay o no gente para dar de baja
    if(vecConfederaciones != NULL &&  tamConfederaciones > 0 )
    {
        printf("**** Baja Confederacion ****\n\n");

        flag=mostrarConfederaciones(vecConfederaciones, tamConfederaciones);
		if(flag==-1)
		{
			printf("Primero debe haber una alguna confederacion dado de alta para realizar una baja\n\n");
		}
		else
		{
			utn_getInt(&legajo, "\nIngrese el Id de la confederacion que desea modificar: ", "\nError, elija un id valido: ", 0, 1000, 3);
			buscarConfederacionPorId(&indice, legajo, vecConfederaciones, tamConfederaciones);

			while(indice == -1)
			{
				printf("No existe un jugador con ese legajo: %d\n", legajo);
				utn_getCharSeguir(&confirma, "\nConfirma modificacion?: ", "\nError, ingrese una opcion valida s/n (si/no):", 3);
				buscarConfederacionPorId(&indice, legajo, vecConfederaciones, tamConfederaciones);
			}

			systemCls();
			mostrarConfederacion(vecConfederaciones[indice], tamConfederaciones);
			utn_getCharSeguir(&confirma, "\nConfirma modificacion?s/n: ", "\nError, ingrese una opcion valida s/n (si/no):", 3);
			if(confirma == 's')
			{
				vecConfederaciones[indice].isEmpty = 1;
				printf("Baja exitosa.\n");
			}
			else
			{
				printf("Se ha cancelado la baja.\n");
			}

			todoOk = 1;
		}
    }
    return todoOk;
}


int modificarConfederaciones(eConfederacion vecConfederaciones[],int tamConfederaciones)
{
	int todoOk = 0;
	int legajo;
	int indice;
	char seguir;
	int modificar;
	char confirma;
	int idRegion;
	int flag;
	eConfederacion auxConfederacion;

	if(vecConfederaciones != NULL && tamConfederaciones >0)
	{
		systemCls();
		printf("**** Modificar Confederaciones ****\n\n");

		flag=mostrarConfederaciones(vecConfederaciones, tamConfederaciones);
		if(flag==-1)
		{
			printf("Primero debe haber dado de alta para realizar una modificacion\n\n");
		}
		else
		{
			do
			{
				utn_getInt(&legajo, "\nIngrese ID de la confederacion que desea modificar: ", "\nError\n", 0, 9999, 3);
				buscarConfederacionPorId(&indice, legajo, vecConfederaciones, tamConfederaciones);
				if(indice == -1)
				{
					printf("No existe una confederacion con ese ID: %d\n", legajo);
				}
				else
				{
					systemCls();
					mostrarConfederaciones(vecConfederaciones, tamConfederaciones);
					modificar=subMenuModificarConfederaciones();
					switch(modificar)
					{
						case 1:
							systemCls();
							utn_getString(auxConfederacion.nombre, "\nIngrese nuevo nombre de su confederacion:", "\nError\n");
							fflush(stdin);
							utn_getCharSeguir(&confirma, "\nConfirma modificacion?: ", "\nError, ingrese una opcion valida s/n (si/no):", 3);
							if(confirma == 's')
							{
								strcpy(vecConfederaciones[indice].nombre, auxConfederacion.nombre);
								mostrarConfederacion(vecConfederaciones[indice], tamConfederaciones);
								printf("\n\nModificacion exitosa.\n\n");
							}
							else
							{
								printf("\n\nSe ha cancelado la modificacion.\n\n");
							}
							break;

						case 2:
							systemCls();
							mostrarRegiones();
							utn_getInt(&idRegion, "\nIngrese nueva region de su confederacion:", "\nError\n", 1, 4, 3);
							cargarDescripcionRegion(idRegion, &auxConfederacion);
							utn_getCharSeguir(&confirma, "\nConfirma modificacion?: ", "\nError, ingrese una opcion valida s/n (si/no):", 3);
							if(confirma == 's')
							{
								strcpy(vecConfederaciones[indice].region, auxConfederacion.region);
								mostrarConfederacion(vecConfederaciones[indice],tamConfederaciones);
								printf("\n\nModificacion exitosa.\n\n");
							}
							else
							{
								printf("\n\nSe ha cancelado la modificacion.\n\n");
							}
							break;
						case 3:
							systemCls();
							utn_getInt(&auxConfederacion.anioCreacion, "\nIngrese nuevo anio de creacion: ", "\nError\n", 1700, 2023, 3);
							utn_getCharSeguir(&confirma, "\nConfirma modificacion?: ", "\nError, ingrese una opcion valida s/n (si/no):", 3);
							if(confirma == 's')
							{

								vecConfederaciones[indice].anioCreacion=auxConfederacion.anioCreacion;
								mostrarConfederacion(vecConfederaciones[indice],tamConfederaciones);
								printf("\n\nModificacion exitosa.\n\n");
							}
							else
							{
								printf("\n\nSe ha cancelado la modificacion.\n\n");
							}
							break;

						default:
							printf("Esta opcion no existe en este menu");
							break;
					}
					systemCls();
					mostrarConfederacion(vecConfederaciones[indice], tamConfederaciones);
					utn_getCharSeguir(&seguir, "Desea cambiar otra area?:", "\nError, ingrese una opcion valida s/n (si/no)", 4);

				}

			}while(seguir!='n');
		}
		todoOk = 1;
	}

	return todoOk;

}


int hardcodearConfederaciones(int* pLegajo ,eConfederacion vec[], int tam, int cant)
{
	/*int cant, es la cantidad que quiero que me cargue.
	 * porque el vector puede ser de 10.000, pero que me cargue 10 nomas*/
    int todoOk = 0;

    eConfederacion confederaciones[] =
    {
		{100,"CONMEBOL","SUDAMERICA",1916,0},
		{101, "UEFA", "EUROPA",1954,0},
		{102, "AFC", "ASIA",1954,0},
		{103, "CAF", "AFRICA",1957,0},
		{104, "CONCACAF", "NORTE Y CENTRO AMERICA",1961,0},
		{105, "OFC", "OCEANIA",1966,0}
	};

    if(vec != NULL && tam > 0 && cant <= tam && cant <= 10)
    {

      for(int i = 0 ; i < cant ; i++){

      vec[i] = confederaciones[i];
      *pLegajo = *pLegajo + 1;
      }
        todoOk = 1;
    }
    return todoOk;
}
