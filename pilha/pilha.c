#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define CAPACIDADE 1000000

struct pilha {
	int itens[CAPACIDADE];
	int topIndex;
};

// inicializa pilha vazia (o topIndex sendo um índice inválido para os itens da pilha)
int initializeStack(struct pilha *stack) {
	stack->topIndex = -1;
}

// retornará o índice do topo da pilha, nos informando o tamanho total dela
int getTopIndex(struct pilha stack) {
    return stack.topIndex;
}

// verifica se o topIndex da pilha é o índice inválido que definimos
int isStackEmpty(struct pilha stack) {
	if (stack.topIndex == -1) return 1;
	else return 0;
}

// busca na lista de itens o índice
int getStackTop(struct pilha stack) {
	return stack.itens[stack.topIndex];
}

// insere no topo da pilha o valor que desejamos
int insertIntoStack(struct pilha *stack, int valor_inserido) {
	if (stack->topIndex != (CAPACIDADE - 1)) {
		stack->topIndex++;
		stack->itens[stack->topIndex] = valor_inserido;
		return 0;
	} else {
		printf("Overflow!");
		return -1;
	}
}

// opera apenas no índice do topo da pilha, portanto não necessita de um valor para remoção
int removeFromStack(struct pilha *stack) {
	int valor;
	if (stack->topIndex != -1) {
		valor = stack->itens[stack->topIndex];
		stack->topIndex--;
		return valor;
	} else {
		printf("Underflow!");
		return 0;
	}
}

// virtualmente identico ao bubblesort da lista
int stackBubbleSort(struct pilha *stack){
    int i, j = 0;

    for( i = 0; i < stack->topIndex; i++ )
    {
        for( j = i + 1; j < stack->topIndex; j++ )
        {
            if( stack->itens[i] > stack->itens[j] )
            {
                int aux = stack->itens[i];
                stack->itens[i] = stack->itens[j];
                stack->itens[j] = aux;
            }
        }
    }
}

int main() {
	struct pilha stack;
    clock_t clock_inicial, clock_final;

	initializeStack(&stack);


    for (int i = CAPACIDADE; i > 0; i--) {
        insertIntoStack(&stack, rand() % CAPACIDADE);
    }

    clock_inicial = clock();
    stackBubbleSort(&stack);
    clock_final = clock();
    printf("Tempo decorrido na ordenação: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));

    printf("O indice do topo é %d\n", getTopIndex(stack));
	printf("O valor do topo da pilha é %d\n", getStackTop(stack));

	return 0;
}
