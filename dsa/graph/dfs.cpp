#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

void dfs(vector<int> adj[], vector<bool> &visited, int u)
{
    // Take action on vertex after entering the vertex
    visited[u] = true;
    cout << u << " ";
    for (auto v : adj[u])
    {
        if (!visited[v]) // Take action on child before entering the child node
            dfs(adj, visited, v);
        // take action on child after entering the child node
    }
    // take action on vertex before exiting the vertex
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    ui N, M;
    cin >> N >> M;

    vector<int> adj[N + 1]; // List of vectors
    // Input the graph
    for (ui i = 0; i < M; ++i)
    {
        ui u, v;
        cin >> u >> v;

        // Done twice because this is undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Traverse the graph
    vector<bool> visited(N + 1, false); // Initially all vertices are unvisited'
    dfs(adj, visited, 1);
    return 0;
}