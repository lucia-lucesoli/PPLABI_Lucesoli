/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Primer Parcial - LABORATORIO I
 ============================================================================
 */

#include "arcades.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int inicializarArcade(eArcade arcades[], int tam)
{
	int error = 1;

	if (arcades != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			arcades[i].isEmpty = 1;
		}
		error = 0;
	}
	return error;
}

int altaArcade(eArcade arcades[], int tam, int id, int idSalon, char nacionalidad[], char nombre[], char sonido[], int jugadores, int fichas)
{
	int error = 1;

	if (arcades != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			if (arcades[i].isEmpty)
			{
				arcades[i].id = id;
				arcades[i].idSalon = idSalon;
				strcpy(arcades[i].nacionalidad, nacionalidad);
				strcpy(arcades[i].nombre, nombre);
				strcpy(arcades[i].sonido, sonido);
				arcades[i].jugadores = jugadores;
				arcades[i].fichas = fichas;
				arcades[i].isEmpty = 0;
				error = 0;
				break;
			}
		}
	}
	return error;
}

int modificarArcade(eArcade arcades[], int indice)
{
	int error = 1;

	if (arcades != NULL && indice >=0)
	{
		printf("Datos del Arcade: \n");
		mostrarArcade(arcades[indice]);
		printf("\nModificar Juego: ");
		scanf("%s", arcades[indice].nombre);
		printf("\nModificar la cantidad de Jugadores: ");
		scanf("%d", &arcades[indice].jugadores);

		error = 0;
	}
	return error;
}

int bajaArcade(eArcade arcades[], int indice)
{
	int error = 1;

	if (arcades != NULL && indice >= 0) {
		arcades[indice].isEmpty = 1;
		error = 0;
	}
	return error;
}

int bajaArcadesPorBajaSalon(eArcade arcades[], int tam, int idSalon) {
	int error = 1;

	if (arcades != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (arcades[i].idSalon == idSalon) {
				bajaArcade(arcades, i);
			}
		}
		error = 0;
	}

	return error;
}

void mostrarArcade(eArcade arcades)
{
	printf(" %5d     %15s      %15s      %15s      %5d      %5d\n", arcades.id, arcades.nombre, arcades.nacionalidad, arcades.sonido, arcades.jugadores, arcades.fichas);

}

void mostrarArcades(eArcade arcades[], int tam)
{
	printf("                                      *** Lista de Salones *** \n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("   ID    |       Nombre       |       Nacionalidad       |   Sonido      |   Jugadores      |   Fichas   \n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < tam; i++) {
		if (!arcades[i].isEmpty) {
			mostrarArcade(arcades[i]);
		}
	}
}

int buscarArcadePorId(eArcade arcades[], int tam, int id) {
	int indice = -1;

	if (arcades != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (arcades[i].id == id) {
				indice = i;
			}
		}
	}

	return indice;
}

int juegoNoExiste(eArcade arcades[], int tam, char juego[]) {
	return 0;
}

void imprimirJuegos(eArcade arcades[], int tam) {
	if (arcades != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (!arcades[i].isEmpty) {
				printf("Juego %d: %s\n", (i + 1), arcades[i].nombre);
			}
		}
	}
}



























