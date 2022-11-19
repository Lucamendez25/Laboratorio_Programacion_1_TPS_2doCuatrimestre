#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "utn.h"

Jugador* jug_new()
{
	return malloc(sizeof(Jugador));
}
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr)
{
	Jugador* unJugador;
	int todoOk;

	unJugador = jug_new();

	if(unJugador != NULL && idStr != NULL && nombreCompletoStr != NULL
	&& edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL
	&& idSeleccionStr != NULL)
	{
		if(jug_setId(unJugador, atoi(idStr))==0 &&
		   jug_setNombreCompleto(unJugador, nombreCompletoStr)==0 &&
		   jug_setEdad(unJugador, atoi(edadStr))==0 &&
		   jug_setPosicion(unJugador, posicionStr)==0&&
		   jug_setNacionalidad(unJugador, nacionalidadStr)==0&&
		   jug_setIdSeleccion(unJugador ,atoi(idSeleccionStr))==0)
		{
			todoOk=1;
		}

	}
	if(!todoOk)
	{
		free(unJugador);
		unJugador=NULL;
		printf("\nNo se pudo asignar memoria..\n");
	}

	return unJugador;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Jugador_delete(Jugador* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int jug_setId(Jugador* this,int id)
{
	int retorno=-1;

	if(this != NULL && id > 0 )
	{
		retorno = 0;
		this->id = id;
	}

	return retorno;
}

int jug_getId(Jugador* this,int* id)
{
	int retorno=-1;

	if(this != NULL)
	{
		retorno = 0;
		*id = this->id;
	}

	return retorno;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
    int retorno = -1;

    if(this != NULL && nombreCompleto != NULL && strlen(nombreCompleto) > 2 )
    {
        strcpy(this->nombreCompleto, nombreCompleto);

        retorno = 0;
    }

    return retorno;
}

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno=-1;

	if(this != NULL && nombreCompleto != NULL)
	{
		strcpy(nombreCompleto,this->nombreCompleto);

		retorno = 0;
	}

	return retorno;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int jug_setEdad(Jugador* this,int edad)
{
	int retorno=-1;

	if(this != NULL && edad > 0)
	{
		retorno = 0;
		this->edad = edad;
	}

	return retorno;
}

int jug_getEdad(Jugador* this,int* edad)
{
	int retorno=-1;

	if(this != NULL)
	{
		retorno = 0;
		*edad = this->edad;
	}

	return retorno;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int jug_setPosicion(Jugador* this,char* posicion)
{
    int retorno = -1;

    if(this != NULL && posicion != NULL && strlen(posicion) > 2 )
    {
        strcpy(this->posicion, posicion);

        retorno = 0;
    }

    return retorno;
}

int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno=-1;

	if(this != NULL && posicion != NULL)
	{
		strcpy(posicion,this->posicion);

		retorno = 0;
	}

	return retorno;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
    int retorno = -1;

    if(this != NULL && nacionalidad != NULL && strlen(nacionalidad) > 2 )
    {
        strcpy(this->nacionalidad, nacionalidad);

        retorno = 0;
    }

    return retorno;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno=-1;

	if(this != NULL && nacionalidad != NULL)
	{
		strcpy(nacionalidad,this->nacionalidad);

		retorno = 0;
	}

	return retorno;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno=-1;

	if(this != NULL && idSeleccion > -1)
	{
		retorno = 0;
		this->idSeleccion = idSeleccion;
	}

	return retorno;
}

int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno=-1;

	if(this != NULL)
	{
		*idSeleccion = this->idSeleccion;
		retorno = 0;
	}

	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Jugador_mostrar(Jugador* unJugador, LinkedList* pArrayListSeleccion)
{
	int auxId;
	char auxNombreCompleto[100];
	int auxEdad=0;
	char auxPosicion[30];
	char auxNacionalidad[30];
	int auxIdSeleccion;
	char seleccionStr[30];


	jug_getId(unJugador, &auxId);
	jug_getNombreCompleto(unJugador, auxNombreCompleto);
	jug_getEdad(unJugador, &auxEdad);
	jug_getPosicion(unJugador, auxPosicion);
	jug_getNacionalidad(unJugador, auxNacionalidad);
	jug_getSIdSeleccion(unJugador, &auxIdSeleccion);
	Jugador_CargarDescripcionConvocatoria(seleccionStr, auxIdSeleccion, pArrayListSeleccion);



	if(unJugador != NULL)
	{
		printf("|%4d        | %30s|    %4d|  %20s|     %15s |%20s|\n",
				auxId,auxNombreCompleto,auxEdad,auxPosicion, auxNacionalidad,seleccionStr);
	}
	else
	{
		printf("\nError\n");
	}

}




void Jugador_mostrarConvocado(Jugador* unJugador, LinkedList* pArrayListSeleccion)
{
	int auxId;
	char auxNombreCompleto[100];
	int auxEdad=0;
	char auxPosicion[30];
	char auxNacionalidad[30];
	int auxIdSeleccion;
	char seleccionStr[30];

	jug_getId(unJugador, &auxId);
	jug_getNombreCompleto(unJugador, auxNombreCompleto);
	jug_getEdad(unJugador, &auxEdad);
	jug_getPosicion(unJugador, auxPosicion);
	jug_getNacionalidad(unJugador, auxNacionalidad);
	jug_getSIdSeleccion(unJugador, &auxIdSeleccion);
	Jugador_CargarDescripcionConvocatoria(seleccionStr, auxIdSeleccion, pArrayListSeleccion);


	if(unJugador != NULL)
	{
		if(auxIdSeleccion != 0 && auxIdSeleccion>0)
		{
			printf("|%4d        | %30s|    %4d|  %20s|     %15s |%20s|\n",
			auxId,auxNombreCompleto,auxEdad,auxPosicion, auxNacionalidad,seleccionStr);
		}
	}
	else
	{
		printf("\nError\n");
	}

}

int Jugador_CargarDescripcionConvocatoria(char * seleccionStr, int idSeleccion, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int idAux;
	char auxPaisSeleccion[30];
	int tam = ll_len(pArrayListSeleccion);
	Seleccion * auxSeleccion;


	for(int i=0; i<tam; i++)
	{
		auxSeleccion = ll_get(pArrayListSeleccion, i);
		selec_getId(auxSeleccion, &idAux);
		if(idSeleccion==0)
		{
			strcpy(seleccionStr, "No convocado");
		}
		else
		{
			if(idAux==idSeleccion)
			{
				selec_getPais(auxSeleccion, auxPaisSeleccion);
				strcpy(seleccionStr, auxPaisSeleccion);
			}

		}
		retorno=0;
	}

	return retorno;
}
int Jugador_PosicionInt(int posicion,char* posicionStr)
{
	int retorno = -1;

	if(posicionStr != NULL)
	{
		switch(posicion)
		{
		case 1:
			strcpy(posicionStr,"Portero");
		break;
		case 2:
			strcpy(posicionStr,"Defensa Central");
		break;
		case 3:
			strcpy(posicionStr,"Lateral Izquiero");
		break;
		case 4:
			strcpy(posicionStr,"Lateral Derecho");
		break;
		case 5:
			strcpy(posicionStr,"Pivote");
		break;
		case 6:
			strcpy(posicionStr,"Mediocentro");
		break;
		case 7:
			strcpy(posicionStr,"Extremo Izquiero");
		break;
		case 8:
			strcpy(posicionStr,"Extremo Derecho");
		break;
		case 9:
			strcpy(posicionStr,"Media Punta");
		break;
		case 10:
			strcpy(posicionStr,"Delantero Centro");
		break;
		default:
			printf("error");
		break;
		}
	}
	return retorno;
}

int Jugador_nacionalidadInt(int seleccion, char * seleccionStr)
{
	int retorno = -1;
	if(seleccionStr != NULL)
	{
		switch(seleccion)
		{
		case 1:
			strcpy(seleccionStr,"Argentino");
		break;
		case 2:
			strcpy(seleccionStr,"Brasilero");
		break;
		case 3:
			strcpy(seleccionStr,"Uruguayo");
		break;
		case 4:
			strcpy(seleccionStr,"Portugues");
		break;
		case 5:
			strcpy(seleccionStr,"Ingles");
		break;
		case 6:
			strcpy(seleccionStr,"Aleman");
		break;
		case 7:
			strcpy(seleccionStr,"Mexicano");
		break;
		case 8:
			strcpy(seleccionStr,"Estado Unidense");
		break;
		case 9:
			strcpy(seleccionStr,"Camerunes");
		break;
		case 10:
			strcpy(seleccionStr,"Senegales");
		break;
		case 11:
			strcpy(seleccionStr,"Australiano");
		break;
		case 12:
			strcpy(seleccionStr,"Qatari");
		break;
		default:
			printf("error Nacion");
		break;
		}
	}
	return retorno;
}


void Jugador_leerId(char * auxId)
{
	FILE* pArchivoId = NULL;

	char idchar[20];
	int id;

	pArchivoId = fopen("archivoId.txt","r");

	if(pArchivoId != NULL)
	{
		fscanf(pArchivoId,"%[^\n]",idchar);

		strcpy(auxId,idchar);

		id = atoi(idchar);

		id++;

		fclose(pArchivoId);

		pArchivoId = fopen("archivoId.txt","w");

		fprintf(pArchivoId,"%d\n",id);

		fclose(pArchivoId);
	}
}


int Jugador_add(LinkedList* this)
{
	int retorno = -1;
	char auxId[20];
	char auxNombreCompleto[50];
	int edad;
	char auxEdad[20];
	int posicion;
	char auxPosicion[50];
	int nacionalidad;
	char auxNacionalidad[50];
	int convocado=0;
	char auxConvocado[20];
	Jugador *auxJugador=NULL;

	if(this != NULL)
	{
		if(!(utn_getNombre(auxNombreCompleto, 50, "\nIngrese su nombre completo:", "\n◉Error,reingrese su nombre:(no se aceptan numeros ni simbolos)", 3))
		&&!(utn_getNumero(&edad, "\nIngrese su edad:", "\n◉Error,reingrese una edad valida:", 18, 99, 3))
		&&!(utn_getNumero(&posicion, "\nIngrese su posicion: \n1.Portero\n2.Defensa Central\n3.Lateral Izquiero\n4.Lateral Derecho\n5.Pivote\n6.Mediocentro"
		"\n7.Extremo Izquiero\n8.Extremo Derecho\n9.Media Punta\n10.Delantero Centro.", "\nError,reingrese una posicion valida:", 1, 10, 3))
		&&!(utn_getNumero(&nacionalidad, "\n1.Argentino\n2.Brasilero\n3.Uruguayo\n4.Portugues\n5.Ingles\n6.Aleman\n7.Mexicano\n8.Estado Unidense"
		"\n9.Camerunes\n10.Senegales\n11.Australiano\n12.Qatari","\nError, ingrese una seleccion valida",1,12,3))
		)
		{
			Jugador_leerId(auxId);
			Jugador_PosicionInt(posicion, auxPosicion);
			Jugador_nacionalidadInt(nacionalidad, auxNacionalidad);
			Jugador_leerId(auxId);
			itoa(edad,auxEdad,10);
			itoa(convocado,auxConvocado,10);

			auxJugador= jug_newParametros(auxId, auxNombreCompleto, auxEdad, auxPosicion, auxNacionalidad, auxConvocado);
			if(auxJugador != NULL)
			{
				ll_add(this, auxJugador);
			}
		}
	}
	return retorno;
}


int Jugador_modificar(Jugador* auxJugador)
{
	int opcion;
	int retorno = -1;
	char auxNombreCompleto[50];
	int auxEdad;
	int posicion;
	char auxPosicion[50];
	int nacionalidad;
	char auxNacionalidad[50];
	if(auxJugador != NULL)
	{
		do
		{
			systemCls();
			opcion = subMenu_modificar();
			switch(opcion)
			{
				case 1:
					if(!utn_getNombre(auxNombreCompleto, 50, "\nIngrese su nuevo nombre:","\nError,reingrese su nombre:(no se aceptan numeros ni simbolos)", 3))
					{
						jug_setNombreCompleto(auxJugador, auxNombreCompleto);
						printf("\nSu cambio se ha realizado exitosamente\n");
					}
					else
					{
						printf("\nNo se pudo cambiar el nombre\n");
					}
					break;
				case 2:
					if(!utn_getNumero(&auxEdad, "\nIngrese su nueva edad:", "\nError,reingrese una edad valida:", 18, 99, 3))
					{
						jug_setEdad(auxJugador, auxEdad);
						printf("\nSu cambio se ha realizado exitosamente\n");
					}
					break;

				case 3:
					if(!utn_getNumero(&posicion, "\nIngrese su nueva posicion: \n1.Portero\n2.Defensa Central\n3.Lateral Izquiero\n4.Lateral Derecho\n5.Pivote\n6.Mediocentro"
					"\n7.Extremo Izquiero\n8.Extremo Derecho\n9.Media Punta\n10.Delantero Centro.", "\nError,reingrese una posicion valida:", 1, 10, 3))
					{
						Jugador_PosicionInt(posicion, auxPosicion);
						jug_setPosicion(auxJugador, auxPosicion);
						printf("\nSu cambio se ha realizado exitosamente\n");
					}
					break;

				case 4:
					if(!utn_getNumero(&nacionalidad, "\n1.Argentino\n2.Brasilero\n3.Uruguayo\n4.Portugues\n5.Ingles\n6.Aleman\n7.Mexicano\n8.Estado Unidense"
					"\n9.Camerunes\n10.Senegales\n11.Australiano\n12.Qatari","\nError, ingrese una nacionalidad valida",1,12,3))
					{
						Jugador_nacionalidadInt(nacionalidad, auxNacionalidad);
						jug_setNacionalidad(auxJugador,auxNacionalidad);
					}
					printf("\nSu cambio se ha realizado exitosamente\n");
					break;

				default:
					printf("\nOpcion incorrecta..\n");
					break;
			}

		}while(opcion != 5);

		retorno = 0;
	}

	return retorno;
}


int Jugador_buscarPorId(LinkedList* pArrayListJugador, int buscadorId)
{
	int tam;
	int retorno=-1;
	Jugador* auxJugador = NULL;
	if(pArrayListJugador!=NULL)
	{
		tam = ll_len(pArrayListJugador);
		for(int i=0;i<tam;i++)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador, i);

			if(auxJugador->id == buscadorId)
			{
				retorno = ll_indexOf(pArrayListJugador, auxJugador);
			}
		}
	}
	return retorno;
}

