#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

const int N = 1e5 + 10;

vector<int> g[N];
int depth[N];
int height[N];

void dfs(int vertex, int parent = 0)
{
  for (int child : g[vertex])
  {
    if (child == parent)
      continue;
    depth[child] = depth[vertex] + 1; // Update the depth of child before entering
    dfs(child, vertex);
    height[vertex] = max(height[child] + 1, height[vertex]);
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
  for (int i = 0; i <= n; i++)
  {
    cout << depth[i] << " " << height[i];
    cout << "\n";
  }

  return 0;
}