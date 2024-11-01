# Prova Mensal - **PONTEIROS**

Este projeto implementa uma fila circular em C, permitindo a inserção e remoção de elementos de forma eficiente ao utilizar ponteiros e sctructures.

---

## Funcionalidades

- **Criação de fila**: Cria uma fila com uma capacidade inicial especificada.
- **Inserção de elementos**: Permite a inserção de elementos na fila.
- **Remoção de elementos**: Permite a remoção de elementos do início da fila.
- **Exibição de elementos**: Exibe todos os elementos atuais na fila.
- **Limpeza da fila**: Libera a memória utilizada pela fila.

---

## Estrutura de Dados

A fila é implementada como uma estrutura que contém os seguintes campos:

- `void **dados`: um ponteiro genérico que armazena os elementos da fila.
- `int inicio`: índice do primeiro elemento na fila.
- `int fim`: índice do último elemento na fila.
- `int tamanho`: número atual de elementos na fila.
- `int capacidade`: capacidade total da fila.

---

## Compilação e Execução

Para compilar e executar o projeto, siga os seguintes passos:

1. Certifique-se de ter o compilador GCC instalado.
2. Salve o código em um arquivo chamado `fila.c`.
3. No terminal, navegue até o diretório onde o arquivo está salvo e execute os seguintes comandos:

   ```bash
   gcc -o fila fila.c
   ./fila

---

## **Colaboradores:**
- [Cauã Guerra](https://www.github.com/caua-guerra)
- [Luca Aroeira](https://www.github.com/lucaaroeiracrv)
- [Murilo Giovani](https://www.github.com/mumuka)
- [Pedro Hayashida](https://www.github.com/hayasshida)
- [Pedro Kohn](https://www.github.com/kohnn)
- [Richard Vinicius](https://www.github.com/mockjk)


