/*
 * input.c
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

int utn_getCharSeguir(char * pResultado, char * mensaje, char * mensajeError, int reintentos)
{
	char aux[30];
	int retorno = -1;
	if(pResultado != NULL)
	{
		fflush(stdin);
		while(reintentos > 0)
		{
			reintentos--;
			printf ( "%s" ,mensaje);
			if(getChar(aux)==1)
			{
				aux[0]= tolower(aux[0]);
				if(aux[0] == 's' || aux[0] == 'n')
				{
					*pResultado = aux[0];
					retorno = 1;
					break;
				}

			}
			printf("%s",mensajeError);
		}
		if(reintentos < 1)
		{
			retorno= -1;
		}
	}
	return retorno;
}

int getChar ( char * pResultado)
{
	int retorno = -1;
	char buffer[30];
	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof (buffer))==1 && esNumericaChar(buffer) == 1)
		{
			strcpy(pResultado,buffer);
			retorno = 1;
		}
	}
	return retorno;

}

int esNumericaChar ( char * cadena)
{
	int retorno;
	int i=0;

	if (cadena != NULL && strlen (cadena) > 0)
	{
		retorno = 1;
		while (cadena[i] != '\0' )
		{
			if (cadena[i] >= '0' && cadena[i] <= '9' )
			{
				retorno = -1;
				break ;
			}
			i++;
		}
	}
	else
	{
		retorno = -1;
	}
	return retorno;

}


int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		retorno=1;
	}
	return retorno;
}



int utn_getInt(int* pResultado,char* mensaje, char* mensajeError, int min, int max, int intentos)
{
	int num;
	int rto;
	while( intentos > 0)
	{
		num = getInt(mensaje);
		if(num<=max && num>=min)
		{
			break;
		}
		intentos--;
		printf(mensajeError);
	}

	if(intentos == 0){
		rto= -1;
	}
	else{
		rto=0;
		*pResultado = num;
	}
	return rto;
}

int getInt(char mensaje[])
{

	int retorno = -1;
	int esNumero;
	char auxiliar[30];

	getString(auxiliar,mensaje,30);

	while(esNumerica(auxiliar) < 1)
	{
	  getString(auxiliar,mensaje,30);
	}

	esNumero = atoi(auxiliar);

	retorno = esNumero;

 return retorno;
}

void getString(char palabra[],char mensaje[],int tamanio)
{
	char auxilar[1024];
	int cantidadLetras;

	printf("%s",mensaje);
	setbuf(stdin,NULL);
	gets(auxilar);

	cantidadLetras = strlen(auxilar);

	while(cantidadLetras > tamanio)
	{
		printf("%s",mensaje);
		setbuf(stdin,NULL);
		gets(auxilar);
	}
	strcpy(palabra,auxilar);
}

int esNumerica(char auxiliar[])
{

	int i;
	int largo;
	int retorno =-1;

	if(auxiliar != NULL){
		retorno = 1;

		largo = strlen(auxiliar);

		for(i=0;i<largo;i++){
			if(isdigit(auxiliar[i])==0){
				retorno =0;
				break;
			}
		}
	}
	return retorno;
}

int utn_getString(char cadena[], char mensaje[],char mensajeError[])
{
    int rto = -1;
    char aux[300];

    if( cadena != NULL && mensaje != NULL && mensajeError != NULL )
    {
        rto = 0;

        printf("%s",mensaje);
        setbuf(stdin,NULL);
        scanf("%[^\n]",aux);

        while(validar_Cadena(aux)==-1){

            printf("%s",mensajeError);
            setbuf(stdin,NULL);
            scanf("%[^\n]",aux);
        }
    }
    strcpy(cadena,aux);
    return rto;
}

int validar_Cadena(char cadena[])
{
    int i=0;
    int rto=0;
    int j;

    j = strlen(cadena);

    while(i<j && rto == 0)
    {

        if(isalpha(cadena[i])!=0 || cadena[i] == ' ' || cadena[i] == '.')
        {
            i++;
        }
        else
        {
            rto = -1;
        }

    }
    return rto;
}

int utn_getShort(short* pResultado,char* mensaje, char* mensajeError, int min, int max, int intentos) {

	short num;
	int rto;

	while( intentos > 0){
		num = getInt(mensaje);
		if(num<=max && num>=min)
		{
			break;
		}
		intentos--;
		printf("%s",mensajeError);
	}

	if(intentos == 0)
	{
		rto= -1;
	}
	else
	{
		rto=0;
		*pResultado = num;
	}
	return rto;
}

int utn_getFloat(float* pResultado,char* mensaje, char* mensajeError, int min, int max, int intentos)
{

	float num;
	int rto;

	while(intentos > 0)
	{
		num =getFloat(mensaje);
		if( num <= max && num >= min )
		{
			break;
		}
		intentos--;
		printf(mensajeError);
	}

	if(intentos == 0)
	{
		rto= -1;
	}
	else
	{
		rto=0;
		*pResultado = num;
	}
	return rto;
}

float getFloat(char mensaje[])
{
	float retorno = -1;
	float esNumero;
	char auxiliar[30];

    printf("%s",mensaje);
	setbuf(stdin, NULL);
	scanf("%[^\n]",auxiliar);

	while(validaSoloNumeroFlotante(auxiliar) < 1)
	{
		printf("%s",mensaje);
		setbuf(stdin, NULL);
		scanf("%[^\n]",auxiliar);
	}

	esNumero = atof(auxiliar);

	retorno = esNumero;

 return retorno;
}

int validaSoloNumeroFlotante(char* pAuxiliar)
{
	int contadorSigno = 0;
	int rto = 1;

	if( strlen(pAuxiliar) > 0 )
	{
		for(int i=0; i < strlen(pAuxiliar); i++)
		{

			if(pAuxiliar[i] == '.' || pAuxiliar[i] == ',')
			{
				contadorSigno++;
			}
			else
			{
				if (isdigit(pAuxiliar[i] ) == 0)
				{
					if ( i == 0 )
					{
						if( pAuxiliar[0] != '-' )
						{
							rto = 0;
							break;
						}
					}
					else
					{
						rto = 0;
						break;
					}
				}
			}
		}

		if( contadorSigno > 1 )
		{
			rto = 0;
		}
	}
	else
	{
		rto =0;
	}
	return rto;
}




