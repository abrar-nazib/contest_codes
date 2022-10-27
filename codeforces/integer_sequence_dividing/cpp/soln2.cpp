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
    n %= 4;
    if (n == 0 || n == 3)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
    }

    return 0;
}