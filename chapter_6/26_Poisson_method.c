#include <stdio.h>
#include <math.h>

double poisson(double x) {
    return exp(-x)*pow(x,5)/120;
}

int main() {
    double a = 0;
    double b = 2;
    double h = 0.1;
    double x, result = 0;
    int n = (b-a)/h;

    for (int i = 1; i < n; i++) {
        x = a + i*h;
        result += poisson(x);
    }
    result += (poisson(a) + poisson(b))/2;
    result *= h;

    printf("Result: %f\n", result);

    return 0;
}
