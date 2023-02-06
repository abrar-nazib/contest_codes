/*
Problem: A1. Non-alternating Deck (easy version)
Link: https://codeforces.com/contest/1786/problem/A1
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
    int n;
    int current = 1;
    int alice = 0, bob = 0;
    cin >> n;
    bool flag = 1;
    while (n)
    {
        if (flag == true)
        {
            if (n - current > 0)
            {
                alice += current;
            }
            else
            {
                alice += n;
                break;
            }
            n -= current++;
            // current++;

            if (n - current > 0)
            {
                bob += current;
            }
            else
            {
                bob += n;
                break;
            }
            n -= current++;
            // current++;

            flag = false;
        }
        else
        {
            if (n - current > 0)
            {
                bob += current;
            }
            else
            {
                bob += n;
                break;
            }
            n -= current++;
            // current++;

            if (n - current > 0)
            {
                alice += current;
            }
            else
            {
                alice += n;
                break;
            }
            n -= current++;
            // current++;

            flag = true;
        }
        if (n < 0)
            n = 0;
    }
    cout << alice << " " << bob << "\n";
}