// for integration of f(x) from a to b.
#include <stdio.h>
#include <conio.h>
#include <math.h>
void GaussLegendre(float, float, int);

float f(float x) { return (exp(x)); }

float g(float a, float b, float z)
{
    float x = (b - a) / 2 * z + (b + a) / 2;
    return (exp(x));
}

void main()
{
    float a, b;
    int n;
    printf("Enter a and b: ");
    scanf("%f%f", &a, &b);
INPUT:
    printf("Enter 2 for 2-point formula: \n");
    printf("Enter 3 for 3-point formula: \n");
    printf("Enter 4 for 4-point formula: \n");
    scanf("%d", &n);
    switch (n)
    {
    case 2:
        printf("Using 2-point Formula::\n");
        GaussLegendre(a, b, n);
        break;
    case 3:
        printf("Using 3-point Formula::\n");
        GaussLegendre(a, b, n);
        break;
    case 4:
        printf("Using 4-point Formula::\n");
        GaussLegendre(a, b, n);
        break;
    default:
        printf("INVALID\n");
        goto INPUT;
    }
    getch();
}

void GaussLegendre(float a, float b, int n)
{
    float I;
    if (a == -1 && b == 1)
    {
        if (n == 2)
        {
            I = 1 * f(-1 / sqrt(3)) + 1 * f(1 / sqrt(3));
            printf("I=%f", I);
        }
        if (n == 3)
        {
            I = 5 / 9 * f(-sqrt(3 / 5)) + 8 / 9 * f(0) + 5 / 9 * f(sqrt(3 / 5));
            printf("I=%f", I);
        }
        if (n == 4)
        {
            I = 0.34785 * f(-0.86114) + 0.65215 * f(-0.33998) + 0.65215 * f(0.33998) + 0.34785 * f(0.86114);
            printf("I=%f", I);
        }
    }
    else
    {
        if (n == 2)
        {
            I = (b - a) / 2 * (1 * g(a, b, -1 / sqrt(3)) + 1 * g(a, b, 1 / sqrt(3)));
            printf("I=%f", I);
        }
        if (n == 3)
        {
            I = (b - a) / 2 * (5 / 9 * g(a, b, -sqrt(3 / 5)) + 8 / 9 * g(a, b, 0) + 5 / 9 * g(a, b, sqrt(3 / 5)));
            printf("I=%f", I);
        }
        if (n == 4)
        {
            I = (b - a) / 2 * (0.34785 * g(a, b, -0.86114) + 0.65215 * g(a, b, -0.33998) + 0.65215 * g(a, b, 0.33998) + 0.34785 * g(a, b, 0.86114));
            printf("I=%f", I);
        }
    }
}