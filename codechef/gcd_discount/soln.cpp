#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

void solve()
{
  int n;
  cin >> n;
  long p_pref_gcd[n + 2] = {0};
  long p_suff_gcd[n + 2] = {0};
  long prices[n + 2] = {0};
  long discounted_prices[n + 2] = {0};
  for (int i = 1; i <= n; i++)
  {
    cin >> prices[i];
    p_pref_gcd[i] = gcd(p_pref_gcd[i - 1], prices[i]);
  }
  for (int i = n; i >= 1; i--)
  {
    p_suff_gcd[i] = gcd(p_suff_gcd[i + 1], prices[i]);
  }
  long best = -INT_MAX;
  for (int i = 1; i <= n; i++)
  {
    cin >> discounted_prices[i];
    long calc_gcd = gcd(gcd(p_pref_gcd[i - 1], discounted_prices[i]), p_suff_gcd[i + 1]);
    if (calc_gcd > best)
    {
      best = calc_gcd;
    }
  }
  if (p_pref_gcd[n] < best)
    cout << best << "\n";
  else
    cout << p_pref_gcd[n] << "\n";
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
  while (t--)
  {
    solve();
  }
  return 0;
}