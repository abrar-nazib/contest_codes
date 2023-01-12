#include <stdio.h>

#define _DEBUG 1

int main()
{

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int inp = 1;
    for (int i = 0;; i++)
    {
        scanf("%d", &inp);
        if (inp == 0)
            break;
        printf("Case %d: %d\n", i + 1, inp); // newline case
    }
    return 0;
}