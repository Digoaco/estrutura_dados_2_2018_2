#include "library.h"

void insertionsort(TFila * primeiro){
	int pivo;
	TFila * atual, * anterior;
	for (atual = primeiro->next; atual != NULL; atual = atual->next){
		anterior = atual->prev;
		pivo = atual->info;
		while (anterior != NULL && anterior->info > pivo){
			anterior->next->info = anterior->info;
			anterior = anterior->prev;
		}
		if (anterior == NULL)
			primeiro->info = pivo;
		else
			anterior->next->info = pivo;		
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
	insertionsort(fila);
	listar();
	return 0;
}

