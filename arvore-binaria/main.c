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

void criarRaiz(int informacao){
	raiz = malloc(sizeof(TArvore));
	raiz->info = informacao;
	raiz->dir = raiz->esq = NULL;
}

void preencher(TArvore * no){
	int leitura, cont = 1;
	TArvore * novo;
	
	if (no == NULL)
		return;	
	while (cont <= 2){
		printf("Pai: %d, informe o valor do nó: ", no->info);
		scanf("%d",&leitura);
		if (leitura == 0){
			cont++;
			continue;
		}
		novo = malloc(sizeof(TArvore));
		novo->info = leitura;
		novo->esq = novo->dir = NULL;
		if (cont == 1)
			no->esq = novo;
		else
			no->dir = novo;	
		cont++;
	}
	preencher(no->esq);
	preencher(no->dir);
}


int main(int argc, char **argv)
{
	criarRaiz(1);
	preencher(raiz);


	posFixado(raiz);


		return 0;
}

