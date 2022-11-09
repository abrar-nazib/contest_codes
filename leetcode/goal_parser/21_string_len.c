#include <stdio.h>

int main()
{
    char str[100];
    int len;
    scanf("%[^\n]s", str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        len = i + 1;
    }
    printf("%d", len);
    return 0;
}