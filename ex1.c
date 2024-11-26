#include <stdio.h>
//identificar se o ponto esta ou nao esta no retangulo
typedef struct {
    int x;
    int y;
} ponto;

int dentro_ret(ponto *p0, ponto *p1, ponto *p) {
    if (p->x >= p0->x && p->x <= p1->x && p->y >= p0->y && p->y <= p1->y) {
        return 1;
    }
    return 0;
}

int main() {
    ponto p1 = {1, 1};
    ponto p2 = {5, 5};
    ponto p3 = {2, 2};

    if (dentro_ret(&p1, &p2, &p3)) {
        printf("O ponto esta dentro do retangulo\n");
    } else {
        printf("O ponto nao esta dentro do retangulo\n");
    }

    return 0;
}
