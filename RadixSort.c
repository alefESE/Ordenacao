#include <stdio.h>
#include <stdlib.h>
#include "util.h"

/*
Counting sort de array[] de acordo com o digito representado por exp.
k = 10 [0-9]
*/
void countSort(int array[], int len, int exp)
{
    int aux[len];
    int i, count[10] = {0}; 
    //guarda a contagem de cada inteiro
    for (i = 0; i < len; i++) 
        ++count[(array[i]/exp) % 10];
    //guarda a posicao do inteiro no array de resultado
    for(i = 1; i < 10; i++) 
        count[i] += count[i-1];
    //constroi o array de saida
    for(i = len-1; i >= 0; i--) 
    {
        aux[count[(array[i]/exp) % 10] - 1] = array[i];
        --count[(array[i]/exp) % 10];
    }
    //recupera dados do array auxiliar
    for(i = 0; i < len; i++) array[i] = aux[i];
}

void radixSort(int array[], int len)
{
    //encontra numero maximo no array
    int m = getMax(array, len);
    int exp;
    for(exp = 1; m/exp > 0; exp *= 10)
        countSort(array, len, exp);
}

int main(int argc, char *argv[]) 
{
    if (argc < 2)
    {
        printf("Modo de uso:\n");
        printf("RadixSort <num1> <num2> <...>\n");
        return 0;
    }
    int len = argc - 1;
    int array[len];
    int i;
    for(i = 1; i <= len; i++)
        array[i-1] = atoi(argv[i]);
    radixSort(array, len);
    printf("Array ordenado:\n");
    for(i = 0; i < len; i++)
        printf("%d ", array[i]);
}