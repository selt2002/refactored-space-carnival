#include <stdio.h>
#include <ctype.h> 

int vocales(char *string) {
    if (string == NULL) {
        return 0;  // Cadena nula, no hay vocales
    }

    int count = 0;
    char *ptr = string;

    while (*ptr != '\0') {
        char ch = tolower(*ptr);  // Convertir el carácter a minúscula

        // Verificar si el carácter es una vocal
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;  // Incrementar el contador de vocales
        }

        ptr++;  // Moverse al siguiente carácter en la cadena
    }

    printf("Número de vocales: %d\n", count);

    return count;  // Devolver la cantidad total de vocales encontradas
}

// void main() {
//     char input[] = "Hello World! This is a test string.";

//     vocales(input);
// }

