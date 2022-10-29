/*
 * confederaciones.h
 *
 *  Created on: 27 oct. 2022
 *      Author: Luca
 */

#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_




/**
 * @brief inicializa las confederaciones en isEmpty=1 (esta vacio es verdadero)
 *
 * @param vec
 * @param tam
 * @return
 */
int inicializarConfederaciones(eConfederacion vec[], int tam);


/**
 * @brief recorre el vector y busca una confederacion libre (isEmpty == true)
 *
 * @param pIndice
 * @param vec
 * @param tam
 * @return
 */
int buscarLibreConfederaciones(int* pIndice, eConfederacion vec[], int tam);




/**
 * @brief da de alta una confederacion
 *
 * @param pLegajo
 * @param vecConfederacion
 * @param tamConfederaciones
 * @return
 */
int altaConfederaciones(int* pLegajo,eConfederacion vecConfederacion[], int tamConfederaciones);


/**
 * @brief carga los datos una confederacion
 *
 * @param pConfederacion
 * @param vecConfederacion
 * @param tamConfederaciones
 * @return
 */
int cargarConfederacion(eConfederacion * pConfederacion, eConfederacion vecConfederacion[], int tamConfederaciones);



/**
 * @brief carga la descripcion de una region, dependiendo el id que eliga de esa region el usuario
 *
 * @param idRegion
 * @param vec
 * @return
 */
int cargarDescripcionRegion(int idRegion, eConfederacion * vec);


/**
 * @brief da de baja la confederacion que eliga el usuario
 *
 * @param vecConfederaciones
 * @param tamConfederaciones
 * @return
 */
int bajaConfederacion(eConfederacion vecConfederaciones[], int tamConfederaciones);



/**
 * @brief modifica el valor o valores de una o varias confederaciones, que elija el usuario
 *
 * @param vecConfederaciones
 * @param tamConfederaciones
 * @return
 */
int modificarConfederaciones(eConfederacion vecConfederaciones[],int tamConfederaciones);


/**
 * @brief busca la posicion del array confederacion
 *
 * @param vec
 * @param id
 * @param tam
 * @return
 */
int buscarConfederacion(eConfederacion * vec, int id, int tam);

/**
 * @brief busca la confederacion por id
 *
 * @param pIndice
 * @param legajo
 * @param vec
 * @param tam
 * @return
 */
int buscarConfederacionPorId(int* pIndice, int legajo, eConfederacion vec[], int tam);

/**
 * @brief
 *
 * @param pLegajo hardcodea 6 confederaciones
 * @param vec
 * @param tam
 * @param cant
 * @return
 */
int hardcodearConfederaciones(int* pLegajo ,eConfederacion vec[], int tam, int cant);


#endif /* CONFEDERACIONES_H_ */
