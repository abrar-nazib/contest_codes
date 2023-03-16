#define _LOCAL 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test_cases;
    scanf("%d", &test_cases);
    for (int i = 0; i < test_cases; i++)
    {
        int a, b, c;
        int sum;
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", a + b + c);
    }
    return 0;
}