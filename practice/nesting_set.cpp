#include <bits/stdc++.h>
using namespace std;

#define _DEBUG 1

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    map<pair<int, int>, int> m;
    pair<int, int> p1, p2;
    p1 = {2, 4};
    p2 = {2, 5};
    cout << (p1 > p2) << endl;
    return 0;
}