#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, bool &atlantic, bool &pacific)
{
  visited[i][j] = true;

  int cols = grid[0].size();
  int rows = grid.size();

  // check if the water can flow to atlantic
  if (i == rows - 1 or j == cols - 1)
  {
    atlantic = true;
  }
  // Check if the water can flow to pacific
  if (i == 0 or j == 0)
  {
    pacific = true;
  }

  vector<vector<int>> diff({{i - 1, j},
                            {i + 1, j},
                            {i, j + 1},
                            {i, j - 1}});
  for (auto elem : diff)
  {
    int row = elem[0];
    int col = elem[1];
    if (row >= 0 and row < rows and col >= 0 and col < cols)
    {
      if (grid[row][col] <= grid[i][j] and !visited[row][col])
      {
        dfs(row, col, grid, visited, atlantic, pacific);
      }
    }
  }
}

class Solution
{
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
  {
    vector<vector<int>> output;
    for (int i = 0; i < heights.size(); i++)
    {
      for (int j = 0; j < heights[0].size(); j++)
      {
        bool atlantic = 0;
        bool pacific = 0;
        vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), 0));
        dfs(i, j, heights, visited, atlantic, pacific);
        if (atlantic && pacific)
        {
          output.push_back({i, j});
        }
      }
    }
    return output;
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
  cout << "Output:\n";
  vector<vector<int>> heights({{1, 2, 2, 3, 5},
                               {3, 2, 3, 4, 4},
                               {2, 4, 5, 3, 1},
                               {6, 7, 1, 4, 5},
                               {5, 1, 1, 2, 4}});
  Solution soln;
  vector<vector<int>> output = soln.pacificAtlantic(heights);
  for (int i = 0; i < output.size(); i++)
  {
    for (int j = 0; j < output[0].size(); j++)
    {
      cout << output[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}