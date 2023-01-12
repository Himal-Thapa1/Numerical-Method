#include <stdio.h>
#include <stdlib.h>

#define N 4

void rungeKutta4(double *y, double *t, double h, double (*f)(double, double)) {
    double k1, k2, k3, k4;
    double temp_y = *y;
    double temp_t = *t;

    k1 = h * f(temp_t, temp_y);
    k2 = h * f(temp_t + h/2, temp_y + k1/2);
    k3 = h * f(temp_t + h/2, temp_y + k2/2);
    k4 = h * f(temp_t + h, temp_y + k3);

    *y = temp_y + (k1 + 2*k2 + 2*k3 + k4) / 6;
    *t = temp_t + h;
}

double f(double t, double y) {
    return -y;
}

int main() {
    double y = 1;
    double t = 0;
    double h = 0.1;
    int i;

    printf("t\ty\n");
    for (i = 0; i < N; i++) {
        printf("%.1lf\t%.8lf\n", t, y);
        rungeKutta4(&y, &t, h, f);
    }

    return 0;
}
