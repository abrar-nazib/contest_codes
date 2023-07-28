#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, int &perimeter)
{
  visited[i][j] = true;
  vector<vector<int>> diff({{i - 1, j},
                            {i + 1, j},
                            {i, j - 1},
                            {i, j + 1}});
  for (auto elem : diff)
  {
    int row = elem[0];
    int col = elem[1];
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0)
    {
      perimeter++;
    }
    else
    {
      if (!visited[row][col])
        dfs(row, col, grid, visited, perimeter);
    }
  }
}

class Solution
{
public:
  int islandPerimeter(vector<vector<int>> &grid)
  {
    int perimeter = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (grid[i][j] == 1)
        {
          dfs(i, j, grid, visited, perimeter);
          return perimeter;
        }
      }
    }
    return perimeter;
  }
};

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<vector<int>> graph(
      {{1, 1}, {1, 1}});
  Solution solution;
  cout << solution.islandPerimeter(graph);

  return 0;
}