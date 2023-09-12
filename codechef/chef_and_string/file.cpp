#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

void solve()
{
  // Solution
  int c = 0;
  string s;
  cin >> s;

  for (int i = 1; i < s.size(); i++)
  {
    if (s[i - 1] != s[i])
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

  long long T;
  cin >> T;
  while (T--)
  {
    solve();
  }

  return 0;
}
