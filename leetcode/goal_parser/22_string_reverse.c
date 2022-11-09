#include <stdio.h>

int strlenX(char str[])
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        len = i + 1;
    }
    return len;
}

int main()
{
    char str[100];
    char str2[100];
    int len;
    scanf("%[^\n]s", str);
    len = strlenX(str);
    // printf("%d", len);
    for (int i = len - 1; i >= 0; i--)
    {
        str2[len - i - 1] = str[i];
    }
    for (int i = 0; i < len; i++)
    {
        if (i == len - 1)
            printf("%c", str2[i]);
        else
            printf("%c ", str2[i]);
    }
    // printf("\0");
    return 0;
}