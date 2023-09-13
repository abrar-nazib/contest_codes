/*
Given 2D array of N*N integers, Given Q queries and each query given a, b, c and d. Print sum of square represented by (a, b) and (c, d) as top left and bottom right accordingly

Constraints:
1 <= N <= 10^3
1 <- a[i][j] <= 10^9
1 <= Q <= 10^5
1 <= a, b, c, d <= N
*/

#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

const int N = 10e3 + 10;
long long arr[N][N];
long long pf_sum[N][N];

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> arr[i][j];
      pf_sum[i][j] = arr[i][j] + pf_sum[i][j - 1] + pf_sum[i - 1][j] - pf_sum[i - 1][j - 1];
    }
  }
  int q;
  cin >> q;
  while (q--)
  {
    int a, b, c, d, sum = 0;
    cin >> a >> b >> c >> d;
    // for (int i = a; i <= c; i++)
    // {
    //   for (int j = b; j <= d; j++)
    //   {
    //     sum += arr[i][j];
    //   }
    // }
    // cout << sum << "\n";
    cout << pf_sum[c][d] - pf_sum[c][b - 1] - pf_sum[a - 1][d] + pf_sum[a - 1][b - 1] << "\n";
  }

  return 0;
}