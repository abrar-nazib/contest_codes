#include <stdio.h>

int main()
{
    int n; // 0
    int sum = 0;
    printf("Enter a value: ");
    scanf("%d", &n);
    // Print even numbers
    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    printf("Sum is: %d", sum);
}
