#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

int check_divisibility(ui x, ui a, ui b, ui r)
{
    ui c = x / (a * b);
    if (c > r && x % (a * b * c) == 0)
    {
        return -1;
    }
    else
    {
        while ((a * b * c) < x)
    }
}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    ui t;
    cin >> t;
    ui a, b, c, l, r, x;
    while (t--)
    {
        cin >> x >> l >> r;
        a = l;
        b = a + 1;
    }

    return 0;
}