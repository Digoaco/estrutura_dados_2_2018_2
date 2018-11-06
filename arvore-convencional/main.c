#include <stdio.h>
#include <stdlib.h>

typedef struct SArvore{
	struct SArvore * filho;
	int info;
	struct SArvore * irmao;	
} TArvore;

	
TArvore * raiz;

void profundidade (TArvore * no){
	if (no == NULL)
		return;
		
	printf("%d ",no->info);
	profundidade(no->filho);
	profundidade(no->irmao);
	
}

void largura (TArvore * no){
	if (no == NULL)
		return;
		
	printf("%d ",no->info);
	largura(no->irmao);
	largura(no->filho);
	
}



void criarRaiz(int informacao){
	raiz = malloc(sizeof(TArvore));
	raiz->info = informacao;
	raiz->filho = raiz->irmao = NULL;
}

void preencher(TArvore * no){
	int leitura;
	TArvore * novo;
	TArvore * irmao;
	
	if (no == NULL)
		return;
			
	while(1){
		printf("Pai: %d, informe o valor do nó: ", no->info);
		scanf("%d",&leitura);
		if (leitura == 0)
			break;
		
		novo = malloc(sizeof(TArvore));
		novo->info = leitura;
		novo->filho = novo->irmao = NULL;
		
		if (no->filho == NULL){
			no->filho = novo;
			irmao = novo; 
		}
		else{
			irmao->irmao = novo;	
			irmao = novo;
		}
	}
	preencher(no->filho);
	preencher(no->irmao);
}

TArvore * novo(){
	TArvore * node = malloc(sizeof(TArvore));
	node->filho = node->irmao = NULL;
	return node;
	
}

int main(int argc, char **argv)
{
	TArvore * node;
	int leitura;
	scanf("%d",&leitura);
	criarRaiz(leitura);
	preencher(raiz);
	/*
	node = novo();
	node->info = 2;
	raiz->filho = node;
	
	node = novo();
	node->info = 3;
	raiz->filho->irmao = node;
	
	node = novo();
	node->info = 4;
	raiz->filho->irmao->irmao = node;
	
	node = novo();
	node->info = 8;
	raiz->filho->irmao->irmao->filho = node;
	
	node = novo();
	node->info = 5;
	raiz->filho->filho = node;
	
	node = novo();
	node->info = 6;
	raiz->filho->filho->irmao = node;
	
	node = novo();
	node->info = 7;
	raiz->filho->filho->irmao->irmao = node;
	*/
	printf("\n\nProfundidade\n");
	profundidade(raiz);
	printf("\n\nLargura\n");
	largura(raiz);
	
	
	return 0;
}

