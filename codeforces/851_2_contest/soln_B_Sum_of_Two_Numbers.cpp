/*
Problem: B. Sum of Two Numbers
Link: https://codeforces.com/contest/1788/problem/B
Date: 09-02-2023
Author: Nazib Abrar
*/

#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

long long sum_of_digits(long long n)
{
    long long sum = 0;
    while (n)
    {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}

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
        return 0;
    }

    return 0;
}

void solve()
{
    // Solution code from here
    long long n, sum, diff;
    cin >> n;
    for (int i = n; i >= 0;)
    {
        diff = abs(sum_of_digits(i) - sum_of_digits(n - i));

        if (diff <= 1)
        {
            cout << i << " " << n - i << "\n";
            return;
        }
        i--;
    }
}