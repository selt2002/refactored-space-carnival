#include <stdio.h>

int string_copy(char *source, char *destination) {
    // Verifica si los punteros son nulos
    if (source == NULL || destination == NULL) {
        printf("Error: Punteros nulos\n");
        return 0;
    }

    // Iteración sobre cada carácter de la cadena source y copia en destination
    while (*source != '\0') {
        *destination = *source; // Copia el carácter de source a destination
        source++;               // Avanza al siguiente carácter en source
        destination++;          // Avanza al siguiente carácter en destination
    }

    *destination = '\0'; // Agrega el carácter nulo al final de destination

    return 1; // Retorna 1 indicando éxito
}

// void main() {
//     char source[] = "Hello, world!";
//     char destination[20]; 

//     if (string_copy(source, destination)) {
//         printf("Cadena copiada correctamente: %s\n", destination);
//     } else {
//         printf("Error al copiar la cadena.\n");
//     }
// }