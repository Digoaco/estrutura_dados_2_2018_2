#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct SVertice{
	int info;
	_Bool visitado;
	struct SVertice * prox;
	struct SListaAdj * listaAdj;
}TVertice;

typedef struct SListaAdj{
	struct SVertice * vertice;
	struct SListaAdj * prox;
}TListaAdj;

TVertice * inicio;
TVertice * fim;


TVertice * buscarVertice(int informacao){
	TVertice * ultimo = inicio;
	while (ultimo != NULL){
		if (ultimo->info == informacao)
			return ultimo;
		ultimo = ultimo->prox;
	}
	return NULL;
}

TVertice * adicionarVertice(int informacao){
	TVertice * novo;
	
	novo = buscarVertice(informacao);
	if (novo != NULL)
		return novo;
	
	novo = malloc(sizeof(TVertice));
	novo->info = informacao;
	novo->visitado = FALSE;
	novo->prox = novo->listaAdj = NULL;
	
	if (inicio == NULL)
		inicio = novo;
	else
		fim->prox = novo;
		
	fim = novo;
	return novo;
}

void conectar(int informacao1, int informacao2){
	TVertice * vertice, *vertice2;
	
	vertice = adicionarVertice(informacao1);
	vertice2 = adicionarVertice(informacao2);
	
	TListaAdj * aresta = malloc(sizeof(TListaAdj));
	aresta->vertice = vertice2;
	aresta->prox = NULL;
	
	TListaAdj * listaArestas = vertice->listaAdj;
	if (listaArestas == NULL)
		vertice->listaAdj = aresta;
	else{
		while (listaArestas->prox != NULL)
			listaArestas = listaArestas->prox;
		listaArestas->prox = aresta;	
	}
}

void profundidade(TVertice * vertice){
	if (vertice == NULL)
		return;
		
	vertice->visitado = TRUE;
	printf("%d ",vertice->info);
	
	TListaAdj * lista = vertice->listaAdj;
	while (lista != NULL){
		if (lista->vertice->visitado == FALSE)
			profundidade(lista->vertice);
		lista = lista->prox;
	}		
}


int main(int argc, char **argv)
{
	int valor1, valor2;
	
	while (1){
		scanf("%d %d",&valor1, &valor2);
		if (valor1 == 0)
		 break;
		
		if (valor2 != 0)
			conectar(valor1, valor2);
		else
			adicionarVertice(valor1);	
	}
	
	profundidade(inicio);
	return 0;
}

