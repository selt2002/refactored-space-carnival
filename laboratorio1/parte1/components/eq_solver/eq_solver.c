#include <stdio.h>
#include <math.h>

// definimos la estructura coeff_s con sus respectivos coeficientes (a, b, c)
typedef struct coeff_s {
    float a;
    float b;
    float c;
} coeff_t;

// definimos la estructura root_s donde se guardaran luego las dos soluciones posibles (root1 y root2)
typedef struct root_s {
    float root1;
    float root2;
} root_t;

// definimos la funcion eq_solover
root_t eq_solver(coeff_t* coeficientes) {

    // asignamos los valores de a, b, c a cada coeficiente en la estructura
    float a = coeficientes->a;
    float b = coeficientes->b;
    float c = coeficientes->c;

    // definimos el determinante de la ecuacion
    float D;

    D = b*b - (4*a*c);

    root_t roots;

    // contemplamos los diferentes casos posibles para las diferentes soluciones
    if (D == 0) {
        roots.root1 = -b / (2 * a);
        roots.root2 = roots.root1;
    } else if (D > 0) {
        roots.root1 = (-b + sqrt(D)) / (2 * a);
        roots.root2 = (-b - sqrt(D)) / (2 * a);
    } else { /* D<0 */
        roots.root1 = -b / (2 * a);
        roots.root2 = sqrt(-D) / (2 * a);
    }

    // imprimimos y retornamos las soluciones
    printf("Sol 1: %.2f\n", roots.root1);
    printf("Sol 2: %.2f\n", roots.root2);

    return roots;
}

// void main(){

//     coeff_t coeficientes;
//     root_t resultados;

//     coeficientes.a = 8;
//     coeficientes.b = -3;
//     coeficientes.c = 1;

//     eq_solver(&coeficientes);
// }

