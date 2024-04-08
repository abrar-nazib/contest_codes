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
        int n, k, sum;
        bool flag = 0;
        vector<int> a;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            int ai;
            cin >> ai;
            a.push_back(ai);
        }

        long long l = 0, r = n - 1;
        int k_init = k;
        while (k > 0 and l < r)
        {
            int min_elem = min(a[l], a[r]);
            if (r != l && k >= 2 * min_elem)
            {
                a[l] -= min_elem;
                a[r] -= min_elem;
                k -= 2 * min_elem;
            }

            else
            {
                if (k % 2 == 0)
                    a[l] -= 1;
                else
                    a[r] -= 1;
                k -= 1;
            }
            if (a[l] == 0)
                l += 1;
            if (a[r] == 0)
                r -= 1;
        }
        if (k <= 0)
            cout << n - (r - l + 1) << "\n";
        else
            cout << n - (r - l) << "\n";
    }

    return 0;
}