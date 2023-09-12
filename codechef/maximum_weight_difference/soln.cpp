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

  ui t;
  cin >> t;

  while (t--)
  {
    int n, k, w;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> w;
      a[i] = w;
    }
    sort(a, a + n);
    if (k > n / 2)
      k = n - k;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
      if (k > 0)
      {
        k--;
        x += a[i];
      }
      else
      {
        y += a[i];
      }
    }
    cout << abs(x - y) << '\n';
  }

  return 0;
}