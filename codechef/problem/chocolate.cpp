#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

void solve()
{
  // Solution
  int n;
  cin >> n;
  if (n % 2 != 0)
  {
    cout << 1 << " ";
    cout << (n - 1) / 2 << " " << (n - 1) / 2 << "\n";
  }
  else
  {
    cout << "1 1 " << n - 2 << "\n";
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