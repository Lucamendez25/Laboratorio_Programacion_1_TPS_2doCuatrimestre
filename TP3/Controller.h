int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador); //
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);//
int controller_agregarJugador(LinkedList* pArrayListJugador);//
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList*pArrayListSeleccion);//
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//
int controller_ordenarJugadores(LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);//
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//
int controller_jugadoresConfederacionConvocados(LinkedList* pArrayListJugador, LinkedList * pArrayListJugadorConvocados, LinkedList* pArrayListSeleccion);//
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);//
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);//
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);//
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);//
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//
int controller_convocarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//
int controller_desconvocarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//
