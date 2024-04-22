#include <stdio.h>
#include "components/Global_H.h"
#include <stdint.h> 
#include <stdbool.h>

void main(){

   // init_lab
   init_lab();
   
   // eq_solver
    coeff_t coeficientes;
    root_t resultados;

    // Asigna valores a los coeficientes
    printf("Ingrese el coficiente a: ");
    scanf("%f", &coeficientes.a);
    printf("Ingrese el coficiente b: ");
    scanf("%f", &coeficientes.b);
    printf("Ingrese el coficiente c: ");
    scanf("%f", &coeficientes.c);

    // Llama a la función eq_solver
    resultados = eq_solver(&coeficientes);

    // Imprime los resultados
    printf("Sol. 1: %.2f\n", resultados.root1);
    printf("Sol. 2: %.2f\n", resultados.root2);

    // bin2dec
    int32_t binary;
    bool sign;
    int signo;
    
    printf("\nIngrese su numero binario: ");
    scanf("%i", &binary);

    printf("Ingrese 0 si el binario es positivo y 1 si es negativo: ");
    scanf("%i", &signo);
    sign = signo;

    bin2dec(binary, sign);

    // print_reverse_array
   
}
