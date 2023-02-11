#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    ui n, x;
    cin >> n;
    ui arr[n];
    set<ui> s;
    for (ui i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(x);
    }
    // sort(arr, arr + n);
    // for (ui i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // cout << *lower_bound(arr, arr + n, 5) << endl;
    // cout << *upper_bound(arr, arr + n, 8) << endl;
    cout << *lower_bound(arr, arr + n, 5) << endl;
    cout << *upper_bound(arr, arr + n, 8) << endl;
    return 0;
}