#include <stdio.h>
#define TAM 5
                  
int vetor[TAM];// = {5,4,3,2,1};

void SelectionSort(int v[]){
	int temp,i,j;
	for (i = 0; i < TAM - 1; i++){
		for (j = i + 1; j < TAM; j++){
			if (v[j] < v[i]){
				temp = v[j];
				v[j] = v[i];
				v[i] = temp;
			}
		}
	}
}

void SelectionSortEstavel(int v[]){
	int temp,i,j,menor;
	for (i = 0; i < TAM - 1; i++){
		menor = i;
		for (j = i + 1; j < TAM; j++){
			if (v[j] < v[menor]){
				menor = j;
			}
		} 
		temp = v[menor];
		v[menor] = v[i];
		v[i] = temp;
	}
}

void SelectionSortEstavelMelhorado(int v[]){
	int temp,i,j,menor;
	for (i = 0; i < TAM - 1; i++){
		menor = i;
		for (j = i + 1; j < TAM; j++){
			if (v[j] < v[menor]){
				menor = j;
			}
		} 
		if (i != menor){
			temp = v[menor];
			v[menor] = v[i];
			v[i] = temp;
		}
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
	int i;
	for(i = 0; i < TAM; i++){
		printf("Informe o numero: ");
		scanf("%d",&vetor[i]);
	}
	
	listar(vetor);
	SelectionSortEstavel(vetor);
	listar(vetor);
	
	return 0;
}

