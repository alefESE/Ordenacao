#include <stdio.h>
#include <stdlib.h>

#define troca(A, B) {int t = A; A = B; B = t;}

void ordena(int array[], int n){
    heapSort(array, n);
}

void heap(int array[], int raiz, int base){
    int flag, filho;

    flag = 0;
    while((raiz*2 <= base) && (!flag)){
        if(raiz*2 == base)
            filho = raiz*2;
        else if(array[raiz*2] > array[raiz*2+1])
            filho = raiz*2;
        else
            filho = raiz*2+1;
        if(array[raiz] < array[filho]){
            troca(array[raiz], array[filho]);
            raiz = filho;
        }
        else
            flag = 1;
    }
}

void heapSort(int array[], int n){
    int m;
    for(m = (n/2)-1; m >= 0; m--)
        heap(array, m, n);

    for(m = n-1;m >= 1; m--){
        troca(array[0], array[m]);
        heap(array, 0, m-1);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Modo de uso:\n");
        printf("HeapSort <num1> <num2> <...>\n");
        return 0;
    }
    int len = argc - 1;
    int array[len];
    int i;
    for(i = 1; i <= len; i++)
        array[i-1] = atoi(argv[i]);
    ordena(array, len);
    printf("Array ordenado:\n");
    for(i = 0; i < len; i++)
        printf("%d ", array[i]);
}