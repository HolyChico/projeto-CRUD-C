// bibliotecas
#include <stdio.h> // de entrada e saida
#include <string.h> // de manipulacao de strings

// bibliotecas "extra"
#include <stdlib.h> // de utilitarios // Usaremos "system("cls");"
#include <windows.h> // do Windows // Usaremos "Sleep(2000);"

// constantes e estruturas
#define max_livros 100 // define numero maximo de livros na biblioteca


struct livro {
    char titulo[100];
    char autor[100];
    int ano_publicacao;
    int disponivel; // 1 para disponivel, 0 para emprestado
    int ativo;      // 1 para ativo, 0 para removido
};


// array global para armazenar os livros
struct livro biblioteca[max_livros];
int total_livros = 0; // contador de livros cadastrados, variavel global


// informa funcoes existentes:
void limpa_buffer(void); // funcao para limpar o buffer do teclado "mais facil" (evita erro com scanf + fgets)
void cadastrar_livro(void);
void consultar_livro(void);
void atualizar_livro(void);
void remover_livro(void);
void emprestar_livro(void);
void devolver_livro(void);
void gerar_relatorios(void);

// funcoes para arquivos
void carregar_dados(void);
void salvar_dados(void);


// ----- funcao principal -----

int main(void) {
    // variaveis
    int opcao = 1; // escolha do usuario do menu

    // carrega os dados do arquivo ao iniciar
    carregar_dados();


    do { // inicio loop principal do-while

        // menu
        system("cls"); // limpa a tela
        printf("----- menu -----\n");
        printf("[1] - cadastrar livro \n");
        printf("[2] - consultar livro\n");
        printf("[3] - atualizar livro\n");
        printf("[4] - remover livro\n");
        printf("[5] - emprestar livro\n");
        printf("[6] - devolver livro\n");
        printf("[7] - gerar relatorios\n");
        printf("[0] - sair\n");
        printf("---------------------\n");
        Sleep(750); // pausa de 0,75 seg

        printf("escolha uma opcao: "); // selecao do usuario
        scanf("%d", &opcao);

        // opcoes do menu
        switch (opcao) {
            case 1: // cadastrar livro
                cadastrar_livro(); 
                salvar_dados();
                break;

            case 2: // consultar livro
                consultar_livro(); break;

            case 3: // atualizar livro
                atualizar_livro(); 
                salvar_dados();
                break;

            case 4: // remover livro
                remover_livro(); 
                salvar_dados();
                break;

            case 5: // emprestar livro
                emprestar_livro(); 
                salvar_dados();
                break;

            case 6: // devolver livro
                devolver_livro(); 
                salvar_dados();
                break;

            case 7: // gerar relatorios
                gerar_relatorios(); break;

            case 0: // sair
                break;

            default: // qualquer numero diferente de 0 a 7
                printf("opcao invalida. tente novamente.\n");
                Sleep(750); //pausa de 0,75 seg
                break;
        }

    } while (opcao != 0); // fim do loop do-while (caso opcao seja o)
    printf("encerrando o programa...\n");

    return 0;
} // fim do codigo principal



// ----- funcoes -----

// funcao para limpar o buffer do teclado
void limpa_buffer(void) {
    int c; // variavel temporaria para o caractere
    while ((c = getchar()) != '\n' && c != EOF); // limpa ate o fim da linha
}



