#include <bits/stdc++.h>
using namespace std;

/*
given an array a of n integers, all integers are present in event count except one. Find that one integer that has odd count in O(N) time complexity. and O(1) space complexity

*/

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

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);

  // Xor all the elements. Even count xors become zero. Then 0^x becomes x

  int t;
  cin >> t;
  int x, xx = 0;
  while (t--)
  {
    cin >> x;
    xx ^= x;
  }
  cout << xx << "\n";

  return 0;
}