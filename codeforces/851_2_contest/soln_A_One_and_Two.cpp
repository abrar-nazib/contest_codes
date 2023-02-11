/*
Problem: A. One and Two
Link: https://codeforces.com/contest/1788/problem/0
Date: 09-02-2023
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
#ifndef ONLINE_JUDGE
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
    long long n, inp, sum1 = 0, sum2 = 0;
    cin >> n;
    vector<long long> prefix(n - 1), suffix(n - 1), inp_arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        if (inp == 2)
            sum1 += 1;
    }
    sum2 = 0;
    for (int i = n - 1; i > 0; i--)
    {
        sum1 += inp_arr[i];
        suffix[i - 1] = sum1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (prefix[i] == suffix[i])
        {
            // cout << prefix[i] << " " << suffix[i] << "\n";
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}
