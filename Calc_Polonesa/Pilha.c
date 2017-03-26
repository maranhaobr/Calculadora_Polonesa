#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include "Pilha.h"

#define TAM_MAX 50

struct pilha {
	int itens[TAM_MAX];
	int tp;
};

Pilha * criar() {
	Pilha * p = (Pilha *)malloc(sizeof(Pilha));
	p->tp = 0;
	return p;
}

void destruir(Pilha * p) {
	if (p != NULL) {
		free(p);
	}
}

int desempilhar(Pilha * p) {
	if (p->tp == 0) {
		printf("Pilha vazia");
		return -1;
	}
	return p->itens[--p->tp];
}

void empilhar(Pilha * p, int x) {
	if (p->tp == TAM_MAX) {
		printf("Estouro de pilha!");
		return;
	}
	p->itens[p->tp++] = x;
}

int tamanho(Pilha * p) {
	return p->tp;
}

int topo(Pilha * p) {
	if (p->tp == 0) {
		printf("Pilha vazia");
		return -1;
	}
	return p->itens[p->tp - 1];
}

void imprimir(Pilha * p) {
	int i;
	printf("[ ");
	for (i = 0; i<p->tp; i++) {
		printf("%d ", p->itens[i]);
	}
	printf("]\n");
}

void limpar(Pilha * p) {
	p->tp = 0;
}