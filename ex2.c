#include <stdio.h>

int primo(int n){
    int i;
    if(n == 1 || n == 0){
        return 0;
    }
    for(i = 2; i < n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
    
}


int main(void) {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    if(primo(n)){
        printf("O numero %d e primo\n", n);
    }else{
        printf("O numero %d nao e primo\n", n);
    }

    return 0;
}
