#include <stdio.h>

typedef struct no{
    int conteudo;
    struct no *esq , * dir;
}No;

typedef struct {
    No *raiz;
}ArvB;

void inserirEsq(No *no , int valor ){
    if(no->esq == NULL){
         No *novo =(No*) malloc(sizeof(No));
        novo->conteudo = valor;
        novo->dir = NULL;
        novo->esq = NULL;
        novo->esq = novo;
        
    }else{
        if(valor < no->esq->conteudo){
            inserirEsq(no->esq , valor);
            
        }else{
            inserirDir(no->esq,valor)
        }
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
        if(valor > no->dir->conteudo){
           inserirDir(no->dir,valor);
           
        }else{
            inserirEsq(no->dir, valor);
        }
    }
}

//fazer o imprime 

void inserir (ArvB * arv , int valor){
    if(arv->raiz == NULL){
        No *novo =(No*) malloc(sizeof(No));
        novo->conteudo = valor;
        novo->dir = NULL;
        novo->esq = NULL;
        arv->raiz = novo //diz quem e a raiz !
    }else{
        if(valor < arv->raiz->conteudo){
            inserirEsq(arv->raiz,valor);
        }else{
            inserirDir(arv->raiz,valor);
        }
    
     }

}

int main(){


    return 0;
}
