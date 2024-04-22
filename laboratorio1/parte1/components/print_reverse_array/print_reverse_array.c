#include <stdio.h>
#include <string.h>

void print_reverse_array(void *array, size_t data_type, size_t array_size) {
    // Calcula el tamano toal del array en bytes
    size_t total_size = data_type * array_size;

    // Crea un puntero al final del array 
    char *end = (char *)array + total_size - data_type;

    // Itera hacia atras sobre le array
    while (end >= (char *)array) {
        // Imprime el elemento segun el data type
        switch (data_type) {
            case sizeof(int):
                printf("%d ", *((int *)end));
                break;
            case sizeof(double):
                printf("%lf ", *((double *)end));
                break;
            case sizeof(char):
                printf("%c ", *((char *)end));
                break;
            // En caso de no ser un data type conocido
            default:
                printf("Unknown data type\n");
                return;
        }

        end -= data_type;
    }

    printf("\n"); 
}

// void main() {
//     int int_array[] = {1, 2, 3, 4, 5};
//     double double_array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
//     char char_array[] = {'a', 'b', 'c', 'd', 'e'};

//     printf("int array: ");
//     print_reverse_array(int_array, sizeof(int), sizeof(int_array) / sizeof(int));

//     printf("double array: ");
//     print_reverse_array(double_array, sizeof(double), sizeof(double_array) / sizeof(double));

//     printf("char array: ");
//     print_reverse_array(char_array, sizeof(char), sizeof(char_array) / sizeof(char));
// }