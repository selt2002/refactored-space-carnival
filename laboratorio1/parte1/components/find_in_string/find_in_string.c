#include <stdio.h>
#include <string.h>

int find_in_string(char *haystack, char *needle) {
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);
    
    if (needle_len > haystack_len) {
        // Si needle es mas grande que haystack no se puede encontrar
        return -1;
    }
    
    for (int i = 0; i <= haystack_len - needle_len; i++) {
        int j;
        for (j = 0; j < needle_len; j++) {
            if (haystack[i + j] != needle[j]) {
                break; // Si los caracteres no son iguales, se mueve a la siguiente posicion en haystack
            }
        }
        
        if (j == needle_len) {
            // Si completamos el loop sin romper el substring es encontrado
            return i;
        }
    }
    
    // Substring no encontrado
    return -1;
}

// void main(){
//     char *haystack = "hola como te va"; 
//     char *needle = "hola";

//     find_in_string(haystack,needle);

// }