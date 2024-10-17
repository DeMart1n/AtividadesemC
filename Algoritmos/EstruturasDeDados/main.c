#include <stdio.h>
#define numeroDeProdutos 3
#define numeroDePrecos 2

int main() {
    float mediaDosValores[numeroDeProdutos][numeroDePrecos] = {
        {15.00, 12.50},
        {13.00, 7.50},
        {100.00, 97.00}
    };
    for(int i = 0; i < numeroDeProdutos; i++) {
        float soma = 0;
        for(int j = 0; j < numeroDePrecos; j++) {
            soma += mediaDosValores[i][j];
        }
        mediaDosValores[i][0] = soma/numeroDePrecos;
    }

    for(int i = 0; i<numeroDeProdutos; i++) {
        printf("Produto: %f\n", mediaDosValores[i][0]);
    }
    return 0;
}

