#include <stdio.h>
#include <stdlib.h>

void ordena(int array[], int len){
    if(len <= 1) return;
    int i, j, min, bkp;
    //looping externo
    for(i = 1; i < len; i++){
        bkp = array[i];//possivel menor numero
        //looping interno
        for(j = i-1; j >= 0 && array[j] > bkp; j--)
        //swap se um elemento maior for encontrado a esquerda
            array[j+1] = array[j];
    array[j+1] = bkp;//recupera o bakup
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Modo de uso:\n");
        printf("InsertionSort <num1> <num2> <...>\n");
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
