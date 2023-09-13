#include <iostream>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n - 2; i++)
  {
    if (s[i] == '1')
    {
      for (int j = i + 1; j < n; j++)
      {
        s[j] = '0';
      }
      break;
    }
  }
  cout << s << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}