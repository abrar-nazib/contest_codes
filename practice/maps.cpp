#include <bits/stdc++.h>
using namespace std;

#define DEBUG

int main()
{
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    map<int, string> m;
    map<int, string>::iterator it;
    m[1] = "Hello";
    m[3] = "World";
    it = m.begin();
    it++;
    cout << it->first << " " << it->second;
    return 0;
}