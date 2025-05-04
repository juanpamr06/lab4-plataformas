#include <stdio.h>

int main() {
	int n;

	// Para leer el tamano de la matriz nxn
	printf("Ingrese el tamano de la matriz cuadrada que desee: ");
		scanf("%d", &n);

	//Matriz es de tamano nxn
	int matriz[n][n];

	//Recorre e imprime una matriz de tamano nxn
	printf("Ingrese los elementos de la matriz:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("Elemento [%d][%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}

	//Donde se almacenan las sumas de las diagonales principal y secundaria
	int suma_principal = 0;
	int suma_secundaria = 0;

	//Calculo de la suma de diagonales de la matriz
	for (int i = 0; i < n; i++) {

	//Suma de la diagonal principal de la matriz
	suma_principal += matriz[i][i]; 

	//Suma de la diagonal secundaria de la matriz
	suma_secundaria += matriz[i][n - 1 - i];
	}

	printf("Suma de la diagonal principal: %d\n", suma_principal);
	printf("Suma de la diagonal secundaria: %d\n", suma_secundaria);
	
	return 0;
}
