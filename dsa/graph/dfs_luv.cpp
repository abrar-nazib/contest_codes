#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector<int> g[N];
bool visited[N];

void dfs(int vertex)
{
  // if(visited[vertex]) return;  // If already visited, return
  cout << vertex << endl;
  visited[vertex] = true;
  for (int child : g[vertex])
  {
    cout << "parent: " << vertex << " child: " << child << endl;
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

  for (int i = 0; i < 9; i++)
  {
    int u, v;
    cin >> u >> v;

    // Dual sided graph
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);

  return 0;
}