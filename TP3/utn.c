/*
 * utn.c
 *
 *  Created on: 14 nov. 2022
 *      Author: Luca
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
static int esNumerica(char* cadena, int limite);
static int getInt(int* pResultado);
static int esFlotante(char* cadena);
static int getFloat(float* pResultado);
static int getString(char* cadena, int longitud);
static int esNombre(char* cadena,int longitud);
static int getNombre(char* pResultado,int longitud);
static int esDescripcion(char* cadena,int longitud);
static int getDescripcion(char* pResultado, int longitud);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un maximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getString(char* cadena, int len)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && len > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len)
			{
				strncpy(cadena,bufferString,len);
				retorno=0;
			}
		}
	}
	return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Obtiene un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int* pResultado)
{

    int retorno=-1;
    char bufferString[50];

    if(	pResultado != NULL && getString(bufferString,sizeof(bufferString)) == 0 && esNumerica(bufferString,sizeof(bufferString)))
    {
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int len)
{
	int retorno = -1;
	int i;

	if(cadena != NULL && len > 0)
	{
		retorno = 1;

		for(i=0;i<len && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	do{
		fflush(stdin);
		printf("%s",mensaje);

		if(	getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}

		printf("%s",mensajeError);
		reintentos--;

	}while(reintentos>=0);

	return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Obtiene un numero flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++){
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;

	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);

		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;

				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 && esNombre(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);

			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] != ' '))
			{
				retorno = 0;

				break;
			}
		}
	}
	return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);

		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud && bufferString[0] != '\0' && bufferString[0] != ' ')
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;

			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Obtiene un string valido como descripcion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDescripcion(char* pResultado, int longitud)
{
    int retorno = -1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 && esDescripcion(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Verifica si la cadena ingresada es una descripcion valida
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esDescripcion(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;

				break;
			}
		}
	}
	return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{

	char bufferString[4096];
	int retorno = -1;

	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		printf("%s",pResultado);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			printf("%s",pResultado);
			retorno = 0;

			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int validarNumero(char *numero)
{
    int retorno=1;
    int len;

    if(numero!=NULL)
    {
        len=strlen(numero);

        for(int i=0;i<len;i++)
        {
            if(!isdigit(numero[i]))
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int pedirEntero(char *mensaje,char *mensajeError)
{
    int retorno;
    char numero[1000];

    printf(mensaje);
    scanf("%s",numero);

    while(!validarNumero(numero))
    {
        printf(mensajeError);
        printf(mensaje);
        scanf("%s",numero);
    }

    retorno = atoi(numero);

    return retorno;
}

int menu()
{
	int opcion;

	  printf("\n=============================================MENU==================================================");
	  opcion =pedirEntero(
			"\n1 Cargar los datos de los jugadores desde el archivo data.csv (modo texto)"
			"\n2 Alta Jugadores"
			"\n3 Modificar Jugadores"
			"\n4 Baja de Jugadores"
			"\n5 Listado de Jugadores"
			"\n6 Convocar Jugadores"
			"\n7 Ordenar y Listar"
			"\n8 Generar/guardar lista jugadores archivo Binario"
			"\n9 Cargar archivo binario"
			"\n10 Guardar archivos jugadores.csv y selecciones.csv"
			"\n11 Salir."
			"\nOpcion:","\n\nError, opcion no valida\n");
	  printf("===================================================================================================\n");

	  return opcion;
}

int subMenu_modificar()
{
int opcion;

	printf("\n==================================SUBMENU MODIFICAR==================================================");
	opcion =pedirEntero(
			"\n1 Modificar Nombre"
			"\n2 Modificar Edad"
			"\n3 Modificar Posicion"
			"\n4 Modificar Nacionalidad"
			"\n5 Salir."
			"\nOpcion:","\n\nError, opcion no valida\n");
	printf("===================================================================================================\n");

  return opcion;
}

int subMenuListar()
{
	int opcion;

	  printf("\n=====================================SUBMENU LISTAR==================================================");
	  opcion =pedirEntero(
			"\n1 Todos los jugadores"
			"\n2 Todas las selecciones"
			"\n3 Jugadores convocados exclusivamente"
			"\nOpcion:","\n\nError, opcion no valida\n");
	  printf("===================================================================================================\n");

	  return opcion;
}

int subMenuConvocados()
{
	int opcion;

	  printf("\n=====================================SUBMENU CONVOCADOS==================================================");
	  opcion =pedirEntero(
			"\n1 Convocar Jugador"
			"\n2 Quitar Convocatoria"
			"\nOpcion:","\n\nError, opcion no valida\n");
	  printf("===================================================================================================\n");

	  return opcion;
}

int subMenu_ordenar()
{
	int opcion;
	printf("\n=========================================SUBMENU ORDENAR===============================================");
	opcion = pedirEntero(
			"\n1 Lista Jugadores"
			"\n2 Lista Selecciones"
			"\n3 Salir"
			"\nOpcion:","\n\nError, opcion no valida\n");
	printf("===================================================================================================\n");
	return opcion;
}



int subMenu_ordenarListaJugadores()
{
	int opcion;
	printf("\n================================SUBMENU ORDENAR LISTA JUGADORES===============================================");
	opcion = pedirEntero(
			"\n1 Ordenar jugadores por nacionalidad"
			"\n2 Ordenar jugadores por edad"
			"\n3 Ordenar jugadores por nombre"
			"\n4 Salir"
			"\nOpcion:","\n\nError, opcion no valida\n");
	printf("===================================================================================================\n");
	return opcion;
}

int subMenu_ordenarListaSelecciones()
{
	int opcion;
	printf("\n=================================SUBMENU ORDENAR LISTA SELECCION===============================================");
	opcion = pedirEntero(
			"\n1 Ordenar seleccion por confederacion"
			"\n2 Salir"
			"\nOpcion:","\n\nError, opcion no valida\n");
	printf("===================================================================================================\n");
	return opcion;
}

int subMenu_confederacion()
{
	int opcion;
	printf("\n================================SUBMENU ORDENAR LISTA JUGADORES===============================================");
	opcion = pedirEntero(
			"\n1 AFC"
			"\n2 CAF"
			"\n3 CONCACAF"
			"\n4 CONMEBOL"
			"\n5 UEFA"
			"\nOpcion:","\n\nError, opcion no valida\n");
	printf("===================================================================================================\n");
	return opcion;
}

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

