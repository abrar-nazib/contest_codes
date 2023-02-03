#define _LOCAL 1

#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

string cut_string(string str, int start, int end)
{
    str = &str[start];
    str.resize(end);
    return str;
}

int main()
{
#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    string str, str1, str2;

    str = "mairala";

    str1 = cut_string(str, 0, 3);
    str2 = cut_string(str, 3, 2);

    cout << str1 << " " << str2;

    return 0;
}