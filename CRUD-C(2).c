// bibliotecas
#include <stdio.h> // de entrada e saída
#include <string.h> // de manipulação de strings

// bibliotecas "extra"
#include <stdlib.h> // de utilitários // Usaremos "system("cls");"  
#include <windows.h> // do Windows // Usaremos "Sleep(2000);"

#define MAX_LIVROS 100 // define número máximo de livros na biblioteca

struct livro {
    char titulo[100];
    char autor[100];
    int ano_publicacao;
    int disponivel; // 1 para disponível, 0 para emprestado
    int ativo;      // 1 para ativo, 0 para removido
};

// Array global para armazenar os livros
struct livro biblioteca[MAX_LIVROS];
int totalLivros = 0;

// informa funções existentes:

void cadastrar_livro(void);
void consultar_livro(void);
void atualizar_livro(void);
void remover_livro(void);
void emprestar_livro(void);
void devolver_livro(void);
void gerar_relatorios(void);

// função principal
int main(void) {
    // variáveis
    int opcao=1; // escolha do usuário do menu

    // notas
    // Sleep(1000);  -- Pausa a execução por 1000 miliseg
    // system("cls"); -- Limpa a tela do console (Windows)
 
    do{    // inicio loop principal do-while

        // menu
            system("cls"); // limpa a tela
        printf("----- menu -----\n");
        printf("[1] - Cadastrar livro \n");
        printf("[2] - Consultar livro\n");
        printf("[3] - Atualizar livro\n");
        printf("[4] - Remover livro\n");
        printf("[5] - Emprestar livro\n");
        printf("[6] - Devolver livro\n");
        printf("[7] - Gerar relatórios\n");
        printf("[0] - Sair\n");
        printf("---------------------\n");
            Sleep(1000); // pausa de 1 seg

        printf("Escolha uma opção: "); // seleção do usuário
            scanf("%d", &opcao);

        switch (opcao){
            case 1: // cadastrar livro 
                cadastrar_livro(); break;

            case 2: // consultar livro
                consultar_livro(); break;

            case 3: // atualizar livro
                atualizar_livro(); break;

            case 4: // remover livro
                remover_livro(); break;

            case 5: // emprestar livro
                emprestar_livro(); break;
            
            case 6: // devolver livro
                devolver_livro(); break;

            case 7: // gerar relatórios
                gerar_relatorios(); break;

            default: // qualquer numero diferente de 0 a 7
                printf("Opção inválida! Tente novamente.\n");
                Sleep(2000); //pausa de 2 seg
                break;
        }
        
    } while(opcao!=0); // fim do loop do-while (caso opção seja o)
    printf("Encerrando o programa...\n");

    return 0;
}  // fim do código principal


// implementação das funções

// função para cadastrar um livro
void cadastrar_livro(void) {
    if (totalLivros >= MAX_LIVROS) {
        printf("Biblioteca cheia! Não é possível cadastrar mais livros.\n");
        Sleep(2000);
        return;
    }
    system("cls");
    printf("----- Cadastro de Livro -----\n\n");
    
    printf("Digite o título: ");
    fflush(stdin);  // Limpa o buffer do teclado
    gets(biblioteca[totalLivros].titulo);
    
    printf("Digite o autor: ");
    fflush(stdin);
    gets(biblioteca[totalLivros].autor);
    
    printf("Digite o ano de publicação: ");
    scanf("%d", &biblioteca[totalLivros].ano_publicacao);
    
    // Define o livro como disponível e ativo
    biblioteca[totalLivros].disponivel = 1;
    biblioteca[totalLivros].ativo = 1;
    
    totalLivros++;
    
    printf("\nLivro cadastrado com sucesso!\n");
    Sleep(2000);
}

// função para consultar um livro
void consultar_livro(void) {
    printf("Função consultar_livro ainda não implementada\n");
    Sleep(2000);
}

// função para atualizar um livro
void atualizar_livro(void) {
    printf("Função atualizar_livro ainda não implementada\n");
    Sleep(2000);
}

// função para remover um livro
void remover_livro(void) {
    printf("Função remover_livro ainda não implementada\n");
    Sleep(2000);
}

// função para emprestar um livro
void emprestar_livro(void) {
    printf("Função emprestar_livro ainda não implementada\n");
    Sleep(2000);
}

// função para devolver um livro
void devolver_livro(void) {
    printf("Função devolver_livro ainda não implementada\n");
    Sleep(2000);
}

// função para gerar relatórios
void gerar_relatorios(void) {
    printf("Função gerar_relatorios ainda não implementada\n");
    Sleep(2000);
}
