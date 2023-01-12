#include <stdio.h>
#include <math.h>

double f(double x)
{
    // replace this function with the function you want to integrate
    return x * x;
}

double gaussian_2point(double a, double b)
{
    double x1 = -sqrt(3) / 3, x2 = sqrt(3) / 3;
    double f1 = f((b + a) / 2 + x1 * (b - a) / 2), f2 = f((b + a) / 2 + x2 * (b - a) / 2);
    return (b - a) * (f1 + f2) / 2;
}

int main()
{
    double a, b;
    printf("Enter the limits of integration (a b): ");
    scanf("%lf %lf", &a, &b);
    printf("Integration of function from %lf to %lf is: %lf", a, b, gaussian_2point(a, b));
    return 0;
}
