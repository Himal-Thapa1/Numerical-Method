#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3
#define TOL 0.0001

void laplace(double a[N][N], double x[N], double b[N], int n) {
    int i, j, k;
    double ratio, sum;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            ratio = a[j][i] / a[i][i];
            for (k = i; k < n; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
            b[j] = b[j] - ratio * b[i];
        }
    }
    x[n - 1] = b[n - 1] / a[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--) {
        sum = 0;
        for (j = i + 1; j < n; j++) {
            sum = sum + a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
    }
    printf("The solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %f\n", i, x[i]);
    }
}

int main() {
    double a[N][N] = {{3, 2, -1}, {2, -2, 4}, {1, 1, 2}};
    double x[N] = {0, 0, 0};
    double b[N] = {7, -5, 1};

    laplace(a, x, b, N);

    return 0;
}
