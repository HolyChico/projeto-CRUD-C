#include <stdio.h>
#include <string.h>

// ATENCAO: esta estrutura deve ser IDÊNTICA
// a do seu programa principal
struct livro {
    char titulo[100];
    char autor[100];
    int ano_publicacao;
    int disponivel; // 1 para disponivel, 0 para emprestado
    int ativo;      // 1 para ativo, 0 para removido
};

int main(void) {
    FILE *f;
    int total_a_gravar = 10;

    // aqui estao os 10 livros que voce pediu
    // (mantendo o padrao sem acentos e minusculas)
    struct livro livros_iniciais[10] = {
        {"o senhor dos aneis", "j.r.r. tolkien", 1954, 1, 1},
        {"1984", "george orwell", 1949, 1, 1},
        {"o apanhador no campo de centeio", "j.d. salinger", 1951, 1, 1},
        {"dom quixote", "miguel de cervantes", 1605, 1, 1},
        {"orgulho e preconceito", "jane austen", 1813, 0, 1}, // este comeca emprestado
        {"a revolucao dos bichos", "george orwell", 1945, 1, 1},
        {"moby dick", "herman melville", 1851, 1, 1},
        {"o grande gatsby", "f. scott fitzgerald", 1925, 1, 1},
        {"crime e castigo", "fyodor dostoevsky", 1866, 1, 1},
        {"o morro dos ventos uivantes", "emily bronte", 1847, 1, 1}
    };

    // abrindo o arquivo para escrita binaria ("wb")
    f = fopen("biblioteca.dat", "wb");

    if (f == NULL) {
        printf("erro ao tentar criar o arquivo 'biblioteca.dat'!\n");
        return 1; // retorna um erro
    }

    // --- gravando os dados ---

    // 1. grava o numero total de livros
    fwrite(&total_a_gravar, sizeof(int), 1, f);

    // 2. grava o array inteiro com os 10 livros
    fwrite(livros_iniciais, sizeof(struct livro), 10, f);

    // fecha o arquivo
    fclose(f);

    printf("arquivo 'biblioteca.dat' com 10 livros gerado com sucesso!\n");
    printf("agora voce pode executar o seu programa principal.\n");

    return 0;
}