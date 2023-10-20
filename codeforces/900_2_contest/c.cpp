#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long llu;
//------- /typedefs--------

//-------- functions -------
template <typename T>
bool is_even(T num)
{
  return !(num & 1);
}
//------- /functions--------

void solve()
{
  unsigned int n, k, x;
  cin >> n >> k >> x;
  unsigned long long prefix_sum = 0, suffix_sum = 0;
  for (int i = 1; i <= n; i++)
  {
    if (i <= k)
    {
      prefix_sum += i;
    }
    if (i >= (n - k + 1))
    {
      suffix_sum += i;
    }
    if (x >= prefix_sum || x <= suffix_sum)
    {

      cout << x << " " << prefix_sum << " " << suffix_sum << " "
           << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }
  // Solution
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);

  long long T;
  cin >> T;
  while (T--)
  {
    solve();
  }

  return 0;
}