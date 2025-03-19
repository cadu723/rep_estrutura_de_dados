#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;//endereco do proximo no da lista
}No;
 
//inicio
void insere_inicio(No **lista,int num){//** pois recebe  o end de um novo no  
    No *novo = malloc(sizeof(No)); //alocando memoria para o novo no

    if(novo){
        novo->dado = num;//atribui o valor ao novo no
        novo->prox = *lista;//o proximo do novo no aponta para o inicio da lista
        *lista = novo;//atualiza o inicio da lista para o novo primeiro no

    }else{
        printf("Erro de alocação\n");
    }

}

//fim 
void insere_fim(No **lista,int num){
    No *novo = malloc(sizeof(No));
    No *aux ;//ponteiro auxiliar para percorrer a lista


    if(novo){
        novo ->dado = num;
        novo->prox = NULL;

        //acima o ponteiro novo tem  valor atribuido e aponta para NULL pois sera o ultimo da lista

        //checar se a lista esta vazia! 
        if(*lista == NULL){
            *lista = novo;//se estiver, o novo no sera o primeiro da lista
        }else{
            aux = *lista;//o ponteiro auxiliar recebe o inicio da lista
           
            while(aux->prox != NULL){//percorre a lista ate o ultimo no
                aux = aux->prox;//atualiza o ponteiro auxiliar
            }
            aux->prox = novo;//o ultimo no aponta para o novo no

        }

    }else{
        printf("Erro de alocação\n");
    }

}

//meio
void insere_meio(No **lista, int num,int ant){//ant = valor do no anterior
    No *novo = malloc(sizeof(No));
    No * aux;

    if(novo){
        novo->dado = num;
        //e o primeiro ? 
        if(*lista == NULL){
            novo ->prox = NULL;
            *lista = novo;// atualiza o inicio d alista recebendo o 1 no
        }else {
            aux = *lista;

            while( aux->dado != ant && aux->prox){
                    aux = aux->prox;//vai pulando de no em no ate encontrar o no anterior
            }
                novo->prox = aux->prox;//o novo no aponta para o proximo do no anterior
                aux->prox = novo;//o no anterior aponta para o novo no

        }

    }else{
        printf("Erro de alocação\n");
    }
}

//imprime
void imprime(No *lista){
    printf("Lista: ");
    while(lista){
        printf("%d ", lista->dado );
        lista = lista->prox; 
    }
    printf("\n ");
    
}

void remove(No **lista , int num){
    No *aux = *lista;
    No *xua= NULL;
    
    if(*lista == NULL){
        printf("lista esta vazia");
        return 1;
    }
    
    // if for o primeiro
    if((*lista)->dado == num){
        No *first = *lista;//ponteiro aponta para o primeiro
        *lista = (*lista)->prox;//o primeiro elemento se torna o proximo removendo o primeiro"perdendo-o"
        free(temp);//free no primeiro!
        printf("o dado %d foi removido", num);
        return 1 ;
        
    }
    
    
    // if for no meio ou final
        while(aux->dado != num && aux != NULL){
            xua = aux;
            aux = aux->prox;
        }    
        
       //se nao tiver o elemento 
       if(aux == NULL){
           printf("elemento %d nao encontrado\n",num);
           return 1 ;
       }
        
       xua->prox = aux->prox;
        free(aux);
        printf("dado %d foi removido ",num);

    }
    
    


// Programa principal
int main() {
    int opcao,valor,ant;
    No *lista = NULL;

    do{
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Inserir no meio\n");
        printf("4 - Imprimir\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                insere_inicio(&lista, valor);
                break;
            case 2:
                printf("digite o valor:");
                scanf("%d",&valor);
                insere_fim(&lista,valor);    

                break;
            case 3:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                printf("Digite o valor do no anterior: ");
                scanf("%d", &ant);
                insere_meio(&lista, valor, ant);
                
                break;
            case 4:
                imprime(lista);

             
                break;
                
            case 5:
                printf("digite o valor da lista a ser retirado");
                scanf("%d", &valor);
                remove(&lista, valor);
            
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
