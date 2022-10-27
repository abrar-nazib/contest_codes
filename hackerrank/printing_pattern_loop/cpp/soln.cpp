// Problem: Printing Patterns using loop
// Date: 27-10-22
// Link: https://www.hackerrank.com/challenges/printing-pattern-2/problem
// Author: Nazib Abrar

#include <bits/stdc++.h>
using namespace std;

#define _DEBUG 1

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int range = (2 * n) - 1;
    for (int i = 0; i < range; i++)
    {
        for (int j = 0; j < range; j++)
        {
            if (j >= i && j < range - i)
                cout << abs(n - i) << " ";
            else if (j >= (range - i) - 1 && j <= i)
                cout << abs(n - i) + 2 << " ";
            else
                cout << n << " ";
        }
        cout << "\n";
    }

    return 0;
}