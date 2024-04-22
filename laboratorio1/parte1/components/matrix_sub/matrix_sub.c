#include "global.h"
#include <stdio.h>
#include <stdlib.h>

// Definition of the matriz_t structure
typedef struct {
    int rows;
    int cols;
    double **data;
} matriz_t;

// Function to return the subtraction of two matrices
matriz_t matrix_sub(matriz_t A, matriz_t B) {
    matriz_t result;

    // Verify if the matrices have the same size
    if (A.rows != B.rows || A.cols != B.cols) {
        // If they don't have the same size, return an empty matrix
        result.rows = 0;
        result.cols = 0;
        result.data = NULL;
        return result;
    }

    // Create the resulting matrix of the same size as A and B
    result.rows = A.rows;
    result.cols = A.cols;
    result.data = (double **)malloc(result.rows * sizeof(double *));
    for (int i = 0; i < result.rows; i++) {
        result.data[i] = (double *)malloc(result.cols * sizeof(double));
    }

    // Perform the subtraction of matrices A and B
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            result.data[i][j] = A.data[i][j] - B.data[i][j];
        }
    }
    return result;
}

// int main(void) {
//     matriz_t a, b, res;
//     // Initialize matrices a and b
//     a.rows = 2;
//     a.cols = 2;
//     a.data = (double **)malloc(a.rows * sizeof(double *));
//     for (int i = 0; i < a.rows; i++) {
//         a.data[i] = (double *)malloc(a.cols * sizeof(double));
//     }
//     a.data[0][0] = 1;
//     a.data[0][1] = 3;
//     a.data[1][0] = 1;
//     a.data[1][1] = 4;

//     b.rows = 2;
//     b.cols = 2;
//     b.data = (double **)malloc(b.rows * sizeof(double *));
//     for (int i = 0; i < b.rows; i++) {
//         b.data[i] = (double *)malloc(b.cols * sizeof(double));
//     }
//     b.data[0][0] = 2;
//     b.data[0][1] = 3;
//     b.data[1][0] = 5;
//     b.data[1][1] = 2;

//     // Perform matrix subtraction
//     res = matrix_sub(a, b);

//     // Print the result
//     printf("%f %f\n%f %f\n", res.data[0][0], res.data[0][1], res.data[1][0], res.data[1][1]);

//     // Free allocated memory for matrices a, b, and res
//     for (int i = 0; i < a.rows; i++) {
//         free(a.data[i]);
//     }
//     free(a.data);

//     for (int i = 0; i < b.rows; i++) {
//         free(b.data[i]);
//     }
//     free(b.data);

//     for (int i = 0; i < res.rows; i++) {
//         free(res.data[i]);
//     }
//     free(res.data);

//     return 0;
// }
