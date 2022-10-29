/*
 * output.h
 *
 *  Created on: 24 oct. 2022
 *      Author: Luca
 */
//MOSTRAR DATOS
#ifndef OUTPUT_H_
#define OUTPUT_H_


/**
 * @briefes un system("cls"), en el que en verdad no borra, sino que salta varias lineas
 *
 */
void systemCls();

/**
 * @brief es un system("Pause"), en el que debe tocar enter para seguir
 *
 */
void systemPause();


/**
 * @brief Muestra el menu principal
 *
 * @return
 */
int menu();



/**
 * @brief muestra el submenu Jugadores
 *
 * @return
 */
int subMenuMostrarJugadores();

/**
 * @brief	muestra el submenu alta
 *
 * @return
 */
int subMenuAlta();

/**
 * @brief muestra el submenu baja
 *
 * @return
 */
int subMenuBaja();


/**
 * @brief muestra el submenu modificar
 *
 * @return
 */
int subMenuModificar();


/**
 * @brief muestra el submenu modificar de conferaciones
 *
 * @return
 */
int subMenuModificarConfederaciones();

/**
 * @brief muestra el submenu modificar de Jugadores
 *
 * @return
 */
int subMenuModificarJugadores();

/**
 * @brief muestra un mensaje al finalizar el programa
 *
 * @return
 */
void cerrandoMenu();


/**
 * @brief muestra todos los jugadores
 *
 * @param vecJugadores
 * @param vecConfederaciones
 * @param tamJugadores
 * @param tamConfederaciones
 * @return
 */
int mostrarJugadores(eJugador vecJugadores[], eConfederacion vecConfederaciones[] ,int tamJugadores, int tamConfederaciones);

/**
 * @brief muestra un jugador
 *
 * @param jugador
 * @param vecTipos
 * @param tamConfederaciones
 * @return
 */
int mostrarJugador(eJugador jugador, eConfederacion vecConfederacion[], int tamConfederaciones );



/**
 * @brief muestra todas las confederaciones
 *
 * @param vecConfederaciones
 * @param tamConfederaciones
 * @return
 */
int mostrarConfederaciones(eConfederacion vecConfederaciones[], int tamConfederaciones);

/**
 * @brief muestra una confederacion
 *
 * @param vecConfederaciones
 * @param tamConfederaciones
 * @return
 */
int mostrarConfederacion(eConfederacion vecConfederaciones, int tamConfederaciones);

/**
 * @brief muestra las posiciones y sus id
 *
 * @return
 */
int mostrarPosiciones();

/**
 * @brief muestra las regiones y sus id
 *
 * @return
 */
int mostrarRegiones();

/**
 * @brief ordena los jugadores dependiendo que opcion elija el usuario
 *
 * @param vecJugador
 * @param vecConfederacion
 * @param tamJugadores
 * @param tamConfederaciones
 * @return
 */
int ordenarJugadores(eJugador vecJugador[], eConfederacion vecConfederacion[], int tamJugadores, int tamConfederaciones);



/**
 * @brief ordena los jugadores primero, por confederacion y despues por nombre
 *
 * @param vecJugador
 * @param vecConfederacion
 * @param tamJugadores
 * @param tamConfederaciones
 * @return
 */
int ordenarJugadorPorConfederacion(eJugador vecJugador[], eConfederacion vecConfederacion[], int tamJugadores, int tamConfederaciones);




/**
 * @brief muestra los jugadores por confederacion, todos los de una confederacion, todos de otra, y asi sucesivamente.
 *
 * @param vecJugador
 * @param vecConfederacion
 * @param tamJugadores
 * @param tamConfederaciones
 * @return
 */
int mostrarJugadoresPorConfederacion(eJugador vecJugador[], eConfederacion vecConfederacion[],int tamJugadores, int tamConfederaciones);





/**
 * @brief Muestra la cantidad de jugadores que hay dados de alta, muestra el salario promedio.
 * Y muestra al final, los jugadores que superan ese salario promedio
 *
 * @param vecJugador
 * @param vecConfederacion
 * @param tamJugadores
 * @param tamConfederaciones
 * @return
 */
int totalYPromedioTodosSalarios(eJugador vecJugador[], eConfederacion vecConfederacion[],int tamJugadores, int tamConfederaciones);


/**
 * @brief informa la confederacion con mayor cantidad de anios de contrato
 *
 * @param vecJugador
 * @param vecConfederacion
 * @param tamJugadores
 * @param tamConfederaciones
 * @return
 */
int confederacionMayorAniosDeContrato(eJugador vecJugador[], eConfederacion vecConfederacion[],int tamJugadores, int tamConfederaciones);



/**
 * @brief Informar porcentaje de jugadores por cada confederación.
 *
 * @param vecJugador
 * @param vecConfederacion
 * @param tamJugadores
 * @param tamConfederaciones
 * @return
 */
int porcentajeJugadoresPorConfederacion(eJugador vecJugador[], eConfederacion vecConfederacion[],int tamJugadores, int tamConfederaciones);


/**
 * @brief Informar cual es la región con más jugadores y los lista.
 *
 * @param vecJugador
 * @param vecConfederaciones
 * @param tamJugadores
 * @param tamConfederaciones
 * @return
 */
int mostrarRegionMasJugadores(eJugador vecJugador[], eConfederacion vecConfederaciones[],int tamJugadores, int tamConfederaciones);



#endif /* OUTPUT_H_ */
