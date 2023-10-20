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
  int n, k, x;
  cin >> n >> k >> x;

  // Check if it's possible to choose k distinct integers between 1 and n
  // such that their sum is equal to x
  if (x >= k && x <= k * n && k <= n)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
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

  long long T;
  cin >> T;
  while (T--)
  {
    solve();
  }

  return 0;
}