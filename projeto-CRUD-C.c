// rodar no terminal integrado "chcp 65001" para suportar UTF-8 no Windows, casa dê erro de caracteres estranhos.

//bibliotecas
#include <stdio.h> // de entrada e saída
#include <string.h> // de manipulação de strings

// bibliotecas "extra"
#include <stdlib.h> // de utilitários // Usaremos "system("cls");"  
#include <windows.h> // do Windows // Usaremos "Sleep(2000);"

//informa funções 

//função principal
int main(void) {
    // variáveis
    int opcao=1; // escolha do usuário do menu


    // notas
    //Sleep(1000);  -- Pausa a execução por 1000 miliseg
    //system("cls"); -- Limpa a tela do console (Windows)


    //inicio loop principal do-while
    do{ 
        // menu
        system("cls");
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

        Sleep(1000); //pausa de 1 seg
        printf("Escolha uma opção: "); //seleção do usuário
        scanf("%d", &opcao);

        switch (opcao){
        case 1: // cadastrar livro
            printf("Você escolheu a opção 1!\n");
            Sleep(2000); //pausa de 2 seg

            break;

        case 2:
            printf("Você escolheu a opção 2!\n");
            Sleep(2000); //pausa de 2 seg

            break;

        case 3:
            printf("Você escolheu a opção 3!\n");
            Sleep(2000); //pausa de 2 seg

            break;

        case 4:
            printf("Você escolheu a opção 4!\n");
            Sleep(2000); //pausa de 2 seg

            break;

        case 5:
            printf("Você escolheu a opção 5!\n");
            Sleep(2000); //pausa de 2 seg

            break;
        
        case 6:
            printf("Você escolheu a opção 6!\n");
            Sleep(2000); //pausa de 2 seg

            break;
            
        case 7:
            printf("Você escolheu a opção 7!\n");
            Sleep(2000); //pausa de 2 seg

            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
            Sleep(2000); //pausa de 2 seg

            break;
        }


    } while(opcao!=0);
    printf("Encerrando o programa...\n");

    return 0;
}
//fim do código principal

// funções