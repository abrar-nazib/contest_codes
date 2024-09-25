#include <stdio.h>
#include <math.h>
// Given a quadratic equation, find the roots of the equation.

int main()
{
    int a, b, c;
    printf("Enter the values of a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);
    double d = b * b - 4 * a * c;
    if (d < 0)
    {
        printf("No real roots\n");
    }
    else if (d == 0)
    {
        double root = -b / (2 * a);
        printf("Root is: %lf\n", root);
    }
    else
    {
        double root1 = (-b + sqrt(d)) / (2 * a);
        double root2 = (-b - sqrt(d)) / (2 * a);
        printf("Roots are: %lf, %lf\n", root1, root2);
    }
    return 0;
}