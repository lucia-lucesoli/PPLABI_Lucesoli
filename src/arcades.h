/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Primer Parcial - LABORATORIO I
 ============================================================================
 */

#ifndef ARCADES_H_
#define ARCADES_H_

typedef struct {
	int id;
	int idSalon;
	char nombre[63];
	char nacionalidad[50];
	char sonido[10];
	int jugadores;
	int fichas;
	int isEmpty;
} eArcade;

#endif /* ARCADES_H_ */


int inicializarArcade(eArcade arcades[], int tam);
int altaArcade(eArcade arcades[], int tam, int id, int idSalon, char nacionalidad[], char nombre[], char sonido[], int jugadores, int fichas);
int modificarArcade(eArcade arcades[], int indice);
int bajaArcade(eArcade arcades[], int indice);
int bajaArcadesPorBajaSalon(eArcade arcades[], int tam, int idSalon);

void mostrarArcade(eArcade arcades);
void mostrarArcades(eArcade arcades[], int tam);
int buscarArcadePorId(eArcade arcades[], int tam, int id);

int juegoYaExiste(eArcade arcades[], int tam, char juego[]);
void imprimirJuegos(eArcade arcades[], int tam);

int hayArcadesAgregados(eArcade arcades[], int tam);
