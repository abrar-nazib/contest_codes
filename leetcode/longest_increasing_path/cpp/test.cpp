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

  vector<vector<int>> vec({
      {0, 1, 1},
      {5, 2, 3},
      {4, 5, 3},
  });
  sort(vec.begin(), vec.end());
  for (auto elem : vec)
  {
    for (auto x : elem)
    {
      cout << x << " ";
    }
    cout << "\n";
  }

  return 0;
}