
#ifndef PARSER_H_
#define PARSER_H_



int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);//
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);//
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);//

int parser_guardarBinarioJugador(FILE* pFile , LinkedList* pArrayListJugador);//
int parser_guardarTextoJugador(FILE* pFile , LinkedList* pArrayListJugadores);//

int parser_guardarTextoSeleccion(FILE* pFile , LinkedList* pArrayListSeleccion);//


#endif /* PARSER_H_ */
