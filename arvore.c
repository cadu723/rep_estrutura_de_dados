#include <stdio.h>
#include <stdlib.h>

//arvore binaria e uma ED que tem no maximo dois filhos e sua eficiencia principal e a busca

typedef struct no{// estrutura do no
    int conteudo;
    struct no *esq , * dir;
}No;

typedef struct {// ponteiro para o no raiz que será a raiz da arvore
    No *raiz;
   
}ArvB;

void inserirEsq(No *no , int valor ){//recebe o no e o valor a ser inserido 
    if(no->esq == NULL){// tratamento para inserir o primeiro
         No *novo =(No*) malloc(sizeof(No));
        novo->conteudo = valor;
        novo->dir = NULL;
        novo->esq = NULL;
        no->esq = novo;
        
    }else{
         if(valor < no->esq->conteudo)
            inserirEsq(no->esq , valor);
            
         if(valor > no->esq->conteudo)
            inserirDir(no->esq,valor);
        }
    }
    
void inserirDir(No *no, int valor){
      if(no->dir == NULL){
         No *novo =(No*) malloc(sizeof(No));
        novo->conteudo = valor;
        novo->dir = NULL;
        novo->esq = NULL;
        no ->dir = novo;
        
    }else{
        if(valor > no->dir->conteudo)
           inserirDir(no->dir,valor);
           
           if(valor < no->dir->conteudo)
            inserirEsq(no->dir, valor);
        }
    }

No* inserir(No *raiz, int valor) {
        if (raiz == NULL) {
            No *novo = (No *)malloc(sizeof(No));
            novo->conteudo = valor;
            novo->esq = NULL;
            novo->dir = NULL;
            return novo;
        }
        if (valor < raiz->conteudo)
            raiz->esq = inserir(raiz->esq, valor);
        else if (valor > raiz->conteudo)
            raiz->dir = inserir(raiz->dir, valor);
        return raiz;
    }

void imprimir(No *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->conteudo);
        imprimir(raiz->esq);
        imprimir(raiz->dir);
        
    }

}

int altura(No *raiz) {
    if (raiz == NULL)
        return 0; // Árvore vazia tem altura 0
    else {
        int alturaEsq = altura(raiz->esq); // Altura da subárvore esquerda
        int alturaDir = altura(raiz->dir); // Altura da subárvore direita
        if (alturaEsq > alturaDir)
        return 1 + alturaEsq;
    else
        return 1 + alturaDir;
    
    }
}

int buscar (No *raiz, int chave){
    if(raiz == NULL){
        return -1;
    }else{
        if(raiz->conteudo == chave)
            return raiz->conteudo;
        if(chave < raiz->conteudo){
            return buscar(raiz->esq, chave);
        }else{
            return buscar(raiz->dir, chave);
        }    

    }
}

No* remover(No *raiz, int chave){//incompleto
    if(raiz == NULL){
        printf("VALOR NAO ENCONTRADO \n\n\n");
        return NULL;
    }else{
        if (raiz->conteudo == chave){
            if(raiz->esq == NULL && raiz->dir == NULL){
                free(raiz);
                return NULL;
            }
        }else{
            if(chave < raiz->conteudo)
                raiz->esq = remover(raiz->esq, chave);
            else
                raiz->dir = remover(raiz->dir, chave);    

        }

    }
}

No* limpa_arvore(No *raiz){
    if(raiz != NULL){
        limpa_arvore(raiz->esq);
        limpa_arvore(raiz->dir);
        free(raiz);
    }
    return NULL;
}

No* buscarNO (No *raiz, int chave){
    if(raiz == NULL){
        return NULL;
    }else{
        if(raiz->conteudo == chave)
            return raiz;
        if(chave < raiz->conteudo){
            return buscarNO(raiz->esq, chave);
        }else{
            return buscarNO(raiz->dir, chave);
        }    

    }
}

int alturaSubArv(No *raiz,int chave) {
  No *no = buscarNO(raiz,chave);
    if(no)
        return altura(no);
    else
        return -1; // Retorna -1 se o nó não for encontrado
}




int main(){
    int op,valor;
    ArvB arv;
    arv.raiz = NULL;

    do{
        printf("1 - Inserir\n");
        printf("2 - Imprimir\n");
        printf("3 - Tamanho\n");
        printf("4 - Buscar\n");
        printf("5 - Remover\n");
        printf("6 - Limpar\n");
        printf("7 - Altura de um nó\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch(op){

            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                arv.raiz = inserir(arv.raiz, valor);
                break;

            case 2:
                imprimir(arv.raiz); 
                printf("\n");
                break;
            
            case 3:
                printf("Tamanho da arvore: %d\n",altura( arv.raiz)); // Chama a função de altura para calcular o tamanho da árvore
                break;   

            case 4:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                if(buscar(arv.raiz, valor) != -1){
                    printf("Valor %d encontrado na arvore.\n", valor);
                }else{
                    printf("Valor %d nao encontrado na arvore.\n", valor);
                }
                break;
            case 5:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                arv.raiz = remover(arv.raiz, valor);
                break;    
            case 6:
                arv.raiz = limpa_arvore(arv.raiz);
                printf("Arvore limpa com sucesso!\n");
                break;    
            case 7:
                printf("digite o valor para ver sua altura:\n");
                scanf("%d", &valor);
                printf("Altura do no %d: %d\n", valor, alturaSubArv(arv.raiz,valor));    
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    }while(op != 0);

    return 0;
}
