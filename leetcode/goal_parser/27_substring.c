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

void swap_elems(char str[], int i, int j)
{
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

int strcmpX(char str1[], int str1i, int str1e, int str2)
{
    return 0;
}

int main()
{
    char str1[100], str2[100];
    scanf("%s", str1);
    scanf("%s", str2);
    int len1 = strlenX(str1);
    int len2 = strlenX(str2);
    for (int i = 0; i < len1; i++)
    {
        if (str1[i] == str2[0])
        {
            for (int j = 0; j < len2; j++)
            {
                if (str1[i + j] != str2[j])
                    goto xLabel;
            }
            printf("yes");
            return 0;
        xLabel:
        }
    }
    printf("no");
    return 0;
}
