/* GIven array a of N integers, Given Q queries, and in each query, given L and R. Print sum of array elements from index L to R. L and R included*/

/*
Constraints:
1 <= N <= 10^5
1 <= a[i] <= 10^9
1 <= Q <= 10^5
1 <= L, R <= N
*/

#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

const int N = 1e5 + 10;
int a[N];
int pf_sum[N];

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
    cin >> a[i];
    pf_sum[i] = pf_sum[i - 1] + a[i];
  }
  int q;
  cin >> q;
  while (q--)
  {
    int l, r;
    cin >> l >> r;

    cout << pf_sum[r] - pf_sum[l - 1] << "\n";
  }

  return 0;
}