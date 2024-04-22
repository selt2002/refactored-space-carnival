#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura para datos de un estudiante
typedef struct {
    char nombre[50];
    char apellido[50];
    int CI; 
    int grado;
    float promedio; 
} Estudiante;

// Definición de la estructura para un nodo de la lista enlazada
typedef struct Nodo {
    Estudiante datos;
    struct Nodo *siguiente;
} Nodo;

// Función para crear un nuevo nodo de la lista enlazada
Nodo* crearNodo(Estudiante est) {
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(1);
    }
    nuevoNodo->datos = est;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para insertar un estudiante al final de la lista
void insertarAlFinal(Nodo **head, Estudiante est) {
    Nodo *nuevoNodo = crearNodo(est);
    if (*head == NULL) {
        *head = nuevoNodo;
        return;
    }
    Nodo *temp = *head;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }
    temp->siguiente = nuevoNodo;
}

// Función para imprimir todos los estudiantes en la lista
void imprimirLista(Nodo *head) {
    Nodo *temp = head;
    while (temp != NULL) {
        Estudiante est = temp->datos;
        printf("Nombre: %s %s\n", est.nombre, est.apellido);
        printf("CI: %d\n", est.CI);
        printf("Grado: %d\n", est.grado);
        printf("Promedio: %.2f\n", est.promedio);
        printf("\n");
        temp = temp->siguiente;
    }
}

// Función para liberar la memoria utilizada por la lista enlazada
void liberarLista(Nodo *head) {
    Nodo *temp;
    while (head != NULL) {
        temp = head;
        head = head->siguiente;
        free(temp);
    }
}

// Función para insertar un estudiante en una posición específica de la lista
void insertarEnPosicion(Nodo **head, Estudiante est, int posicion) {
    if (posicion < 0) {
        printf("Error: La posición no puede ser negativa.\n");
        return;
    }

    Nodo *nuevoNodo = crearNodo(est);

    if (posicion == 0) {
        nuevoNodo->siguiente = *head;
        *head = nuevoNodo;
        return;
    }

    Nodo *temp = *head;
    int i = 0;

    while (temp != NULL && i < posicion - 1) {
        temp = temp->siguiente;
        i++;
    }

    if (temp == NULL) {
        printf("Error: La posición excede el tamaño de la lista.\n");
        return;
    }

    nuevoNodo->siguiente = temp->siguiente;
    temp->siguiente = nuevoNodo;
}

// Función para eliminar un estudiante en una posición específica de la lista
void eliminarEnPosicion(Nodo **head, int posicion) {
    if (*head == NULL) {
        printf("Error: La lista está vacía.\n");
        return;
    }

    if (posicion < 0) {
        printf("Error: La posición no puede ser negativa.\n");
        return;
    }

    Nodo *temp = *head;

    if (posicion == 0) {
        *head = temp->siguiente;
        free(temp);
        return;
    }

    int i = 0;
    while (temp != NULL && i < posicion - 1) {
        temp = temp->siguiente;
        i++;
    }

    if (temp == NULL || temp->siguiente == NULL) {
        printf("Error: La posición excede el tamaño de la lista.\n");
        return;
    }

    Nodo *nodoAEliminar = temp->siguiente;
    temp->siguiente = nodoAEliminar->siguiente;
    free(nodoAEliminar);
}

// Función para comparar dos estudiantes por nombre para orden alfabético
int compararPorNombre(const Estudiante *est1, const Estudiante *est2) {
    return strcmp(est1->nombre, est2->nombre);
}

// Función para ordenar la lista de estudiantes por nombre (orden alfabético)
void ordenarPorNombre(Nodo **head) {
    if (*head == NULL || (*head)->siguiente == NULL) {
        return; // Lista vacía o con un solo elemento, ya está ordenada
    }

    Nodo *actual = *head;
    Nodo *indice = (*head)->siguiente;

    while (indice != NULL) {
        Estudiante temp = indice->datos;
        Nodo *pos = actual;

        while (pos != indice && compararPorNombre(&(pos->datos), &temp) > 0) {
            pos->siguiente->datos = pos->datos;
            pos = pos->siguiente;
        }

        pos->datos = temp;
        indice = indice->siguiente;
    }
}

// Función para comparar dos estudiantes por CI (Cédula de Identidad) para orden numérico
int compararPorCI(const Estudiante *est1, const Estudiante *est2) {
    return (est1->CI - est2->CI);
}

// Función para ordenar la lista de estudiantes por CI (Cédula de Identidad) ascendente
void ordenarPorCI(Nodo **head) {
    if (*head == NULL || (*head)->siguiente == NULL) {
        return; // Lista vacía o con un solo elemento, ya está ordenada
    }

    Nodo *actual = *head;
    Nodo *indice = (*head)->siguiente;

    while (indice != NULL) {
        Estudiante temp = indice->datos;
        Nodo *pos = actual;

        while (pos != indice && compararPorCI(&(pos->datos), &temp) > 0) {
            pos->siguiente->datos = pos->datos;
            pos = pos->siguiente;
        }

        pos->datos = temp;
        indice = indice->siguiente;
    }
}

// Función para obtener la letra correspondiente a una calificación
char obtenerLetraCalificacion(float calificacion) {
    if (calificacion >= 0 && calificacion <= 30) {
        return 'D';
    } else if (calificacion >= 31 && calificacion <= 60) {
        return 'R';
    } else if (calificacion >= 61 && calificacion <= 75) {
        return 'B';
    } else if (calificacion >= 76 && calificacion <= 81) {
        return 'B';
    } else if (calificacion >= 82 && calificacion <= 94) {
        return 'M';
    } else if (calificacion > 95) {
        return 'S';
    } else {
        return '?'; // Si la calificación está fuera de los rangos especificados
    }
}

int main() {
    Nodo *listaEstudiantes = NULL;

    Estudiante est1 = {"Lucas", "Fernandez", 53848188, 8, 92.3};
    Estudiante est2 = {"Martina", "Rodriguez", 53848122, 9, 52.4};
    Estudiante est3 = {"Lucia", "Perez", 29543162, 11, 71.9};

    insertarAlFinal(&listaEstudiantes, est1);
    insertarAlFinal(&listaEstudiantes, est2);
    insertarAlFinal(&listaEstudiantes, est3);

    // Imprime la lista de estudiantes antes de ordenar
    printf("Lista de Estudiantes (sin ordenar):\n");
    imprimirLista(listaEstudiantes);
    printf("\n");

    // Recorre la lista de estudiantes y muestra la letra de la calificación
    Nodo *actual = listaEstudiantes;
    while (actual != NULL) {
        Estudiante est = actual->datos;
        printf("Nombre: %s %s\n", est.nombre, est.apellido);
        printf("CI: %d\n", est.CI);
        printf("Grado: %d\n", est.grado);
        printf("Promedio: %.2f\n", est.promedio);

        // Obtiene la letra correspondiente a la calificación
        char letra = obtenerLetraCalificacion(est.promedio);
        printf("Letra de Calificación: %c\n", letra);

        printf("\n");
        actual = actual->siguiente;
    }

    // Libera la memoria al finalizar el programa
    liberarLista(listaEstudiantes);

    return 0;
}