#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para llenar la matriz con numeros aleatorios
static void completarMatrizRandom(int** matriz, int n) {

    for (int i = 0; i < n; i++) {//1+1+2 OE
        for (int j = 0; j < n; j++) {//1+1+2 OE
            matriz[i][j] = rand() % 9; // Genera números aleatorios, 2 OE
        }
    }
}

static void imprimirMatriz(int** matriz, int n) {

    for (int i = 0; i < n; i++) {//1+1+2 OE
        for (int j = 0; j < n; j++) {//1+1+2 OE
            printf("%5d\t", matriz[i][j]);//2 OE
        }
        printf("\n");//1 OE
    }
}

// Función para multiplicar matrices y calcular el tiempo de ejecución
static double multiplicarMatrices(int** matriz1, int** matriz2, int** matrizMultiplicada, int n) {

    clock_t tiempoInicial, tiempoFinal;
    double tiempoEjecucion;

    tiempoInicial = clock(); // Guarda el tiempo antes de la multiplicación, 2 OE

    //Utilizando tres bucles for, se multiplican las matrices
    for (int i = 0; i < n; i++) {//1+1+2 OE
        for (int j = 0; j < n; j++) {//1+1+2 OE
            matrizMultiplicada[i][j] = 0;//1 OE
            for (int k = 0; k < n; k++) {//1+1+2 OE
                matrizMultiplicada[i][j] += matriz1[i][k] * matriz2[k][j];//3 OE
            }
        }
    }

    tiempoFinal = clock(); // Guarda el tiempo después de la multiplicación, 2 OE

    tiempoEjecucion = ((double)(tiempoFinal - tiempoInicial)) / CLOCKS_PER_SEC;//se utiliza CLOCKS_PER_SEC para convertir a segundos, 3 OE

    return tiempoEjecucion;//1 OE
}

int main() {
    int numero;

    printf("Ingrese un numero para generar las matrices: ");//1 OE
    scanf_s("%d", &numero);//2 OE

    // Usando malloc se asigna memoria dinámica a las matrices de tamaño 'numero'
    int** matrizDinamica1 = (int**)malloc(numero * sizeof(int*));//4 OE
    int** matrizDinamica2 = (int**)malloc(numero * sizeof(int*));//4 OE
    int** matrizDinamica3 = (int**)malloc(numero * sizeof(int*));//4 OE
    int** resultadoPrimeraMultiplicacion = (int**)malloc(numero * sizeof(int*));//4 OE
    int** matrizMultiplicada = (int**)malloc(numero * sizeof(int*));//4 OE

    for (int i = 0; i < numero; i++) {//1+1+2
        matrizDinamica1[i] = (int*)malloc(numero * sizeof(int));//4 OE
    }
    for (int i = 0; i < numero; i++) {//1+1+2
        matrizDinamica2[i] = (int*)malloc(numero * sizeof(int));//4 OE
    }
    for (int i = 0; i < numero; i++) {//1+1+2
        matrizDinamica3[i] = (int*)malloc(numero * sizeof(int));//4 OE
    }
    for (int i = 0; i < numero; i++) {//1+1+2
        resultadoPrimeraMultiplicacion[i] = (int*)malloc(numero * sizeof(int));//4 OE
    }
    for (int i = 0; i < numero; i++) {//1+1+2
        matrizMultiplicada[i] = (int*)malloc(numero * sizeof(int));//4 OE
    }

    // Se llenan las matrices con numeros aleatorios
    completarMatrizRandom(matrizDinamica1, numero);//3 OE
    completarMatrizRandom(matrizDinamica2, numero);//3 OE
    completarMatrizRandom(matrizDinamica3, numero);//3 OE

    // Impresión de las matrices generadas
    printf("Matriz generada numero 1\n");//1 OE
    imprimirMatriz(matrizDinamica1, numero);//3 OE
    printf("\nMatriz generada numero 2\n");//1 OE
    imprimirMatriz(matrizDinamica2, numero);//3 OE
    printf("\nMatriz generada numero 3\n");//1 OE
    imprimirMatriz(matrizDinamica3, numero);//3 OE

    // Realiza la multiplicación de matrices y tiempo de ejecución
    double tiempo1 = multiplicarMatrices(matrizDinamica1, matrizDinamica2, resultadoPrimeraMultiplicacion, numero);//6 OE
    
    double tiempo2 = multiplicarMatrices(resultadoPrimeraMultiplicacion, matrizDinamica3, matrizMultiplicada, numero);//6 OE
    
    double tiempoTotalEjecucion = tiempo1 + tiempo2;//2 OE

    // Impresión de la matriz
    printf("\nMatriz multiplicada\n");//1 OE
    imprimirMatriz(matrizMultiplicada, numero);//3 OE

    printf("\n> El tiempo total de ejecucion del ciclo de repeticion para multiplicar las matrices es de: %f segundos\n", tiempoTotalEjecucion);//2 OE

    // Se libera la memoria asignada a las matrices
    for (int i = 0; i < numero; i++) {//1+1+2 OE
        free(matrizDinamica1[i]);//2 OE
    }
    free(matrizDinamica1);//2 OE

    for (int i = 0; i < numero; i++) {//1+1+2 OE
        free(matrizDinamica2[i]);//2 OE
    }
    free(matrizDinamica2);//2 OE

    for (int i = 0; i < numero; i++) {//1+1+2 OE
        free(matrizDinamica3[i]);//2 OE
    }
    free(matrizDinamica3);//2 OE

    for (int i = 0; i < numero; i++) {//1+1+2 OE
        free(resultadoPrimeraMultiplicacion[i]);//2 OE
    }
    free(resultadoPrimeraMultiplicacion);//2 OE

    for (int i = 0; i < numero; i++) {//1+1+2 OE
        free(matrizMultiplicada[i]);//2 OE
    }
    free(matrizMultiplicada);//2 OE

    return 0;//1 OE
} // fin main
