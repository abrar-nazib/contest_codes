// #define _LOCAL 1

/*
Problem: D. Distinct Split
Link: https://codeforces.com/contest/1791/problem/D
Date: 05-02-2023
Author: Nazib Abrar
*/

#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

void solve();

int main()
{
#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }

    return 0;
}

void solve()
{
    // Solution code from here
    set<char> s1, s2;
    string str;
    unsigned int n, max = 0, sum = 0;
    cin >> n;
    cin >> str;

    if (n == 2)
    {
        cout << 2 << "\n";
        return;
    }
    for (unsigned int i = 1; i < n - 1; i++)
    {
        s1.clear();
        s2.clear();
        for (unsigned int j = 0; j < n; j++)
        {
            if (j < i)
            {
                s1.insert(str[j]);
            }
            else
            {
                s2.insert(str[j]);
            }
        }
        sum = s1.size() + s2.size();
        if (sum > max)
        {
            max = sum;
        }
    }
    cout << max << "\n";
}