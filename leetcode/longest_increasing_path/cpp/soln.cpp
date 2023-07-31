#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

void dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<bool>> &visited, int &count)
{
  visited[i][j] = true;
  count++;
  // cout << i << " " << j << " = " << matrix[i][j] << "\n";
  int rows = matrix.size(), cols = matrix[0].size();
  vector<vector<int>> diff({{i + 1, j},
                            {i - 1, j},
                            {i, j + 1},
                            {i, j - 1}});

  vector<vector<int>> visitable;
  for (auto elem : diff)
  {
    int row = elem[0];
    int col = elem[1];
    if (row >= 0 and row < rows and col >= 0 and col < cols)
    {
      if (!visited[row][col] and matrix[row][col] > matrix[i][j])
      {
        visitable.push_back({matrix[row][col], row, col});
      }
    }
  }
  if (visitable.size() != 0)
  {
    sort(visitable.begin(), visitable.end());
    dfs(visitable[0][1], visitable[0][2], matrix, visited, count);
  }
}

class Solution
{
public:
  int longestIncreasingPath(vector<vector<int>> &matrix)
  {
    int max = -INT_MAX;

    for (int i = 0; i < matrix.size(); i++)
    {
      for (int j = 0; j < matrix[0].size(); j++)
      {
        int count = 0;
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), 0));

        dfs(i, j, matrix, visited, count);
        if (count > max)
        {
          max = count;
        }
        // cout << "Count: " << count << "\n\n";
      }
    }
    return max;
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

  vector<vector<int>> matrix({{9, 9, 4}, {6, 6, 8}, {2, 1, 1}});
  Solution soln;
  cout << soln.longestIncreasingPath(matrix);

  return 0;
}