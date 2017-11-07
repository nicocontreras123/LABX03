#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "cola.h"
#include "ruleta.h"

int main(){
	int main(){
	Cola *c1;
	Cola *c2;
	Cola *c3;
	c1 = crearCola();
	c2 = crearCola();
	c3 = crearCola();
	Ruleta *r1;
	int op, op1, a, d;
	do{
		printf("\n1. Colas ");
		printf("\n2. Ruleta");
		printf("\nSalir");
		printf("\nopc: ");
		scanf("%d", &op);
		switch (op)
		{
			case 1:
				do{
					printf("\n1. Agregar Nodo ");
					printf("\n2. Recorrer Cola");
					printf("\nSalir");
					printf("\nopc: ");
					scanf("%d", &op1);
					switch (op1){
					case 1:
						printf("Ingrese valor a crear: ");
						scanf("%d", &a);
						encolar(c1, a);
						break;
				
					case 2:
						recorrerCola(c1);
						break;
					case 3:
						intercambiarNodo(c1);
						break;
					}
				
				}while(op!=3);
				break;
			case 2:
				do{
					printf("\nIngrese tamaño de ruleta: ")
					scanf("%d", &d);
					r1 = crearRuleta(d);
					printf("Ruleta Creada!");
					printf("===================");
					printf("\n1. Girar Ruleta ");
					printf("\n2. Mostrar Ruleta");
					printf("\nSalir");
					printf("\nopc: ");
					switch (op1){
						case 1:
							Darvuelta(r1);
							break;
						case 2:
							Mostrar(r1);
					}
					
				}
				
			
	}while(op!=3);

	}
}
