#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
typedef long long ll;
//------- /typedefs--------

template <typename T>
bool is_even(T num)
{
  return !(num & 1);
}

void print_binary(int num)
{
  for (int i = 16; i >= 0; i--)
  {

    cout << ((num >> i) & 1);
  }
  cout << "\n";
}

void toggle_case(char &c)
{
  c = c ^ (1 << 5);
}

void clear_bits(int &num, int i)
{
  // num = (num >> i);
  // num = (num << i);
  num = num & ~((1 << (i + 1)) - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);

  // for (char i = 'A'; i < 'C'; i++)
  // {
  //   cout << i << " ";
  //   print_binary(i);
  // }
  // for (char i = 'a'; i < 'c'; i++)
  // {
  //   cout << i << " ";
  //   print_binary(i);
  // }
  // char ch = 'a';
  // cout << ch << "\n";
  // toggle_case(ch);
  // cout << ch << "\n";
  // toggle_case(ch);
  // cout << ch << "\n";
  // return 0;
  int num = 59;
  print_binary(num);
  clear_bits(num, 4);
  print_binary(num);
}