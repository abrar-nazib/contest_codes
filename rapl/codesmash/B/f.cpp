#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

map<long long, int> update_map_insert(map<long long, int> sc_map, long long data)
{
    if (sc_map.find(data) != sc_map.end())
    {
        sc_map[data] += 1;
    }
    else
    {
        // sc_map[data] = 1;
        sc_map.insert({data, 1});
    }
    return sc_map;
}

map<long long, int> update_map_remove(map<long long, int> sc_map, long long data)
{

    sc_map[data] -= 1;
    if (sc_map[data] == 0)
    {
        sc_map.erase(data);
    }
    return sc_map;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    ui test_cases;
    long long m, n, idx, val, data;
    cin >> test_cases;
    while (test_cases--)
    {

        cin >> m >> n;
        map<long long, int> sc_map;
        vector<long long> scores(m);
        for (ui i = 0; i < m; i++)
        {
            cin >> data;
            scores[i] = data;
            sc_map = update_map_insert(sc_map, data);
        }
        for (ui i = 0; i < n; i++)
        {
            cin >> idx >> val;

            sc_map = update_map_insert(sc_map, scores[idx - 1] + val);
            sc_map = update_map_remove(sc_map, scores[idx - 1]);
            scores[idx - 1] += val;
            cout << sc_map.size() << "\n";
        }
    }

    return 0;
}