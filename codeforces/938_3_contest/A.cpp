#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        if (2 * a > b)
        {
            if (n % 2 == 0)
            {
                cout << (n / 2) * b << "\n";
            }
            else
            {
                cout << (n / 2) * b + a << "\n";
            }
        }
        else
        {
            cout << n * a << "\n";
        }
    }

    return 0;
}