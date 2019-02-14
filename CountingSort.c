#include <stdio.h>
#include <stdlib.h>

void ordena(int array[], int len, int k) {
    if(len <= 1) return;
    //k+1 porque o 0 conta
    int count[k+1], aux[len], i;
    //inicializa count zerado
    for(i = 0; i <= k; i++)
        count[i] = 0;
    //guarda a contagem de cada inteiro
    for(i = 0; i < len; i++)
        ++count[array[i]];
    //guarda a posicao do inteiro no array de resultado
    for(i = 1; i <= k; i++) 
        count[i] += count[i-1];
    //constroi o array de saida
    for(i = len-1; i >= 0; i--) {
        aux[count[array[i]] - 1] = array[i];
        --count[array[i]];
    }
    //recupera dados do array auxiliar
    for(i = 0; i < len; i++) array[i] = aux[i];
}

int main(int argc, char *argv[]) {
    if (argc < 3)
    {
        printf("Modo de uso:\n");
        printf("CountingSort k <num1> <num2> <...>\n");
        printf("OBS: um k menor que o maior numero presente no array tem resultado inesperado\n");
        return 0;
    }
    int k = atoi(argv[1]);
    int len = argc - 2;
    int array[len];
    int i;
    for(i = 2; i <= len+1; i++)
        array[i-2] = atoi(argv[i]);
    ordena(array, len, k);
    printf("Array ordenado:\n");
    for(i = 0; i < len; i++)
        printf("%d ", array[i]);
    return 1;
}