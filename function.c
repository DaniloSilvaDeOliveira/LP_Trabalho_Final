#include "function.h"
#include <stdlib.h>
#include <stdio.h>

struct Conta {
    int numero;
    char cliente[51];
    int especial;
    float saldo;
};

void inicializar(ponteiro_Conta vetorConta[], int tamanho) {
    for(int i=0; i<tamanho; i++){
        vetorConta[i] = NULL;
    }
}

void cadastrar(ponteiro_Conta vetorConta[], int posicao){
    vetorConta[posicao] = (ponteiro_Conta) malloc(sizeof(struct Conta));
    int numero,numeroVerificado = 0;
    system("cls");
    do{
        fflush(stdin);
        printf("Digite o numero do cliente: \n");
        scanf("%d", &numero);
        if(verificaNumeroDaConta(vetorConta,posicao,numero)){
            vetorConta[posicao]->numero = numero;
            numeroVerificado = 1;
        }else{
            printf("numero da conta já existe, tente outro numero\n");
        }
    }while(numeroVerificado != 1);

    fflush(stdin);
    printf("Digite o nome do cliente: \n");
    gets(vetorConta[posicao]->cliente);
    
    int especial,verificaEstado = 0;
    do{
        fflush(stdin);
        printf("Digite 0 - se o cliente for normal\nDigite 1 - se o cliente for especial\n");
        scanf("%d", &especial);
        if(especial == 1 || especial == 0){
            verificaEstado = 1;
        }
        if(verificaEstado == 0){
            printf("por favor digite um numero válido\n");
        }
    }while(verificaEstado != 1);
    vetorConta[posicao]->especial = especial;
    vetorConta[posicao]->saldo = 0;
    printf("Cliente cadastrado com sucesso\n");

}

int verificaNumeroDaConta(ponteiro_Conta vetorConta[],int posicao,int numero){
    //passar pelo vetor, mostrando cada ponteiro o seu membro
    for (int i = 0; i < posicao; i++) {
        if(numero == vetorConta[i]->numero){
            return 0;
        }
    }
    return 1;
}

void procurar(ponteiro_Conta vetorConta[],int posicao,int numero){
    system("cls");
    int contador = 0;
    for (int i = 0; i < posicao; i++) {
        if(numero == vetorConta[i]->numero){
            printf("numero: %d\n",vetorConta[i]->numero);
            printf("nome: %s\n",vetorConta[i]->cliente);
            if(vetorConta[i]->especial == 0){
                printf("tipo de cliente: normal\n");
            }else if(vetorConta[i]->especial == 1){
                 printf("tipo de cliente: especial\n");
            }
            printf("saldo: %.2f\n",vetorConta[i]->saldo);
            system("pause");
            contador = 1;
        }
    }
    if(contador == 0){
        printf("nenhuma conta encontrada\n");
        system("pause");
    }
}

void alterar(ponteiro_Conta vetorConta[],int posicao,int numero){
    system("cls");
    int contador = 0;
    for (int i = 0; i < posicao; i++) {
        if(numero == vetorConta[i]->numero){
            printf("nome anterior: %s\n",vetorConta[i]->cliente);
            fflush(stdin);
            printf("novo nome: \n");
            gets(vetorConta[i]->cliente);
            system("pause");
            contador = 1;
        }
    }
    if(contador == 0){
        printf("nenhuma conta encontrada\n");
        system("pause");
    }   
}

void listarContas(ponteiro_Conta vetorConta[], int posicao){
    for (int i = 0; i < posicao; i++) {
        printf("numero: %d \n", vetorConta[i]->numero);
        printf("cliente: %s \n", vetorConta[i]->cliente);
        if(vetorConta[i]->especial == 0){
            printf("tipo: normal\n");
        }else if(vetorConta[i]->especial == 1){
            printf("tipo: especial\n");
        }
        printf("Valor: %.2lf \n", vetorConta[i]->saldo);
        printf("------------------------------------\n");
    }
    if(posicao == 0){
        printf("nenhuma conta encontrada\n");
    }
    system("pause");
}

void procurarNoVetor(ponteiro_Conta vetorConta[], int posicao,int numero){
    int contador = 0;
    for (int i = 0; i < posicao; i++) {
        if(numero == vetorConta[i]->numero){
            printf("posicao no vetor: %d\n",i);
            contador = 1;
            system("pause");
        }
    }
    if(contador == 0){
        printf("nenhuma conta encontrada\n");
        system("pause");
    }
}

void depositar(ponteiro_Conta vetorConta[], int posicao,int numero){
    int contador = 0;
    float dinheiro = 0;
    for (int i = 0; i < posicao; i++) {
        if(numero == vetorConta[i]->numero){
            do{
                fflush(stdin);
                printf("deposito: ");scanf("%f",&dinheiro);
                if(dinheiro < 0){
                    printf("por favor digite um deposito válido\n");
                }
            }while(dinheiro < 0);
            printf("saldo antigo: %0.2f\n",vetorConta[i]->saldo);
            vetorConta[i]->saldo = vetorConta[i]->saldo + dinheiro;
            printf("deposito de: %0.2f\n",dinheiro);
            printf("novo saldo: %0.2f\n",vetorConta[i]->saldo);
            contador = 1;
            system("pause");
        }
    }
    if(contador == 0){
        printf("nenhuma conta encontrada\n");
        system("pause");
    }
}

void sacar(ponteiro_Conta vetorConta[], int posicao,int numero){
    int contador = 0;
    float dinheiro = 0;
    for (int i = 0; i < posicao; i++) {
        if(numero == vetorConta[i]->numero){
            if(vetorConta[i]->saldo > 0){
                fflush(stdin);
                printf("saque: ");scanf("%f",&dinheiro);
                if(dinheiro > vetorConta[i]->saldo){
                    printf("infelizmente o seu saldo é de %0.2f, estaremos fazendo o saque do valor que está na sua conta\n",vetorConta[i]->saldo);
                    printf("saldo antigo: %0.2f\n",vetorConta[i]->saldo);
                    printf("saque de: %0.2f\n",vetorConta[i]->saldo);
                    vetorConta[i]->saldo = vetorConta[i]->saldo - vetorConta[i]->saldo;
                    printf("novo saldo: %0.2f\n",vetorConta[i]->saldo);
                }else{
                    printf("saldo antigo: %0.2f\n",vetorConta[i]->saldo);
                    vetorConta[i]->saldo = vetorConta[i]->saldo - dinheiro;
                    printf("saque de: %0.2f\n",dinheiro);
                    printf("novo saldo: %0.2f\n",vetorConta[i]->saldo);
                }
                contador = 1;
                system("pause");
            }else{
                printf("sua conta está zerada por favor faça um deposito!\n");
            }
        }
    }
    if(contador == 0){
        printf("nenhuma conta encontrada\n");
        system("pause");
    }
}

void saldoGeral(ponteiro_Conta vetorConta[], int posicao){
    float saldoGeral = 0;
    for (int i = 0; i < posicao; i++) {
        saldoGeral += vetorConta[i]->saldo;
    }
    printf("saldo geral: %0.2f\n",saldoGeral);
    system("pause");
}