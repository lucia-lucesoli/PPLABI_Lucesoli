/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Primer Parcial - LABORATORIO I
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "salones.h"
#include "inputs.h"
#include "arcades.h"
#include <string.h>
#include "informes.h"

#define TAM 100
#define TAM_A 1000

int main(void) {
	setbuf(stdout,NULL);
	int corriendo = 1;
	eSalones salones[TAM];
	eArcade arcades[TAM_A];
	char nombre[60];
	char direccion[60];
	char tipo[60];

	int idSalonArcade;
	char nombreArcade[63];
	char nacionalidadArcade[50];
	char sonidoArcade[10];
	int jugadoresArcade;
	int fichasArcade;

	int idArcade = 5001;
	int idSalon = 1001;
	int idSalonTemp;
	int idArcadeTemp;
	int indiceSalon;
	int indiceArcade;
	char confirma;
	int valorFicha;

	if (!inicializarSalones(salones, TAM) && !inicializarArcade(arcades, TAM_A)) {
		//ALTA FORZADA SALONES
		altaSalones(salones, TAM, idSalon, "Salon 1", "CABA", "SALON");
		idSalon++;
		altaSalones(salones, TAM, idSalon, "Salon 2", "CORDOBA", "SHOPPING");
		idSalon++;
		altaSalones(salones, TAM, idSalon, "Salon 3", "BARILOCHE", "SALON");
		idSalon++;
		altaSalones(salones, TAM, idSalon, "Salon 4", "ROSARIO", "SALON");
		idSalon++;

		//ALTA FORZADA ARCADES
		altaArcade(arcades, TAM_A, idArcade, 1001, "Japon", "MARIO-BROS", "MONO", 2, 9);
		idArcade++;
		altaArcade(arcades, TAM_A, idArcade, 1001, "USA", "MORTAL-KOMBAT", "ESTEREO", 2, 9);
		idArcade++;
		altaArcade(arcades, TAM_A, idArcade, 1001, "Japon", "LOL", "MONO", 2, 9);
		idArcade++;
		altaArcade(arcades, TAM_A, idArcade, 1001, "USA", "ZELDA", "ESTEREO", 2, 9);
		idArcade++;
		altaArcade(arcades, TAM_A, idArcade, 1001, "Japon", "METROID", "MONO", 2, 9);
		idArcade++;
		altaArcade(arcades, TAM_A, idArcade, 1001, "USA", "FINAL-FANTASY", "ESTEREO", 2, 9);
		idArcade++;
		altaArcade(arcades, TAM_A, idArcade, 1001, "Japon", "POKEMON", "MONO", 2, 9);
		idArcade++;
		altaArcade(arcades, TAM_A, idArcade, 1001, "USA", "LUIGI", "ESTEREO", 2, 9);
		idArcade++;
		altaArcade(arcades, TAM_A, idArcade, 1002, "Japon", "HUGO", "MONO", 2, 9);
		idArcade++;
		altaArcade(arcades, TAM_A, idArcade, 1002, "Japon", "DAYTONA", "ESTEREO", 4, 5);
		idArcade++;
		altaArcade(arcades, TAM_A, idArcade, 1003, "Japon", "TETRIS", "MONO", 2, 9);
		idArcade++;
		altaArcade(arcades, TAM_A, idArcade, 1003, "Japon", "DAYTONA", "ESTEREO", 4, 5);
		idArcade++;
		altaArcade(arcades, TAM_A, idArcade, 1004, "Japon", "TETRIS", "MONO", 2, 9);
		idArcade++;
		altaArcade(arcades, TAM_A, idArcade, 1004, "Japon", "DAYTONA", "ESTEREO", 4, 5);
		idArcade++;

		while (corriendo) {
			system("clear");
			fpurge(stdin);
			switch(desplegarMenu()) {
			case 1:
				printf("Ingrese el nombre: ");
				fpurge(stdin);
				scanf("%s", nombre);
				printf("\nIngrese la direccion: ");
				fpurge(stdin);
				scanf("%s", direccion);
				printf("\nIngrese el tipo (SALON | SHOPPING): ");
				fpurge(stdin);
				scanf("%s", tipo);

				if (strcmp(tipo, "SALON") == 0 || strcmp(tipo, "SHOPPING") == 0) {
					if (!altaSalones(salones, TAM, idSalon, nombre, direccion, tipo)) {
						printf("\n\nAgregado salon:\n\n");
						mostrarSalon(salones[buscarSalonesPorid(salones, TAM, idSalon)]);
						idSalon++;
					} else {
						printf("\nError\n");
					}
				} else {
					printf("\n\nIngrese un tipo valido\n\n");
				}

				break;
			case 2:
				if (haySalonesAgregados(salones, TAM)) {
					mostrarSalones(salones, TAM);
					printf("\nIngrese el ID del salon a eliminar: ");
					scanf("%d", &idSalonTemp);

					indiceSalon = buscarSalonesPorid(salones, TAM, idSalonTemp);

					if (indiceSalon != -1) {
						bajaArcadesPorBajaSalon(arcades, TAM_A, idSalonTemp);
						bajaSalones(salones, indiceSalon);
					} else {
						printf("\nNo se encontro un salon con ese ID\n\n");
					}
				} else {
					printf("\nNo hay salones agregados\n\n");
				}

				break;
			case 3:
				mostrarSalones(salones, TAM);
				break;
			case 4:
				if (haySalonesAgregados(salones, TAM)) {
					mostrarSalones(salones, TAM);
					printf("\n\nIngrese el ID del salon al que se incorpora el arcade: ");
					scanf("%d", &idSalonArcade);
					printf("Ingrese el nombre del juego: ");
					fpurge(stdin);
					scanf("%s", nombreArcade);
					printf("\nIngrese la nacionalidad del arcade: ");
					fpurge(stdin);
					scanf("%s", nacionalidadArcade);
					printf("\nIngrese la cantidad de jugadores: ");
					scanf("%d", &jugadoresArcade);
					printf("\nIngrese la capacidad maxima de fichas: ");
					scanf("%d", &fichasArcade);
					printf("\nIngrese el tipo de sonido (MONO | ESTEREO): ");
					fpurge(stdin);
					scanf("%s", sonidoArcade);

					if (strcmp(sonidoArcade, "MONO") == 0 || strcmp(sonidoArcade, "ESTEREO") == 0) {
						if (!altaArcade(arcades, TAM_A, idArcade, idSalonArcade, nacionalidadArcade, nombreArcade, sonidoArcade, jugadoresArcade, fichasArcade)) {
							printf("\n\nAgregado arcade:\n\n");
							mostrarArcade(arcades[buscarArcadePorId(arcades, TAM_A, idArcade)]);
							idArcade++;
						}
					} else {
						printf("\n\nIngrese un tipo de sonido valido\n\n");
					}
				} else {
					printf("\nNo hay salones agregados\n\n");
				}

				break;
			case 5:
				if(hayArcadesAgregados(arcades, TAM_A)){
					mostrarArcades(arcades, TAM_A);
					printf("\n\nIngrese el ID del arcade a modificar: ");
					scanf("%d", &idArcadeTemp);

					indiceArcade = buscarArcadePorId(arcades, TAM_A, idArcadeTemp);

					if (indiceArcade != -1) {
						modificarArcade(arcades, indiceArcade);
					} else {
						printf("\n\nNo se encontro un arcade con ese ID\n\n");
					}
				}else{
					printf("\nNo hay Arcades agregados.");
				}
				break;
			case 6:
				if(hayArcadesAgregados(arcades, TAM_A)){

					mostrarArcades(arcades, TAM_A);
					printf("\n\nIngrese el ID del arcade a eliminar: ");
					scanf("%d", &idArcadeTemp);

					indiceArcade = buscarArcadePorId(arcades, TAM_A, idArcadeTemp);

					if (indiceArcade != -1) {
						mostrarArcade(arcades[indiceArcade]);
						printf("\n\nConfirma que desea eliminar? S/N\n");
						fpurge(stdin);
						scanf("%c", &confirma);

						if (confirma == 's' || confirma == 'S') {
							bajaArcade(arcades, indiceArcade);
						} else {
							printf("\n\nCancelando baja\n\n");
						}

					} else {
						printf("\n\nNo se encontro un arcade con ese ID\n\n");
					}

				}else{
					printf("\nNo hay Arcades agregados.");
				}

				break;
			case 7:
				mostrarArcades(arcades, TAM_A);
				break;
			case 8:
				imprimirJuegos(arcades, TAM_A);
				break;
			case 9:
				switch(desplegarSubmenu()) {
				case 1:
					listarSalonesConMasDe4Arcades(salones, TAM, arcades, TAM_A);
					break;
				case 2:
					listarArcadesParaMasDe2Jugadores(salones, TAM, arcades, TAM_A);
					break;
				case 3:
					mostrarSalones(salones, TAM);
					printf("\nIngrese el ID del salon: ");
					scanf("%d", &idSalonTemp);

					indiceSalon = buscarSalonesPorid(salones, TAM, idSalonTemp);

					if (indiceSalon != -1) {
						mostrarInforSalon(salones[indiceSalon], arcades, TAM_A);
					}

					break;
				case 4:
					mostrarSalones(salones, TAM);
					printf("\nIngrese el ID del salon: ");
					scanf("%d", &idSalonTemp);

					indiceSalon = buscarSalonesPorid(salones, TAM, idSalonTemp);

					if (indiceSalon != -1) {
						mostrarInfoArcades(arcades, TAM_A, salones[indiceSalon]);
					}
					break;
				case 5:
					mostrarSalonConMasArcades(salones, TAM, arcades, TAM_A);
					break;
				case 6:
					mostrarSalones(salones, TAM);
					printf("\nIngrese el ID del salon: ");
					scanf("%d", &idSalonTemp);

					indiceSalon = buscarSalonesPorid(salones, TAM, idSalonTemp);

					if (indiceSalon != -1) {
						printf("\nIngrese el valor de la ficha: ");
						scanf("%d", &valorFicha);
						imprimirMontoMaxPesos(salones[indiceSalon], valorFicha, arcades, TAM_A);
					}

					break;
				case 7:
					printf("\nIngrese el nombre del juego: ");
					scanf("%s", nombreArcade);
					mostrarCantidadDeArcadesPorJuego(arcades, TAM_A, nombreArcade);
					break;
				case 8:
					salonCompleto(salones, TAM, arcades, TAM_A);
					break;
				case 9:
					promedioArcadesSalon(salones, TAM, arcades, TAM_A);
					break;

				}

				break;
			case 10:
				corriendo = 0;
				break;
			default:
				printf("\nIngrese una opcion valida\n");
				break;
			}
			printf("\nPresione una tecla para continuar");
			fpurge(stdin);
			scanf("%c", &confirma);
		}
	} else {
		printf("Error");
	}

	return EXIT_SUCCESS;
}

