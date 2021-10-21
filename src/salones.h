/*
 ============================================================================
 Nombre: Lucia Lucesoli
 Division: 1 - H
 Descripcion: Primer Parcial - LABORATORIO I
 ============================================================================
 */

#ifndef SALONES_H_
#define SALONES_H_

typedef struct {
	int id;
	char nombre[60];
	char direccion[60];
	char tipo[60];
	int isEmpty;
} eSalones;

#endif /* SALONES_H_ */

int inicializarSalones(eSalones salones[], int tam);
int altaSalones(eSalones salones[], int tam, int id, char nombre[], char direccion[], char tipo[]);
int bajaSalones(eSalones salones[], int indice);
void mostrarSalon(eSalones salones);
void mostrarSalones(eSalones salones[], int tam);
int buscarSalonesPorid(eSalones salones[], int tam, int id);
int haySalonesAgregados(eSalones salones[], int tam);