// funcao para cadastrar um livro
void cadastrar_livro(void) {
    system("cls"); // limpa a tela
    Sleep(750); // pausa de 0,75 seg

    if (total_livros >= max_livros) {
        printf("capacidade maxima de livros atingida.\n");  
        Sleep(750);
        return;
    }

    struct livro novo_livro; // variavel temporaria para o novo livro

    limpa_buffer(); // limpa o buffer antes de ler os dados

    printf("digite o titulo do livro: ");
    fgets(novo_livro.titulo, 100, stdin);
    novo_livro.titulo[strcspn(novo_livro.titulo, "\n")] = 0; 

    printf("digite o autor do livro: ");
    fgets(novo_livro.autor, 100, stdin);
    novo_livro.autor[strcspn(novo_livro.autor, "\n")] = 0; 

    printf("digite o ano de publicacao: ");
    scanf("%d", &novo_livro.ano_publicacao);


    novo_livro.disponivel = 1; // livro disponivel
    novo_livro.ativo = 1;      // livro ativo

    biblioteca[total_livros] = novo_livro; // adiciona o novo livro ao array
    total_livros++; // incrementa o contador de livros

    printf("livro cadastrado com sucesso.\n"); 
    printf("total de livros: %d\n", total_livros); 

    Sleep(1000); 
}



// funcao para consultar um livro
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
        printf("[5] - ver todos os livros\n");
        printf("[0] - voltar ao menu\n");
        printf("--------------------------\n");

        Sleep(750); // pausa de 0,75 seg

        printf("escolha uma opcao: "); // selecao do usuario
        scanf("%d", &opcao);
        limpa_buffer(); // Limpa o buffer apos o scanf, para o proximo fgets funcionar

        int encontrado = 0; // flag para saber se achamos algo
        int i; // contador do loop

        switch (opcao) {
            case 1: { // busca por titulo
                char busca_titulo[100];
                printf("digite o titulo (ou parte) para buscar: ");
                fgets(busca_titulo, 100, stdin);
                busca_titulo[strcspn(busca_titulo, "\n")] = 0; 

                system("cls");
                printf("----- resultados da busca por titulo -----\n");
                for (i = 0; i < total_livros; i++) {
                    if (biblioteca[i].ativo == 1 && strstr(biblioteca[i].titulo, busca_titulo) != NULL) {
                        printf("titulo: %s\n", biblioteca[i].titulo);
                        printf("autor: %s\n", biblioteca[i].autor);
                        printf("ano: %d\n", biblioteca[i].ano_publicacao);
                        printf("status: %s\n", biblioteca[i].disponivel ? "disponivel" : "emprestado");
                        printf("----------------------------------------\n");
                        encontrado = 1;
                    }
                }
                if (!encontrado) {
                    printf("nenhum livro encontrado com esse titulo.\n");
                }
                Sleep(3000); // Pausa de 3 segundos
                break;
            }

            case 2: { // busca por autor
                char busca_autor[100];
                printf("digite o autor (ou parte) para buscar: ");
                fgets(busca_autor, 100, stdin);
                busca_autor[strcspn(busca_autor, "\n")] = 0; 

                system("cls");
                printf("----- resultados da busca por autor -----\n");
                for (i = 0; i < total_livros; i++) {
                    if (biblioteca[i].ativo == 1 && strstr(biblioteca[i].autor, busca_autor) != NULL) {
                        printf("titulo: %s\n", biblioteca[i].titulo);
                        printf("autor: %s\n", biblioteca[i].autor);
                        printf("ano: %d\n", biblioteca[i].ano_publicacao);
                        printf("status: %s\n", biblioteca[i].disponivel ? "disponivel" : "emprestado");
                        printf("----------------------------------------\n");
                        encontrado = 1;
                    }
                }
                if (!encontrado) {
                    printf("nenhum livro encontrado desse autor.\n");
                }
                Sleep(3000); // Pausa de 3 segundos
                break;
            }

            case 3: { // busca por ano
                int busca_ano;
                printf("digite o ano de publicacao para buscar: ");
                scanf("%d", &busca_ano);
                limpa_buffer(); 

                system("cls");
                printf("----- resultados da busca por ano (%d) -----\n", busca_ano);
                for (i = 0; i < total_livros; i++) {
                    if (biblioteca[i].ativo == 1 && biblioteca[i].ano_publicacao == busca_ano) {
                        printf("titulo: %s\n", biblioteca[i].titulo);
                        printf("autor: %s\n", biblioteca[i].autor);
                        printf("ano: %d\n", biblioteca[i].ano_publicacao);
                        printf("status: %s\n", biblioteca[i].disponivel ? "disponivel" : "emprestado");
                        printf("----------------------------------------\n");
                        encontrado = 1;
                    }
                }
                if (!encontrado) {
                    printf("nenhum livro encontrado desse ano.\n");
                }
                Sleep(3000); // Pausa de 3 segundos
                break;
            }

            case 4: { // busca por disponibilidade
                int busca_disp;
                printf("buscar livros (1 - disponiveis / 0 - emprestados): ");
                scanf("%d", &busca_disp);
                limpa_buffer();

                system("cls");
                printf("----- resultados da busca por status -----\n");
                for (i = 0; i < total_livros; i++) {
                    if (biblioteca[i].ativo == 1 && biblioteca[i].disponivel == busca_disp) {
                        printf("titulo: %s\n", biblioteca[i].titulo);
                        printf("autor: %s\n", biblioteca[i].autor);
                        printf("ano: %d\n", biblioteca[i].ano_publicacao);
                        printf("----------------------------------------\n");
                        encontrado = 1;
                    }
                }
                if (!encontrado) {
                    printf("nenhum livro encontrado com esse status.\n");
                }
                Sleep(3000); // Pausa de 3 segundos
                break;
            }
            
            case 5: { // ver todos
                system("cls");
                printf("----- relatorio: todos os livros ativos -----\n");
                for (i = 0; i < total_livros; i++) {
                    if (biblioteca[i].ativo == 1) { // so mostra os ativos
                        printf("titulo: %s\n", biblioteca[i].titulo);
                        printf("autor: %s\n", biblioteca[i].autor);
                        printf("ano: %d\n", biblioteca[i].ano_publicacao);
                        printf("status: %s\n", biblioteca[i].disponivel ? "disponivel" : "emprestado");
                        printf("----------------------------------------\n");
                        encontrado = 1;
                    }
                }
                if (!encontrado) {
                    printf("nenhum livro ativo cadastrado.\n");
                }
                Sleep(3000); // Pausa de 3 segundos
                break;
            }


            case 0: // voltar ao menu
                break;

            default: // qualquer numero diferente de 0 a 5
                printf("opcao invalida. tente novamente.\n");  
                Sleep(750); //pausa de 0,75 seg
                break;
        }
    } while (opcao != 0);
    printf("voltando ao menu principal...\n");
    Sleep(750);
}




