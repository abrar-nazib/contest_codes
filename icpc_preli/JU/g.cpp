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

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int len;
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        vector<pair<int, int>> matches;
        int min_pop = INT_MAX;
        cin >> len;
        for (int j = 0; j < len; j++)
        {
            int val;
            cin >> val;
            m1[val] = j;
        }
        for (int j = 0; j < len; j++)
        {
            int val;
            cin >> val;
            m2[val] = j;
        }
        for (auto &m : m1)
        {
            if (m2.find(m.first) != m2.end())
            {
                matches.push_back({m.second, m2[m.first]});
            }
        }
        cout << "len: " << matches.size() << "\n";
        for (auto &x : matches)
        {
            cout << x.first << " " << x.second << "\n";
        }
        cout << "\n\n";
    }

    return 0;
}