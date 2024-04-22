#include <stdio.h>
#include <ctype.h>

// Función para contar el número de consonantes en una cadena
int consonantes(char *string) {
    int count = 0;

    // Itera a través de cada carácter en la cadena
    while (*string != '\0') {
        char ch = *string;

        // Verifica si el carácter es una letra minúscula (a-z) o una letra mayúscula (A-Z)
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            // Convierte el carácter a minúscula si es una letra mayúscula
            if (ch >= 'A' && ch <= 'Z') {
                ch = tolower(ch);
            }

            // Verifica si el carácter no es una vocal 
            if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
                count++; // Incrementa el contador de consonantes
            }
        }

        // Se mueve al siguiente carácter en la cadena
        string++;
    }

    printf("Cantidad de consonantes: %d\n", count);

    return count;
}

// void main() {

//     char array[] = "Buenas noches que tal";

//     consonantes(array);
// }