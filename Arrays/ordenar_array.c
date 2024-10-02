#include <stdio.h>
#include <stdlib.h>

int buscaMenor(int arr[], int inicio, int tamanho);
void ordenacaoPorSelecao(int arr[], int tamanho);

int main ()
{
    int arr[100];
    int tamanho;

    printf("Insira o tamanho do array a ser ordenado: "); //Declarar tamanho do array int eh necessario!
    scanf("%d", &tamanho);

    printf("Digite o array que será ordenado: ");
    for (int i = 0; i < tamanho; i++)
        scanf("%d", &arr[i]);

    ordenacaoPorSelecao(arr, tamanho);
    printf("Array ordenado: ");
    for(int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}

int buscaMenor(int arr[], int inicio, int tamanho) {
    int minIndex = inicio;
    for (int i = inicio + 1; i < tamanho; i++) {
       if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Função para ordenar o array usando o Selection Sort
void ordenacaoPorSelecao(int arr[], int tamanho) {
    int i, minIndex, temp;

    for (i = 0; i < tamanho - 1; i++) {
        // Encontra o índice do menor elemento a partir do índice 'i'
        minIndex = buscaMenor(arr, i, tamanho);

        // Troca o elemento atual com o menor elemento encontrado
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}