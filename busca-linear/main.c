#include <stdio.h>
#define TAM 5
                  
int vetor[TAM] = {4,3,5,2,1};

int buscaLinear(int v[], int tamanho, int key){
	int i;
	for (i = 0; i < tamanho; i++){
		if (v[i] == key)
			return i;	
	}
	return -1;
}





int main(int argc, char **argv)
{
	int chave;
	
	scanf("%d",&chave);
	
	int posicao = buscaLinear(vetor,TAM, chave);
	if (posicao == -1)
		printf("nao encontrado");
	else
		printf("Chave encontrada na posicao: %d",posicao);
	
	return 0;
}

