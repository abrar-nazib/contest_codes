// #define _LOCAL 1

/*
Problem: E. Negatives and Positives
Link: https://codeforces.com/contest/1791/problem/E
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
    // test_cases = 1;  // for only test case.
    cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }

    return 0;
}

void solve()
{
    unsigned int arr_size, negative_count = 0;
    ;
    long long sum = 0, arr_elem, min = INT64_MAX;
    cin >> arr_size;
    for (unsigned int i = 0; i < arr_size; i++)
    {
        cin >> arr_elem;
        if (abs(arr_elem) < min)
        {
            min = abs(arr_elem);
        }
        if (arr_elem < 0)
        {
            negative_count++;
        }
        sum += abs(arr_elem);
    }
    if (negative_count % 2 == 0)
        cout << sum << "\n";
    else
        cout << sum - (2 * min) << "\n";
}