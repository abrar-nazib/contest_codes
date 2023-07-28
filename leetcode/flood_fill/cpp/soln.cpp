#include <bits/stdc++.h>
using namespace std;

//-------- typedefs -------
typedef unsigned int ui;
typedef unsigned long long llu;
//------- /typedefs--------

void dfs(int sr, int sc, int prev_color, int color, vector<vector<int>> &graph, vector<vector<bool>> &visited)
{
  int r = sr;
  int c = sc;
  visited[sr][sc] = true;
  graph[sr][sc] = color;
  vector<vector<int>> diff({{-1, 0},
                            {1, 0},
                            {0, -1},
                            {0, 1}});
  for (auto elem : diff)
  {
    int row = r + elem[0];
    int col = c + elem[1];
    if (row > -1 && row < graph.size() && col > -1 && col < graph[0].size())
    {
      if (graph[row][col] == prev_color && !visited[row][col])
      {
        dfs(row, col, prev_color, color, graph, visited);
      }
    }
  }
}

class Solution
{
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
  {
    vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), 0));
    int prev_color = image[sr][sc];
    dfs(sr, sc, prev_color, color, image, visited);
    return image;
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

  vector<vector<int>> image({{1, 1, 1}, {1, 1, 0}, {1, 0, 1}});
  Solution solution;
  solution.floodFill(image, 2, 2, 2);

  return 0;
}