/*
 * output.c
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




void systemCls()
{
	for(int i=0; i<50;i++)
	{
		printf("\n\n\n");
	}
}
void systemPause()
{
	char seguir[50];
	printf("presione enter para continuar");
	fflush(stdin);
	gets(seguir);
}

////////////////////////////////////////////////////////MENUS///////////////////////////////////////////////////////////////////////////////////////////////////


int menu()
{
	int opcion;
	int auxOpcion;
	printf("\n         #############################################################");
	printf("\n         *                                                           *");
	printf("\n         *                 - Trabajo Practico Nro. 2 -               *");
	printf("\n         *                                                           *");
	printf("\n         *                   >>     Jugadores     <<                 *");
	printf("\n         *                                                           *");
	printf("\n         *                       x Mendez Luca x                     *");
	printf("\n         *                                                           *");
	printf("\n         #############################################################");
	printf("\n         |                                                           |");
	printf("\n             1 - Altas");
	printf("\n         |                                                           |");
	printf("\n             2 - Bajas");
	printf("\n         |                                                           |");
	printf("\n             3 - Modificaciones");
	printf("\n         |                                                           |");
	printf("\n             4 - Informes");
	printf("\n         |                                                           |");
	printf("\n             5 - Salir");
	printf("\n         |                                                           |");
	printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	printf("\n");
	utn_getInt(&auxOpcion, "\t Ingrese una opcion: ", "\n\t Error ingrese una opcion valida(1 al 5)\n", 1, 5, 3);
	opcion=auxOpcion;

	return opcion;
}



int subMenuModificarJugadores()
{
	int opcion;
	int auxOpcion;
	printf("\n         #############################################################");
	printf("\n         *                                                           *");
	printf("\n         *                 - Trabajo Practico Nro. 2 -               *");
	printf("\n         *                                                           *");
	printf("\n         *                  >> Modificar Jugadores  <<               *");
	printf("\n         *                                                           *");
	printf("\n         *                      x Mendez Luca x                      *");
	printf("\n         *                                                           *");
	printf("\n         #############################################################");
	printf("\n         |                                                           |");
	printf("\n             1 - Nombre");
	printf("\n         |                                                           |");
	printf("\n             2 - Posicion");
	printf("\n         |                                                           |");
	printf("\n             3 - N° de Camiseta");
	printf("\n         |                                                           |");
	printf("\n             4 - Sueldo");
	printf("\n         |                                                           |");
	printf("\n             5 - Confederacion");
	printf("\n         |                                                           |");
	printf("\n             6 - Contrato");
    printf("\n         |                                                           |");
	printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	printf("\n");
	utn_getInt(&auxOpcion, "\t Ingrese una opcion: ", "\n\t Error ingrese una opcion valida(1 al 6)\n", 1, 6, 3);
	opcion=auxOpcion;

	return opcion;
}
int subMenuModificarConfederaciones()
{
	int opcion;
	int auxOpcion;
	printf("\n         #############################################################");
	printf("\n         *                                                           *");
	printf("\n         *                 - Trabajo Practico Nro. 2 -               *");
	printf("\n         *                                                           *");
	printf("\n         *                 >>Modificar Confederaciones<<             *");
	printf("\n         *                                                           *");
	printf("\n         *                      x Mendez Luca x                      *");
	printf("\n         *                                                           *");
	printf("\n         #############################################################");
	printf("\n         |                                                           |");
	printf("\n             1 - Nombre");
	printf("\n         |                                                           |");
	printf("\n             2 - Region");
	printf("\n         |                                                           |");
	printf("\n             3 - Anios de creacion");
	printf("\n         |                                                           |");
	printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	printf("\n");
	utn_getInt(&auxOpcion, "\t Ingrese una opcion: ", "\n\t Error ingrese una opcion valida(1 al 3)\n", 1, 3, 3);
	opcion=auxOpcion;

	return opcion;
}

int subMenuMostrarJugadores()
{
	int opcion;
	int auxOpcion;
	printf("\n         #############################################################");
	printf("\n         *                                                           *");
	printf("\n         *                 - Trabajo Practico Nro. 2 -               *");
	printf("\n         *                                                           *");
	printf("\n         *                  >> Ordenar jugadores   <<                *");
	printf("\n         *                                                           *");
	printf("\n         *                      x Mendez Luca x                      *");
	printf("\n         *                                                           *");
	printf("\n         #############################################################");
	printf("\n         |                                                           |");
	printf("\n             1 - Por nombre de Confederacion.");
	printf("\n         |                                                           |");
	printf("\n             2 - Listado de confederacion con sus jugadores.");
	printf("\n         |                                                           |");
	printf("\n             3 - Total y promedio de todos los salarios.");
	printf("\n         |                                                           |");
	printf("\n             4 - Confederación mayor cantidad de años de contratos.");
	printf("\n         |                                                           |");
	printf("\n             5 - Porcentaje de jugadores por cada confederación.");
	printf("\n         |                                                           |");
	printf("\n             6 - La región con más jugadores.");
    printf("\n         |                                                           |");
	printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	printf("\n                                                                      ");
	utn_getInt(&auxOpcion,"\n\t Ingrese una opcion: ", "\n\t Error ingrese una opcion valida(1 al 2)\n", 1, 6, 3);
	opcion=auxOpcion;

	return opcion;
}

int subMenuAlta()
{
	int opcion;
	int auxOpcion;
	printf("\n         #############################################################");
	printf("\n         *                                                           *");
	printf("\n         *                 - Trabajo Practico Nro. 2 -               *");
	printf("\n         *                                                           *");
	printf("\n         *                  >>  SubMenu Alta   <<                    *");
	printf("\n         *                                                           *");
	printf("\n         *                      x Mendez Luca x                      *");
	printf("\n         *                                                           *");
	printf("\n         #############################################################");
	printf("\n         |                                                           |");
	printf("\n             1 - Jugadores");
	printf("\n         |                                                           |");
	printf("\n             2 - Confederaciones");
	printf("\n         |                                                           |");
	printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	printf("\n");
	utn_getInt(&auxOpcion, "\t Ingrese una opcion: ", "\n\t Error ingrese una opcion valida(1 al 2)\n", 1, 2, 3);
	opcion=auxOpcion;

	return opcion;
}
int subMenuModificar()
{
	int opcion;
	int auxOpcion;
	printf("\n         #############################################################");
	printf("\n         *                                                           *");
	printf("\n         *                 - Trabajo Practico Nro. 2 -               *");
	printf("\n         *                                                           *");
	printf("\n         *                  >>  SubMenu Modificar   <<               *");
	printf("\n         *                                                           *");
	printf("\n         *                      x Mendez Luca x                      *");
	printf("\n         *                                                           *");
	printf("\n         #############################################################");
	printf("\n         |                                                           |");
	printf("\n             1 - Jugadores");
	printf("\n         |                                                           |");
	printf("\n             2 - Confederaciones");
	printf("\n         |                                                           |");
	printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	printf("\n");
	utn_getInt(&auxOpcion, "\t Ingrese una opcion: ", "\n\t Error ingrese una opcion valida(1 al 2)\n", 1, 2, 3);
	opcion=auxOpcion;

	return opcion;
}

int subMenuBaja()
{
	int opcion;
	int auxOpcion;
	printf("\n         #############################################################");
	printf("\n         *                                                           *");
	printf("\n         *                 - Trabajo Practico Nro. 2 -               *");
	printf("\n         *                                                           *");
	printf("\n         *                  >>   SubMenu Baja     <<                 *");
	printf("\n         *                                                           *");
	printf("\n         *                      x Mendez Luca x                      *");
	printf("\n         *                                                           *");
	printf("\n         #############################################################");
	printf("\n         |                                                           |");
	printf("\n             1 - Jugadores");
	printf("\n         |                                                           |");
	printf("\n             2 - Confederaciones");
	printf("\n         |                                                           |");
	printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	printf("\n");
	utn_getInt(&auxOpcion, "\t Ingrese una opcion: ", "\n\t Error ingrese una opcion valida(1 al 2)\n", 1, 2, 3);
	opcion=auxOpcion;

	return opcion;
}

void cerrandoMenu()
{

	printf("\n         #######################################################################");
	printf("\n         *                                                                     *");
	printf("\n         *                    - Trabajo Practico Nro. 2 -                      *");
	printf("\n         *                                                                     *");
	printf("\n         *                  >>Jugadores Y Confederaciones    <<                *");
	printf("\n         *                                                                     *");
	printf("\n         *                        x Mendez Luca x                              *");
	printf("\n         *                                                                     *");
	printf("\n         #######################################################################");
	printf("\n         |                                                                     |");
	printf("\n         |            *          * * *        *       * * *      * * * *       |");
	printf("\n         |           * *         *    *             *       *   *              |");
	printf("\n         |          *   *        *     *      *    *         *  *              |");
	printf("\n         |         *     *       *      *     *    *         *  *              |");
	printf("\n         |        * * * * *      *      *     *    *         *    * * * *      |");
	printf("\n         |       *         *     *      *     *    *         *           *     |");
	printf("\n         |      *           *    *     *      *    *         *           *     |");
	printf("\n         |     *             *   *    *       *     *       *           *      |");
	printf("\n         |    *               *  * * *        *       * * *      * * * *       |");
	printf("\n         |                                                                     |");
	printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	printf("\n");
}
////////////////////////////////////////////////////////MOSTRAR///////////////////////////////////////////////////////////////////////////////////////////////////

int mostrarJugadores(eJugador vecJugadores[], eConfederacion vecConfederaciones[] ,int tamJugadores, int tamConfederaciones)
{
	systemCls();
    int todoOk = 0;
    int flag = 1;

    if(vecJugadores != NULL && vecConfederaciones != NULL && tamJugadores > 0 && tamConfederaciones > 0 )
    {

        printf("                          **** LISTA DE JUGADORES ****\n");
        printf("------------|------------------------|------------------------|-----------------|------------------------|------------------------|----------------|\n");
        printf("ID JUGADOR  |              NOMBRE    |             POSICION   |    N°CAMISETA   |         SUELDO         |      CONFEDERACION     |AÑOS DE CONTRATO|\n");
        printf("------------|------------------------|------------------------|-----------------|------------------------|------------------------|----------------|\n");
        for(int i = 0 ; i < tamJugadores ; i++)
        {
            if(!vecJugadores[i].isEmpty)
            {
				mostrarJugador(vecJugadores[i], vecConfederaciones, tamConfederaciones);
				flag = 0;
				todoOk = 1;
            }
        }
        if(flag)
        {
            printf("\n*****************NO HAY JUGADORES EN EL SISTEMA*****************\n\n");
            todoOk=-1;
        }
	}

    return todoOk;
}

int mostrarJugador(eJugador jugador, eConfederacion vecConfederacion[], int tamConfederaciones )
{
    int todoOk = 0;
    char confederacion[20];

    cargarDescripcionConfederacion(jugador.idConfederacion, confederacion,vecConfederacion, tamConfederaciones);

    printf("%4d        |    %20s|    %20s|        %2hu       |     %15.2f    |      %15s   |      %2hu        |\n",
    		jugador.id,
			jugador.nombre,
			jugador.posicion,
			jugador.numeroCamiseta,
			jugador.salario,
			confederacion,
			jugador.aniosContrato);

    return todoOk;
}

int mostrarConfederaciones(eConfederacion vecConfederaciones[], int tamConfederaciones)
{
    int todoOk = 0;
    int flag = 1;

    if( vecConfederaciones != NULL && tamConfederaciones > 0 )
    {

    	printf("                      ***Lista de confederaciones***                    \n");
    	printf("----|-------------------|-----------------------------|----------------|\n");
    	printf(" ID |            Nombre |            Region           |Anio de Creacion|\n");
    	printf("----|-------------------|-----------------------------|----------------|\n");
    	 for(int i = 0 ; i < tamConfederaciones ; i++)
    	 {
			if(!vecConfederaciones[i].isEmpty)
			{
				mostrarConfederacion(vecConfederaciones[i], tamConfederaciones);
				flag = 0;
				todoOk = 1;
			}
			}
			if(flag)
			{
				printf("\n*****************NO HAY CONFEDERACIONES EN EL SISTEMA*****************\n\n");
				todoOk=-1;
			}

		}

    return todoOk;
}
int mostrarConfederacion(eConfederacion vecConfederaciones, int tamConfederaciones)
{
	int todoOk = 0;

	printf("%4d|%19s|   %25s |       %4d     |\n",
			vecConfederaciones.id,
			vecConfederaciones.nombre,
			vecConfederaciones.region,
			vecConfederaciones.anioCreacion);

	return todoOk;
}

int mostrarPosiciones()
{
	int todoOk = 0;
    printf("     ***Lista de posiciones*** \n");
	printf("----|------------------------|\n");
	printf(" ID |  Nombre de posiciones  |\n");
	printf("----|------------------------|\n");
	printf("  1 |         Arquero        |\n");
	printf("----|------------------------|\n");
	printf("  2 |         Defensa        |\n");
	printf("----|------------------------|\n");
	printf("  3 |      MedioCampista     |\n");
	printf("----|------------------------|\n");
	printf("  4 |        Delantero       |\n");
	printf("----|------------------------|\n");


	return todoOk;
}
int mostrarRegiones()
{
	int todoOk = 0;
    printf("     ***Lista de posiciones*** \n");
	printf("----|------------------------|\n");
	printf(" ID |  Nombre de posiciones  |\n");
	printf("----|------------------------|\n");
	printf("  1 |       Sudamerica       |\n");
	printf("----|------------------------|\n");
	printf("  2 |         Europa         |\n");
	printf("----|------------------------|\n");
	printf("  3 |          Asia          | \n");
	printf("----|------------------------|\n");
	printf("  4 |         Africa         |\n");
	printf("----|------------------------|\n");
	printf("  5 | Norte y Centro America |\n");
	printf("----|------------------------|\n");
	printf("  6 |        Oceania         |\n");
	printf("----|------------------------|\n");

	return todoOk;
}


int ordenarJugadorPorConfederacion(eJugador vecJugador[], eConfederacion vecConfederacion[], int tamJugadores, int tamConfederaciones)
{
	int todoOk=0;
	int i;
	int j;
	int iConfe;
	int jConfe;
	eJugador auxJugador;

	if(vecJugador != NULL && vecConfederacion != NULL &&  tamJugadores > 0 && tamConfederaciones >0)
	{
		for (i=0; i<tamJugadores-1; i++)
		{
			for(j=i+1; j<tamJugadores; j++)
			{
				iConfe=buscarConfederacion(vecConfederacion, vecJugador[i].idConfederacion, tamConfederaciones);
				jConfe=buscarConfederacion(vecConfederacion, vecJugador[j].idConfederacion, tamConfederaciones);
				if(strcmp(vecConfederacion[iConfe].nombre, vecConfederacion[jConfe].nombre) > 0)
				{
					auxJugador = vecJugador[i];
					vecJugador[i] = vecJugador[j];
					vecJugador[j] = auxJugador;
				}
			    else
				{
					if(strcmp(vecConfederacion[iConfe].nombre, vecConfederacion[jConfe].nombre) == 0)
					{
						if(strcmp(vecJugador[i].nombre, vecJugador[j].nombre) > 0)
						{
							auxJugador = vecJugador[i];
							vecJugador[i] = vecJugador[j];
							vecJugador[j] = auxJugador;
						}
					}
				}
			}
		}
		todoOk=1;
	}
	return todoOk;
}


int mostrarJugadoresPorConfederacion(eJugador vecJugador[], eConfederacion vecConfederacion[],int tamJugadores, int tamConfederaciones)
{
	systemCls();
	int todoOk=0;
	int flag;
	if(vecJugador != NULL && vecConfederacion != NULL && tamJugadores > 0 && tamConfederaciones > 0)
	{
		for(int i=0; i<tamConfederaciones;i++)
		{

			printf("\n\n\n                                        CONFEDERACION:%8s                           \n", vecConfederacion[i].nombre);
			printf("                                        **** LISTA DE JUGADORES ****\n");
			printf("------------|------------------------|------------------------|-----------------|------------------------|------------------------|----------------|\n");
			printf("ID JUGADOR  |              NOMBRE    |             POSICION   |    N°CAMISETA   |         SUELDO         |      CONFEDERACION     |AÑOS DE CONTRATO|\n");
			printf("------------|------------------------|------------------------|-----------------|------------------------|------------------------|----------------|\n");

			flag=1;
			for(int j=0; j < tamJugadores;j++)
			{
				if(!vecJugador[j].isEmpty && vecJugador[j].idConfederacion == vecConfederacion[i].id)
				{
					mostrarJugador(vecJugador[j], vecConfederacion ,tamConfederaciones);
					flag=0;
				}

			}
			if(flag)
			{
				printf("                                  No hay ningun jugador de la confederacion: %s\n", vecConfederacion[i].nombre);
			}
		}
	}
	return todoOk;
}


int totalYPromedioTodosSalarios(eJugador vecJugador[], eConfederacion vecConfederacion[],int tamJugadores, int tamConfederaciones)
{
	systemCls();
	int todoOk=0;
	float acumuladorSalario=0;
	int contadorJugadores=0;
	int contadorJugadoresPromedio=0;
	float promedio;
	int flag;
	if(vecJugador != NULL && vecConfederacion != NULL && tamJugadores > 0 && tamConfederaciones > 0)
	{
		mostrarJugadores(vecJugador, vecConfederacion, tamJugadores, tamConfederaciones);

		for(int i=0; i<tamJugadores;i++)
		{
			if(!vecJugador[i].isEmpty && vecJugador[i].salario > 0)
			{
				acumuladorSalario=acumuladorSalario+vecJugador[i].salario;
				contadorJugadores++;
			}
		}

		promedio=(float)acumuladorSalario/contadorJugadores;

		printf("\nEl total entre todos los salarios es %.2f", acumuladorSalario);
		printf("\nLa cantidad de jugadores que hay ingresadas en el sistemas es %d\n", contadorJugadores);
		printf("El promedio del salario de los jugadores es: %.2f\n", promedio);


		printf("\n             **** LISTA DE JUGADORES QUE SUPERAN SALARIO PROMEDIO ****\n");
		printf("------------|------------------------|------------------------|-----------------|------------------------|------------------------|----------------|\n");
		printf("ID JUGADOR  |              NOMBRE    |             POSICION   |    N°CAMISETA   |         SUELDO         |      CONFEDERACION     |AÑOS DE CONTRATO|\n");
		printf("------------|------------------------|------------------------|-----------------|------------------------|------------------------|----------------|\n");
		flag=1;
		for(int i=0; i<tamJugadores;i++)
		{
			if(!vecJugador[i].isEmpty && vecJugador[i].salario > promedio)
			{
				mostrarJugador(vecJugador[i], vecConfederacion, tamConfederaciones);
				contadorJugadoresPromedio++;
				flag=0;
			}
		}
		if(flag)
		{
			printf("                          No hay ningun jugador que supere el salario promedio \n");
		}
		else
		{
			if(!flag)
			{
				printf("\nLa cantidad de jugadores que superan el salario promedio es %d\n", contadorJugadoresPromedio);
			}
		}
	}
	return todoOk;
}


int confederacionMayorAniosDeContrato(eJugador vecJugador[], eConfederacion vecConfederacion[],int tamJugadores, int tamConfederaciones)
{
	systemCls();
	int todoOk=0;
	int acumuladores[tamConfederaciones];
	int mayor;
	if(vecJugador != NULL && vecConfederacion != NULL && tamJugadores > 0 && tamConfederaciones > 0)
	{
		for(int i=0; i<tamConfederaciones;i++)
		{
			acumuladores[i]=0;
		}

		for(int i=0; i<tamConfederaciones;i++)
		{
			for(int j=0; j < tamJugadores;j++)
			{
				if(!vecConfederacion[i].isEmpty && !vecJugador[j].isEmpty && vecJugador[j].idConfederacion == vecConfederacion[i].id)
				{
					acumuladores[i]=acumuladores[i]+vecJugador[j].aniosContrato;
				}
			}
		}
		for(int i=0; i<tamConfederaciones;i++)
		{
			if(i==0 || acumuladores[i]>mayor)
			{
				mayor=acumuladores[i];
			}
		}

		for(int i=0; i<tamConfederaciones;i++)
		{
			if(!vecJugador[i].isEmpty && acumuladores[i]==mayor)
			{
				mostrarJugadores(vecJugador, vecConfederacion, tamJugadores, tamConfederaciones);
				printf("\n\nLa confederacion con mayor cantidad de anios de contrato es:\n");
				printf("%s: %d\n\n", vecConfederacion[i].nombre, mayor);
				printf("                       ***Lista jugadores de la confederacion %s***\n",  vecConfederacion[i].nombre);
				printf("------------|------------------------|------------------------|-----------------|------------------------|------------------------|----------------|\n");
				printf("ID JUGADOR  |              NOMBRE    |             POSICION   |    N°CAMISETA   |         SUELDO         |      CONFEDERACION     |AÑOS DE CONTRATO|\n");
				printf("------------|------------------------|------------------------|-----------------|------------------------|------------------------|----------------|\n");
				for(int j=0; j < tamJugadores;j++)
				{
					if(vecConfederacion[i].id == vecJugador[j].idConfederacion)
					{

						mostrarJugador(vecJugador[j], vecConfederacion, tamConfederaciones);
					}
				}
			}
		}
	}
	return todoOk;
}


int porcentajeJugadoresPorConfederacion(eJugador vecJugador[], eConfederacion vecConfederacion[],int tamJugadores, int tamConfederaciones)
{
	systemCls();
	int todoOk=0;
	int contadores[tamConfederaciones];
	int contadorJugadores=0;
	float porcentaje;

	if(vecJugador != NULL && vecConfederacion != NULL && tamJugadores > 0 && tamConfederaciones > 0)
	{
		for(int i=0; i<tamConfederaciones;i++)
		{
			contadores[i]=0;
		}
		for(int i=0; i<tamConfederaciones;i++)
		{
			for(int j=0; j < tamJugadores;j++)
			{
				if(!vecConfederacion[i].isEmpty && !vecJugador[j].isEmpty )
				{
					if(vecJugador[j].idConfederacion == vecConfederacion[i].id)
					{
						contadores[i]++;
					}
				}
			}
		}
		for(int i=0; i<tamJugadores;i++)
		{
			if(!vecJugador[i].isEmpty)
			{
				contadorJugadores++;
			}
		}

		for(int i=0; i<tamConfederaciones;i++)
		{
			if(!vecConfederacion[i].isEmpty)
			{
				printf("                       ***Lista jugadores de la confederacion %s***\n",  vecConfederacion[i].nombre);
				printf("------------|------------------------|------------------------|-----------------|------------------------|------------------------|----------------|\n");
				printf("ID JUGADOR  |              NOMBRE    |             POSICION   |    N°CAMISETA   |         SUELDO         |      CONFEDERACION     |AÑOS DE CONTRATO|\n");
				printf("------------|------------------------|------------------------|-----------------|------------------------|------------------------|----------------|\n");
				for(int j=0; j < tamJugadores;j++)
				{
					if(!vecConfederacion[i].isEmpty && !vecJugador[j].isEmpty && vecConfederacion[i].id == vecJugador[j].idConfederacion)
					{
						mostrarJugador(vecJugador[j], vecConfederacion, tamConfederaciones);
					}
					porcentaje=(float)(contadores[i]*100)/contadorJugadores;
				}
				printf("\nel porcentaje de jugadores que hay de esta region es: %.2f%c\n\n\n",porcentaje,37);
			}

		}

	}
	return todoOk;
}

int mostrarRegionMasJugadores(eJugador vecJugador[], eConfederacion vecConfederaciones[],int tamJugadores, int tamConfederaciones)
{
	systemCls();
	int todoOk=0;
	int contadores[tamConfederaciones];
	int mayor;
	if(vecJugador != NULL && vecConfederaciones != NULL && tamJugadores > 0 && tamConfederaciones > 0)
	{

		for(int i=0; i<tamConfederaciones;i++)
		{
			contadores[i]=0;
		}

		for(int i=0; i<tamConfederaciones;i++)
		{
			for(int j=0; j < tamJugadores;j++)
			{
				if(!vecJugador[j].isEmpty && vecJugador[j].idConfederacion == vecConfederaciones[i].id)
				{
					contadores[i]++;
				}
			}
		}

		for(int i=0; i<tamConfederaciones;i++)
		{
			if(i==0 || contadores[i]>mayor)
			{
				mayor=contadores[i];
			}
		}


		for(int i=0; i<tamConfederaciones;i++)
		{
			if(!vecConfederaciones[i].isEmpty && contadores[i]==mayor)
			{
				mostrarJugadores(vecJugador, vecConfederaciones, tamJugadores, tamConfederaciones);
				printf("\n\nLa mayoria de los jugadores son de la region:\n");
				printf("%s: %d\n\n", vecConfederaciones[i].region, mayor);
				printf("                       ***Lista de jugadores de la region: %s***\n",  vecConfederaciones[i].region);
				printf("------------|------------------------|------------------------|-----------------|------------------------|------------------------|----------------|\n");
				printf("ID JUGADOR  |              NOMBRE    |             POSICION   |    N°CAMISETA   |         SUELDO         |      CONFEDERACION     |AÑOS DE CONTRATO|\n");
				printf("------------|------------------------|------------------------|-----------------|------------------------|------------------------|----------------|\n");				for(int j=0; j < tamJugadores;j++)
				{

					if(!vecJugador[j].isEmpty && vecConfederaciones[i].id == vecJugador[j].idConfederacion)
					{
						mostrarJugador(vecJugador[j], vecConfederaciones, tamConfederaciones);
					}
				}
			}
		}
	}
	return todoOk;
}
