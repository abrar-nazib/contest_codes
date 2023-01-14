#define _DEBUG 1
#include <stdio.h>

int main()
{

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int rows = 5;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}