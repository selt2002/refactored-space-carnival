#include <stdio.h>
#include <string.h>

void *min_element(void *array, size_t data_type, size_t array_size) {
    if (array == NULL || data_type == 0 || array_size == 0) {
        // Verifica los parámetros de entrada
        printf("Error: Parámetros inválidos.\n");
        return NULL;
    }

    // Convierte el puntero genérico a un puntero del tipo deseado
    char *arr = (char *)array;

    // Inicializa el puntero al elemento mínimo como el primer elemento del array
    char *min_element_ptr = arr;

    // Iteración sobre los elementos del array
    for (size_t i = 1; i < array_size; i++) {
        // Obtención del puntero al siguiente elemento en el array
        char *current_element = arr + (i * data_type);

        // Comparación del elemento actual con el elemento mínimo encontrado hasta ahora
        if (memcmp(current_element, min_element_ptr, data_type) < 0) {
            // Si el elemento actual es menor que el elemento mínimo, actualiza el puntero al mínimo
            min_element_ptr = current_element;
        }
    }

    printf("Elemento mínimo del array: %d\n", *min_element_ptr);

    // Devuelve el puntero al elemento mínimo encontrado
    return (void *)min_element_ptr;
}

// void main() {
//     int int_array[] = {10, 20, 5, 30, 15};

//     min_element(int_array, sizeof(int), sizeof(int_array) / sizeof(int));
// }