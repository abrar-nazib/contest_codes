#define _LOCAL 1

// Problem: Sherlock and his AMMO quest
// Link: https://www.hackerearth.com/problem/algorithm/stl/
// Date: 03-02-2023
// Author: Nazib Abrar

#include <bits/stdc++.h>
using namespace std;

bool compare_pair(pair<string, int> e1, pair<string, int> e2)
{
    if (e1.second == e2.second)
    {
        return e1.first < e2.first;
    }
    return e1.second > e2.second;
}

int main()
{
#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned int n;
    vector<pair<string, int>> jealousy_array;
    string name;
    int j_coeff;
    cin >> n;
    while (n--)
    {
        cin >> name >> j_coeff;
        jealousy_array.push_back({name, j_coeff});
    }
    sort(jealousy_array.begin(), jealousy_array.end(), compare_pair);
    for (auto elem : jealousy_array)
    {
        cout << elem.first << " " << elem.second << "\n";
    }

    return 0;
}