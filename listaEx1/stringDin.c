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

void adicionarNaString(char *string, int* tam, int count);
//void removerString();
//void listar(char* string, int* tam);

int main() {
    int opcao;
    int count = 0;
    int tamanhoString=0;
    char *string;

    printf("\t1) Adicionar Nome\n\t2) Remover Nome\n\t3) Listar\n");
    scanf("%d", &opcao);
    while( opcao>=1 && opcao <=3) {
        getchar();
        switch ( opcao ) {
            case  1:
                adicionarNaString(string, &tamanhoString, count);
                break;
            case 2:
                //removerString();
                break;
            case 3:
                //listar(string, &tamanhoString);
                break;
        }
        printf("\t1) Adicionar Nome\n\t2) Remover Nome\n\t3) Listar\n");
        scanf("%d", &opcao);
        count++;
    }

    return 0;
}

void adicionarNaString(char *string, int* tam, int count) {
    char nome[NUMERO_MAX];
    char c;
    int i = 0;

    printf("Informe o nome que quer adicionar: ");
    c = getchar();
    while ( c != '\n' ) {
        nome[i] = c;
        c = getchar();
        i++;
    }
    nome[i] = '-';
    if ( count==0 ) {
        *tam = strlen(nome) + 1;
        string = (char *)malloc((*tam)*sizeof(char));
        strcpy(string, nome);
        printf("a");
    } else {
        *tam += strlen(nome) + 1;
        string = (char *)realloc(string, (*tam)*sizeof(char));
        strcat(string, nome);
        printf("b");
    }
    printf("%s\n", string);
}

/*void listar(char* string, int* tam) {
    for ( int i=0 ; i<*tam ; i++ ) {
        if ( string[i]=='-') {
            putchar('\n');
        } else {
            putchar(string[i]);
        }
    }
}*/