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
        int n, m, k, max_freq = -INT_MAX;
        cin >> n >> m >> k;
        vector<int> ribbon;
        vector<int> color_freq(m + 1, 0);
        for (int i = 0, j = 1; i < n; i++, j++)
        {
            if (j > m)
                j = 1;
            ribbon.push_back(j);
            color_freq[j] += 1;
            if (color_freq[j] > max_freq)
            {
                max_freq = color_freq[j];
            }
        }
        if (n - max_freq > k)
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