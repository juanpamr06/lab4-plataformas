#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

// Funcion para reservar la matriz en memoria dinamica
void allocateMatrix(int*** matrix, int size) {
    
    *matrix = (int**) malloc(size * sizeof(int*));

    
    if (*matrix == NULL) {
        printf("Error al reservar memoria para las filas.\n");
        exit(1);
    }

    // Reserva memoria para cada fila 
    for (int i = 0; i < size; i++) {
        *(*matrix + i) = (int*) malloc(size * sizeof(int));

        
	if (*(*matrix + i) == NULL) {
            printf("Error al reservar memoria para la fila %d.\n", i);
            exit(1);
        }
    }
}

// Funcion para llenar la matriz con numeros aleatorios (0s y 1s)
void fillMatrix(int** matrix, int size) {
    // Genera numeros aleatorios diferentes
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
        	*(*(matrix + i) + j) = rand() % 2;
	       // genera un valor aleatorio entre 0 y 1

	}
    }
}

// Funcion para imprimir la matriz
void printMatrix(int** matrix, int size) {
    printf("Matrix (%dx%d):\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

// Funcion para liberar la memoria asignada a la matriz
void freeMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(*(matrix + i)); 
    }
    free(matrix); 
}

// Funcion para  encontrar la longitud de la linea  mas larga de 1s en una matriz

void findLargestLine(int** matrix, int size, int* result) {
    int maxCount = 0;
    int count = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int value = *(*(matrix + i) + j);

            if (value == 1) {
                count++;
                if (count > maxCount) {
                    maxCount = count;
                }
            } else {
                count = 0;
            }
        }
    }

    *result = maxCount;
}

int main() {
    int size;
    int largestLine;
    int** matrix = NULL;

   
    printf("Ingrese el tamano de la matriz cuadrada: ");
    scanf("%d", &size);

    // Reserva la matriz en la memoria
    allocateMatrix(&matrix, size);

    // Llena la matriz con 0s y 1s aleatorios
    fillMatrix(matrix, size);

    // Imprime la matriz
    printMatrix(matrix, size);

    // Busca la secuencia mas larga de 1s
    findLargestLine(matrix, size, &largestLine);
    printf("El tamano de la secuencia de 1s mas grande es: %d\n", largestLine);

    // Libera la memoria
    freeMatrix(matrix, size);

    return 0;
}

