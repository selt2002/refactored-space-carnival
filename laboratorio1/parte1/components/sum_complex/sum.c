#include <stdio.h>

// Definimos una estructura para representar un numero complejo
typedef struct {
    double parte_real;
    double parte_imaginaria;
} complex_t;

// Función para calcular la suma de dos complejos
complex_t sum(complex_t a, complex_t b) {
    complex_t resultado;

    // Sumar las partes reales e imaginarias por separado
    resultado.parte_real = a.parte_real + b.parte_real;
    resultado.parte_imaginaria = a.parte_imaginaria + b.parte_imaginaria;

    printf("Suma: %.2f + %.2fi\n", resultado.parte_real, resultado.parte_imaginaria);

    return resultado;
}

// void main() {
//     complex_t num1 = {3.0, 2.0};   
//     complex_t num2 = {1.0, -1.0};  

//     sum(num1, num2);
// }