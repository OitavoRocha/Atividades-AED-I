#include <stdio.h>

void Unidade(int resto);
void Dezena(int div);
void Centena(int div);
void Milhar(int div);

int main() {
    int n=3867;
    int resto10, resto100, resto1000;
    int div10, div100, div1000;

    printf("Informe um numero: ");
    scanf("%d", &n);
    while ( n<0 || n>=4000 ) {
        printf("Numero invalido, informe outro\n");
        scanf("%d", &n);
    }
    
    if ( n <= 100 ) {
        resto10 = n%10;
        div10 = n/10;
        Dezena(div10);
        Unidade(resto10);
    } else if ( n==100 ){
        printf("C");
    } else if ( n<1000 ) {
        resto100 = n%100;
        div100 = n/100;
        div10 = resto100/10;
        resto10 = resto100%10;
        Centena(div100);
        Dezena(div10);
        Unidade(resto10);
    } else {
        resto1000 = n%1000;
        div1000 = n/1000;
        resto100 = resto1000%100;
        div100 = resto1000/100;
        resto10 = resto100%10;
        div10 = resto100/10;
        Milhar(div1000);
        Centena(div100);
        Dezena(div10);
        Unidade(resto10);
    }

    printf("\n");

    return 0;
}

void Unidade(int resto) {
    if( resto >=9 ) {
        printf("IX");
    } else {
        if ( resto >= 4) {
            switch ( resto ) {
            case 4:
                printf("IV");
                break;
            case 5:
                printf("V");
                break;
            default:
                printf("V");
                for (int i = 0; i < resto-5; i++){
                    printf("I");
                }
                break;
            }
        } else if ( resto < 4 ) {
            for (int i = 0; i < resto; i++){
                printf("I");
            }
        }
    }    
}

void Dezena(int div) {
    if ( div <=3 ) {
        for(int i=0 ; i<div ; i++ ) {
            printf("X");
        }
    } else if ( div==4 ) {
        printf("XL");
    } else if ( div==5 ) {
        printf("L");
    } else if ( div<=8 ) {
        printf("L");
        for(int i=0 ; i<div-5 ; i++ ) {
            printf("X");
        }
    } else {
        printf("XC");
    }
}

void Centena(int div) {
    if( div<=3 ) {
        for(int i=0 ; i<div ; i++ ) {
            printf("C");
        }
    } else if ( div<9 ) {
        switch (div) {
        case 4:
            printf("CD");
            break;
        case 5:
            printf("D");
            break;
        default:
            printf("D");
            for (int i = 0; i < div-5; i++) {
                printf("C");
            }            
            break;
        }
    } else if ( div==9 ) {
        printf("CM");
    }
}

void Milhar(int div) {
    for(int i=0 ; i<div ; i++ ) {
        printf("M");
    }
}