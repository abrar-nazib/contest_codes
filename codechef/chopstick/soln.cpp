#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

void solve()
{
  int n, x, d;
  cin >> n >> d;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    a[i] = x;
  }

  sort(a, a + n);
  int c = 0;
  for (int i = 1; i < n; i++)
  {
    if (abs(a[i - 1] - a[i]) <= d)
    {
      c++;
      i++;
    }
  }
  cout << c << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);

  // ui t;
  // cin >> t;
  // while (t--)
  // {
  solve();
  // }
  return 0;
}