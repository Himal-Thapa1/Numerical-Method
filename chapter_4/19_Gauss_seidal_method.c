#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3
#define TOL 0.0001

void gaussSeidel(double a[N][N], double x[N], double b[N], int n) {
    int i, j;
    double error = 100;
    int iterations = 0;

    while (error > TOL) {
        error = 0;
        for (i = 0; i < n; i++) {
            double x_prev = x[i];
            x[i] = b[i];
            for (j = 0; j < n; j++) {
                if (i != j) {
                    x[i] = x[i] - a[i][j] * x[j];
                }
            }
            x[i] = x[i] / a[i][i];
            error += fabs(x[i] - x_prev);
        }
        iterations++;
    }
    printf("Iterations: %d\n", iterations);
}

int main() {
    double a[N][N] = {{10, -1, 2}, {-1, 11, -1}, {2, -1, 10}};
    double x[N] = {1, 1, 1};
    double b[N] = {12, -1, 29};

    gaussSeidel(a, x, b, N);

    printf("The solution is: \n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %f\n", i, x[i]);
    }

    return 0;
}
