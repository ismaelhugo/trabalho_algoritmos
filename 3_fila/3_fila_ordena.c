#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define CAPACIDADE 1000000

struct fila
{
    int itens[CAPACIDADE];
    int indexInicio;
    int indexFim;
};

// inicializa fila com índices negativos, indicando que não contém itens
void initializeQueue(struct fila *queue)
{
    queue->indexInicio = -1;
    queue->indexFim = -1;
}

// recupera o índice inicial da fila, ou seja, o índice do item que será removido
int getStartIndex(struct fila queue)
{
    return queue.indexFim;
}

// recupera o índice do final da fila, ou seja, do item mais recentemente inserido
int getEndIndex(struct fila queue)
{
    return queue.indexFim;
}

// verifica se a fila está vazia
int isQueueEmpty(struct fila queue)
{
    if (queue.indexInicio == -1)
        return 1;
    else
        return 0;
}

// recupera o valor no topo da fila (o mais antigo)
int getQueueStart(struct fila f)
{
    return f.itens[f.indexInicio];
}

// recupera o valor no topo da fila (o mais recente)
int getQueueEnd(struct fila queue)
{
    return queue.itens[queue.indexFim];
}

int insertIntoQueue(struct fila *queue, int valor)
{
    int novo_index = (queue->indexFim + 1) % CAPACIDADE;
    if (novo_index != queue->indexInicio)
    {
        queue->indexFim = novo_index;
        queue->itens[queue->indexFim] = valor;
        if (queue->indexInicio == -1)
        {
            queue->indexInicio = 0;
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
    if (queue->indexInicio != -1)
    {
        primeiro_index = queue->itens[queue->indexInicio];
        if (queue->indexInicio == queue->indexFim)
        {
            queue->indexInicio = -1;
            queue->indexFim = -1;
        }
        else
        {
            queue->indexInicio = (queue->indexInicio + 1) % CAPACIDADE;
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

    for (int i = CAPACIDADE; i > 0; i--)
    {
        insertIntoQueue(&queue, rand() % CAPACIDADE);
    }

    int queue_size = getEndIndex(queue);

    clock_inicial = clock();
    for (int i = 0; i < queue_size; i++)
    {
        removeFromQueue(&queue);
    }
    clock_final = clock();

    printf("Quantidade de remoções: %d \n", CAPACIDADE);
    printf("Tempo decorrido nas remoções: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));

    return 0;
}
