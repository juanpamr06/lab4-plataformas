#include <stdio.h>
#include <stdlib.h>

// Funcion que revisa si es letra o numero
int esLetraONumero(char c) {
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9')) {
        return 1;
    }
    return 0;
}

// Funcion que convierte una letra mayuscula a minuscula
char convertirMinuscula(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32; 
    }
    return c;
}

// Funcion que elimina simbolos y convierte todo a minusculas
void limpiarPalabra(char* original, char* limpia) {
    int i = 0, j = 0;
    while (original[i] != '\0') {
        char c = convertirMinuscula(original[i]);
        if (esLetraONumero(c)) {
            limpia[j] = c;
            j++;
        }
        i++;
    }
    limpia[j] = '\0';
}

// Funcion que verifica si una palabra es palindromo
int esPalindromo(char* palabra) {
    int inicio = 0;
    int final = 0;

    while (palabra[final] != '\0') {
        final++;
    }

    final = final - 1; 

    while (inicio < final) {
        if (palabra[inicio] != palabra[final]) {
            return 0; 
        }
        inicio++;
        final--;
    }

    return 1;
}

int main() {
    FILE* archivo;
    char palabra[100];
    char limpia[100];
    char palindromoMasLargo[100] = "";
    int maxLargo = 0;

    archivo = fopen("input.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo input.txt\n");
        return 1;
    }

    while (fscanf(archivo, "%s", palabra) != EOF) {
        limpiarPalabra(palabra, limpia);

        if (esPalindromo(limpia)) {
            
            int largo = 0;
            while (limpia[largo] != '\0') {
                largo++;
            }

            if (largo > maxLargo) {
                maxLargo = largo;

                int i = 0;
                while (limpia[i] != '\0') {
                    palindromoMasLargo[i] = limpia[i];
                    i++;
                }
                palindromoMasLargo[i] = '\0';
            }
        }
    }

    fclose(archivo);

    if (maxLargo > 0) {
        printf("El palindromo mas largo es: %s\n", palindromoMasLargo);
    } else {
        printf("No se encontro ningun palindromo.\n");
    }

    return 0;
}


