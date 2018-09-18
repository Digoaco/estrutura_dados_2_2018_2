#include <stdio.h>
#define TAM 5
                  
int vetor[TAM] = {5,4,1,2,3};


int partition(int v[], int inicio, int fim){
	int atual,temp;
	int pivo = v[fim];
	int menores = inicio - 1;
	
	for (atual = inicio; atual < fim; atual++){
		if (v[atual] < pivo){
			menores++;
			if (menores != atual){
				temp = v[atual];
				v[atual] = v[menores];
				v[menores] = temp;
			}
		}
	}
	int meio = menores + 1;
	temp = v[meio];
	v[meio] = v[fim];
	v[fim] = temp;
	return meio;
}

void quickSort(int v[], int inicio, int fim){
	if (inicio < fim) {
		int meio = partition(v,inicio,fim);
		quickSort(v,inicio, meio - 1);
		quickSort(v, meio + 1, fim);	
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
	quickSort(vetor,0, TAM -1);
	listar(vetor);
	return 0;
}

