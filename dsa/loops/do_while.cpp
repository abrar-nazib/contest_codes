#include <stdio.h>

int main()
{
    int p = 20;

    do
    {
        printf("Incrementing p\n");
        p = p + 1;
    } while (p == 10);

    printf("p = %d", p);
    return 0;
}
