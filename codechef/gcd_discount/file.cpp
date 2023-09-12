#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

int determine_gcd(vector<int> numbers)
{
  int result = numbers[0];
  for (size_t i = 1; i < numbers.size(); ++i)
  {
    result = std::gcd(result, numbers[i]);
  }
}

void solve()
{
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