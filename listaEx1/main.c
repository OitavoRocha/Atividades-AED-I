#include<stdio.h>
#include<stdlib.h>

//void lerString();
//void removerString();
//void listar();

int main() {
    int opcao;

    while(1) {
        printf("\t1) Adicionar Nome\n\t2)Remover Nome\n\t3)Listar\n\t4)Sair\n");
        do {
            scanf("%d", &opcao);
        } while ( opcao < 1 || opcao > 4 );

        switch ( opcao ) {
            case  1:
                //lerString();
                break;
            case 2:
                //removerString();
                break;
            case 3:
                //listar();
                break;
            case 4:
                exit(1);
                break;
        }
    }

    return 0;
}