// funcao para atualizar um livro
void atualizar_livro(void) {
    system("cls");
    char busca_titulo[100];
    int encontrado = 0;
    int id_atualizar = -1; 
    int i;

    limpa_buffer(); 
    printf("digite o titulo do livro que deseja atualizar: ");
    fgets(busca_titulo, 100, stdin);
    busca_titulo[strcspn(busca_titulo, "\n")] = 0;

    for (i = 0; i < total_livros; i++) {
        if (biblioteca[i].ativo == 1 && strstr(biblioteca[i].titulo, busca_titulo) != NULL) {
            printf("livro encontrado:\n");
            printf("titulo: %s\n", biblioteca[i].titulo);
            printf("autor: %s\n", biblioteca[i].autor);
            printf("ano: %d\n", biblioteca[i].ano_publicacao);
            id_atualizar = i;
            encontrado = 1;
            break; 
        }
    }

    if (!encontrado) {
        printf("livro nao encontrado.\n");
    } else {
        printf("\n--- insira os novos dados ---\n");
        printf("novo titulo: ");
        fgets(biblioteca[id_atualizar].titulo, 100, stdin);
        biblioteca[id_atualizar].titulo[strcspn(biblioteca[id_atualizar].titulo, "\n")] = 0;

        printf("novo autor: ");
        fgets(biblioteca[id_atualizar].autor, 100, stdin);
        biblioteca[id_atualizar].autor[strcspn(biblioteca[id_atualizar].autor, "\n")] = 0;

        printf("novo ano de publicacao: ");
        scanf("%d", &biblioteca[id_atualizar].ano_publicacao);
        limpa_buffer(); 

        printf("livro atualizado com sucesso.\n");  
    }
    Sleep(1500); 
}





