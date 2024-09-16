#include <stdio.h>

int main()
{
    int n; // 0
    int even_sum = 0, odd_sum = 0;

    printf("Enter a value: ");
    scanf("%d", &n);
    // Print even numbers
    for (int i = 0; i <= n; i++)
    {
        if (i % 2 == 0) // 0 for even
        {
            even_sum = even_sum + i;
        }
        else
        {
            odd_sum = odd_sum + i;
        }
    }
    printf("Even sum: %d, Odd sum: %d", even_sum, odd_sum);
}
