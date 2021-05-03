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

int bubblesort(int *lista, int tamanho)
{
    int i, j;
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho - 1; j++)
        {
            if (lista[j] > lista[j + 1])
            {
                int maior = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = maior;
            };
        };
    };
};

int main()
{
    FILE *arq;
    clock_t clock_inicial, clock_final;
    int *lista;
    int contador, valor_a_remover;
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

    clock_inicial = clock();
    bubblesort(lista, contador);
    clock_final = clock();

    printf("Tempo decorrido: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));

    return 0;
}
