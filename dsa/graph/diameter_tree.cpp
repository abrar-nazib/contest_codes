#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

const int N = 1e5 + 10;
vector<int> g[N];
int depth[N];

void dfs(int vertex, int parent = -1)
{
  for (int child : g[vertex])
  {
    if (child == parent)
      continue;
    depth[child] = depth[vertex] + 1;
    dfs(child, vertex);
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
  dfs(1);
  int max_depth = -1;
  int max_depth_node;
  for (int i = 1; i <= n; i++)
  {
    if (depth[i] > max_depth)
    {
      max_depth = depth[i];
      max_depth_node = i;
    }
    depth[i] = 0;
  }
  dfs(max_depth_node);
  max_depth = -1;
  for (int i = 1; i <= n; i++)
  {
    if (depth[i] > max_depth)
    {
      max_depth = depth[i];
      max_depth_node = i;
    }
    depth[i] = 0;
  }
  cout << max_depth << " " << max_depth_node << "\n";

  return 0;
}