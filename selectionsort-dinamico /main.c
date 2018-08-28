#include "library.h"

void selectionSort(TFila * primeiro){
	TFila * atual, *proximo;
	int temp;
	for (atual = primeiro; atual->next != NULL; atual = atual->next){
		for (proximo = atual->next; proximo != NULL; proximo = proximo->next){
			if (proximo->info < atual->info){
				temp = atual->info;
				atual->info = proximo->info;
				proximo->info = temp;
			}
		}
		
	}
	
}


int main(int argc, char **argv)
{
	enfileirar(5);
	enfileirar(4);
	enfileirar(3);
	enfileirar(2);
	enfileirar(1);
	listar();
	selectionSort(fila);
	listar();
	return 0;
}

