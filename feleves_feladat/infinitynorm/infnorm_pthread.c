#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <float.h>
#include "matrix_operations.h"

#define START_SIZE 100
#define STEP_SIZE 100
#define END_SIZE 15500

static Matrix matrix;
static double *maxes;
volatile int MAX_NO_OF_THREADS = 12;

typedef struct arg_data {
    int thread_number;
    int N;
    double *solutions;
} arg_data;

void* infnorm(void* arg){
    arg_data* current_thread_data = (arg_data*)arg;
    printf("Current thread no is : %d\n", current_thread_data->thread_number);

    int endpart = (current_thread_data->thread_number) * (current_thread_data->N / MAX_NO_OF_THREADS);
    int startpart = endpart - (current_thread_data->N / MAX_NO_OF_THREADS);

    printf("Here we will sum %d to %d\n", startpart, endpart - 1);

    int N = current_thread_data->N;
    current_thread_data->solutions = (double *)malloc(current_thread_data->N*sizeof(double));

    //double B[N/MAX_NO_OF_THREADS];
    double seged = 0;
    
    for (int i = startpart; i < endpart; i++)
    {
        seged = 0;
        for (int j = 0; j < N; j++)
        {
            seged += abs(matrix.data[i][j]);
        }
        //B[i] = seged;
        current_thread_data->solutions[i] = seged;
    }
    maxes[current_thread_data->thread_number] = max(current_thread_data->solutions,endpart);

}

int main() {

    for (int size = start_size; size <= end_size; size += step_size) {
        alloc_matrix(&matrix, size, size);
        double *maxes = (double *)malloc(MAX_NO_OF_THREADS * sizeof(double));

        srand(time(NULL));
        randomfill_matrix(&matrix);

        pthread_t id[MAX_NO_OF_THREADS];
        arg_data arg_data[MAX_NO_OF_THREADS];

        printf("Creating %d number of threads...\n", MAX_NO_OF_THREADS);

        clock_t start, end;
        double time_taken;

        start = clock();

        for (int thread_no = 1; thread_no <= MAX_NO_OF_THREADS; thread_no++) {
            arg_data[thread_no - 1].thread_number = thread_no;
            arg_data[thread_no - 1].N = matrix.N;
            pthread_create(&id[thread_no - 1], NULL, infnorm, &arg_data[thread_no - 1]);
        }

        // Joining the threads one by one
        for (int j = 1; j <= MAX_NO_OF_THREADS; j++) {
            pthread_join(id[j - 1], NULL);
        }

        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Matrix size: %d, time taken: %lf\n", matrix.N, time_taken);

        free_matrix(&matrix);
        free(maxes);

        FILE *fp;
        fp = fopen("Datas/data.csv", "a");

        fprintf(fp, "%d %d %lf\n", 12, size, time_taken);

        fclose(fp);

        printf("Exit...");
    }

    return 0;
}