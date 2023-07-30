#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, vector<vector<pair<bool, bool>>> &reachable, bool which)
{
  visited[i][j] = true;
  if (which)
  {
    reachable[i][j].second = true;
  }
  else
  {
    reachable[i][j].first = true;
  }
  int cols = grid[0].size();
  int rows = grid.size();

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
      if (grid[row][col] >= grid[i][j] and !visited[row][col])
      {
        dfs(row, col, grid, visited, reachable, which);
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
    vector<vector<pair<bool, bool>>> reachable(heights.size(), vector<pair<bool, bool>>(heights[0].size(), {false, false}));
    // Trverse for pacific
    for (int j = 0; j < heights[0].size(); j++)
    {
      vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), 0));
      dfs(0, j, heights, visited, reachable, true);
    }
    for (int i = 0; i < heights.size(); i++)
    {
      vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), 0));
      dfs(i, 0, heights, visited, reachable, true);
    }
    for (int j = 0; j < heights[0].size(); j++)
    {
      vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), 0));
      dfs(heights.size() - 1, j, heights, visited, reachable, false);
    }
    for (int i = 0; i < heights.size(); i++)
    {
      vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), 0));
      dfs(i, heights[0].size() - 1, heights, visited, reachable, false);
    }

    for (int i = 0; i < heights.size(); i++)
    {
      for (int j = 0; j < heights[0].size(); j++)
      {
        if (reachable[i][j].first == true && reachable[i][j].second == true)
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