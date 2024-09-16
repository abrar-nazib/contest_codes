#include <stdio.h>

int main()
{
    int count = 0; // 0

    for (int i = 101; i < 450; i++)
    {
        if (i % 10 == 0)
        {
            count = count + 1;
            // printf("[%d %d]", i, count);
        }
    }
    printf("%d", count);
}