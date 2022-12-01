#include <stdlib.h>
#include <stdio.h>
#include "function.c"

#define MAX 100

/*
    88      a8P       88        88      8b           d8             db             8b        d8  
    88    ,88'        88        88      `8b         d8'            d88b             Y8,    ,8P   
    88  ,88"          88        88       `8b       d8'            d8'`8b             `8b  d8'    
    88,d88'           88        88        `8b     d8'            d8'  `8b              Y88P      
    8888"88,          88        88         `8b   d8'            d8YaaaaY8b             d88b      
    88P   Y8b         88        88          `8b d8'            d8""""""""8b          ,8P  Y8,    
    88     "88,       Y8a.    .a8P           `888'            d8'        `8b        d8'    `8b   
    88       Y8b       `"Y8888Y"'             `8'            d8'          `8b      8P        Y8 

    Integrantes:
    Danilo Silva de Oliveira
    Gabriel Rocha
    Juliana Lopes de Carvalho
    Luma F. De Sousa
    Samuel Sousa de Araújo                                                                            
                                                                                             
*/

void main(){
    ponteiro_Conta vetorConta[MAX];
    inicializar(vetorConta,MAX);
    int ponteiro = 0, opcao = 0, nPivotDeNumeros;
    do{
        system("cls");
        printf("Menu Principal - Banco\n");
        printf("1 - cadastrar conta\n");
        printf("2 - alterar nome da conta\n");
        printf("3 - procurar conta\n");
        printf("4 - listar contas\n");
        printf("5 - depositar\n");
        printf("6 - sacar\n");
        printf("7 - imprimir\n");
        printf("8 - saldo geral\n");
        printf("9 - sair\n");
        printf("escolha: ");scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            cadastrar(vetorConta,ponteiro);
            ponteiro++;
            break;

        case 2:
            printf("digite o numero do cliente a ser alterado: ");scanf("%d",&nPivotDeNumeros);
            alterar(vetorConta,ponteiro,nPivotDeNumeros);
            break;

        case 3:
            printf("digite o numero do cliente a ser encontrado: ");scanf("%d",&nPivotDeNumeros);
            procurarNoVetor(vetorConta,ponteiro,nPivotDeNumeros);
            break;
        case 4:
            listarContas(vetorConta,ponteiro);
            break;
        
        case 5:
            printf("digite o numero do cliente: ");scanf("%d",&nPivotDeNumeros);
            depositar(vetorConta,ponteiro,nPivotDeNumeros);
            break;
        
        case 6:
            printf("digite o numero do cliente: ");scanf("%d",&nPivotDeNumeros);
            sacar(vetorConta,ponteiro,nPivotDeNumeros);
            break;

        case 7:
            printf("digite o numero do cliente a ser procurado: ");scanf("%d",&nPivotDeNumeros);
            procurar(vetorConta,ponteiro,nPivotDeNumeros);
            break;

        case 8:
            saldoGeral(vetorConta,ponteiro);
            break;

        case 9:
            printf("Goodbye!");
            break;
        
        default:
            printf("escolha inválida!");
            break;
        }

    }while(opcao != 9);
}