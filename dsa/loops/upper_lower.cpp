#include <stdio.h>

int main()
{
    char ch;
    scanf("%c", &ch);
    if (ch > 65 && ch < 90)
    {
        // Uppercase
        printf("%c", ch + 32);
    }
    else
    {
        printf("%c", ch - 32);
    }
    return 0;
}