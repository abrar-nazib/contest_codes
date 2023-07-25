//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // Function to detect cycle in an undirected graph.

  bool dfs(int vertex, int parent, vector<int> adj[], bool visited[])
  {

    visited[vertex] = true;
    bool loopExists = false;
    for (int child : adj[vertex])
    {
      if (visited[child] && child == parent)
        continue;
      if (visited[child])
        return true;

      loopExists |= dfs(child, vertex, adj, visited);
    }
    return loopExists;
  }
  // Function to detect cycle in an undirected graph.
  bool isCycle(int V, vector<int> adj[])
  {
    bool visited[V + 10];
    for (unsigned int i = 0; i <= V; i++)
    {
      visited[i] = 0;
    }
    for (unsigned int i = 0; i < V; i++)
    {
      if (visited[i])
        continue;
      if (dfs(i, -1, adj, visited))
        return true;
    }
    return false;
  }
};

//{ Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int tc;
  cin >> tc;
  while (tc--)
  {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    Solution obj;
    bool ans = obj.isCycle(V, adj);
    if (ans)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}
// } Driver Code Ends