#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n;
    cin >> n;
    int x = 0;
    if (n % 2 != 0)
        cout << 0;
    else
    {
        if ((n / 2) % 2 == 0)
        {
            x = n / 4 - 1;
        }
        else
            x = n / 4;
        cout << x;
    }

    return 0;
}