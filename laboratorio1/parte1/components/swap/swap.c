#include <stdio.h>
#include <string.h>  // Incluido para usar memcpy

// Función para intercambiar dos elementos genéricos
int swap(void *elem_1, void *elem_2, size_t data_type) {
    // Verifica si los punteros son válidos
    if (elem_1 == NULL || elem_2 == NULL) {
        return -1;  // Error si algún puntero es nulo
    }

    // Crea un buffer temporal del tamaño de data_type
    void *temp = malloc(data_type);
    if (temp == NULL) {
        return -1;  // Error si no se puede asignar memoria
    }

    // Copia el contenido de elem_1 a temp
    memcpy(temp, elem_1, data_type);

    // Copia el contenido de elem_2 a elem_1
    memcpy(elem_1, elem_2, data_type);

    // Copia el contenido de temp a elem_2
    memcpy(elem_2, temp, data_type);

    // Libera la memoria del buffer temporal
    free(temp);

    return 0;  // Éxito
}

// void main() {
//     int a = 10;
//     int b = 20;

//     printf("Antes del intercambio: a = %d, b = %d\n", a, b);

//     swap(&a, &b, sizeof(int));

//     printf("Después del intercambio: a = %d, b = %d\n", a, b);
// }