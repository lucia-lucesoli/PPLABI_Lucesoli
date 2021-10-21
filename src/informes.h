/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Primer Parcial - LABORATORIO I
 ============================================================================
 */


#include "salones.h"
#include "arcades.h"

#ifndef INFORMES_H_
#define INFORMES_H_



#endif /* INFORMES_H_ */

int desplegarSubmenu();

void listarSalonesConMasDe4Arcades(eSalones salones[], int tam, eArcade arcades[], int tam_a);
void listarArcadesParaMasDe2Jugadores(eSalones salones[], int tam, eArcade arcades[], int tam_a);
void mostrarInforSalon(eSalones salon, eArcade arcades[], int tam);
void mostrarInfoArcades(eArcade arcades[], int tam, eSalones salon);
void mostrarSalonConMasArcades(eSalones salones[], int tam, eArcade arcades[], int tam_a);
void mostrarCantidadDeArcadesPorJuego(eArcade arcades[], int tam, char juego[]);
void imprimirMontoMaxPesos(eSalones salon, int valorFicha, eArcade arcades[], int tam);
void salonCompleto(eSalones salones[], int tam, eArcade arcades[], int tam_a);
void promedioArcadesSalon(eSalones salones[], int tam, eArcade arcades[], int tam_a);

