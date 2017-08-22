#include <stdio.h>
#include <stdlib.h>

#define troca(A, B) {int t = A; A = B; B = t;}

void ordena(int array[], int n){
    quickSort(array, 0, n);
}

void quickSort(int array[], int ini, int fim){
    if(ini < fim){
        int meio = particao(array, ini, fim);
        quickSort(array, ini, meio-1);
        quickSort(array, meio+1, fim);
    }
}

int particao(int array[], int ini, int fim){
    int pivo = array[ini], i = ini+1, j = fim, aux; // pivo com elemento inicial
        while (1) {
            while (i <= fim && array[i] <= pivo) ++i;
            while (pivo < array[j]) --j;
                if (i >= j) break; // cruzaram
            //swap
            troca(array[i], array[j]);
            ++i; --j;
    }                                        
    array[ini] = array[j], array[j] = pivo;                   
    return j;

}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Modo de uso:\n");
        printf("QuickSort <num1> <num2> <...>\n");
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