#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int buscar(int *lista, int tamanho, int valor_buscado) {
   int i;

   for (i = 0; i < tamanho; i++) {
        if (lista[i] == valor_buscado) {
            return i;
	    }
   }
   if (i == tamanho) {
        return -1;
   }
}

int remover (int *lista, int tamanho, int valor_para_remover) {
   if(tamanho > 0) {
       int indice = buscar(lista, tamanho, valor_para_remover);
       if(indice > 0) {
            // modifica o valor de todos os itens que vêm após o item removido;
            // reordenando a lista para que não fique "furada"
           for(int i = indice; i < tamanho; i++) { 
               lista[i] = lista[i + 1]; 
            };
        };
    }
}

int main() {
    FILE *arq;
    clock_t clock_inicial, clock_final;
    int *lista;
    int contador, valor_a_remover;
    long int numero;

    // alocação para uma quantidade máxima de 1 milhão de ints na lista
    lista = malloc(1000000*sizeof(int));

    // leitura dos dados em disco (arquivo) para um vetor
    arq = fopen("lista.txt", "r");
    contador = 0;
    while (fscanf(arq, "%ld", &numero) > 0) {
        lista[contador] = numero;
	    contador++;
    }
    fclose(arq);
    // fecha o arquivo ao fim da leitura

    // define valor a ser removido e executa o algoritmo
    printf("Digite um numero para remover: ");
    scanf("%d", &valor_a_remover);

    clock_inicial = clock();
    remover(lista, contador, valor_a_remover);
    clock_final = clock();

    printf("Tempo decorrido: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));

    return 0;
}
