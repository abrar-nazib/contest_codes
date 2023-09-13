// Given T test cases and in each test case a number N print it's factorial for each test case % M where M = 10^9 + 7

// Constraints: 1 <= T <= 10^5
// 1 <= N <= 10^5

#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

const int M = 10e5 + 7;
const int N = 10e5 + 10;
long long int fact[N];

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  fact[0] = fact[1] = 1;
  for (int i = 2; i < N; i++)
  {
    fact[i] = fact[i - 1] * i;
  }

  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    cout << fact[n] << endl;
  }

  return 0;
}