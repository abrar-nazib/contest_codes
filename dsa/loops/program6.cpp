#include <stdio.h>

int main()
{

    int N, i;
    printf("Enter the number: ");
    scanf("%d", &N);

    printf("Multiplication Table for %d:\n", N);
    for (i = 1; i <= 5; i++)
    { // Loop 2 N=5, i=2
        printf("%d x %d = %d\n", N, i, N * i);
        // 5 x 2 = 10
    }

    return 0;
}
