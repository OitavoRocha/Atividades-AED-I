#include <stdio.h>
#include <stdlib.h>

int main() {
    int* array;
    int n;
    
    printf("Informe qual degrau voce que chegar: ");
    scanf("%d", &n);

    array = (int*)malloc(n*sizeof(int));

    array[0]=1;
    array[1]=2;

    for( int i=2 ; i<n ; i++ ) {
        array[i] = array[i-1] + array[i-2];
    }

    printf("Serao %d formas de chegar ate o degrau desejado\n", array[n-1]);

    return 0;
}