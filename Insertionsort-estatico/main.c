#include <stdio.h>
#define TAM 5
                  
int vetor[TAM] = {5,4,3,2,1};

void insertionSort(int v[]){
	int i,j,pivo;
	
	for(i = 1; i < TAM; i++){
		j = i - 1;
		pivo = v[i];
		
		while (j >= 0 && v[j] > pivo){
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = pivo;
	}
}


void listar(int v[]){
	int i;
	
	printf("\n\nListando\n\n");
	for (i = 0; i < TAM; i++)
		printf("%d ",v[i]);
}


int main(int argc, char **argv)
{
	
	listar(vetor);
	insertionSort(vetor);
	listar(vetor);
	
	return 0;
}

