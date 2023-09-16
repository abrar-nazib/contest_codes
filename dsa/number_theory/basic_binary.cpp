#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

void print_binary(int num)
{
  for (int i = 16; i >= 0; i--)
  {

    cout << ((num >> i) & 1);
  }
  cout << "\n";
}

bool check_set_bit(int num, int n)
{
  int check_num = 1 << n;
  bool check = num & check_num;
  cout << (int)(num & check_num) << "\n";
  return check;
}

void set_bit(int &num, int n)
{
  int setter_num = 1 << n;
  num |= setter_num;
}

void unset_bit(int &num, int n)
{
  int setter_num = 1 << n;
  // print_binary(setter_num);
  setter_num = ~setter_num; // Not Operation
  num &= setter_num;
}

void toggle_bit(int &num, int n)
{
  int converter = 1 << n;
  num ^= converter; // ^ is the xor operator
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n = 0b00000101;
  // cout << check_set_bit(n, 2);
  // unset_bit(n, 2);
  // print_binary(n);
  // toggle_bit(n, 2);
  // print_binary(n);
  // toggle_bit(n, 2);
  // print_binary(n);
  cout << __builtin_popcount(3);
  return 0;
}