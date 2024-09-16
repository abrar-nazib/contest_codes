#include <stdio.h>

int main()
{
    int n;

    printf("Enter a positive integer n: ");
    scanf("%d", &n);
    printf("1");
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
            printf("+1/%d", i);
    }

    return 0;
}