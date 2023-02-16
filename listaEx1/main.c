/*
Faça um programa que armazena nomes.
O programa deve armazenar todos os nomes na mesma string
O tamanho da string deve crescer e diminuir conforme nomes
forem colocados ou removidos. Não pode ter desperdício de memória.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUMERO_MAX 100

void adicionarNaString(char *string);
//void removerString();
//void listar();

int main() {
    int opcao;
    char *string;

    string = (char *)malloc(sizeof(char));
    string = "";

    printf("\t1) Adicionar Nome\n\t2) Remover Nome\n\t3) Listar\n");
    scanf("%d", &opcao);
    while( opcao>=1 && opcao <=3) {
        switch ( opcao ) {
            case  1:
                adicionarNaString(string);
                break;
            case 2:
                //removerString();
                break;
            case 3:
                //listar();
                break;
        }
        printf("\t1) Adicionar Nome\n\t2) Remover Nome\n\t3) Listar\n");
        scanf("%d", &opcao);
    }

    return 0;
}

void adicionarNaString(char *string) {
    char nome[NUMERO_MAX];
    char str[strlen(string) + NUMERO_MAX];

    strcpy(str, "");
    scanf("%s", nome);
    getchar();
    strcat(nome, "-");
    strcpy(str, string);
    strcat(str, nome); 
    string = (char *)realloc(string, (strlen(str)+1)*sizeof(char));
    string = str;
    printf("%s string\n", string);
}