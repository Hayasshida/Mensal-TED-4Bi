#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void **dados;      // Ponteiro genérico para os elementos da fila
    int inicio;        // Índice do primeiro elemento
    int fim;           // Índice do último elemento
    int tamanho;       // Capacidade atual da fila
    int capacidade;    // Capacidade total da fila
} Fila;

// Função para criar a fila
Fila* criarFila(int capacidadeInicial) {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    if (fila == NULL) return NULL;  // Verifica se a alocação foi bem-sucedida

    fila->dados = (void **) malloc(sizeof(void*) * capacidadeInicial);
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 0;
    fila->capacidade = capacidadeInicial;

    return fila;
}

// Função para limpar e liberar a fila
void limparFila(Fila *fila) {
    if (fila != NULL) {
        free(fila->dados);  // Libera a memória alocada para os dados
        free(fila);         // Libera a memória da estrutura da fila
    }
}

//Função para dobrar Tamanho da fila

void dobrarTamanho(Fila *fila) {
    void** dobro = (void **) malloc(sizeof(void*) * (*(int*)fila->dados * 2));
    dobro = fila->dados;
    free(fila->dados);
    fila->dados = dobro;
    fila->capacidade = fila->capacidade * 2;
}

void inserirNaFila(Fila *fila){
    
}

int main (){
    Fila* fila = criarFila(10);
    printf("%d \n", fila->capacidade);
    
    printf("dobra tamanho \n");
    
    dobrarTamanho(fila);
    
    printf("%d", fila->capacidade);
    
    return 0;
}
