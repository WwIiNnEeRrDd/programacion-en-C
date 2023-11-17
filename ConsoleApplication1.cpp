#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void completarMatrizRandom(int** matriz, int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 9; // Genera números aleatorios 
        }
    }
}

static void imprimirMatriz(int** matriz, int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

static double multiplicarMatrices (int** matriz1, int** matriz2, int** matrizMultiplicada, int n) {
    
    clock_t tiempoInicial, tiempoFinal;
    double tiempoEjecucion;

    tiempoInicial = clock();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrizMultiplicada[i][j] = 0;
            for (int k = 0; k < n; k++) {
                matrizMultiplicada[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    tiempoFinal = clock();

    tiempoEjecucion = ((double)(tiempoFinal - tiempoInicial)) / CLOCKS_PER_SEC;//se utiliza CLOCKS_PER_SEC para convertir a segundos
    
    return tiempoEjecucion;
}

int main() {
    int numero;

    printf("Ingrese un numero para generar las matrices");
    scanf_s("%d", &numero);

    int** matrizDinamica1 = (int**)malloc(numero * sizeof(int*));
    int** matrizDinamica2 = (int**)malloc(numero * sizeof(int*));
    int** matrizDinamica3 = (int**)malloc(numero * sizeof(int*));
    int** resultadoPrimeraMultiplicacion = (int**)malloc(numero * sizeof(int*));
    int** matrizMultiplicada = (int**)malloc(numero * sizeof(int*));

    for (int i = 0; i < numero; i++) {
        matrizDinamica1[i] = (int*)malloc(numero * sizeof(int));
    }
    for (int i = 0; i < numero; i++) {
        matrizDinamica2[i] = (int*)malloc(numero * sizeof(int));
    }
    for (int i = 0; i < numero; i++) {
        matrizDinamica3[i] = (int*)malloc(numero * sizeof(int));
    }
    for (int i = 0; i < numero; i++) {
        resultadoPrimeraMultiplicacion[i] = (int*)malloc(numero * sizeof(int));
    }
    for (int i = 0; i < numero; i++) {
        matrizMultiplicada[i] = (int*)malloc(numero * sizeof(int));
    }

    completarMatrizRandom(matrizDinamica1, numero);
    completarMatrizRandom(matrizDinamica2, numero);
    completarMatrizRandom(matrizDinamica3, numero);

    printf("Matriz generada numero 1\n");
    imprimirMatriz(matrizDinamica1, numero);
    printf("Matriz generada numero 2\n");
    imprimirMatriz(matrizDinamica2, numero);
    printf("Matriz generada numero 3\n");
    imprimirMatriz(matrizDinamica3, numero);
    

    double tiempo = multiplicarMatrices(matrizDinamica1, matrizDinamica2, resultadoPrimeraMultiplicacion, numero);
    printf("El tiempo de ejecucion de la primera multiplicacion fue de: %f segundos\n", tiempo);
    tiempo = multiplicarMatrices(resultadoPrimeraMultiplicacion, matrizDinamica3, matrizMultiplicada, numero);
    printf("El tiempo de ejecucion de la segunda multiplicacion fue de: %f segundos\n", tiempo);

    printf("Matriz multiplicada\n");
    imprimirMatriz(matrizMultiplicada, numero);

    for (int i = 0; i < numero; i++) {
        free(matrizDinamica1[i]);
    }
    free(matrizDinamica1);

    for (int i = 0; i < numero; i++) {
        free(matrizDinamica2[i]);
    }
    free(matrizDinamica2);

    for (int i = 0; i < numero; i++) {
        free(matrizDinamica3[i]);
    }
    free(matrizDinamica3);

    for (int i = 0; i < numero; i++) {
        free(resultadoPrimeraMultiplicacion[i]);
    }
    free(resultadoPrimeraMultiplicacion);

    for (int i = 0; i < numero; i++) {
        free(matrizMultiplicada[i]);
    }
    free(matrizMultiplicada);

    return 0;
}

