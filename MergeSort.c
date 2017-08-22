#include <stdio.h>
#include <stdlib.h>

void ordena(int array[], int n){
    // ordena array array em destino
    mergeSort(array, 0, n);
}

void mergeSort(int array[], int ini, int fim){
    if(fim - ini < 2 ) return;
        int meio = (ini + fim)/2;
        // split esquerdo
        mergeSort(array, ini, meio);
        // split direito
        mergeSort(array, meio, fim);
        // combina folhas
        merge(array, ini, meio, fim);
    
}

void merge(int array[], int ini, int meio, int fim){
    int i = ini, j = meio, k = 0, *aux;
    aux = malloc((fim - ini) * sizeof(int));// array auxiliar
    // Enquanto os indices nao se cruzarem
    while(i < meio && j < fim){
        if(array[i] <= array[j]){
            aux[k] = array[i];
            i++;
        } else {
            aux[k] = array[j];
            j++;
        }
        k++;
    }
    // Ordena, se houver, os elementos à esquerda restantes
    while(i < meio){
        aux[k] = array[i];
        k++;
        i++;
    }
    // Ordena, se houver, os elementos à direita restantes
    while(j < fim){
        aux[k] = array[j];
        k++;
        j++;
    } 
    for(i = ini; i < fim; i++) array[i] = aux[i-ini]; // Recupera os dados do array auxiliar
    free(aux);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Modo de uso:\n");
        printf("MergeSort <num1> <num2> <...>\n");
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