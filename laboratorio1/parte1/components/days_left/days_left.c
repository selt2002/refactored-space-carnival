#include <stdio.h>

// Define una estructura para representar una fecha
typedef struct {
    int dia;
    int mes;
    int ano;
} date_t;

// Función para determinar si el año dado es bisiesto
int ano_bisiesto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

// Función para calcular el número de días en el mes dado
int dias_mes(int mes, int ano) {
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return ano_bisiesto(ano) ? 29 : 28;
        default:
            return -1; // Mes inválido
    }
}

// Función para calcular el número de días entre dos fechas
int days_left(date_t start, date_t finish) {
    int dias = 0;

    // Si la fecha de inicio es después de la fecha final, devuelve 0 días
    if (start.ano > finish.ano ||
       (start.ano == finish.ano && start.mes > finish.mes) ||
       (start.ano == finish.ano && start.mes == finish.mes && start.dia >= finish.dia)) {
        return dias;
    }

    // Calcula los días desde la fecha de inicio hasta el final del mes de inicio
    dias += dias_mes(start.mes, start.ano) - start.dia;

    // Avanza al siguiente mes
    start.mes++;
    if (start.mes > 12) {
        start.mes = 1;
        start.ano++;
    }

    // Agrega días para los meses completos entre el mes de inicio y el mes final
    while (!(start.ano == finish.ano && start.mes == finish.mes)) {
        dias += dias_mes(start.mes, start.ano);
        start.mes++;
        if (start.mes > 12) {
            start.mes = 1;
            start.ano++;
        }
    }

    // Agrega días para el mes final hasta el día final
    dias += finish.dia;

    // Imprime la cantidad de días entre las dos fechas dadas
    printf("Cantidad de días entre las dos fechas dadas: %d\n", dias);

    return dias;
}

// int main() {
//     date_t start = {1, 1, 2024};     
//     date_t finish = {31, 12, 2024};  

//     days_left(start, finish);

//     return 0;
// }