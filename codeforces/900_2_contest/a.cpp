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
  // Solution
  int n, k, in;
  bool flag = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> in;
    if (in == k)
    {
      flag = 1;
    }
  }
  if (flag)
    cout << "YES\n";
  else
    cout << "NO\n";
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