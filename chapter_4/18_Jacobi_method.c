#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3
#define TOL 0.0001

void jacobi(double a[N][N], double x[N], double b[N], int n) {
    int i, j;
    double x_prev[N];
    double error = 100;
    int iterations = 0;

    while (error > TOL) {
        for (i = 0; i < n; i++) {
            x_prev[i] = x[i];
        }

        for (i = 0; i < n; i++) {
            x[i] = b[i];
            for (j = 0; j < n; j++) {
                if (i != j) {
                    x[i] = x[i] - a[i][j] * x_prev[j];
                }
            }
            x[i] = x[i] / a[i][i];
        }

        error = 0;
        for (i = 0; i < n; i++) {
            error += fabs(x[i] - x_prev[i]);
        }
        iterations++;
    }
    printf("Iterations: %d\n", iterations);
}

int main() {
    double a[N][N] = {{10, -1, 2}, {-1, 11, -1}, {2, -1, 10}};
    double x[N] = {1, 1, 1};
    double b[N] = {12, -1, 29};

    jacobi(a, x, b, N);

    printf("The solution is: \n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %f\n", i, x[i]);
    }

    return 0;
}
