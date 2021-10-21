/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Trabajo Practico 2
 ============================================================================
 */

#include "inputs.h"
#include <stdlib.h>
#include <stdio.h>

int desplegarMenu() {
	int retorno = -1;
	int input;

	printf("***        SALONES DE JUEGOS ARCADE        ***\n\n"
			"1) Alta de Salones\n"
			"2) Eliminar Salones\n"
			"3) Imprimir Salones\n"
			"4) Incorporar arcade\n"
			"5) Modificar arcade\n"
			"6) Eliminar arcade\n"
			"7) Imprimir arcades\n"
			"8) Imprimir juegos\n"
			"9) Informes\n"

			"10) Salir\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &input);
	if (input >= 1 && input <= 10) {
		retorno = input;
	}

	return retorno;
}

