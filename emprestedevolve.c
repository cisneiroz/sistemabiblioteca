#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[50];
    int status; // 0 = emprestado | 1 = disponível
} Livro;

// Exemplo com 4 livros já cadastrados
Livro biblioteca[] = {
    {"Coraline", 1},
    {"O pequeno principe", 1},
	{"Outlander", 0},
	{"Castelo Animado", 0},
};

int totalLivros = 4;

// Função para emprestar
void emprestarLivro() {
    char nome[50];
    printf("Digite o nome do livro para emprestar: ");
    scanf(" %[^\n]", nome);

    for(int i = 0; i < totalLivros; i++) {
        if(strcmp(nome, biblioteca[i].titulo) == 0) {

            if(biblioteca[i].status == 0) {
                printf("Livro ja esta emprestado!\n");
            } else {
                biblioteca[i].status = 0;
                printf("Emprestimo realizado com sucesso!\n");
            }
            return;
        }
    }

    printf("Livro nao encontrado!\n");
}

// Função para devolver
void devolverLivro() {
    char nome[50];
    printf("Digite o nome do livro para devolver: ");
    scanf(" %[^\n]", nome);

    for(int i = 0; i < totalLivros; i++) {
        if(strcmp(nome, biblioteca[i].titulo) == 0) {

            if(biblioteca[i].status == 1) {
                printf("Livro ja esta disponivel!\n");
            } else {
                biblioteca[i].status = 1;
                printf("Devolucao realizada com sucesso!\n");
            }
            return;
        }
    }

    printf("Livro nao encontrado!\n");
}

// MAIN simples só pra testar
int main() {
    emprestarLivro();
    devolverLivro();
    return 0;
}
