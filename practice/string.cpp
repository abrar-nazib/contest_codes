#include <bits/stdc++.h>
using namespace std;

#define DEBUG

int main()
{
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    string rev_str;
    cin >> str;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        rev_str.push_back(str[i]);
    }
    cout << rev_str;
    return 0;
}