#include <stdio.h>

// Definimos una estructura para representar un numero complejo
typedef struct {
    double parte_real;
    double parte_imaginaria;
} complex_t;

// Función para calcular el producto de dos números complejos
complex_t prod(complex_t a, complex_t b) {
    complex_t resultado;

    // Calcula el producto de los números complejos
    resultado.parte_real = (a.parte_real * b.parte_real) - (a.parte_imaginaria * b.parte_imaginaria);
    resultado.parte_imaginaria = (a.parte_real * b.parte_imaginaria) + (a.parte_imaginaria * b.parte_real);

    printf("Producto: %.2f + %.2fi\n", resultado.parte_real, resultado.parte_imaginaria);

    return resultado;
}

// void main() {
//     complex_t num1 = {3.0, 2.0};   
//     complex_t num2 = {1.0, -1.0}; 

//     complex_t product = prod(num1, num2);

// }