// #define _LOCAL 1

// Problem: B. Following Directions
// Link: https://codeforces.com/contest/1791/problem/B
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

    unsigned int t, n;
    int x = 0, y = 0;
    string str;
    char c;
    bool flag;
    cin >> t;
    while (t--)
    {
        flag = 0;
        x = 0;
        y = 0;
        cin >> n;
        cin >> str;
        for (int i = 0; i < n; i++)
        {
            c = str[i];
            // while (n--)
            // {
            //     // c = getchar();
            if (c == 'U')
                y++;

            if (c == 'D')
                y--;

            if (c == 'R')
                x++;

            if (c == 'L')
                x--;

            if (x == 1 && y == 1)
            {
                cout << "YES\n";
                flag = 1;
                break;
            }
        }
        if (flag != 1)
        {
            cout << "NO\n";
        }
    }

    return 0;
}