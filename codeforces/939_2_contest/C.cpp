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
        int n;
        cin >> n;
        vector<int> freq(n + 1, 0);
        int freq_count = 0;
        for (int i = 0; i < n; i++)
        {
            int card;
            cin >> card;
            freq[card] += 1;
            if (freq[card] > 1)
            {
                freq_count += 1;
            }
        }
        cout << freq_count << "\n";
    }

    return 0;
}