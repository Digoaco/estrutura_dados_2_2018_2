#include <stdio.h>
#include <stdlib.h>

typedef struct SArvore{
	struct SArvore * esq;
	int info;
	struct SArvore * dir;
	
} TArvore;



TArvore * noPai = NULL;
int tipo; // 0 -> raiz, 1 -> esq, 2 -> dir
	
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

void preencherABB(TArvore * no, int informacao){
	TArvore * novo;
	if (no == NULL)
		return;
		
		if (informacao < no->info){
			if (no->esq == NULL){
				novo = malloc(sizeof(TArvore));
				novo->info = informacao;
				novo->dir = novo->esq = NULL;
				no->esq = novo;
			}else{
				preencherABB(no->esq, informacao);
			}
		}else if (informacao > no->info){
				if (no->dir == NULL){
					novo = malloc(sizeof(TArvore));
					novo->info = informacao;
					novo->dir = novo->esq = NULL;
					no->dir = novo;
				}else{
					preencherABB(no->dir, informacao);
				}
			}else{
				printf("Valor ja inserido na arvore");
			}
}

TArvore * buscaBinariaPai(TArvore * no, int key){
	if (no == NULL)
		return NULL;
	
	if (key == no->info){
		return no;
	}
	else
		if (key < no->info){
			tipo = 1;
			noPai = no;
			return buscaBinariaPai(no->esq, key);
		}
		else{
			tipo = 2;
			noPai = no;
			return buscaBinariaPai(no->dir,key);
		}
}

TArvore * buscaBinaria(TArvore * no, int key){
	if (no == NULL)
		return NULL;
	
	if (key == no->info)
		return no;
	else
		if (key < no->info)
			return buscaBinaria(no->esq, key);
		else
			return buscaBinaria(no->dir,key);
}

void deletarArvore(TArvore * no, int key){
	
	TArvore * pos = buscaBinariaPai(no, key);
	if (pos == NULL){
		printf("Chave nao encontrada");
		return;
	}
	
	pos->esq->dir->dir = pos->dir;
	if (tipo == 1)
		noPai->esq = pos->esq;
	else
		noPai->dir = pos->esq;
	free(pos);	
}

void alterarArvore(TArvore * no, int key, int novoValor){
	
	TArvore * pos = buscaBinaria(no, key);
	if (pos == NULL){
		printf("Chave nao encontrada");
		return;
	}
	
	_Bool permitido = 1;
	if ((pos->esq != NULL) && (pos->esq->info > novoValor))
		permitido = 0;
	if ((pos->dir != NULL) && (pos->dir->info < novoValor))
		permitido = 0;
		
	if (permitido)
		pos->info = novoValor;
	else 
		printf("Alteracao nao permitida");
}



int main(int argc, char **argv)
{
	int leitura;
	scanf("%d",&leitura);
	criarRaiz(leitura);
	
	while(1){
		
		printf("Infome o valor: ");
		scanf("%d",&leitura);
		if (leitura == 0)
			break;
		preencherABB(raiz,leitura);
	}
	central(raiz);
	/*
	int chave;
	printf("\nInforme a chave da busca: ");
	scanf("%d",&chave);
	TArvore * pos = buscaBinaria(raiz,chave);
	
	if (pos == NULL)
		printf("Chave nao encontrada\n");
	else
		printf("Chave encontrada na posicao: %p\n", pos);
		
	alterarArvore(raiz, 5, 6);*/
	tipo = 0;
	deletarArvore(raiz, 25);
	printf("apos deletar \n\n");
	central(raiz);
	return 0;
}

