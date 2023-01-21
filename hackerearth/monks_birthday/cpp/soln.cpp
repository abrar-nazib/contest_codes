
// Problem: Monk's Birthday Party
// Link: https://www.hackerearth.com/problem/algorithm/monks-birthday-party
// Date: 20-01-2023
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

    unsigned long long test_cases, n_inputs;
    string name;
    set<string> names;
    cin >> test_cases;
    while (test_cases--)
    {
        names.clear();
        cin >> n_inputs;
        for (unsigned long long i = 0; i < n_inputs; i++)
        {
            cin >> name;
            names.insert(name);
        }
        for (auto elem : names)
        {
            cout << elem << "\n";
        }
    }

    return 0;
}