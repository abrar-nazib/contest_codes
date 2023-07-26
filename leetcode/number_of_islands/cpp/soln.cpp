#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

class Solution
{
public:
  int numIslands(vector<vector<char>> &grid)
  {
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));

    int num_islands = 0;

    for (ui i = 0; i < grid.size(); i++)
    {
      for (ui j = 0; j < grid[0].size(); j++)
      {
        if (!visited[i][j] && grid[i][j] == '1')
        {
          dfs_matrix({i, j}, grid, visited);
          num_islands++;
        }
      }
    }
    return num_islands;
  }
};

void dfs_matrix(pair<int, int> coord, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
  int row = coord.first, col = coord.second, rows = grid.size(), cols = grid[0].size();
  visited[row][col] = true;
  vector<pair<int, int>> dcoords = {
      {-1, 0},
      {1, 0},
      {0, -1},
      {0, 1}};
  for (pair<int, int> offset : dcoords)
  {
    int r = row + offset.second;
    int c = col + offset.first;
    if ((r >= 0 && c >= 0) && (r < rows && c < cols))
    {
      if (!visited[r][c] && grid[r][c] == '1')
      {
        dfs_matrix({r, c}, grid, visited);
      }
    }
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

  vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '1', '0', '0'},
                               {'0', '0', '0', '1', '1'}};
  vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));

  int num_islands = 0;

  for (ui i = 0; i < grid.size(); i++)
  {
    for (ui j = 0; j < grid[0].size(); j++)
    {
      if (!visited[i][j] && grid[i][j] == '1')
      {
        dfs_matrix({i, j}, grid, visited);
        num_islands++;
      }
    }
  }
  cout << num_islands;
  return 0;
}