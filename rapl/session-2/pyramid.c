#define _LOCAL 1
#include <stdio.h>

int main()
{

#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int space, rows, k = 0;
    scanf("%d", &rows);
    for (int i = 1; i <= rows; i++)
    {
        for (int space = 1; space <= rows - i; space++)
        {
            printf("  ");
        }
        for (int j = 1; j <= (2 * i - 1); j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}