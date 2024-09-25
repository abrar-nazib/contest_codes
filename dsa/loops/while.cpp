#include <stdio.h>

int main()
{
    int m = 100;
    int n = 0;

    while (n == 0)
    {
        m = m - 10;
        if (m < 10)
            break;
        printf("%d\n", m);
    }
    return 0;
}