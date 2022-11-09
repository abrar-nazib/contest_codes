
// Problem: hackerrank
// Link: https://www.hackerrank.com/challenges/c-tutorial-strings/problem
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

    string str1, str2;
    char temp;
    cin >> str1 >> str2;
    cout << str1.size() << " " << str2.size() << "\n";
    cout << str1 + str2 << "\n";
    temp = str1[0];
    str1[0] = str2[0];
    str2[0] = temp;
    cout << str1 << " " << str2 << endl;
    return 0;
}