#include <bits/stdc++.h>
using namespace std;

#define DEBUG 1

int sum(int arr[], int index)
{
    if (index == 0)
    {
        return arr[0];
    }
    return arr[index] + sum(arr, index - 1);
}

int digit_sum(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + digit_sum(n / 10);
}

int main()
{
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int arr[5] = {1, 1, 2, 3, 4};
    int number;
    cin >> number;
    cout << digit_sum(number) << endl;
    return 0;
}