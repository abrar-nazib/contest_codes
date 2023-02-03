// #define _LOCAL 1

// Problem: C. Prepend and Append
// Link: https://codeforces.com/contest/1791/problem/C
// Date: 03-02-2023
// Author: Nazib Abrar

#include <bits/stdc++.h>
using namespace std;

int check_size(string str)
{
    if ((str[0] == '0' && str[str.length() - 1] == '1') || (str[0] == '1' && str[str.length() - 1] == '0'))
    {
        str[str.length() - 1] = '\0';
        return check_size(&str[1]);
    }
    else
    {
        return str.length();
    }
}

int main()
{
#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned int t, n;
    string str;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cin >> str;
        if (n == 1)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << check_size(str) << endl;
        }
    }

    return 0;
}