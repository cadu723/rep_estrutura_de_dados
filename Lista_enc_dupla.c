#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;//endereco do proximo no da lista
    struct no *ant;//endereco do no anterior
}No;
 
//inicio
void insere_inicio(No **lista,int num){//** pois recebe  o end de um novo no  
    No *novo = malloc(sizeof(No)); //alocando memoria para o novo no

    if(novo){
        novo->dado = num;//atribui o valor ao novo no
        novo->prox = *lista;//o proximo do novo no aponta para o inicio da lista
        novo->ant = NULL;
        if(*lista)//se a lista nao estiver vazia 
            (*lista)->ant = novo;
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
        novo->prox = NULL, novo->ant = NULL;


        //acima o ponteiro novo tem  valor atribuido e aponta para NULL pois sera o ultimo da lista

        //checar se a lista esta vazia! 
        if(*lista == NULL){
            *lista = novo;//se estiver, o novo no sera o primeiro da lista
            novo->prox = NULL;
            novo->ant = NULL; 
        }else{
            aux = *lista;//o ponteiro auxiliar recebe o inicio da lista
           
            while(aux->prox != NULL){//percorre a lista ate o ultimo no
                aux = aux->prox;//atualiza o ponteiro auxiliar
            }
            
            novo->prox = NULL;//o novo no aponta para NULL
            novo->ant = aux;//o novo no aponta para o ultimo no
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
            novo->ant = NULL;            
            *lista = novo;// atualiza o inicio d alista recebendo o 1 no
        }else {
            aux = *lista;

            while( aux->dado != ant && aux->prox){
                    aux = aux->prox;//vai pulando de no em no ate encontrar o no anterior
            }
            novo->prox = aux->prox; //o novo no aponta para o proximo do no anterior
            aux->prox->ant = novo;
            novo->ant = aux;//o no anterior aponta para o novo no
            aux->prox = novo;
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


//remover
void tira_no(No **lista , int num){
    
    No *aux = *lista;
    No *xua= NULL;
    
    if(*lista == NULL){
        printf("lista esta vazia");
        return;
    }
    
    // if for o primeiro
    if((*lista)->dado == num){
        No * first = *lista;
        *lista = (*lista)->prox;//o primeiro elemento se torna o proximo removendo o primeiro"perdendo-o"
        if(*lista){
            (*lista)->ant = NULL;
        }

        free(first);//free no primeiro!
        printf("o dado %d foi removido", num);
        return ;
        
    }
    
    
    // if for no meio ou final
        while( aux != NULL && aux->dado != num ){
            xua = aux;
            aux = aux->prox;
        }    
        
       //se nao tiver o elemento 
       if(aux == NULL){
           printf("elemento %d nao encontrado\n",num);
           return;
       }
        
       if (xua != NULL) {
        xua->prox = aux->prox;
    }
    if (aux->prox != NULL) {
        aux->prox->ant = xua;
    }

        free(aux);
        printf("dado %d foi removido ",num);

    }
    
    
No* busca(No **lista,int num) {
    No* aux = *lista, *no = NULL;

    while(aux != NULL && aux->dado != num){
        aux = aux->prox;
    }
    if(aux != NULL){
        no = aux;
    }

    return no;
}   


void insere_ordenado(No **lista,int num){
    No *novo = malloc(sizeof(No));
    No *aux = *lista;
 

    if(novo){
        novo->dado = num; 
        novo->prox = NULL;
        
        //vazia ? 
        if (*lista == NULL) { 
            novo->prox = NULL;
            novo->ant = NULL;
            *lista = novo;
            return;

        }else if (novo->dado < (*lista)->dado){//se for menor que o primeiro
            novo->prox = *lista;
            novo->ant = NULL;
            (*lista)->ant = novo;
            *lista = novo;
            return;

        }else{
            while(aux->prox != NULL && novo->dado > aux->prox->dado){
                aux = aux->prox;
            }

        }
        novo->prox = aux->prox;
        novo->ant = aux;
        aux->prox = novo;
        if(novo->prox != NULL){
            novo->prox->ant = novo;
        }
        
    }else{
        printf("Erro de alocação\n");
    }


}

// Programa principal
int main() {
    int opcao,valor,ant;
    No *lista = NULL, *no = NULL;

    do{
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Inserir no meio\n");
        printf("4 - Imprimir\n");
        printf("5 - Remover\n");
        printf("6 - Buscar\n");
        printf("7 - Inserir ordenado\n");
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
                tira_no(&lista, valor);
            
                break;
                
            case 6:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                no = busca(&lista, valor);
                if(no != NULL){
                    printf("Valor encontrado %d\n", no->dado);
                }else{  
                    printf("Valor nao encontrado\n");
                }
                break;
            case 7:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                insere_ordenado(&lista, valor);
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
