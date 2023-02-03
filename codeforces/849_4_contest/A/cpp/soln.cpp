// #define _LOCAL 1

// Problem: A. Codeforces Checking
// Link: https://codeforces.com/contest/1791/problem/0
// Date: 03-02-2023
// Author: Nazib Abrar

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

    set<char> cf = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};
    unsigned int t;
    char ch;
    cin >> t;

    while (t--)
    {
        cin >> ch;
        if (cf.find(ch) != cf.end())
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