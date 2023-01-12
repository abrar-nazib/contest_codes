#define _LOCAL 1
#include <stdio.h>

int main()
{

#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int H, W;
    while (1)
    {
        scanf("%d %d", &H, &W);
        if (H == 0 && W == 0)
            break;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if ((i + j) % 2 == 0)
                    printf("#");
                else
                    printf(".");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
    return 0;
}