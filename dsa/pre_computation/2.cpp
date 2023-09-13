// Given an array A of N integers, Given Q queries, and in each query given a number X
// Print count of that number in an array.

// Constraints:
// 1 <= N <= 10^5
// 1 <= a[i] <= 10^7
// 1 <= Q <= 10^5

#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

const int N = 1e7 + 10;
int hsh[N];

int main() // Total Complexity O(N^2)
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, e;
  cin >> n;

  for (int i = 0; i < n; i++) // O(N)
  {
    cin >> e;
    hsh[e] += 1;
  }

  int T;
  cin >> T;
  while (T--) // O(T*N)
  {
    int x, ct = 0;
    cin >> x;

    cout << hsh[x] << "\n";
  }

  return 0;
}