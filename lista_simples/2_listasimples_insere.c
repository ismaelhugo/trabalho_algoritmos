#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int buscar(int *lista, int tamanho, int valor_buscado) {
   int i;

   for (i = 0; i < tamanho; i++) {
        if ( lista[i] == valor_buscado) {
	        return i;
	    }
   }

   if (i == tamanho) {
        return -1;
   }
}

int inserir(int *lista, int tamanho, int capacidade, int valor_inserido) {
    if (tamanho < capacidade) {
        if (buscar(lista, tamanho, valor_inserido) == -1) {
                lista[tamanho + 1] = valor_inserido;
            tamanho = tamanho + 1;
        } else {
            // se o valor já existe na lista
            return -1;
        }
    } else {
        // erro = capacidade da lista atingida
        return -2;
    }
    // se obtiver sucesso na operação
    printf("valor inserido no indice %d \n", tamanho);
    return 0;
}

int main() {
    FILE *arq;
    clock_t clock_inicial, clock_final;
    int *lista;
    int contador, valor_a_inserir;
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

    // define valor a ser inserido e executa o algoritmo
    printf("Digite um numero para inserir: ");
    scanf("%d", &valor_a_inserir);

    clock_inicial = clock();
    inserir(lista, contador, 1000000, valor_a_inserir);
    clock_final = clock();

    printf("Tempo decorrido: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));

    return 0;
}
