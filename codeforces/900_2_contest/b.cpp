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
  unsigned int n;
  cin >> n;
  unsigned long long arr[n];
  arr[0] = 1;
  arr[1] = 3;
  cout << "1 3 ";
  for (unsigned int i = 2; i < n; i++)
  {
    arr[i] = arr[i - 1] + arr[i - 2];
    while (true)
    {
      if ((3 * arr[i]) % (arr[i - 1] + arr[i - 2]) == 0)
        arr[i] = arr[i] - 1;
      else
        break;
    }
    cout << arr[i];
    if (i != n - 1)
      cout << " ";
  }
  cout << "\n";
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