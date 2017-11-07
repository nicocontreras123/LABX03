#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "cola.h"

typedef struct info{
	int dato;
}Info;

typedef struct nodo{
	Info *valor;
	struct Nodo* sgte;
}Nodo;

typedef struct cola{
	Nodo *ini;
	Nodo *fin;
	int tam;
}Cola;


typedef struct Ruleta{
	Cola *ruleta;
	int tam;
}Ruleta;



Ruleta *crearRuleta(int val){
	Ruleta *rul;
	if(rul=(Ruleta*)malloc(sizeof(Ruleta))){
		rul->ruleta=crearCola();
		rul->tam=val;
		srand(time(NULL));
		int p;
		for(p=0;p<val;p++){
			p=1+rand()%(100-1);
			encolar(rul->ruleta,p);
		}
	}else{
		printf("No hay memoria suficiente");
	}
	return rul
}


void Darvuelta(Ruleta *rul){
    int p, i;
    p=1+rand()%(rul->tam);
    for (i=0; i<num;i++){
    	desencolar(rul->ruleta);
    }
    printf ("Al girar ruleta el valor es: %i\n",rul->ruleta->ini->valor->dato);
}

void Mostrar(Ruleta *rul) {
    while (rul->ruleta != NULL) {
        printf("Valor: %i\n", ruleta->ruleta->start->value);
        desencolar(rul->ruleta);
    }
}
