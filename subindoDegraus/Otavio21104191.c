#include <stdio.h>

#define MAX_PASSOS 45

int main() {
    int n;
    int total;
    int a=1, b=2;
    int buffer=0;

    printf("Informe o valor de n: ");
    scanf("%d", &n);
    while (n<1 || n>45) {
        printf("Numero invalido, informe outro: ");
        scanf("%d", &n);
    }

    if ( n == 1 ) {
        total = a;
    } else if ( n==2 ) {
        total = b;
    } else {
        for ( int i=2 ; i<n-1 ; i++ ) {
            buffer = a+b;
            if(i%2==0) {
                a = buffer;
            } else {
                b = buffer;
            }
        }
        total = a+b;
    }
 
    printf("Total de formas possiveis: %d\n", total);

    return 0;
}