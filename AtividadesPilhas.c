#include <stdio.h>
#include <locale.h>

#define TAMANHO 100

typedef struct {
    char texto[50];
} Acao;

typedef struct {
    Acao acoes[TAMANHO];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *pilha) {
    printf("Localização setada");
    pilha->topo = -1;
}

int esta_vazia(Pilha *pilha) {
    return pilha->topo == -1;
}

int esta_cheia(Pilha *pilha) {
    return pilha->topo == TAMANHO - 1;
}

void empilhar(Pilha *pilha, Acao acao) {
    if (!esta_cheia(pilha)) {
        pilha->acoes[++(pilha->topo)] = acao;
    } else {
        printf("Pilha cheia!\n");
    }
}

Acao desempilhar(Pilha *pilha) {
    if (!esta_vazia(pilha)) {
        return pilha->acoes[(pilha->topo)--];
    } else {
        printf("Pilha vazia!\n");
        Acao acao_vazia = {"Nenhuma ação"};
        return acao_vazia;
    }
}

Pilha pilha_acao;
Pilha pilha_refazer;

void realizar_acao(const char *texto) {
    Acao nova_acao;
    strcpy(nova_acao.texto, texto);
    empilhar(&pilha_acao, nova_acao);

    inicializar_pilha(&pilha_refazer);
    printf("Ação realizada: %s\n", texto);
}

void desfazer() {
    if (!esta_vazia(&pilha_acao)) {
        Acao acao = desempilhar(&pilha_acao);
        empilhar(&pilha_refazer, acao);
        printf("Desfez: %s\n", acao.texto);
    } else {
        printf("Nenhuma ação para desfazer.\n");
    }
}

void refazer() {
    if (!esta_vazia(&pilha_refazer)) {
        Acao acao = desempilhar(&pilha_refazer);
        empilhar(&pilha_acao, acao);
        printf("Refez: %s\n", acao.texto);
    } else {
        printf("Nenhuma ação para refazer.\n");
    }
}

void resultado() {
    printf("\nEstado atual do editor de texto: \n");
    for (int i = 0; i <= pilha_acao.topo; i++) {
        printf("%s\n", pilha_acao.acoes[i].texto);
    }
    printf("\n");
}

int main() {
    inicializar_pilha(&pilha_acao);
    inicializar_pilha(&pilha_refazer);

    realizar_acao(" Olá ");
    realizar_acao(" Mundo");
    desfazer();
    realizar_acao(" Pessoal");
    desfazer();
    refazer();

    resultado();

    return 0;
}