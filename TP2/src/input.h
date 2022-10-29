/*
 * input.h
 *
 *  Created on: 27 oct. 2022
 *      Author: Luca
 */

#ifndef INPUT_H_
#define INPUT_H_


/**
 * @brief valida que no pueda ingresar otra cosa que no sea 's' o 'n'
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param reintentos
 * @return
 */
int utn_getCharSeguir(char * pResultado, char * mensaje, char * mensajeError, int reintentos);


/**
 * @brief almacena como cadena, valida y convierte el texto a numero y lo devuelve como char.

 *
 * @param pResultado
 * @return
 */
int getChar ( char * pResultado);

/**
 * @brief verifica si la cadena tiene numeros, si tiene devuelve -1
 *
 * @param cadena
 * @return
 */
int esNumericaChar ( char * cadena);


/**
 * @brief  Si encuentra un '\n', lo elimina.
 *
 * @param cadena
 * @param longitud
 * @return
 */
int myGets(char* cadena, int longitud);


/**
 * @brief valida que te ingresen solo enteros
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param min
 * @param max
 * @param intentos
 * @return
 */
int utn_getInt(int* pResultado,char* mensaje, char* mensajeError, int min, int max, int intentos);

/**
 * @brief valida que lo que te ingreso sea un entero
 *
 * @param mensaje
 * @return
 */
int getInt(char mensaje[]);

/**
 * @brief lo convierte a string lo que le pase
 *
 * @param palabra
 * @param mensaje
 * @param tamanio
 */
void getString(char palabra[],char mensaje[],int tamanio);


/**
 * @brief Verifica si la cadena ingresada son todos numeros
 *
 *
 * @param auxiliar
 * @return
 */
int esNumerica(char auxiliar[]);


/**
 * @brief verifica que el string no supere la cantidad de espacio que le permito, y que tampoco ingresen numeros
 *
 * @param cadena
 * @param mensaje
 * @param mensajeError
 * @return
 */
int utn_getString(char cadena[], char mensaje[],char mensajeError[]);

/**
 * @brief
 *
 * @param cadena
 * @return
 */
int validar_Cadena(char cadena[]);


/**
 * @brief
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param min
 * @param max
 * @param intentos
 * @return
 */
int utn_getShort(short* pResultado,char* mensaje, char* mensajeError, int min, int max, int intentos);


/**
 * @brief valida que el float que ingresemos
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param min
 * @param max
 * @param intentos
 * @return
 */
int utn_getFloat(float* pResultado,char* mensaje, char* mensajeError, int min, int max, int intentos);


/**
 * @brief
 * @param mensaje
 * @return
 */
float getFloat(char mensaje[]);


/**
 * @brief
 *
 * @param pData
 * @return
 */
int validaSoloNumeroFlotante(char* pData);





#endif /* INPUT_H_ */
