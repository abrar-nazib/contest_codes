#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

void solve();

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long test_cases, n;
    cin >> test_cases;
    for (ui i = 0; i < test_cases; i++)
    {
        unsigned long long t, sum = 0, k, max;
        unsigned int n;

        cin >> n >> k;
        vector<unsigned long long> tv(n), current(n);
        for (ui i = 0; i < n; i++)
        {
            cin >> t;

            tv[i] = t;
            sum += t;
        }
        max = *max_element(tv.begin(), tv.end());

        cout << "Case " << i + 1 << ": " << sum + max * (k - 1) << "\n";
    }

    return 0;
}

void solve()
{
}