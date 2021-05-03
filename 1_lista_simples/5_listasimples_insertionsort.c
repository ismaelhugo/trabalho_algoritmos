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

void insertionsort(int *lista, int tamanho)
{
    int i, j, numero_selecionado;
    for (i = 1; i < tamanho; i++)
    {
        numero_selecionado = lista[i];
        j = i - 1;

        // enquanto o indice J existir, olhamos para o item selecionado e 
        // verificamos se ele é menor do que os itens já ordenados anteriormente
        // podemos dizer que esse while encontra a posição onde devemos inserir 
        // o valor que estamos averiguando
        while ((j >= 0) && (numero_selecionado < lista[j]))
        {
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j + 1] = numero_selecionado;
    }
}

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
    insertionsort(lista, contador);
    clock_final = clock();

    printf("Tempo decorrido: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));

    return 0;
}
