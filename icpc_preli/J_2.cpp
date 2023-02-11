#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (int j = 0; j < n; j++)
            cin >> v[j];
        ll ans = v[0], carry = 0;
        for (int j = 1; j < n; j++)
        {
            if (v[j] > v[j - 1])
            {
                ans += (v[j] - v[j - 1] - carry);
            }
            else
            {
                carry = v[j - 1] - v[j];
            }
        }
        ll sum = 0;
        for (int j = 0; j < n; j++)
            sum += v[j];
        sum += ((k - 1) * ans);
        cout << "Case " << i << ": " << sum << endl;
    }
}