#include <stdio.h>
#include <string.h>

void max_index(void *array, size_t data_type, size_t array_size) {
    if (array == NULL || data_type == 0 || array_size == 0) {
        // Verifica los parámetros de entrada
        printf("Error: Parámetros inválidos.\n");
        return;
    }

    // Convierte el puntero genérico a un puntero del tipo deseado
    char *arr = (char *)array;

    // Definimos variables para el máximo y su índice
    size_t max_index = 0;
    char *max_element_ptr = arr;

    // Iteración sobre los elementos del array
    for (size_t i = 1; i < array_size; i++) {
        // Obtención del puntero al siguiente elemento en el array
        char *current_element = arr + (i * data_type);

        // Comparación del elemento actual con el máximo encontrado hasta ahora
        if (memcmp(current_element, max_element_ptr, data_type) > 0) {
            // Si el elemento actual es mayor que el máximo, actualiza el máximo y su puntero
            max_element_ptr = current_element;
            max_index = i;
        }
    }

    // Imprime el elemento máximo encontrado
    printf("Elemento máximo del array: ");

    // Imprime el valor del elemento máximo, interpretando el puntero según el tipo de datos
    if (data_type == sizeof(int)) {
        printf("%d\n", *(int *)max_element_ptr); // Para int
    } else if (data_type == sizeof(float)) {
        printf("%f\n", *(float *)max_element_ptr); // Para float
    } else if (data_type == sizeof(double)) {
        printf("%lf\n", *(double *)max_element_ptr); // Para double
    } else {
        printf("Tipo de datos no soportado\n");
    }
}

// void main() {
//     int int_array[] = {10, 20, 5, 30, 15};
//     float float_array[] = {3.14, 1.23, 5.67, 2.89, 4.56};
//     double double_array[] = {12.34, 56.78, 23.45, 78.90, 45.67};

//     max_index(int_array, sizeof(int), sizeof(int_array) / sizeof(int));

//     max_index(float_array, sizeof(float), sizeof(float_array) / sizeof(float));

//     max_index(double_array, sizeof(double), sizeof(double_array) / sizeof(double));
// }