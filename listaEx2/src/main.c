/*
Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar, porém, toda a informação incluída na agenda deve ficar num único lugar chamado: “void *pBuffer”.
• Não pergunte para o usuário quantas pessoas ele vai incluir. Não pode alocar espaço para mais pessoas do que o necessário.
• Cada pessoa tem nome[10], idade e telefone.
• O trabalho que vale nota será uma continuação deste.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[10];
    int idade;
    int telefone;
}Pessoa;

void inclui(Pessoa** pBuffer, int tamanho);
void apaga(Pessoa** pBuffer);
void lista(Pessoa** pBuffer, int tamanho);
void busca();
int menu();

int main() {
    Pessoa *pBuffer;
    int tamanho = 0;
    int opcao;

    pBuffer = (Pessoa *)malloc(sizeof(Pessoa));

    opcao = menu();
    while (1) {
        switch (opcao)
        {
        case 1:
            tamanho++;
            inclui(&pBuffer, tamanho);
            break;
        case 2:
            tamanho--;
            //apaga(&pBuffer);
            break;
        case 3:
            lista(&pBuffer, tamanho);
            break;
        case 4:
            //busca();
            break;
        case 5:
            exit(1);
            break;
        default:
            break;
        }
        opcao = menu();
    }
    

    return 0;
}

int menu() {
    int c;

    printf("+---Informe sua Escolha---+\n");
    printf(" 1. Incluir Pessoa\n");
    printf(" 2. Apagar Pessoa\n");
    printf(" 3. Listar\n");
    printf(" 4. Buscar por nome\n");
    printf(" 5. Sair\n");
    scanf("%d", &c);

    return c;
}

void inclui(Pessoa** pBuffer, int tamanho) {
    Pessoa *ptr;

    ptr = (Pessoa *)realloc(*pBuffer, tamanho*sizeof(Pessoa));

    getchar();
    printf("Pessoa %d:\n", tamanho);
    printf("-Nome: ");
    scanf("%[^\n]s", ptr->nome);
    printf("-Idade: ");
    scanf("%d", &ptr->idade);
    printf("-Telefone: ");
    scanf("%d", &ptr->telefone);

    *pBuffer = ptr;
}

void lista(Pessoa** pBuffer, int tamanho) {
    for( int i=0 ; i<tamanho ; i++) {
        printf("Dados da Pessoa %d\n", i+1);
        printf("--Nome: %s\n", pBuffer[i]->nome);
        printf("--Idade: %d\n", pBuffer[i]->idade);
        printf("--Telefone: %d\n", pBuffer[i]->telefone);
    }
}