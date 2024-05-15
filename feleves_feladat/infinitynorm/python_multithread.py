import threading
import random
import time
import numpy as np

def infnorm(matrix, x):
    endpart = x * (N / num_of_threads)
    startpart = endpart - (N / num_of_threads)
    x = startpart
    while x < endpart:
        sum = 0
        for j in range(N):
            sum += abs(matrix[i][j])
        solutions.append(sum)
        x += 1

if __name__ == "__main__":
    global solutions

    start_size = 100
    step_size = 100
    end_size = 15500
    num_of_threads = 4

    for measure in range(start_size, end_size + 1, step_size):
        solutions = []

        N = measure
        matrix = np.random.rand(N, N)

        threads = []
        start = time.time()

        for i in range(num_of_threads):
            threads.append(threading.Thread(target=infnorm, args=(matrix, i + 1)))
            threads[i].start()

        for i in range(num_of_threads):
            threads[i].join()

        solution = max(solutions)
        end = time.time()

        print("Matrix size:", measure, "Elapsed time:", end - start)

        with open("python.csv", "a") as fo:
            fo.write(f"1 {measure} {end - start}\n")

        del solution
