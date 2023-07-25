#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

const int N = 1e5 + 10;
bool visited[N];
vector<int> adj[N];
vector<vector<int>> connected_components;
vector<int> current_connected_component;
void dfs(int vertex)
{
  visited[vertex] = true;
  current_connected_component.push_back(vertex);
  for (int child : adj[vertex])
  {
    if (visited[child])
      continue;
    dfs(child);
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

  int n, m;
  cin >> n >> m;
  for (ui i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ui n_cc = 0;
  for (ui i = 1; i <= n; i++)
  {

    if (visited[i])
      continue;
    current_connected_component.clear();
    dfs(i);
    connected_components.push_back(current_connected_component);
    n_cc++;
  }

  cout << n_cc << "\n";

  // Print the nodes of current component
  for (auto current : connected_components)
  {
    for (auto elem : current)
    {
      cout << elem << " ";
    }
    cout << "\n";
  }

  return 0;
}