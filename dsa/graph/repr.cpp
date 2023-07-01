#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    // N: Number of vertices, M: Number of edges
    ui N, M;
    cin >> N >> M;

    // Adjacency list
    vector<int> adj[N]; // List of vectors

    // vector<pair<int, int>> adj[N]; // For handling weighted graphs

    // Input edges
    for (ui i = 0; i < M; ++i)
    {
        ui u, v;
        // ui u, v, wt; // For handling weighted graphs
        cin >> u >> v;
        // cin >> u >> v >> wt; // For handling weighted graphs
        adj[u].push_back(v);
        adj[v].push_back(u);
        // adj[u].push_back({v, wt}); // For handling weighted graphs
        // adj[v].push_back({u, wt}); // For handling weighted graphs
    }

    return 0;
}