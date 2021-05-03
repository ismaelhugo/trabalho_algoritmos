#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define CAPACIDADE 1000000

struct fila
{
    int itens[CAPACIDADE];
    int inicio;
    int fim;
};

// inicializa fila com índices negativos, indicando que não contém itens
void initializeQueue(struct fila *queue)
{
    queue->inicio = -1;
    queue->fim = -1;
}

// verifica se a fila está vazia
int isQueueEmpty(struct fila queue)
{
    if (queue.inicio == -1)
        return 1;
    else
        return 0;
}

// recupera o valor no topo da fila (o mais antigo)
int getQueueStart(struct fila f)
{
    return f.itens[f.inicio];
}

// recupera o valor no topo da fila (o mais recente)
int getQueueEnd(struct fila queue)
{
    return queue.itens[queue.fim];
}

int insertIntoQueue(struct fila *queue, int valor)
{
    int novo_index = (queue->fim + 1) % CAPACIDADE;
    if (novo_index != queue->inicio)
    {
        queue->fim = novo_index;
        queue->itens[queue->fim] = valor;
        if (queue->inicio == -1)
        {
            queue->inicio = 0;
        }
        return 0;
    }
    else
    {
        printf("Overflow!");
        return -1;
    }
}

int removeFromQueue(struct fila *queue)
{
    int primeiro_index;
    if (queue->inicio != -1)
    {
        primeiro_index = queue->itens[queue->inicio];
        if (queue->inicio == queue->fim)
        {
            queue->inicio = -1;
            queue->fim = -1;
        }
        else
        {
            queue->inicio = (queue->inicio + 1) % CAPACIDADE;
        }
        return primeiro_index;
    }
    else
    {
        printf("Underflow!");
        return 0;
    }
}

int main()
{
    clock_t clock_inicial, clock_final;
    struct fila queue;

    initializeQueue(&queue);

    clock_inicial = clock();
    for (int i = CAPACIDADE; i > 0; i--)
    {
        insertIntoQueue(&queue, rand() % CAPACIDADE);
    }
    clock_final = clock();

    printf("Quantidade de inserções: %d \n", CAPACIDADE);
    printf("Tempo decorrido nas inserções: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));

    return 0;
}
