#include <stdio.h>

void printing()
{

    printing();
}

int add(int a, int b)
{
    int sum = a + b;
    return sum;
}

void recurse_loop(int n)
{
    if (n > 1) // ending condition/ base case
        recurse_loop(n - 1);
    printf("%d\n", n);
}

int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int n = 5;
    int f = 1;
    // for (int i = n; i >= 1; i--)
    // {
    //     fact = fact * i;
    // }
    // printf("%d", fact(n));
    printf("%d", fibo(5));
    return 0;
}