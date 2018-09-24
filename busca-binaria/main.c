#include <stdio.h>
#define TAM 5000000
                  
int vetor[TAM];

int passos = 0;


int buscaLinear(int v[], int tamanho, int key){
	int i;
	for (i = 0; i < tamanho; i++){
		//passos++;
		if (v[i] == key)
			return i;	
	}
	return -1;
}


int buscaBinaria(int v[], int tamanho, int key){
	
	int inicio = 0;
	int fim = tamanho - 1;
	
	while (inicio <= fim){
		//passos++;
		int meio = (inicio + fim)/2;
		
		if (vetor[meio] == key)
			return meio;
		else 
			if (key > vetor[meio])
				inicio = meio + 1;
			else
				fim = meio - 1;		
	}	
	return -1;
}

int buscaBinariaRecursiva(int v[], int inicio, int fim, int key){	
	if (inicio > fim)
	  return -1;
		
	int meio = (inicio + fim)/2;
		
	if (vetor[meio] == key)
		return meio;
	else 
		if (key > vetor[meio])
			return buscaBinariaRecursiva(v,meio + 1,fim, key);
		else
			return buscaBinariaRecursiva(v,inicio,meio - 1,key);		
}



void popularVetor(int v[], int tamanho){
	int i;
	for (i = 0; i < tamanho; i++)
		v[i] = i;
}



int main(int argc, char **argv)
{
	int chave;
	popularVetor(vetor,TAM);
	
	scanf("%d",&chave);
	
	int posicao = buscaLinear(vetor,TAM, chave);
	if (posicao == -1)
		printf("nao encontrado\n");
	else
		printf("Chave encontrada na posicao: %d\n",posicao);
		
	//printf("\n\nPassos(linear): %d\n\n",passos);
	
	//passos = 0; 
	
	posicao = buscaBinariaRecursiva(vetor,0,TAM -1, chave);
	if (posicao == -1)
		printf("nao encontrado");
	else
		printf("Chave encontrada na posicao: %d",posicao);
		
	//printf("\n\nPassos(binaria): %d\n\n",passos);
	
	return 0;
}

