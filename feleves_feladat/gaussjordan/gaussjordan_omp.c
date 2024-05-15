#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_operations.h"
#include "omp.h"

#define START_SIZE 100
#define STEP_SIZE 100
#define END_SIZE 3000

static Matrix matrix;
volatile double *X;

void gauss_jordan_solver(){
    int N = matrix.N;
    int i,j,k;

    #pragma omp parallel for shared(matrix, X) private(i,j,k)
    for (k = 0; k <= N-1; k++)
    {
        for (i = 0; i <= N-1; i++)
        {
            if (k != i)
            {
                for (j = k +1 ; j <= N; j++)
                {
                    matrix.data[i][j] = matrix.data[i][j] - (matrix.data[i][k] / matrix.data[k][k]) * matrix.data[k][j];
                }
                
            }
            
        }
        
    }

    for (int i = 0; i <= N-1; i++)
    {
        X[i] = matrix.data[i][N] / matrix.data[i][i];
    }

    for (int j = 0; j <= N-1; j++)
    {
       //printf( "\nTHE VALUE OF x%d IS %lf\n",j + 1,X[j]);
    }
    
}
int main() {
    FILE *fp;
    fp = fopen("Datas/data.csv", "a");

    for (int col = START_SIZE; col <= END_SIZE; col += STEP_SIZE) {
        int row = col + 1;

        printf("Matrix size: %d\n", col);

        // Allocate matrix
        // alloc_matrix(&matrix, col, row);

        // Allocate X
        double *X = (double *)malloc(col * sizeof(double));

        srand(time(NULL));

        // Fill matrix with random values
        // randomfill_matrix(&matrix);

        clock_t start, end;
        double time_taken;

        start = clock();

        // Solve matrix (gauss_jordan_solver function)
        // gauss_jordan_solver();

        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Time taken: %lf\n", time_taken);

        // Write data to file
        fprintf(fp, "%d %d %lf\n", 0, col, time_taken);

        // Free allocated memory
        // free_matrix(&matrix);
        free(X);
    }

    fclose(fp);

    return 0;
}
