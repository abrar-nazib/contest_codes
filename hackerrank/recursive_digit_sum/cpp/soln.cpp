
// Problem: hackerrank
// Link: https://www.hackerrank.com/challenges/recursive-digit-sum/problem
// Date: 10-01-2023
// Author: Nazib Abrar

#include <bits/stdc++.h>
using namespace std;

#define _DEBUG 1

unsigned long long digit_sum(string n)
{
    if (n == "")
        return 0;
    unsigned long long num = n[n.size() - 1] - '0';
    n.pop_back();
    return num + digit_sum(n);
}

string int_to_str(unsigned long long n)
{
    stringstream strstream;
    string str;
    strstream << n;
    strstream >> str;
    return str;
}

int superDigit(string n, int k)
{

    unsigned long long sum = digit_sum(n) * k;
    while (sum >= 10)
    {
        n = int_to_str(sum);
        sum = digit_sum(n);
    }
    return (int)sum;
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string n;
    int k;
    cin >> n >> k;
    cout << superDigit(n, k) << endl;
    // cout << digit_sum("12") << endl;
    return 0;
}