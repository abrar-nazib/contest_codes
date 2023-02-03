#define _LOCAL 1

// Problem: D. Distinct Split
// Link: https://codeforces.com/contest/1791/problem/D
// Date: 03-02-2023
// Author: Nazib Abrar

#include <bits/stdc++.h>
using namespace std;

int num_distinct(string str)
{

    unordered_set<char> s_chr;

    // Loop to traverse the string
    for (int i = 0; i < str.size(); i++)
    {

        s_chr.insert(str[i]);
    }

    return s_chr.size();
}

string cut_string(string str, int start, int end)
{
    str = &str[start];
    str.resize(end);
    return str.c_str();
}

int main()
{
#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned int t, n, max, sum;
    string str, str1, str2;
    cin >> t;
    while (t--)
    {
        max = 0;
        cin >> n;
        cin >> str;
        if (n <= 2)
        {
            cout << n << "\n";
        }
        else
        {

            for (int i = 1; i < n; i++)
            {
                str1 = cut_string(str, 0, i);
                str2 = cut_string(str, i, str.length());
                // cout << str1 << " " << str2 << endl;
                sum = num_distinct(str1) + num_distinct(str2);
                if (sum > max)
                {
                    max = sum;
                }
            }
            cout << max << "\n";
        }
    }

    return 0;
}