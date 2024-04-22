#include <stdio.h>
#include <ctype.h>  // Incluido para usar tolower

// Función para convertir una cadena de caracteres a letras minúsculas
void string_to_min(char *string) {
    // Iteración sobre cada carácter en la cadena
    while (*string != '\0') {
        // Convierte el carácter a minúscula si es una letra
        *string = tolower(*string);
        string++;  // Se mueve al siguiente carácter
    }
}

// void main() {
//     char str[] = "Hola, Mundo!";  

//     printf("Cadena original: %s\n", str);

//     string_to_min(str);

//     printf("Cadena en minúsculas: %s\n", str);

// }