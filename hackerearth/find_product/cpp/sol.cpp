// Freakin read the question carefully
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long size = 1, n;
    long long modder = pow(10, 9) + 7;
    cin >> size;
    long long x = 1;
    while (size--)
    {
        cin >> n;
        x = (x * n) % modder;
    }
    cout << x;
    return 0;
}