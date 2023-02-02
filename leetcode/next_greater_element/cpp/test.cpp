#define _LOCAL 1

#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

int main()
{
#ifdef _LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<int, int> testing;
    testing.insert({1, 1});
    testing.insert({3, 5});
    // cout << testing[5] << endl;
    if (testing.find(5) == testing.end())
    {
        cout << "not present" << endl;
    }

    return 0;
}