#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;//endereco do proximo no da lista
}No;


void push(No **lista , int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->dado = num;
        novo->prox = *lista;
        *lista = novo;
    }
}

void pop(No **lista){
    No *aux = *lista;
    if(*lista == NULL){
        printf("Pilha vazia\n");
        return;
    }
    printf("%d \t", (*lista)->dado);
    *lista = (*lista)->prox;
    free(aux);
}

void mostrar (No **lista){
    while(*lista){
        pop(lista);
    }
}

int main(){
    No *pilha = NULL;
    int opcao,valor;

    do{
        printf("1 - Push\n");
        printf("2 - Pop\n");
        printf("3 - Mostrar\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                push(&pilha, valor);
                break;
            case 2:
                pop(&pilha);
                break;
            case 3:
                mostrar(&pilha);
                break;
            
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    }while(opcao != 0);
    return 0;
}
