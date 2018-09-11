#include "library.h"

int trocas = 0;
void selectionSort(TFila * primeiro){
	TFila * atual, *proximo;
	int temp;
	for (atual = primeiro; atual->next != NULL; atual = atual->next){
		for (proximo = atual->next; proximo != NULL; proximo = proximo->next){
			if (proximo->info < atual->info){
				trocas++;
				temp = atual->info;
				atual->info = proximo->info;
				proximo->info = temp;
			}
		}
		
	}
}

void selectionSortEstavel(TFila * primeiro){
	TFila * atual, *proximo, *menor;
	int temp;
	for (atual = primeiro; atual->next != NULL; atual = atual->next){
		menor = atual;
		for (proximo = atual->next; proximo != NULL; proximo = proximo->next){
			if (proximo->info < menor->info){
				menor = proximo;
			}
		}
		if (atual != menor){
			trocas++;
			temp = atual->info;
			atual->info = menor->info;
			menor->info = temp;
		}
	}	
}


int main(int argc, char **argv)
{
	enfileirar(1);
	enfileirar(2);
	enfileirar(3);
	enfileirar(4);
	enfileirar(5);
	listar();
	selectionSortEstavel	(fila);
	listar();
	printf("trocas %d",trocas);
	return 0;
}

