#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 7

//Genera matriz binaria aleatoria de 0s y 1s
void generarMatriz(int matriz[SIZE][SIZE]) {
	//Semilla aleatoria basada en el tiempo
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		for (int j =0; j < SIZE; j++) {
			//Rellena con 0 o 1 aleatorio
			matriz[i][j] = rand() % 2;
		}
	}
}

//Imprime la matriz
void imprimirMatriz(int matriz[SIZE][SIZE]) {
	printf("La matriz utilizada corresponde a:\n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

//Encuentra la secuencia diagonal de 1s mas larga en la matriz
int findLargestLine(int matriz[SIZE][SIZE]) {
	int max = 0;

	//Revisa las diagonales que empiezan en la primera columna de la matriz
	for (int fila = 0; fila < SIZE; fila++) {
		int i = fila, j = 0, cantidad = 0;
		while (i < SIZE && j < SIZE) {
		       if (matriz[i][j] == 1) {
			       cantidad++;
			       if (cantidad > max) max = cantidad;
		       } else {
			       cantidad = 0;
		       }
		       i++;
		       j++;
		}
	}

	//Revisa las diagonales que empiezan en la primera fila de la matriz
	 for (int col = 1; col < SIZE; col++) {
                int i = 0, j = col, cantidad = 0;
                while (i < SIZE && j < SIZE) {
                       if (matriz[i][j] == 1) {
                               cantidad++;
                               if (cantidad > max) max = cantidad;
                       } else {
                               cantidad = 0;
                       }
                       i++;
                       j++;
                }
        }

	 return max;
}

int main() {
	int matriz[SIZE][SIZE];

	generarMatriz(matriz);
	imprimirMatriz(matriz);

	int mayor = findLargestLine(matriz);
	printf("El tamano de la secuencia en diagonal de 1s mas grande es: %d\n", mayor);

	return 0;
}

