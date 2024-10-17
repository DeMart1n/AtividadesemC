#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 40

typedef struct {
    char nome[20];
    float nota;
    char status;
} Aluno;

typedef struct {
    Aluno lista[MAX_ALUNOS];
    int n;
} ListaAlunos;

void inicializar(ListaAlunos *lista) {
    lista->n = 0;
}

int incluirAluno(ListaAlunos *lista, Aluno aluno) {
    if (lista->n < MAX_ALUNOS) {
        lista->lista[lista->n] = aluno;
        lista->n++;
        return 1;
    }
    return 0;
}

int excluirAluno(ListaAlunos *lista, const char *nome) {
    for (int i = 0; i < lista->n; i++) {
        if (strcmp(lista->lista[i].nome, nome) == 0) {
            for (int j = i; j < lista->n - 1; j++) {
                lista->lista[j] = lista->lista[j + 1];
            }
            lista->n--;
            return 1;
        }
    }
    return 0;
}

void ordenarPorNota(ListaAlunos *lista) {
    for (int i = 0; i < lista->n - 1; i++) {
        for (int j = 0; j < lista->n - 1 - i; j++) {
            if (lista->lista[j].nota < lista->lista[j + 1].nota) {
                Aluno temp = lista->lista[j];
                lista->lista[j] = lista->lista[j + 1];
                lista->lista[j + 1] = temp;
            }
        }
    }
}

void apresentarLista(ListaAlunos *lista) {
    printf("Lista de Alunos:\n");
    for (int i = 0; i < lista->n; i++) {
        printf("Nome: %s, Nota: %.2f, Status: %c\n", lista->lista[i].nome, lista->lista[i].nota, lista->lista[i].status);
    }
}

void apresentarAtivos(ListaAlunos *lista) {
    printf("Lista de Alunos Ativos:\n");
    for (int i = 0; i < lista->n; i++) {
        if (lista->lista[i].status == 'A') {
            printf("Nome: %s, Nota: %.2f\n", lista->lista[i].nome, lista->lista[i].nota);
        }
    }
}

int main() {
    ListaAlunos lista;
    inicializar(&lista);

    Aluno aluno1 = {"Alice", 9.5, 'A'};
    Aluno aluno2 = {"Bob", 7.0, 'A'};
    Aluno aluno3 = {"Charlie", 8.5, 'C'};

    incluirAluno(&lista, aluno1);
    incluirAluno(&lista, aluno2);
    incluirAluno(&lista, aluno3);

    apresentarLista(&lista);

    ordenarPorNota(&lista);
    printf("\nLista de Alunos Ordenada por Nota:\n");
    apresentarLista(&lista);

    apresentarAtivos(&lista);

    excluirAluno(&lista, "Bob");
    printf("\nLista de Alunos Após Exclusão:\n");
    apresentarLista(&lista);

    return 0;
}
// BY: Cauã De Martin ;)