// funcao para remover um livro
void remover_livro(void) {
    system("cls");
    char busca_titulo[100];
    int encontrado = 0;
    int i;

    limpa_buffer(); 
    printf("digite o titulo do livro que deseja remover: ");
    fgets(busca_titulo, 100, stdin);
    busca_titulo[strcspn(busca_titulo, "\n")] = 0;

    for (i = 0; i < total_livros; i++) {
        if (biblioteca[i].ativo == 1 && strstr(biblioteca[i].titulo, busca_titulo) != NULL) {
            printf("livro encontrado: %s | %s\n", biblioteca[i].titulo, biblioteca[i].autor);

            // Remocao Logica: Apenas desativa o livro
            biblioteca[i].ativo = 0;

            printf("livro removido (logicamente) com sucesso.\n");  
            encontrado = 1;
            break; 
        }
    }
    if (!encontrado) {
        printf("livro nao encontrado.\n");
    }
    Sleep(1500);
}




// funcao para emprestar um livro
void emprestar_livro(void) {
    system("cls");
    char busca_titulo[100];
    int encontrado = 0;
    int i;

    limpa_buffer(); 
    printf("digite o titulo do livro que deseja emprestar: ");
    fgets(busca_titulo, 100, stdin);
    busca_titulo[strcspn(busca_titulo, "\n")] = 0;

    for (i = 0; i < total_livros; i++) {
        if (biblioteca[i].ativo == 1 && strstr(biblioteca[i].titulo, busca_titulo) != NULL) {
            encontrado = 1;
            if (biblioteca[i].disponivel == 1) {
                biblioteca[i].disponivel = 0; 
                printf("livro '%s' emprestado com sucesso.\n", biblioteca[i].titulo);  
            } else {
                printf("livro '%s' ja esta emprestado.\n", biblioteca[i].titulo);  
            }
            break; 
        }
    }
    if (!encontrado) {
        printf("livro nao encontrado.\n");
    }
    Sleep(1500);
}




// funcao para devolver um livro
void devolver_livro(void) {
    system("cls");
    char busca_titulo[100];
    int encontrado = 0;
    int i;

    limpa_buffer(); 
    printf("digite o titulo do livro que deseja devolver: ");
    fgets(busca_titulo, 100, stdin);
    busca_titulo[strcspn(busca_titulo, "\n")] = 0;

    for (i = 0; i < total_livros; i++) {
        if (biblioteca[i].ativo == 1 && strstr(biblioteca[i].titulo, busca_titulo) != NULL) {
            encontrado = 1;
            if (biblioteca[i].disponivel == 0) { 
                biblioteca[i].disponivel = 1; 
                printf("livro '%s' devolvido com sucesso.\n", biblioteca[i].titulo);  
            } else {
                printf("livro '%s' ja estava disponivel (nao estava emprestado).\n", biblioteca[i].titulo);
            }
            break; 
        }
    }
    if (!encontrado) {
        printf("livro nao encontrado (ou ja foi removido).\n");
    }
    Sleep(1500);
}




