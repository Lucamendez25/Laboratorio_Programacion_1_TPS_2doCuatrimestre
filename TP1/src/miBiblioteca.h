/*
 * miBiblioteca.h
 *
 *  Created on: 19 sep. 2022
 *      Author: Luca
 *      Division A
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#ifndef MIBIBLIOTECA_H_
#define MIBIBLIOTECA_H_


/// @fn int Menu(float*, float*, float*, int*, int*, int*, int*)
/// @brief Muestra el menu principal
///
/// @param Recibe como parametro la direccion de memoria del valor hospedaje
/// @param Recibe como parametro la direccion de memoria del valor comida
/// @param Recibe como parametro la direccion de memoria del valor transporte
/// @param Recibe como parametro la direccion de memoria del valor de arqueros
/// @param Recibe como parametro la direccion de memoria del valor de defensores
/// @param Recibe como parametro la direccion de memoria del valor de mediocampistas
/// @param Recibe como parametro la direccion de memoria del valor de delanteros
/// @return Devuelve la opcion que ingrese el usuario
int Menu(float*, float*, float*, int*, int*, int*, int*);

/// @fn int SubMenuGastos(float*, float*, float*)
/// @brief Muestra el submenu gastos, y elige el valor de hospedaje, comida o trasnporte
///
/// @param Recibe como parametro la direccion del valor hospedaje
/// @param Recibe como parametro la direccion del valor comida
/// @param Recibe como parametro la direccion del valor transporte
/// @return Retorna 1 si salio bien. Retorna 0 si sale mal
int SubMenuGastos(float*, float*, float*);

/// @fn int SubMenuJugadores(int*, int*, int*, int*, int*, int*, int*, int*, int*, int*, int*)
/// @brief Muestra la cantidad de jugadores que hay por posicion, y
/// elegis cual queres ingresar, con su region.
///
/// @param Recibe como parametro la direccion el valor de arqueros
/// @param Recibe como parametro la direccion el valor de defensas
/// @param Recibe como parametro la direccion el valor de mediocampistas
/// @param Recibe como parametro la direccion el valor de delanteros
/// @param Recibe como parametro la direccion el valor de la region afc
/// @param Recibe como parametro la direccion el valor de la region caf
/// @param Recibe como parametro la direccion el valor de la region concacaf
/// @param Recibe como parametro la direccion el valor de la region conmebol
/// @param Recibe como parametro la direccion el valor de la region uefa
/// @param Recibe como parametro la direccion el valor de la region ofc
/// @param Recibe como parametro la direccion el valor de la cantidad de jugadores
/// @return Retorna 1 si salio todo bien. Retorna 0 si algo fallo
int SubMenuJugadores(int*, int*, int*, int*, int*, int*, int*, int*, int*, int*, int*);

/// @fn int SubMenuJugadoresRegion()
/// @brief Elegis el numero de camiseta y region que desees
///
/// @return retorna del 1 al 6, para poder elegir la region
int SubMenuJugadoresRegion();

/// @fn float CalcularPromedios(int, int)
/// @brief divide la cantidad de jugadores de una region, por la cantidad de jugadores total
///
/// @param recibe el valor de la cantidad de jugadores de una determinada region
/// @param recibe el valor del contador de jugadores total
/// @return retorna el promedio de una region
float CalcularPromedios(int, int);

/// @fn int ComparadorRegiones(float, float, float, float, float, float)
/// @brief compara la region de la uefa, con todas las demas, para comprobar si es mayor o no
///
/// @param recibe el promedio de la uefa
/// @param recibe el promedio de la afc
/// @param recibe el promedio de la caf
/// @param recibe el promedio de la concacaf
/// @param recibe el promedio de la conmebol
/// @param recibe el promedio de de la ofc
/// @return retorna a 1 si el promedio de uefa es mayor a todos, sino retorna 0
int ComparadorRegiones(float,float,float,float,float,float);

/// @fn float CalcularCostoDeMantenimiento(float, float, float)
/// @brief Suma todos los costos
///
/// @param recibe el valor de hospedaje
/// @param recibe el valor de comida
/// @param recibe el valor de transporte
/// @return devuelve la suma de todos los costos ya realizado
float CalcularCostoDeMantenimiento(float,float,float);



#endif /* MIBIBLIOTECA_H_ */
