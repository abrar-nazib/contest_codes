#include <stdio.h>

#define _DEBUG 1

int main()
{

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    for (int i = 1; i <= 100; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}