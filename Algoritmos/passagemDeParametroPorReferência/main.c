#include <stdio.h>
#include <unistd.h>


void mostrar_cor(int cor) {
    if(cor == 1) {
        printf("A cor do semáforo é vermelha\n");
    } else if(cor == 2) {
        printf("A cor do semáforo é verde\n");
    } else if(cor == 3) {
        printf("A cor do semáforo é amarela\n");
    }
}


void mudar_cor(int *cor) {
    if(*cor == 1) {
        *cor = 2;
    } else if(*cor == 2) {
        *cor = 3;
    } else if(*cor == 3) {
        *cor = 1;
    }
}

int main() {
    int cor = 1;


    for(;;) {
        mostrar_cor(cor);
        sleep(2);
        mudar_cor(&cor);
    }
    return 0;
}
