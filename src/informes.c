/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Primer Parcial - LABORATORIO I
 ============================================================================
 */


#include "informes.h"
#include "salones.h"
#include "arcades.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int desplegarSubmenu() {
	int opcion = -1;

	printf("1) Listar los salones con más de 4 arcades. Indicando ID de salón, nombre, dirección y tipo de salón."
			"\n2) Listar los arcades para más de 2 jugadores, indicando ID de arcade, cantidad de jugadores, nombre del juego y nombre del salón al que pertenece."
			"\n3) Listar toda la información de un salón en específico ingresando su ID. Imprimir nombre, tipo y dirección y cantidad de arcades que posee."
			"\n4) Listar todos los arcades de un salón determinado ingresando su ID. Informar nombre y tipo de salón, listar todos los arcades con sus datos junto con el nombre del juego que lo compone."
			"\n5) Imprimir el salón con más cantidad de arcades, indicando todos los datos del salón y la cantidad de arcades que posee."
			"\n6) Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen.\n\n");

	scanf("%d", &opcion);

	return opcion;
}

void listarSalonesConMasDe4Arcades(eSalones salones[], int tam, eArcade arcades[], int tam_a) {
	int contador = 0;
	for (int i = 0; i < tam; i++) {
		if (!salones[i].isEmpty) {
			for (int j = 0; j < tam_a; j++) {
				if (!arcades[j].isEmpty) {
					if (salones[i].id == arcades[j].idSalon) {
						contador++;
					}
					if (contador >= 4) {
						mostrarSalon(salones[i]);
						contador = 0;
						break;
					}
				}
			}
		}
	}
}
void listarArcadesParaMasDe2Jugadores(eSalones salones[], int tam, eArcade arcades[], int tam_a) {
	for (int i = 0; i < tam; i++) {
		if (!arcades[i].isEmpty && arcades[i].jugadores >= 2) {
			mostrarArcade(arcades[i]);
			printf("Salon: %s\n:", salones[buscarSalonesPorid(salones, tam, arcades[i].idSalon)].nombre);
		}
	}
}
void mostrarInforSalon(eSalones salon, eArcade arcades[], int tam) {
	int contador = 0;
	for (int i = 0; i < tam; i++) {
		if (!arcades[i].isEmpty && arcades[i].idSalon == salon.id) {
			contador++;
		}
	}
	mostrarSalon(salon);
	printf("\nCantidad de arcades: %d\n", contador);
}
void mostrarInfoArcades(eArcade arcades[], int tam, eSalones salon) {
	printf("Salon %s\n", salon.nombre);
	printf("Tipo: %s\n", salon.tipo);
	for (int i = 0; i < tam; i++) {
		if (!arcades[i].isEmpty && arcades[i].idSalon == salon.id) {
			mostrarArcade(arcades[i]);
		}
	}

}
void mostrarSalonConMasArcades(eSalones salones[], int tam, eArcade arcades[], int tam_a) {
	eSalones salon;
	int contadorArcades = 0;
	int contadorArcadesAnterior = 0;

	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam_a; j++) {
			if (arcades[j].idSalon == salones[i].id) {
				contadorArcades++;
			}
		}
		if (contadorArcades >= contadorArcadesAnterior) {
			salon = salones[i];
			contadorArcadesAnterior = contadorArcades;
		}
		contadorArcades = 0;
	}

	mostrarSalon(salon);
}
void mostrarCantidadDeArcadesPorJuego(eArcade arcades[], int tam, char juego[]) {
	int contador = 0;
	for (int i = 0; i < tam; i++) {
		if (strcmp(arcades[i].nombre, juego) == 0) {
			contador++;
		}
	}
	printf("\nCantidad de arcades: %d\n", contador);
}
