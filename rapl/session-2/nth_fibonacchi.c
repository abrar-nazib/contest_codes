#define _LOCAL 1
#include <stdio.h>

int main()
{

#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    unsigned long long n;
    scanf("%llu", &n);
    unsigned long long a = 0, b = 1, c;

    for (int i = 1; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    printf("%llu\n", c);
    return 0;
}