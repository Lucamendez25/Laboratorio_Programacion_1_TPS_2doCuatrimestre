#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete(Seleccion* this);

int selec_getId(Seleccion* this,int * id);
int selec_getPais(Seleccion* this,char* pais);
int selec_getConfederacion(Seleccion* this,char* confederacion);

int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);

void Seleccion_mostrar(Seleccion* unaSeleccion);
int Seleccion_buscarPorId(LinkedList* pArrayListSeleccion, int buscadorId);
int Seleccion_cantidadConvocados(Seleccion* unaSeleccion);
int Seleccion_restarConvocados(Seleccion* unaSeleccion);
int Seleccion_ordenaPorConfederacion(void* pSeleccionUno , void* pSeleccionDos);
int Seleccion_ConfeInt(int confederacion,char* confederacionStr);

#endif // selec_H_INCLUDED
