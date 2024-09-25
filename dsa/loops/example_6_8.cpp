#include <stdio.h>

int main()
{
    int sum = 0;
    for (float n = 0; n <= 5; n += (2 / 3.0))
    {
        printf("%lf\n", n);
    }
    return 0;
}