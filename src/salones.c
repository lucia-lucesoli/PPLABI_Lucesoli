/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Primer Parcial - LABORATORIO I
 ============================================================================
 */

#include "salones.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int inicializarSalones(eSalones salones[], int tam)
{
	int error = 1;

	if (salones != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			salones[i].isEmpty = 1;
		}
		error = 0;
	}
	return error;
}

int altaSalones(eSalones salones[], int tam, int id, char nombre[], char direccion[], char tipo[])
{
	int error = 1;

	if (salones != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			if (salones[i].isEmpty)
			{
				salones[i].id = id;
				strcpy(salones[i].nombre, nombre);
				strcpy(salones[i].direccion, direccion);
				strcpy(salones[i].tipo, tipo);
				salones[i].isEmpty = 0;
				error = 0;
				break;
			}
		}
	}
	return error;
}

int bajaSalones(eSalones salones[], int indice)
{
	int error = 1;

	if (salones != NULL && indice >= 0) {
		salones[indice].isEmpty = 1;
		error = 0;
	}

	return error;
}

void mostrarSalon(eSalones salones)
{
	printf(" %5d     %15s      %15s      %15s\n", salones.id, salones.nombre, salones.direccion, salones.tipo);

}

void mostrarSalones(eSalones salones[], int tam)
{
	printf("                       *** Lista de Salones *** \n");
	printf("--------------------------------------------------------------------\n");
	printf("   ID    |       Nombre       |       Direccion       |   Tipo      \n");
	printf("--------------------------------------------------------------------\n");
		for (int i = 0; i < tam; i++) {
			if (!salones[i].isEmpty) {
				mostrarSalon(salones[i]);
			}
		}
}

int buscarSalonesPorid(eSalones salones[], int tam, int id) {
	int index = -1;

	if (salones != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (salones[i].id == id) {
				index = i;
			}
		}
	}

	return index;
}

int haySalonesAgregados(eSalones salones[], int tam) {
	int retorno = 0;

	if (salones != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (!salones[i].isEmpty) {
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}







































