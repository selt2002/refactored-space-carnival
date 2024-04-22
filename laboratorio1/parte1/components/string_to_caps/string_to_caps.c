#include <stdio.h>
#include <ctype.h>  // Incluido para usar toupper

// Función para convertir una cadena de caracteres a letras mayúsculas
void string_to_caps(char *string) {
    // Iteración sobre cada carácter en la cadena
    while (*string != '\0') {
        // Convierte el carácter a mayúscula si es una letra
        *string = toupper(*string);
        string++;  // Se mueve al siguiente carácter
    }
}

// void main() {
//     char str[] = "Hola, mundo!";  

//     printf("Cadena original: %s\n", str);

//     string_to_caps(str);

//     printf("Cadena en mayusculas: %s\n", str);
// }