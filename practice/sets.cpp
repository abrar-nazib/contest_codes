#include <bits/stdc++.h>
using namespace std;

#define _DEBUG 1

void print_set(set<string> &s)
{
    for (string value : s)
    {
        cout << value << " ";
    }
    cout << endl;

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    set<string> s;
    s.insert("abc");
    s.insert("zdef");
    s.insert("ghi");

    auto it = s.find("def");

    print_set(s);
    int x = INT_MAX / 500;
    while (x--)
    {
        // nothing
    }
    return 0;
}