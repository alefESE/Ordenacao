#include <stdio.h>
#include <stdlib.h>

void ordena(int array[], int len){
    if(len <= 1) return;
    int i, j, min, bkp;
    //looping externo
    for(i = 0; i < len; i++){
        min = i;//possivel menor numero
        //looping interno
        for(j = i+1; j < len; j++)
        //seleciona o menor elemento
            if(array[j] < array[min])
                min = j;
    //guarda o elemento selecionado
    bkp = array[min];
    //swap entre elemento selecionado
    array[min] = array[i];
    array[i] = bkp;
    //e elemento inicial relativo ao looping externo
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Modo de uso:\n");
        printf("Selection <num1> <num2> <...>\n");
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