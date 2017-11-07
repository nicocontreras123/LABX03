#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

typedef struct pila{
	Nodo* tope;
	int tam;
}Pila;

Cola *crearCola(){
	Cola *c;
	if(c=(Cola*)malloc(sizeof(Cola))){
		c->ini=NULL;
		c->fin=NULL;
		c->tam=0;
	}else{
		printf("ERROR EN LA ASIGNACION DE MEMORIA");
	}
	return c;
}

Pila *Crearpila(){
	Pila *p;
	if(p=(Pila*)malloc(sizeof(Pila))){
		p->tope=NULL;
		p->tam=0;
	}else{
		printf("No hay suficiente memoria");
	}
	return p;
}


Info *crearInfo(int c){
	Info *Newinfo;
	if(Newinfo=(Info*)malloc(sizeof(Info))){
		Newinfo->dato=c;
	}else{
		printf("NO HAY SUFICIENTE MEMORIA");
	}
	return Newinfo;
	
}


bool esVacia(Cola *c){
	if(c->ini==NULL){
		return true;
	}else{
		return false;
	}
}

bool esVaciaP(Pila *p){
	
}

void Push(Pila *p, int pval){
	Info *info;
	info = crearInfo(pval);
	Nodo *newNodo;
	if(newNodo=(Nodo*)malloc(sizeof(Nodo))){
		newNodo->valor=info;
		newNodo->sgte=p->tope;
		p->tope=newNodo;
		p->tam++;
	}else{
		printf("no hay memoria");
	}
}

void encolar(Cola *c, int pval){
	Info *pinf;
	pinf= crearInfo(pval);
	Nodo *newNodo;
	if(newNodo=(Nodo*)malloc(sizeof(Nodo))){
		if(esVacia(c)){
			c->ini=newNodo;
		}else{
			c->fin->sgte=newNodo;
		}
		c->fin=newNodo;
		newNodo->sgte=NULL;
		newNodo->valor=pinf;
		c->tam++;
	}else{
		printf("No hay suficiente memoria");
	}
}


Info *desencolar(Cola *c){
	Nodo *aux;
	Info *inf;
	if(esVacia(c)){
		printf("La cola esta vacia, no se puede desencolar");
	}else{
		aux=c->ini; //aux almacenara el inicio de la cola
		inf=aux->valor; //inf almacenara la informacion a eliminar
		c->ini=aux->sgte; //se asignara el segundo nodo al incio de la cola
		c->tam--; //se reduce en uno el valor del tamaño
		free(aux); //se elimina nodo 
	}
	return inf;  //retornamos el informacion
}

Nodo *primero(Cola *c){
	return c->ini;
}

Nodo *ultimo(Cola *c){
	return c->fin;
}

void recorrerCola(Cola *c){
	Nodo *aux;
	int i;
	aux=c->ini;
	if(esVacia(c)){
		printf("\nLa cola esta vacia no se puede recorrer");
	}else{
		while(aux!=NULL){
			printf("\n%d ", aux->valor->dato);
			aux=aux->sgte;
			i=i+1;
		}
	}
}
//


Cola *incrementar(Cola *c){
	Cola *c1;
	c1 = crearCola();
	int val;
	Nodo *aux;
	aux= (Nodo*) malloc(sizeof(Nodo));
	aux = c->ini;
	while(aux != NULL){
		int val = aux->valor->dato;
		aux= aux->sgte;
		encolar(c1, val+1);
	}
	return c1;
}

void intercambiarNodo(Cola *c){
	Nodo *aux1, *aux2;
	Info *in1, *inf2;
	aux1= (Nodo*)malloc(sizeof(Nodo));
	aux2= (Nodo*)malloc(sizeof(Nodo));
	aux1=c->ini;
	in1=aux1->valor;
	int au1= in1->dato;
	printf("\naux1: %d", au1);
	aux2=c->ini->sgte;
	inf2=aux2->valor;
	int au2= inf2->dato;
	printf("\naux2: %d", au2);
	aux1->valor->dato=au2;
	aux2->valor->dato=au1;

}

Info *desapilar(Pila *p){
	Nodo *aux;
	Info *inf;
	if(p->tam==0){
		printf("No hay nada en la pila");
	}else{
		aux=p->tope;
		inf=aux->valor;
		p->tope=aux->sgte;
		p->tam--;
		free(aux);
	}
	return inf;
}

void recorrerPila(Pila *p){
	
}

void invertirCola(Cola *c1){
	Pila *p;
	p = Crearpila();
	while(c1->ini!=NULL){
		Push(p, desencolar(c1));
		
	}
	while(p->tope!=NULL){
		encolar(c1,desapilar(p));
	}
}

void contar(Cola *c){
	int d=1;
	while(c->ini!=NULL){
		d=d+1;
	}
	printf("%d", d);
}

void vaciarCola(Cola *c){
	while(c->ini!=NULL){
		desencolar(c)->dato;
	}
	printf("\nPila Vacia! ");
}


