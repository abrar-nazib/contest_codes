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

int main()
{
    char str[100];
    scanf("%s", str);
    int len = strlenX(str);
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (str[i] > str[j])
                swap_elems(str, i, j);
        }
    }
    printf("%s", str);
    return 0;
}
