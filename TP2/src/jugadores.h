/*
 * jugadores.h
 *
 *  Created on: 24 oct. 2022
 *      Author: Luca
 */

#ifndef JUGADORES_H_
#define JUGADORES_H_

// CALCULO DATOS

typedef struct
{
	int id;
	char nombre[50];
	char region	[50];
	int anioCreacion;
	short isEmpty;
}eConfederacion;

typedef struct
{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;

/**
 * @brief inicializa los jugadores en isEmpty=1 (esta vacio es verdadero)
 *
 * @param vec
 * @param tam
 * @return
 */
int inicializarJugadores(eJugador vec[], int tam);

/**
 * @brief recorre el vector y busca un jugador libre (isEmpty == true)
 *
 * @param pIndice
 * @param vec
 * @param tam
 * @return
 */
int buscarLibreJugadores(int* pIndice, eJugador vec[], int tam);


/**
 * @brief da de alta un jugador
 *
 * @param pLegajo
 * @param vecJugador
 * @param vecConfederacion
 * @param tamJugadores
 * @param tamConfederaciones
 * @return
 */
int altaJugadores(int* pLegajo, eJugador vecJugador[], eConfederacion vecConfederacion[], int tamJugadores, int tamConfederaciones);


/**
 * @brief carga los datos de un jugador
 *
 * @param pJugador
 * @param vecConfederacion
 * @param tamJugadores
 * @param tamConfederaciones
 * @return
 */
int cargarJugador(eJugador * pJugador, eConfederacion vecConfederacion[], int tamJugadores, int tamConfederaciones);


/**
 * @brief carga descripcion de la confederacion del jugador
 *
 * @param idConfederacion
 * @param descripcion
 * @param vec
 * @param tam
 * @return
 */
int cargarDescripcionConfederacion(int idConfederacion, char descripcion[], eConfederacion vec[], int tam);

/**
 * @brief carga descripcion de la posicion del jugador dependiendo el id que eliga de esa region el usuario
 *
 * @param idPosicion
 * @param vec
 * @return
 */
int cargarDescripcionPosicion(int idPosicion, eJugador * vec);



/**
 * @brief modifica el valor o valores de uno o varios jugadores que elija el usuario
 *
 * @param vecJugador
 * @param vecConfederacion
 * @param tamJugadores
 * @param tamConfederaciones
 * @return
 */
int modificarJugadores(eJugador vecJugador[], eConfederacion vecConfederacion[], int tamJugadores, int tamConfederaciones);


/**
 * @brief Busca jugador (por id) con el indice que ingresa el usuario
 *
 * @param pIndice
 * @param legajo
 * @param vec
 * @param tam
 * @return
 */
int buscarJugador(int* pIndice, int legajo, eJugador vec[], int tam);


/**
 * @brief Da de baja un jugador
 *
 * @param vecJugador
 * @param vecConfederacion
 * @param tamJugadores
 * @param tamConfederaciones
 * @return
 */
int bajaJugadores(eJugador vecJugador[], eConfederacion vecConfederacion[], int tamJugadores, int tamConfederaciones);





/**
 * @brief hardcodeo de 10 jugadores
 *
 * @param pLegajo
 * @param vec
 * @param tam
 * @param cant
 * @return
 */
int hardcodearJugadores(int* pLegajo ,eJugador vec[], int tam, int cant);

#endif /* JUGADORES_H_ */
