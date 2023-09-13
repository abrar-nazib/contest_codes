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

  int n, m;
  cin >> n >> m;
  // int arr[n] = {0};
  vector<long> arr(n + 1, 0);
  vector<long> pref_arr(n + 1, 0);
  while (m--)
  {
    long a, b, k;
    cin >> a >> b >> k;
    arr[a] += k;
    arr[b + 1] -= k;
  }
  // Prepare the array
  for (int i = 1; i <= n; i++)
  {
    arr[i] += arr[i - 1];
  }
  long highest = -INT_MAX;
  for (int i = 1; i <= n; i++)
  {
    if (arr[i] > highest)
      highest = arr[i];
  }
  cout << highest;

  return 0;
}