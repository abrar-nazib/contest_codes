
// Problem: The Monk and Class Marks
// Link: https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks
// Date: 21-01-2023
// Author: Nazib Abrar

#define _LOCAL 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long test_cases, n_inputs, number;
    set<string> names;
    string name;
    multimap<unsigned long long, set<string>, greater<unsigned long long>> result;
    cin >> test_cases;
    while (test_cases--)
    {
        cin >> name >> number;
        if (result.find(number) != result.end())
        {
            auto it = result.find(number);
            if ((*it).second.find(name) != (*it).second.end())
                result.insert({number, names});
            else
                (*it).second.insert(name);
        }
        else
        {
            names.clear();
            names.insert(name);
            result.insert({number, names});
        }
    }
    for (auto elem : result)
    {
        for (auto elem2 : elem.second)
        {
            cout << elem2 << " " << elem.first << "\n";
        }
    }

    return 0;
}