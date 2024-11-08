#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma fila
typedef struct {
    void **dados;      // Ponteiro genérico para armazenar os elementos da fila
    int inicio;        // Índice do primeiro elemento na fila
    int fim;           // Índice do último elemento na fila
    int tamanho;       // Número atual de elementos na fila
    int capacidade;    // Capacidade total da fila
} Fila;

// Função para criar uma fila com capacidade inicial
Fila* criarFila(int capacidadeInicial) {
    Fila *fila = (Fila *) malloc(sizeof(Fila)); // Aloca memória para a fila
    if (fila == NULL) return NULL; // Verifica se a alocação falhou

    // Aloca memória para os dados da fila
    fila->dados = (void **) malloc(sizeof(void *) * capacidadeInicial);
    fila->inicio = 0; // Inicializa o índice de início
    fila->fim = -1;   // Inicializa o índice de fim
    fila->tamanho = 0; // Inicializa o tamanho da fila
    fila->capacidade = capacidadeInicial; // Define a capacidade da fila

    return fila; // Retorna a fila criada
}

// Função para limpar a fila e liberar a memória
void limparFila(Fila *fila) {
    if (fila != NULL) {
        free(fila->dados); // Libera a memória dos dados
        free(fila); // Libera a memória da estrutura da fila
    }
}

// Função para dobrar a capacidade da fila
void dobrarCapacidade(Fila *fila) {
    int newCapacidade = fila->capacidade * 2; // Nova capacidade
    void **a = (void **) malloc(sizeof(void*) * newCapacidade); // Aloca nova memória para os dados

    // Copia os elementos existentes para a nova estrutura
    for (int i = 0; i < fila->tamanho; i++) {
        a[i] = fila->dados[(fila->inicio + i) % fila->capacidade];
    }

    free(fila->dados); // Libera a memória da antiga estrutura
    fila->dados = a; // Atualiza o ponteiro para os novos dados
    fila->capacidade = newCapacidade; // Atualiza a capacidade
    fila->inicio = 0; // Reinicializa o índice de início
    fila->fim = fila->tamanho - 1; // Atualiza o índice de fim
}

// Função para inserir um elemento na fila
void inserirNaFila(Fila *fila, void *e) {
    if (fila->tamanho == fila->capacidade) { // Verifica se a fila está cheia
        dobrarCapacidade(fila); // Dobra a capacidade se necessário
    }

    fila->fim = (fila->fim + 1); // Move o índice de fim para a frente
    fila->dados[fila->fim] = e; // Insere o novo elemento
    fila->tamanho++; // Incrementa o tamanho da fila
}

// Função para remover um elemento da fila
void* removerDaFila(Fila *fila) {
    if (fila->tamanho == 0) {
        return NULL; // Retorna NULL se a fila estiver vazia
    }

    void *e = fila->dados[fila->fim]; // Armazena o elemento a ser removido
    fila->tamanho--; // Decrementa o tamanho da fila
    return e; // Retorna o elemento removido
}

// Função para mostrar os elementos na fila
void mostrarFila(Fila *fila) {
    printf("Elementos na fila: ");
    for (int i = 0; i < fila->tamanho; i++) {
        int valor = *(int *)fila->dados[(fila->inicio + i) % fila->capacidade]; // Acessa o valor
        printf("%d ", valor); // Imprime o valor
    }
    printf("\n");
}

// Função principal para testar a fila
int main (){
    Fila* fila = criarFila(2); // Cria uma fila com capacidade inicial de 2

    int a = 1, b = 2, c = 3; // Define alguns valores inteiros
    inserirNaFila(fila, &a); // Insere 'a' na fila
    inserirNaFila(fila, &b); // Insere 'b' na fila
    printf("Capacidade antes de dobrar: %d\n", fila->capacidade); // Mostra a capacidade atual
    mostrarFila(fila); // Exibe os elementos na fila

    inserirNaFila(fila, &c); // Insere 'c', o que provoca a dobra da capacidade

    printf("Capacidade depois de dobrar: %d\n", fila->capacidade); // Mostra a nova capacidade
    mostrarFila(fila); // Exibe os elementos na fila

    int *removed = (int *)removerDaFila(fila); // Remove um elemento da fila
    printf("Elemento removido: %d\n", *removed); // Mostra o elemento removido
    mostrarFila(fila); // Exibe os elementos restantes na fila
    limparFila(fila); // Limpa a fila e libera a memória
    return 0; // Retorna 0, indicando que o programa terminou com sucesso
}
