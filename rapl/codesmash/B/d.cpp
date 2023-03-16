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
    int test_cases;
    int a, b, c;
    cin >> test_cases;
    while (test_cases--)
    {
        cin >> a >> b;
        if (360 % (2 * b) == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}