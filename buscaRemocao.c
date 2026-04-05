#include <string.h>
#include <stdio.h>

struct Livro {
    int id;
    char titulo[100];
    char autor[100];
    int disponivel;
};

struct Livro biblioteca[100];
int totalLivros = 0;

void cadastrarLivro() {
    if (totalLivros >= 100) {
        printf("Limite atingido\n");
        return;
    }
 
    printf("Digite o id: ");
    scanf("%d", &biblioteca[totalLivros].id);

    printf("Digite o titulo: ");
    scanf(" %[^\n]", biblioteca[totalLivros].titulo);

    printf("Digite o autor: ");
    scanf(" %[^\n]", biblioteca[totalLivros].autor);

    biblioteca[totalLivros].disponivel = 1;
    totalLivros++;

    printf("Livro cadastrado!\n");
}

void listarLivros() {
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalLivros; i++) {
        printf("\nLivro %d\n", i + 1);
        printf("ID: %d\n", biblioteca[i].id);
        printf("Titulo: %s\n", biblioteca[i].titulo);
        printf("Autor: %s\n", biblioteca[i].autor);

        if (biblioteca[i].disponivel == 1) {
            printf("Status: Disponivel\n");
        } else {
            printf("Status: Emprestado\n");
        }
    }
}

int main() {
    cadastrarLivro();
    listarLivros();
// essa parte é so a de cadastro e listagem dos livros

    int i;
    char busca[50];
    char remocao[50];
    
void buscarLivros() {   
    printf("Digite o nome do livro: ");
    scanf(" %[^\n]", busca);
    
    for (i = 0; i < totalLivros; i++){
     if (strcmp(busca, biblioteca[i].titulo) == 0) {
        printf("%s está disponível\n", busca);
    } 
     else {printf("%s não está disponível\n", busca);
    }
    }
    }

void removerLivros() {   
    printf("Digite o nome do livro a ser removido: ");
    scanf(" %[^\n]", remocao);
    
    for (i = 0; i < totalLivros; i++){
     if (strcmp(remocao, biblioteca[i].titulo) == 0) {
         for (int j = i; j < totalLivros - 1; j++) {
             biblioteca[j] = biblioteca [j + 1];
         }
        totalLivros--;
        printf("%s removido com sucesso\n", remocao);
        break;
    } 

     else {printf("%s já foi removido ou nunca adicionado\n", remocao);
    }
    }
    }
    
    buscarLivros(); //Busca
    removerLivros(); //Remoção
    listarLivros(); //Lista os livros novamente para verificar quais foram adicionados e removidos
    
      return 0;
}