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
    scanf("%s", str);
    int len = strlenX(str), vowel = 0, consonant = 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            vowel++;
        else
            consonant++;
    }
    printf("%d %d", vowel, consonant);
    return 0;
}
