#include "function.h"
#include <stdlib.h>
#include <stdio.h>

struct Conta {
    int numero;
    char cliente[51];
    int especial;
    float saldo;
};

void inicializar(p_conta pProduto[], int tamanho) {
    for(int i=0; i<tamanho; i++){
        pProduto[i] = NULL;
    }
}

void cadastrar(p_conta pProduto[], int posicao){
    pProduto[posicao] = (p_conta) malloc(sizeof(struct Conta));
    fflush(stdin);
    printf("Entre com os dados do produto: \n");
    printf("Digite o codigo do produto: \n");   
    scanf("%d", &pProduto[posicao]->codigo);
    fflush(stdin);
    printf("Digite a descricao do produto: \n");
    gets(pProduto[posicao]->descricao);
    fflush(stdin);
    printf("Digite o preco do produto: \n");
    scanf("%f", &pProduto[posicao]->preco);
    pProduto[posicao]->quantidade = 0;
    printf("Produto cadastrado com sucesso");

}

void imprimir(p_produto pProduto[], int posicao){
    //passar pelo vetor, mostrando cada ponteiro o seu membro
    for (int i = 0; i < posicao; i++) {
        printf("Codigo: %d \n", pProduto[i]->codigo);
        printf("Descricao: %s \n", pProduto[i]->descricao);
        printf("Quantidade: %d \n", pProduto[i]->quantidade);
        printf("Valor: %.2lf \n", pProduto[i]->preco);
        printf("------------------------------------\n");
    }
}