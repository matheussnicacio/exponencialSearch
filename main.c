#include <stdio.h>

// Implementação da busca binária
int binary_search(int arr[], int target, int lo, int hi) {
    while (lo < hi) {
        // Calcula o ponto médio
        int mid = lo + (hi - lo) / 2;

        // Encontrou o elemento
        if (arr[mid] == target) {
            return mid;
        }
        // Se o elemento estiver na metade direita
        else if (arr[mid] < target) {
            lo = mid + 1;
        }
        // Se o elemento estiver na metade esquerda
        else {
            hi = mid;
        }
    }
    // Elemento não encontrado
    return -1;
}

// Implementação da busca exponencial
int exponential_search(int arr[], int n, int target) {
    // Se o primeiro elemento é o alvo
    if (arr[0] == target) {
        return 0;
    }

    // Encontra o intervalo para busca binária
    int i = 1;
    while (i < n && arr[i] <= target) {
        i *= 2;
    }

    // Chama busca binária no intervalo encontrado
    return binary_search(arr, target, i/2, (i < n ? i : n-1));
}

// Função main para teste
int main() {
    int arr[] = {2, 3, 4, 10, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 40;

    int result = exponential_search(arr, n, target);

    if (result == -1) {
        printf("Elemento %d nao encontrado no array\n", target);
    } else {
        printf("Elemento %d encontrado na posicao %d\n", target, result);
    }

    return 0;
}