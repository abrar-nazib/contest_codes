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
    char str1[100];
    char str2[100];
    scanf("%s", str1);
    scanf("%s", str2);
    int len1 = strlenX(str1);
    int len2 = strlenX(str2);
    if (len1 != len2)
    {
        printf("No");
        return 0;
    }
    for (int i = 0; i < len1; i++)
    {
        if (str1[i] != str2[i])
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}