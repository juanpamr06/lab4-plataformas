#include <stdio.h>

int encontrarMaximo(int arr[], int n) {
	
	//Inicia con el primer valor del arreglo
	int maximo = arr[0];

	//Recorre el arreglo desde su segundo elemento
	for (int i = 1; i < n; i++) {

		//Error corregido, ahora es '>' para maximo, antes estaba '<' que sacaba minimo
		if (arr[i] > maximo) {
			//Se actualiza si se encuentra un mayor valor
			maximo = arr[i]; 
		}
	}

	return maximo;

}

int main() {
int numeros[] = {10, 20, 5, 40, 30};
int n = sizeof(numeros) / sizeof(numeros[0]);
int maximo = encontrarMaximo(numeros, n);

        //Muestra el valor maximo encontrado
	printf("El numero mas grande es: %d\n", maximo);

	return 0;
}

