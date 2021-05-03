#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int buscar(int *lista, int tamanho, int valor_buscado)
{
    int i;

    for (i = 0; i < tamanho; i++)
    {
        if (lista[i] == valor_buscado)
        {
            return i;
        }
    }

    if (i == tamanho)
    {
        return -1;
    }
}

int main()
{
    FILE *arq;
    clock_t clock_inicial, clock_final;
    int *lista;
    int contador, valor_buscado, busca;
    long int numero;

    // alocação para uma quantidade máxima de 1 milhão de ints na lista
    lista = malloc(1000000 * sizeof(int));

    // leitura dos dados em disco (arquivo) para um vetor
    arq = fopen("lista.txt", "r");
    contador = 0;
    while (fscanf(arq, "%ld", &numero) > 0)
    {
        lista[contador] = numero;
        contador++;
    }
    fclose(arq);
    // fecha o arquivo ao fim da leitura

    // define valor a ser buscado e executa o algoritmo
    printf("Digite um numero para buscar: ");
    scanf("%d", &valor_buscado);

    clock_inicial = clock();
    busca = buscar(lista, contador, valor_buscado);
    clock_final = clock();

    // se o retorno da busca for um índice negativo, o valor não está presente na lista
    if (busca == -1)
        printf("Valor não encontrado!\n");
    else
        printf("Valor encontrado na posição %d.\n", busca + 1);

    printf("Tempo decorrido: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));

    return 0;
}