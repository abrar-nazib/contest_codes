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
    int words = 1;
    while (len--)
    {
        if (str[len] == ' ')
            words++;
    }
    printf("%d", words);
}