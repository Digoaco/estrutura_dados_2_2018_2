#include <stdio.h>
#include <stdlib.h>

typedef struct SArvore{
	struct SArvore * esq;
	int info;
	struct SArvore * dir;
	
} TArvore;

TArvore * raiz;

void preFixado (TArvore * no){
	if (no == NULL)
		return;
		
	printf("%d ",no->info);
	preFixado(no->esq);
	preFixado(no->dir);
	
}

void posFixado (TArvore * no){
	if (no == NULL)
		return;
		
	posFixado(no->esq);
	posFixado(no->dir);
	printf("%d ",no->info);
	
}

void central (TArvore * no){
	if (no == NULL)
		return;
		
	central(no->esq);
	printf("%d ",no->info);
	central(no->dir);
	
}


int main(int argc, char **argv)
{
	TArvore * node;
	raiz = malloc(sizeof(TArvore));
	raiz->esq = raiz->dir = NULL;
	raiz->info = 10;
	
	node = malloc(sizeof(TArvore));
	node->esq = node->dir = NULL;
	node->info = 2;
	raiz->esq = node;
	
	node = malloc(sizeof(TArvore));
	node->esq = node->dir = NULL;
	node->info = 1;
	raiz->esq->esq = node;
	
	node = malloc(sizeof(TArvore));
	node->esq = node->dir = NULL;
	node->info = 3;
	raiz->esq->dir = node;
	
	node = malloc(sizeof(TArvore));
	node->esq = node->dir = NULL;
	node->info = 6;
	raiz->esq->dir->dir = node;
	
	node = malloc(sizeof(TArvore));
	node->esq = node->dir = NULL;
	node->info = 4;
	raiz->esq->dir->dir->esq = node;
	
	node = malloc(sizeof(TArvore));
	node->esq = node->dir = NULL;
	node->info = 5;
	raiz->esq->dir->dir->esq->dir = node;


	posFixado(raiz);


		return 0;
}

