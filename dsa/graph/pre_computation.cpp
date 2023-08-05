#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

/**
 * Given Q Queries, Q <= 10^5,
 * In each query, given V,
 * Print subtree sum of V, Number of even numbers in subtree of V
 *
 */

const int N = 1e5 + 10;

vector<int> g[N];

void subtree_sum(int vertex, int parent, vector<int> &pre_computed_sum)
{
  pre_computed_sum[vertex] = vertex;
  for (int child : g[vertex])
  {
    if (child == parent)
      continue;
    subtree_sum(child, vertex, pre_computed_sum);
    pre_computed_sum[vertex] += pre_computed_sum[child];
  }
}

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
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> pre_computed_sum(n + 1, 0);
  // int q;
  // while (q--)
  // {
  //   int v;
  //   cin >> v;
  // }

  subtree_sum(1, 0, pre_computed_sum);
  for (int i = 1; i < n + 1; i++)
  {
    cout << i << " " << pre_computed_sum[i] << "\n";
  }

  return 0;
}