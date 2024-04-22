#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>

int32_t bin2dec(int32_t binary, bool sign){
    
    // proporcionamos una variable digito, posicion y resultado
    int digito, posicion = 0, resultado = 0;
    // proporcionamos un array "vector" con los valores exponenciales de 2
    int vector[] = {1,2,4,8,16,32,64,128,256};

    // iteracion para recorrer los digitos del numero binario
    while(binary > 0)
    {
        digito = binary % 10; // dividimos el binario entre 10 y obtenemois el resto
        if (digito == 1) // si el digito es 1 sumamos el resultado mas el valor exponencial de 2 en la posicion correspondiente
            resultado = resultado + vector[posicion];

        posicion++; // incrementacion en el vector posicion
        binary = binary/10; // dividiimos el binario entre 10 para eliminar el ultimo digito y pasar a analizar el siguiente

    }

    // definimos una variable signo para guardar en el booleano sign
    int signo; 

    // se pide al usuario ingresar 1 si el binario es negativo y 0 si es positivo
    printf("Ingrese 0 si el binario es positivo y 1 si es negativo: ");
    scanf("%i", &signo);

    sign = signo;

    // con el booleano sign definimos si es un numero positivo o negativo
    if (sign == 0) {
        printf("El resultado es: %i \n", resultado);
    } else if (sign == 1) {
        printf("El resultado es: -%i \n", resultado);
    }
}

// void main(){

//     int32_t binary;
//     bool sign;
//     int signo;
    
//     printf("Ingrese su binario: ");
//     scanf("%i", &binary);

//     // printf("Ingrese 0 si el binario es positivo y 1 si es negativo: ");
//     // scanf("%i", &signo);
//     // sign = signo;

//     bin2dec(binary, sign);
   
// }
