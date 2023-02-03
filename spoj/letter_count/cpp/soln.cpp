#define _LOCAL 1

// Problem: spoj
// Link: https://www.spoj.com/problems/MAY99_E1/
// Date: 03-02-2023
// Author: Nazib Abrar

#include <bits/stdc++.h>
using namespace std;

bool compare_vect(pair<char, int> e1, pair<char, int> e2)
{
    if (e1.second == e2.second)
        return e1.first < e2.first;
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
    string str;
    cin >> str;
    vector<pair<char, int>> freq_vect;
    unordered_map<char, int> index_map; // for storing the indexes of the vectors
    for (int i = 0; i < str.length(); i++)
    {
        if (index_map.find(str[i]) == index_map.end())
        {
            freq_vect.push_back({str[i], 1});
            index_map[str[i]] = freq_vect.size() - 1;
        }
        else
        {
            freq_vect[index_map[str[i]]].second += 1;
        }
    }
    // sort(freq_map.begin(), freq_map.end());
    sort(freq_vect.begin(), freq_vect.end(), compare_vect);
    // for (auto elem : freq_vect)
    // {
    //     cout << elem.first << " " << elem.second << "\n";
    // }
    cout << freq_vect[0].first;
    return 0;
}