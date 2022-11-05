#include <stdio.h>

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, h_min, v_min, min;
    scanf("%d", &n);
    int len = (n * 2) - 1;

    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= len; j++)
        {
            v_min = i <= len - i ? i - 1 : len - i;
            h_min = j <= len - j ? j - 1 : len - j;
            min = v_min <= h_min ? v_min : h_min;
            printf("%d ", n - min);
        }
        printf("\n");
    }
    return 0;
}