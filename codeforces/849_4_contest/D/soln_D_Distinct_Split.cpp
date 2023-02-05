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
    set<char> char_set;
    unsigned int n;
    string str;
    unsigned int max = 0, sum = 0;
    cin >> n;
    cin >> str;
    vector<unsigned int> prefix_arr(n - 1), suffix_arr(n - 1);

    // for prefix
    char_set.clear();
    for (unsigned int i = 0; i < n - 1; i++)
    {
        char_set.insert(str[i]);
        prefix_arr[i] = char_set.size();
    }

    // calculation for suffixes
    char_set.clear();
    for (unsigned int i = n - 1; i > 0; i--)
    {
        char_set.insert(str[i]);
        suffix_arr[i - 1] = char_set.size();
    }

    for (unsigned int i = 0; i < n - 1; i++)
    {
        sum = prefix_arr[i] + suffix_arr[i];
        // cout << prefix_arr[i] << " + " << suffix_arr[i] << "\n";
        if (sum > max)
            max = sum;
    }
    cout << max << "\n";
}