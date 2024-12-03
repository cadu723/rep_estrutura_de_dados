#include <stdio.h>
void assci_tabela(){
    for ( int i = 0;i < 128;i++){
        printf("%d = %c\n",i,i);// ao demonstrar um int em char ele ira mostrar o da tabela.
    }
}

int main(void) {
    assci_tabela();
    return 0;
}
