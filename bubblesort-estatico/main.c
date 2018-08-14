#include <stdio.h>
#define TAM 5
                  
int vetor[TAM] = {4,3,5,2,1};
int ciclos = 0;


void bubbleSort(int v[]){
	int temp,i,j;
	for (j = 0; j < TAM; j++){
		for (i = 0; i < TAM - 1; i++){
			ciclos++;
			if (v[i] > v[i + 1]){
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
			}
		}
	}
}

void bubbleSortM1(int v[]){
	int temp,i,j;
	for (j = 0; j < TAM - 1; j++){
		for (i = 0; i < TAM - 1; i++){
			ciclos++;
			if (v[i] > v[i + 1]){
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
			}
		}
	}
}

void bubbleSortM2(int v[]){
	int temp,i,j;
	for (j = 0; j < TAM; j++){
		for (i = 0; i < (TAM - 1) - j; i++){
			ciclos++;
			if (v[i] > v[i + 1]){
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
			}
		}
	}
}

void bubbleSortM3(int v[]){
	int temp,i,j;
	_Bool estaOrdenado;
	for (j = 0; j < TAM; j++){
		estaOrdenado = 1;
		for (i = 0; i < TAM - 1; i++){
			ciclos++;
			if (v[i] > v[i + 1]){
				estaOrdenado = 0;
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
			}
		}
		if (estaOrdenado == 1)
			break;
	}
}

void bubbleSortM(int v[]){
	int temp,i,j;
	_Bool estaOrdenado;
	for (j = 0; j < TAM -1; j++){
		estaOrdenado = 1;
		for (i = 0; i < (TAM - 1) - j; i++){
			ciclos++;
			if (v[i] > v[i + 1]){
				estaOrdenado = 0;
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
				
			}
		}
		if (estaOrdenado == 1)
			break;
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
	bubbleSortM(vetor);
	listar(vetor);
	printf("\nPassos: %d", ciclos);
	
	return 0;
}

