#include "library.h"

int passos = 0;

void bubbleSort(TFila * primeiro){
	TFila * atual,* proximo, * ultimo;
	int temp;
	for (ultimo = primeiro; ultimo != NULL; ultimo = ultimo->next){
		for (atual = primeiro; atual->next != NULL; atual = atual->next){
			passos++;
			proximo = atual->next;
			if (atual->info > proximo->info){
				temp = atual->info;
				atual->info = proximo->info;
				proximo->info = temp;
			}
		}
	}
}

void bubbleSortM1(TFila * primeiro){
	TFila * atual,* proximo, * ultimo;
	
	int temp;
	for (ultimo = primeiro; ultimo->next != NULL; ultimo = ultimo->next){
		for (atual = primeiro; atual->next != NULL; atual = atual->next){
			passos++;
			proximo = atual->next;
			if (atual->info > proximo->info){
				temp = atual->info;
				atual->info = proximo->info;
				proximo->info = temp;
			}
		}
	}
}

void bubbleSortM2(TFila * primeiro){
	TFila * atual,* proximo, * ultimo, *fim = NULL;
	
	int temp;
	for (ultimo = primeiro; ultimo->next != NULL; ultimo = ultimo->next){
		for (atual = primeiro; atual->next != fim; atual = atual->next){
			passos++;
			proximo = atual->next;
			if (atual->info > proximo->info){
				temp = atual->info;
				atual->info = proximo->info;
				proximo->info = temp;
			}
		}
		fim = atual;
	}
}

void bubbleSortM3(TFila * primeiro){
	TFila * atual,* proximo, * ultimo;
	int temp;
	_Bool estaOrdenado;
	for (ultimo = primeiro; ultimo != NULL; ultimo = ultimo->next){
		estaOrdenado = 1;
		for (atual = primeiro; atual->next != NULL; atual = atual->next){
			passos++;
			proximo = atual->next;
			if (atual->info > proximo->info){
				estaOrdenado = 0;
				temp = atual->info;
				atual->info = proximo->info;
				proximo->info = temp;
			}
		}
		if (estaOrdenado == 1)
			break;
	}
}

void bubbleSortM(TFila * primeiro){
	TFila * atual,* proximo, * ultimo, * fim = NULL;
	int temp;
	_Bool estaOrdenado;
	for (ultimo = primeiro; ultimo->next != NULL; ultimo = ultimo->next){
		estaOrdenado = 1;
		for (atual = primeiro; atual->next != fim; atual = atual->next){
			passos++;
			proximo = atual->next;
			if (atual->info > proximo->info){
				estaOrdenado = 0;
				temp = atual->info;
				atual->info = proximo->info;
				proximo->info = temp;
			}
		}
		fim = atual;
		if (estaOrdenado == 1)
			break;
	}
}


int main(int argc, char **argv)
{
	enfileirar(1);
	enfileirar(2);
	enfileirar(5);
	enfileirar(4);
	enfileirar(3);
	listar();
	bubbleSortM(fila);
	listar();
	printf("\n\nPassos: %d",passos);
	return 0;
}

