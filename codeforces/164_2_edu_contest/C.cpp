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
        string x, y;
        cin >> x >> y;
        bool flag = 0;
        for (int i = 0; i < x.length(); i++)
        {
            if (flag)
            {
                if (x[i] > y[i])
                    swap(x[i], y[i]);
            }
            else
            {
                if (x[i] < y[i])
                {
                    swap(x[i], y[i]);
                    flag = 1;
                }
                if (x[i] > y[i])
                {
                    flag = 1;
                }
            }
        }
        cout << x << "\n"
             << y << "\n";
    }

    return 0;
}