// bibliotecas
#include <stdio.h> // de entrada e saída
#include <string.h> // de manipulação de strings

// bibliotecas "extra"
#include <stdlib.h> // de utilitários // Usaremos "system("cls");"  
#include <windows.h> // do Windows // Usaremos "Sleep(2000);"

// constantes e estruturas
#define max_livros 100 // define número máximo de livros na biblioteca


struct livro {
    char titulo[100];
    char autor[100];
    int ano_publicacao;
    int disponivel; // 1 para disponível, 0 para emprestado
    int ativo;      // 1 para ativo, 0 para removido
};


// array global para armazenar os livros
struct livro biblioteca[max_livros];
int total_livros = 0; // contador de livros cadastrados, variavel global


// informa funções existentes:
void limpa_buffer(void);  // função para limpar o buffer do teclado "mais fácil" (evita erro com scanf + fgets)
void cadastrar_livro(void);
void consultar_livro(void);
void atualizar_livro(void);
void remover_livro(void);
void emprestar_livro(void);
void devolver_livro(void);
void gerar_relatorios(void);



// ----- função principal -----

int main(void) {
    // variáveis
    int opcao=1; // escolha do usuário do menu

    do{    // inicio loop principal do-while

        // menu
            system("cls"); // limpa a tela
        printf("----- menu -----\n");
        printf("[1] - cadastrar livro \n");
        printf("[2] - consultar livro\n");
        printf("[3] - atualizar livro\n");
        printf("[4] - remover livro\n");
        printf("[5] - emprestar livro\n");
        printf("[6] - devolver livro\n");
        printf("[7] - gerar relatórios\n");
        printf("[0] - sair\n");
        printf("---------------------\n");
            Sleep(750); // pausa de 0,75 seg

        printf("Escolha uma opcao: "); // seleção do usuário
            scanf("%d", &opcao);

        // opções do menu
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

            case 0: // sair
                break;

            default: // qualquer numero diferente de 0 a 7
                printf("opcao invalida! tente novamente.\n");
                Sleep(750); //pausa de 0,75 seg
                break;
        }
        
    } while(opcao!=0); // fim do loop do-while (caso opção seja o)
    printf("encerrando o programa...\n");

    return 0;
}  // fim do código principal



// ----- funções -----

// função para limpar o buffer do teclado
void limpa_buffer(void) {
    int c; // variável temporária para o caractere  
    while ((c = getchar()) != '\n' && c != EOF);  // limpa até o fim da linha
}



// função para cadastrar um livro
void cadastrar_livro(void) {
    system("cls"); // limpa a tela
    Sleep(750); // pausa de 0,75 seg
    
    if (total_livros >= max_livros) {
    printf("capacidade maxima de livros atingida!\n");
    Sleep(750);
        return;
    }

    struct livro novo_livro; // variável temporária para o novo livro
    
    limpa_buffer();  // limpa o buffer antes de ler os dados

    printf("digite o titulo do livro: ");
       fgets(novo_livro.titulo, 100, stdin);

    printf("digite o autor do livro: ");
        fgets(novo_livro.autor, 200, stdin);

    printf("digite o ano de publicacao: ");
        scanf("%d", &novo_livro.ano_publicacao);


    novo_livro.disponivel = 1; // livro disponível
    novo_livro.ativo = 1;      // livro ativo

    biblioteca[total_livros] = novo_livro; // adiciona o novo livro ao array
    total_livros++; // incrementa o contador de livros

    printf("livro cadastrado com sucesso!\n");
    printf("total de livros: %d\n", total_livros); // confirma total de livros

    Sleep(750);
}



// função para consultar um livro
void consultar_livro(void) {

    system("cls"); // limpa a tela
    Sleep(750); // pausa de 0,75 seg
    int opcao;

    do {
        // menu de consulta
            system("cls"); // limpa a tela

        printf("----- consulta livro -----\n");
        printf("[1] - busca por titulo\n");
        printf("[2] - busca por autor\n");
        printf("[3] - busca por ano\n");
        printf("[4] - busca por disponibilidade\n");
        printf("[0] - voltar ao menu\n");
        printf("--------------------------\n");

            Sleep(750); // pausa de 0,75 seg

        printf("escolha uma opcao: "); // seleção do usuário
            scanf("%d", &opcao);
            limpa_buffer(); 

        // opções do menu de consulta
        switch (opcao){
            case 1: // busca por título
                printf("função busca por título ainda não implementada\n");
                Sleep(750); break;

            case 2: // busca por autor
                printf("função busca por autor ainda não implementada\n");
                Sleep(750); break;

            case 3: // busca por ano
                printf("função busca por ano ainda não implementada\n");
                Sleep(750); break;

            case 4: // busca por disponibilidade
                printf("função busca por disponibilidade ainda não implementada\n");
                Sleep(750); break;

            case 0: // voltar ao menu
                break;

            default: // qualquer numero diferente de 0 a 4
                printf("opção inválida! Tente novamente.\n");
                Sleep(750); //pausa de 0,75 seg
                break;
        }
    } while (opcao!=0);
        printf("voltando ao menu principal...\n");
        Sleep(750);
        limpa_buffer();

}




// função para atualizar um livro
void atualizar_livro(void) {
    printf("função atualizar_livro ainda não implementada\n");
    Sleep(750);
}





// função para remover um livro
void remover_livro(void) {
    printf("Função remover_livro ainda não implementada\n");
    Sleep(750);
}




// função para emprestar um livro
void emprestar_livro(void) {
    printf("Função emprestar_livro ainda não implementada\n");
    Sleep(750);
}




// função para devolver um livro
void devolver_livro(void) {
    printf("Função devolver_livro ainda não implementada\n");
    Sleep(750);
}




// função para gerar relatórios
void gerar_relatorios(void) {
    printf("Função gerar_relatorios ainda não implementada\n");
    Sleep(750);
}