// funcao para gerar relatorios
void gerar_relatorios(void) {
    system("cls");
    Sleep(750);
    int opcao;

    do {
        system("cls");
        printf("----- relatorios -----\n");
        printf("[1] - listar todos os livros ativos\n");
        printf("[2] - listar livros disponiveis\n");
        printf("[3] - listar livros emprestados\n");
        printf("[0] - voltar ao menu\n");
        printf("----------------------\n");
        printf("escolha uma opcao: ");
        scanf("%d", &opcao);
        limpa_buffer();

        int encontrado = 0;
        int i;

        switch (opcao) {
            case 1: 
                system("cls");
                printf("----- relatorio: todos os livros ativos -----\n");
                for (i = 0; i < total_livros; i++) {
                    if (biblioteca[i].ativo == 1) {
                        printf("titulo: %s\n", biblioteca[i].titulo);
                        printf("autor: %s\n", biblioteca[i].autor);
                        printf("ano: %d\n", biblioteca[i].ano_publicacao);
                        printf("status: %s\n", biblioteca[i].disponivel ? "disponivel" : "emprestado");
                        printf("----------------------------------------\n");
                        encontrado = 1;
                    }
                }
                if (!encontrado) {
                    printf("nenhum livro ativo cadastrado.\n");
                }
                Sleep(3000); 
                break;

            case 2: 
                system("cls");
                printf("----- relatorio: livros disponiveis -----\n");
                for (i = 0; i < total_livros; i++) {
                    if (biblioteca[i].ativo == 1 && biblioteca[i].disponivel == 1) {
                        printf("titulo: %s\n", biblioteca[i].titulo);
                        printf("autor: %s\n", biblioteca[i].autor);
                        printf("ano: %d\n", biblioteca[i].ano_publicacao);
                        printf("----------------------------------------\n");
                        encontrado = 1;
                    }
                }
                if (!encontrado) {
                    printf("nenhum livro disponivel no momento.\n");
                }
                Sleep(3000); 
                break;

            case 3: 
                system("cls");
                printf("----- relatorio: livros emprestados -----\n");
                for (i = 0; i < total_livros; i++) {
                    if (biblioteca[i].ativo == 1 && biblioteca[i].disponivel == 0) {
                        printf("titulo: %s\n", biblioteca[i].titulo);
                        printf("autor: %s\n", biblioteca[i].autor);
                        printf("ano: %d\n", biblioteca[i].ano_publicacao);
                        printf("----------------------------------------\n");
                        encontrado = 1;
                    }
                }
                if (!encontrado) {
                    printf("nenhum livro emprestado no momento.\n");
                }
                Sleep(3000); 
                break;

            case 0:
                break;

            default:
                printf("opcao invalida.\n");  
                Sleep(750);
                break;
        }

    } while (opcao != 0);

    printf("voltando ao menu principal...\n");
    Sleep(750);
}


// ----- funcoes para arquivos -----

void carregar_dados(void) {
    FILE *f; // ponteiro para o arquivo
    
    // abre o arquivo "biblioteca.dat" em modo de leitura binaria ("rb")
    f = fopen("biblioteca.dat", "rb");

    // se 'f' for NULL, o arquivo nao existe (ex: primeira vez rodando)
    if (f == NULL) {
        // printf("nenhum arquivo de dados encontrado. iniciando do zero.\n"); // opcional
        Sleep(500);
        return; // sai da funcao, total_livros continua 0
    }

    // le o numero de livros
    // le 1 elemento do tamanho de um 'int', e guarda em 'total_livros'
    fread(&total_livros, sizeof(int), 1, f);
    
    // le o array de livros
    // le 'total_livros' elementos, cada um do tamanho de 'struct livro'
    fread(biblioteca, sizeof(struct livro), total_livros, f);

    // fecha o arquivo
    fclose(f);

    printf("dados carregados com sucesso. total: %d\n", total_livros);
    Sleep(500);
}


void salvar_dados(void) {
    FILE *f;
    
    // abre o arquivo "biblioteca.dat" em modo de escrita binaria ("wb")
    // "wb" apaga o arquivo anterior e escreve um novo
    f = fopen("biblioteca.dat", "wb");

    if (f == NULL) {
        printf("erro critico ao salvar dados. verifique permissoes.\n");  
        Sleep(2000);
        return; // sai se nao conseguir abrir/criar o arquivo
    }

    // escreve o numero de livros
    fwrite(&total_livros, sizeof(int), 1, f);
    
    // escreve o array de livros (apenas os 'total_livros' que estao em uso)
    fwrite(biblioteca, sizeof(struct livro), total_livros, f);

    // fecha o arquivo
    fclose(f);
    
    printf("dados salvos.\n");
}
