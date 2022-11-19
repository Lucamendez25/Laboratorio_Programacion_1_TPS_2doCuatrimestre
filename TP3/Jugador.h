#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

Jugador* jug_new(); //
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr); //


void Jugador_delete(Jugador* this);//

int jug_setId(Jugador* this,int id); //
int jug_getId(Jugador* this,int* id);//

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto); //
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);//

int jug_setPosicion(Jugador* this,char* posicion); //
int jug_getPosicion(Jugador* this,char* posicion);//

int jug_setNacionalidad(Jugador* this,char* nacionalidad); //
int jug_getNacionalidad(Jugador* this,char* nacionalidad);//

int jug_setEdad(Jugador* this,int edad); //
int jug_getEdad(Jugador* this,int* edad);//

int jug_setIdSeleccion(Jugador* this,int idSeleccion); //
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);//

void Jugador_mostrar(Jugador* unJugador);//
void Jugador_mostrarConvocado(Jugador* unJugador);//


int Jugador_PosicionInt(int posicion,char* posicionStr);//
int Jugador_nacionalidadInt(int seleccion, char * seleccionStr);//
void Jugador_leerId(char * auxId);//
int Jugador_add(LinkedList* this);//
int Jugador_modificar(Jugador* auxJugador);//
int Jugador_buscarPorId(LinkedList* pArrayListJugador, int buscadorId);//
int Jugador_cambiarSeleccion(Jugador* unJugador, int idSeleccion);//
int Jugador_thisConvocado(Jugador* unJugador);//
int Jugador_anularConvocatoria(Jugador* unJugador);//
int Jugador_ordenaNombre(void* pJugadorUno , void* pJugadorDos);//
int Jugador_ordenaPorNacionalidad(void* pJugadorUno , void* pJugadorDos);//
int Jugador_ordenaPorEdad(void* pJugadorUno , void* pJugadorDos);//



#endif // jug_H_INCLUDED
