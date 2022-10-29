/*
 * jugadores.c
 *
 *  Created on: 24 oct. 2022
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

//////////////////////////////////////////////////INCIALIZAR////////////////////////////////////////////////////////////////////////////////////////
int inicializarJugadores(eJugador vec[], int tam)
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


////////////////////////////////////////////////////BUSCAR LIBRE////////////////////////////////////////////////////////////////////////////////////
int buscarLibreJugadores(int* pIndice, eJugador vec[], int tam)
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
//////////////////////////////////////////////////ALTA////////////////////////////////////////////////////////////////////////////////////////////////////

int altaJugadores(int* pLegajo, eJugador vecJugador[], eConfederacion vecConfederacion[], int tamJugadores, int tamConfederaciones)
{
	char seguir;
    int todoOk = 0;
    int indice;
    eJugador auxJugador;

    if(pLegajo != NULL && vecJugador != NULL && vecConfederacion != NULL && tamJugadores > 0 && tamConfederaciones )
    {
    	do
    	{
    		printf("\n\n**** Alta Jugador ****\n\n");
    		buscarLibreJugadores(&indice, vecJugador, tamJugadores);
			if(indice == -1)
			{
				printf("\nNo hay lugar en el sistema.\n");
			}
			else
			{
				cargarJugador(&auxJugador,vecConfederacion,tamJugadores,tamConfederaciones);
				auxJugador.id = *pLegajo;
				*pLegajo = *pLegajo + 1;
				vecJugador[indice] = auxJugador;
				todoOk = 1;
			}
			utn_getCharSeguir(&seguir, "\nLe gustaria ingresar otro jugador:", "\nError, ingrese una opcion valida s/n (si/no): ", 4);

    	}while(seguir != 'n');


    }
    return todoOk;
}

///////////////////////////////////////////////////////CARGAR//////////////////////////////////////////////////////////////////////////////////////////////////
int cargarJugador(eJugador * pJugador, eConfederacion vecConfederacion[], int tamJugadores, int tamConfederaciones)
{
	systemCls();
    int todoOk = 0;
    int idPosicion;
    eJugador auxJugador;
    if(pJugador != NULL)
	{
		utn_getString(auxJugador.nombre, "\nIngrese nombre de su jugador:", "\nError\n");
		strcpy(pJugador->nombre, auxJugador.nombre);

		systemCls();
		mostrarPosiciones();
		utn_getInt(&idPosicion, "\nIngrese posicion de su jugador:", "\nError\n", 1, 4, 3);
		cargarDescripcionPosicion(idPosicion, &auxJugador);
		strcpy(pJugador->posicion, auxJugador.posicion);

		systemCls();

		utn_getShort(&auxJugador.numeroCamiseta,"\nIngrese numero de camiseta:", "\nError\n", 1, 99, 3);
		pJugador->numeroCamiseta=auxJugador.numeroCamiseta;

		systemCls();

		mostrarConfederaciones(vecConfederacion, tamConfederaciones);
		utn_getInt(&auxJugador.idConfederacion, "\nIngrese id de confederacion:", "\nError\n", 100, 105, 3);
		pJugador->idConfederacion=auxJugador.idConfederacion;

		systemCls();

		utn_getFloat(&auxJugador.salario, "\nIngrese salario:", "\nError\n", 1, 999999, 3);
		pJugador->salario=auxJugador.salario;

		systemCls();

		utn_getShort(&auxJugador.aniosContrato,"\nIngrese anios de contrato:", "\nError\n", 1, 5, 3);
		pJugador->aniosContrato=auxJugador.aniosContrato;

		pJugador->isEmpty = 0;

		todoOk = 1;
	}

    return todoOk;
}

int cargarDescripcionConfederacion(int idConfederacion, char descripcion[], eConfederacion vec[], int tam)
{
	int todoOk=0;
	if(descripcion!=NULL && vec !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(vec[i].id==idConfederacion)
			{
				strcpy(descripcion, vec[i].nombre);
				break;
			}
		}
		todoOk=1;
	}
	return todoOk;
}

int cargarDescripcionPosicion(int idPosicion, eJugador * vec)
{
	int todoOk=0;
	if(vec !=NULL && idPosicion>0)
	{
		switch(idPosicion)
		{
			case 1:
				strcpy(vec->posicion, "arquero");
				break;
			case 2:
				strcpy(vec->posicion, "Defensa");
				break;
			case 3:
				strcpy(vec->posicion, "MedioCampista");
				break;
			case 4:
				strcpy(vec->posicion, "Delantero");
				break;

		}
		todoOk=1;
	}
	return todoOk;
}


///////////////////////////////////////////////////////MODIFICAR/////////////////////////////////////////////////////////////////////////////////////////////////


int modificarJugadores(eJugador vecJugador[], eConfederacion vecConfederacion[], int tamJugadores, int tamConfederaciones)
{
	int todoOk = 0;
	int legajo;
	int indice;
	char seguir;
	int modificar;
	char confirma;
	int flag;
	int idPosicion;
	eJugador auxJugador;

	if(vecJugador != NULL && vecConfederacion != NULL &&  tamJugadores > 0 && tamConfederaciones >0)
	{
		systemCls();
		printf("**** Modificar Jugadores ****\n\n");

		flag=mostrarJugadores(vecJugador,vecConfederacion,tamJugadores ,tamConfederaciones);
		if(flag==-1)
		{
			printf("Primero debe haber dado de alta para realizar una modificacion\n\n");
		}
		else
		{
			do
			{
				mostrarJugadores(vecJugador,vecConfederacion,tamJugadores ,tamConfederaciones);
				utn_getInt(&legajo, "\nIngrese ID del jugador que desea modificar: ", "\nError\n", 0, 9999, 3);
				buscarJugador(&indice, legajo, vecJugador, tamJugadores);
				if(indice == -1)
				{
					printf("No existe un jugador con ese ID: %d\n", legajo);
				}
				else
				{
					systemCls();
					mostrarJugador(vecJugador[indice], vecConfederacion,tamConfederaciones );
					modificar=subMenuModificarJugadores();
					switch(modificar)
					{
						case 1:
							utn_getString(auxJugador.nombre, "\nIngrese nuevo nombre de su jugador:", "\nError\n");
							fflush(stdin);
							utn_getCharSeguir(&confirma, "\nConfirma modificacion?: ", "\nError, ingrese una opcion valida s/n (si/no):", 3);
							if(confirma == 's')
							{
								strcpy(vecJugador[indice].nombre, auxJugador.nombre);
								mostrarJugador(vecJugador[indice], vecConfederacion,tamConfederaciones);
								printf("\n\nModificacion exitosa.\n\n");
							}
							else
							{
								printf("\n\nSe ha cancelado la modificacion.\n\n");
							}
							break;

						case 2:
							systemCls();
							mostrarPosiciones();
							utn_getInt(&idPosicion, "\nIngrese nueva posicion de su jugador:", "\nError\n", 1, 4, 3);
							cargarDescripcionPosicion(idPosicion, &auxJugador);
							utn_getCharSeguir(&confirma, "\nConfirma modificacion?: ", "\nError, ingrese una opcion valida s/n (si/no):", 3);
							if(confirma == 's')
							{
								cargarDescripcionPosicion(idPosicion, &auxJugador);
								strcpy(vecJugador[indice].posicion, auxJugador.posicion);
								mostrarJugador(vecJugador[indice], vecConfederacion,tamConfederaciones);
								printf("\n\nModificacion exitosa.\n\n");
							}
							else
							{
								printf("\n\nSe ha cancelado la modificacion.\n\n");
							}
							break;

						case 3:
							utn_getShort(&auxJugador.numeroCamiseta,"\nIngrese nuevo numero de camiseta: ", "\nError\n", 1, 99, 3);
							utn_getCharSeguir(&confirma, "\nConfirma modificacion?: ", "\nError, ingrese una opcion valida s/n (si/no):", 3);
							if(confirma == 's')
							{

								vecJugador[indice].numeroCamiseta=auxJugador.numeroCamiseta;
								mostrarJugador(vecJugador[indice], vecConfederacion,tamConfederaciones);
								printf("\n\nModificacion exitosa.\n\n");
							}
							else
							{
								printf("\n\nSe ha cancelado la modificacion.\n\n");
							}
							break;
						case 4:
							utn_getFloat(&auxJugador.salario, "\nIngrese nuevo salario:", "\nError\n", 1, 999999, 3);
							utn_getCharSeguir(&confirma, "\nConfirma modificacion?: ", "\nError, ingrese una opcion valida s/n (si/no):", 3);
							if(confirma == 's')
							{

								vecJugador[indice].salario=auxJugador.salario;
								mostrarJugador(vecJugador[indice], vecConfederacion,tamConfederaciones);
								printf("\n\nModificacion exitosa.\n\n");
							}
							else
							{
								printf("\n\nSe ha cancelado la modificacion.\n\n");
							}
							break;
						case 5:
							systemCls();
							mostrarConfederaciones(vecConfederacion, tamConfederaciones);
							utn_getInt(&auxJugador.idConfederacion, "\nIngrese id de nueva confederacion:", "\nError\n", 100, 105, 3);
							utn_getCharSeguir(&confirma, "\nConfirma modificacion?: ", "\nError, ingrese una opcion valida s/n (si/no):", 3);
							if(confirma == 's')
							{

								vecJugador[indice].idConfederacion=auxJugador.idConfederacion;
								mostrarJugador(vecJugador[indice], vecConfederacion,tamConfederaciones);
								printf("\n\nModificacion exitosa.\n\n");
							}
							else
							{
								printf("\n\nSe ha cancelado la modificacion.\n\n");
							}
							break;
						case 6:
							utn_getShort(&auxJugador.aniosContrato,"\nIngrese nuevo anios de contrato:", "\nError\n", 1, 5, 3);
							utn_getCharSeguir(&confirma, "\nConfirma modificacion?: ", "\nError, ingrese una opcion valida s/n (si/no):", 3);
							if(confirma == 's')
							{

								vecJugador[indice].aniosContrato=auxJugador.aniosContrato;
								mostrarJugador(vecJugador[indice], vecConfederacion,tamConfederaciones);
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
					mostrarJugador(vecJugador[indice], vecConfederacion,tamConfederaciones);
					utn_getCharSeguir(&seguir, "Desea cambiar otra area?:", "\nError, ingrese una opcion valida s/n (si/no)", 4);

				}

			}while(seguir!='n');
		}
		todoOk = 1;
	}

	return todoOk;

}

/////////////////////////////////////////////////BUSCAR///////////////////////////////////////////////////////////////////////////////////////////

int buscarJugador(int* pIndice, int legajo, eJugador vec[], int tam)
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

//////////////////////////////////////////////////////////BAJA///////////////////////////////////////////////////////////////////////////////////////////

int bajaJugadores(eJugador vecJugador[], eConfederacion vecConfederacion[], int tamJugadores, int tamConfederaciones)
{
	systemCls();
    int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    int flag;//para ver si hay o no gente para dar de baja
    if(vecJugador != NULL && vecConfederacion != NULL && tamJugadores > 0 && tamConfederaciones > 0 )
    {
        printf("**** Baja Mascota ****\n\n");

        flag=mostrarJugadores(vecJugador,vecConfederacion, tamJugadores,tamConfederaciones);
		if(flag==-1)
		{
			printf("Primero debe haber una alguna mascota dado de alta para realizar una baja\n\n");
		}
		else
		{
			utn_getInt(&legajo, "\nIngrese el Id del jugador que desea modificar: ", "\nError, elija un id valido: ", 0, 1000, 3);
			buscarJugador(&indice, legajo, vecJugador, tamJugadores);

			while(indice == -1)
			{
				printf("No existe un jugador con ese legajo: %d\n", legajo);
				utn_getCharSeguir(&confirma, "\nConfirma modificacion?: ", "\nError, ingrese una opcion valida s/n (si/no):", 3);
				buscarJugador(&indice, legajo, vecJugador, tamConfederaciones);
			}

			systemCls();
			mostrarJugador(vecJugador[indice], vecConfederacion, tamJugadores);
			utn_getCharSeguir(&confirma, "\nConfirma modificacion?: ", "\nError, ingrese una opcion valida s/n (si/no):", 3);
			if(confirma == 's')
			{
				vecJugador[indice].isEmpty = 1;
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



/////////////////////////////////////////////////////ORDENAR/////////////////////////////////////////////////////////////////////////////////////////////

int ordenarJugadores(eJugador vecJugador[], eConfederacion vecConfederacion[], int tamJugadores, int tamConfederaciones)
{
	int todoOk=0;
	int opcionOrdenar;
	int flag;

	if(vecJugador != NULL && vecConfederacion != NULL &&  tamJugadores > 0 && tamConfederaciones >0)
	{

		systemCls();
		flag=mostrarJugadores(vecJugador,vecConfederacion,tamJugadores ,tamConfederaciones);
		if(flag==-1)
		{
			printf("Primero debe haber dado de alta para realizar una modificacion\n\n");
		}
		else
		{
			opcionOrdenar=subMenuMostrarJugadores();
			switch(opcionOrdenar)
			{
				case 1:
					ordenarJugadorPorConfederacion(vecJugador,vecConfederacion,tamJugadores ,tamConfederaciones);
					mostrarJugadores(vecJugador, vecConfederacion, tamJugadores, tamConfederaciones);
					break;
				case 2:
					mostrarJugadoresPorConfederacion(vecJugador,vecConfederacion,tamJugadores ,tamConfederaciones);
					break;
				case 3:
					totalYPromedioTodosSalarios(vecJugador,vecConfederacion,tamJugadores ,tamConfederaciones);
					break;
				case 4:
					confederacionMayorAniosDeContrato(vecJugador, vecConfederacion, tamJugadores, tamConfederaciones);
					break;
				case 5:
					porcentajeJugadoresPorConfederacion(vecJugador, vecConfederacion, tamJugadores, tamConfederaciones);
					break;
				case 6:
					mostrarRegionMasJugadores(vecJugador, vecConfederacion, tamJugadores, tamConfederaciones);
					break;
			}
			todoOk=1;
		}
	}
	return todoOk;
}



/////////////////////////////////////////////////HARDCODEAR///////////////////////////////////////////////////////////////////////////////////////////
int hardcodearJugadores(int* pLegajo ,eJugador vec[], int tam, int cant)
{
	/*int cant, es la cantidad que quiero que me cargue.
	 * porque el vector puede ser de 10.000, pero que me cargue 10 nomas*/
    int todoOk = 0;

    eJugador jugadores[] =
	{
		{1, "Lionel Messi", "delantero", 10, 101, 10.10, 2, 0},
		{2, "Enzo Copetti","arquero", 1, 100, 1000.40, 1, 0},
		{3, "Ngolo Kante", "medio", 7, 101, 1025.50, 6, 0},
		{4, "Mohamed El Shenawy", "delantero", 9, 103, 2000.50, 3, 0},
		{5, "Wayne Rooney", "medio", 6, 104, 18.22, 2, 0},
		{6, "Cristiano Ronaldo", "delantero", 7, 101, 150.10, 2, 0},
		{7, "Mehamed Mehamed","defensa", 1, 103, 107.71, 1, 0},
		{8, "Haaland", "delantero", 9, 105, 110.53, 6, 0},
		{9, "Buffon", "arquero", 1, 101, 2100.50, 5, 0},
		{10, "Ortigoza", "medio", 6, 100, 1000.20, 2, 0}
	};

    if(vec != NULL && tam > 0 && cant <= tam && cant <= 10)
    {

      for(int i = 0 ; i < cant ; i++){

      vec[i] = jugadores[i];
      *pLegajo = *pLegajo + 1;
      }
        todoOk = 1;
    }
    return todoOk;
}


