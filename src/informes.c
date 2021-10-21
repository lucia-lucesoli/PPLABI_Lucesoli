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

	printf("1) Listar los salones con mas de 4 arcades. Indicando ID de salon, nombre, direccion y tipo de salon."
			"\n2) Listar los arcades para mas de 2 jugadores, indicando ID de arcade, cantidad de jugadores, nombre del juego y nombre del salon al que pertenece."
			"\n3) Listar toda la informacion de un salon en especifico ingresando su ID. Imprimir nombre, tipo y direccion y cantidad de arcades que posee."
			"\n4) Listar todos los arcades de un salon determinado ingresando su ID. Informar nombre y tipo de salon, listar todos los arcades con sus datos junto con el nombre del juego que lo compone."
			"\n5) Imprimir el salon con mas cantidad de arcades, indicando todos los datos del salon y la cantidad de arcades queposee."
			"\n6) Ingresar el ID de un salon, y el valor en pesos de una ficha, e imprimir el monto maximo en pesos que puede recaudar el salon (sumar cantidad de fichas maximo de cada arcade del salon y multiplicarla por el valor en pesos ingresado)"
			"\n7) Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen."
			"\n8) Un salon se encuentra equipado por completo si posee al menos 8 arcades de mas de 2 jugadores. Listar los salones que cumplan con este minimo de requisito."
			"\n9) Imprimir el promedio de arcades por salon. (Cantidad de arcades totales / Cantidad de salones totales).\n\n");


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
		if (!salones[i].isEmpty) {
			for (int j = 0; j < tam_a; j++) {
				if (!arcades[j].isEmpty && arcades[j].idSalon == salones[i].id) {
					contadorArcades++;
				}
			}
			if (contadorArcades >= contadorArcadesAnterior) {
				salon = salones[i];
				contadorArcadesAnterior = contadorArcades;
			}
			contadorArcades = 0;
		}
	}
	mostrarSalon(salon);
	printf("\nCantidad de arcades: %d", contadorArcadesAnterior);
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

void imprimirMontoMaxPesos(eSalones salon, int valorFicha, eArcade arcades[], int tam){
	int contFichas = 0;

	for(int i = 0; i < tam; i++){
		if(!arcades[i].isEmpty && arcades[i].idSalon == salon.id){
			contFichas += arcades[i].fichas;
		}
	}

	int recaudacionMax = valorFicha * contFichas;
	printf("Monto maximo a recaudar: %d\n", recaudacionMax);

}






void promedioArcadesSalon(eSalones salones[], int tam, eArcade arcades[], int tam_a){
	int contSalon = 0;
	int contArcade = 0;

	for(int i = 0; i < tam; i++){
		if (!salones[i].isEmpty) {
		   contSalon++;
		}
	}

	for(int j = 0; j < tam_a; j++){
		if (!arcades[j].isEmpty) {
		   contArcade++;
		}
	}


	 if(contArcade == 0){
		 printf("Error, no se cargaron arcades.\n\n");
	 }else{
		 int promedio = contSalon / contArcade;
		 printf("El promedio de arcades por salon es: %d", promedio);
	 }



}



void salonCompleto(eSalones salones[], int tam, eArcade arcades[], int tam_a) {
   int contArcades = 0;
   for (int i = 0; i < tam; i++) {
      for (int j = 0; j < tam_a; j++) {
         if (arcades[j].idSalon == salones[i].id && arcades[j].jugadores >= 2) {
            contArcades++;
         }
         if (contArcades >= 8) {
            mostrarSalon(salones[i]);
            contArcades = 0;
            break;
         }
      }
   }
}

















