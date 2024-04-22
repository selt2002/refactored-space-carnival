#include <stdio.h>
#include <stdint.h>  // Incluido para usar int32_t

// Función para calcular la longitud de una cadena de caracteres
int32_t string_length(char *string) {
    int32_t length = 0;  // Inicializa la longitud como 0

    // Recorre la cadena hasta encontrar el carácter nulo ('\0')
    while (*string != '\0') {
        length++;        // Incrementa la longitud
        string++;        // Mueve el puntero al siguiente carácter
    }

    printf("Longitud del string: %d\n", length);

    return length;       // Devuelve la longitud calculada
}

// void main() {
//     char str1[] = "Hola, mundo!";          
//     char str2[] = "¡Esta es otra cadena!"; 
    
//     string_length(str1);
//     string_length(str2);
// }