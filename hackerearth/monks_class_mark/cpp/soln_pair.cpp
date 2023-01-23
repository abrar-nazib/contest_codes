
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

    unsigned long long test_cases, number;
    string name;
    multiset<pair<int, string>> result;
    cin >> test_cases;
    while (test_cases--)
    {
        cin >> name >> number;
        result.insert(make_pair(-1 * number, name));
    }
    for (auto elem : result)
    {
        cout << elem.second << " " << -1 * elem.first << "\n";
    }

    return 0;
}