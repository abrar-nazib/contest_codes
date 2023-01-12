#define _LOCAL 1
#include <stdio.h>

int main()
{

#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int h, w;
    while (1)
    {
        scanf("%d %d", &h, &w);
        if (h == 0 && w == 0)
            break;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                printf("#");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}