int Jugador_thisConvocado(Jugador* unJugador)
{
	int retorno=-1;
	int idConvocado;

	if(unJugador!=NULL)
	{
		jug_getSIdSeleccion(unJugador, &idConvocado);
		if(idConvocado==0)
		{
			retorno=0;
		}
		else
		{
			if(idConvocado>0)
			{
				retorno=1;
			}
		}
	}
	return retorno;
}

int Jugador_cambiarSeleccion(Jugador* unJugador, int idSeleccion)
{
	int retorno=-1;

	if(unJugador!=NULL && idSeleccion > 0)
	{
		jug_setIdSeleccion(unJugador, idSeleccion);
	}
	return retorno;
}

int Jugador_anularConvocatoria(Jugador* unJugador)
{
	int retorno=-1;

	if(unJugador!=NULL)
	{
		jug_setIdSeleccion(unJugador, 0);
	}
	return retorno;
}

int Jugador_ordenaNombre(void* pJugadorUno , void* pJugadorDos)
{
	int retorno = -1;
	char nombreJugadorUno[50];
	char nombreJugadorDos[50];
	Jugador* jugadorUno = NULL;
	Jugador* JugadorDos = NULL;

	if(pJugadorUno != NULL && pJugadorDos != NULL)
	{
		jugadorUno = (Jugador*)pJugadorUno;
		JugadorDos =  (Jugador*)pJugadorDos;

		if(jugadorUno != NULL && JugadorDos != NULL)
		{
			jug_getNombreCompleto(jugadorUno, nombreJugadorUno);
			jug_getNombreCompleto(pJugadorDos, nombreJugadorDos);
			retorno = strcmp(nombreJugadorUno,nombreJugadorDos);
		}
	}

	return retorno;
}
int Jugador_ordenaPorNacionalidad(void* pJugadorUno , void* pJugadorDos)
{
	int retorno = -1;
	char nacionalidadJugadorUno[50];
	char nacionalidadJugadorDos[50];
	Jugador* jugadorUno = NULL;
	Jugador* JugadorDos = NULL;

	if(pJugadorUno != NULL && pJugadorDos != NULL)
	{
		jugadorUno = (Jugador*)pJugadorUno;
		JugadorDos =  (Jugador*)pJugadorDos;

		if(jugadorUno != NULL && JugadorDos != NULL)
		{
			jug_getNacionalidad(jugadorUno, nacionalidadJugadorUno);
			jug_getNacionalidad(JugadorDos, nacionalidadJugadorDos);
			retorno = strcmp(nacionalidadJugadorUno,nacionalidadJugadorDos);
		}
	}

	return retorno;
}
int Jugador_ordenaPorEdad(void* pJugadorUno , void* pJugadorDos)
{
	int retorno = -1;
	int edadJugadorUno;
	int edadJugadorDos;
	Jugador* jugadorUno = NULL;
	Jugador* JugadorDos = NULL;

	if(pJugadorUno != NULL && pJugadorDos != NULL)
	{
		jugadorUno = (Jugador*)pJugadorUno;
		JugadorDos =  (Jugador*)pJugadorDos;

		if(jugadorUno != NULL && JugadorDos != NULL)
		{
			jug_getEdad(jugadorUno, &edadJugadorUno);
			jug_getEdad(JugadorDos, &edadJugadorDos);
			if(edadJugadorUno > edadJugadorDos)
			{
				retorno = 1;
			}
			else
			{
				if(edadJugadorUno == edadJugadorDos)
				{
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

