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
    char str[200];
    scanf("%[^\n]s", str);
    int len = strlenX(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
            printf("\n");
        else
            printf("%c", str[i]);
    }
    return 0;
}