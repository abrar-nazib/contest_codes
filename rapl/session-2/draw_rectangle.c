#define _LOCAL 1
#include <stdio.h>

int main()
{

#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int h, w;
    int a = 2;
    int b = 3;
    for (;;)
    {
        scanf("%d %d", &h, &w);
        if (h == 0 && w == 0)
            break;
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                printf("#");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}