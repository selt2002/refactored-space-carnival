#include <stdio.h>
#include <stdint.h> 
#include <stdbool.h> 

int32_t string_words(char *string) {
    if (string == NULL) {
        printf("Error: Cadena nula.\n");
        return -1; // Retorna un valor indicando error
    }

    int32_t word_count = 0; // Contador de palabras
    bool in_word = false;   // Indicador de si estamos dentro de una palabra

    // Iteración sobre cada carácter de la cadena
    while (*string != '\0') {
        // Verifica si el carácter actual es un espacio en blanco
        if (*string == ' ' || *string == '\t' || *string == '\n') {
            // Si estamos dentro de una palabra y encontramos un espacio en blanco, contamos la palabra
            if (in_word) {
                word_count++;
                in_word = false; // Cambiamos a fuera de una palabra
            }
        } else {
            // Si el carácter actual no es un espacio en blanco, estamos dentro de una palabra
            in_word = true;
        }

        // Avanza al siguiente carácter
        string++;
    }

    // Cuenta la última palabra si la cadena termina con una palabra
    if (in_word) {
        word_count++;
    }

    printf("Número de palabras: %d\n", word_count);
    return word_count; // Retorna el número total de palabras
}

// void main() {
//     char input_string[] = "    Hello  \t world\n How are you?\n";

//     string_words(input_string);
// }