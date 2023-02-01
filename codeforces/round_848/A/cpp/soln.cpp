// #define _LOCAL 1

// Problem: A. Flip Flop Sum
// Link: https://codeforces.com/contest/1778/problem/0
// Date: 01-02-2023
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

    unsigned int t, n;
    long long prev = 0, now = 0, sum;
    int adj = 0, case_found = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        sum = 0;
        now = 0;
        prev = 0;
        adj = 0;
        case_found = 0;

        while (n--)
        {
            prev = now;
            cin >> now;

            if (now == -1 && prev == -1)
            {
                adj = 4;
                case_found = 2;
            }
            if ((now == 1 && prev == -1) || (now == -1 && prev == 1))
            {
                if (case_found <= 1)
                {
                    case_found = 1;
                    adj = 0;
                }
            }
            if (now == 1 && prev == 1)
            {
                if (!case_found)
                {
                    adj = -4;
                    case_found = -1;
                }
            }

            sum += now;
        }
        sum += adj;
        cout << sum << "\n";
    }

    return 0;
}