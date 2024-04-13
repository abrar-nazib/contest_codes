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
        int k, q;
        cin >> k >> q;
        vector<int> a(k);
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < q; i++)
        {
            int n;
            cin >> n;
            while (n >= *(a.end() - 1))
            {
                n -= k;
            }
            while (n >= a[0])
            {
                for (int i = 0; i < k; i++)
                {
                    if (a[i] > n)
                    {
                        n -= i;
                        break;
                    }
                }
            }
            cout << n << " ";
        }
        cout << "\n";
    }

    return 0;
}