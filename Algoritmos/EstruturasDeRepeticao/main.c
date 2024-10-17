#include <stdio.h>

int main() {
    int votos[7] = {0, 0, 0, 0, 0, 0, 0};
    int voto = 0;
    int totalVotos = 0;

    printf("Insira seus votos (0 para encerrar):\n");


    while (1) {

        scanf("%d", &voto);


        if (voto == 0) {
            break;
        }

        else if (voto >= 1 && voto <= 6) {
            totalVotos++;
            votos[voto]++;
        }

        else {
            printf("Voto inválido, insira números entre 0 e 6\n");
        }
    }
    printf("\nResultado da enquete:\n");
    char *sistemas[] = {
        "N/A",
        "Windows Server",
        "Unix",
        "Linux",
        "Netware",
        "Mac OS",
        "Outro"
    };

    for (int i = 1; i <= 6; i++) {

        float percentual = (totalVotos == 0) ? 0.0 : (float)votos[i] / totalVotos * 100;
        printf("%s: %d votos (%.2f%%)\n", sistemas[i], votos[i], percentual);
    }

    return 0;
}
