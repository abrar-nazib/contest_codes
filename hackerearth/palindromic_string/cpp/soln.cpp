
// Problem: Palindromic String
// Link: https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/palindrome-check-2/
// Date: 05-11-2022
// Author: Nazib Abrar

#include <bits/stdc++.h>
using namespace std;

#define _DEBUG 1

int main()
{

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str, rev_str;
    cin >> str;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        rev_str.push_back(str[i]);
    }
    if (rev_str == str)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}