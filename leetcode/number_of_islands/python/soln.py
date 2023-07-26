import collections

class Solution(object):
    def numIslands(self, grid):
      # Check for empty grid
      if not grid:
        return 0
      
      rows, columns = len(grid), len(grid[0])
      visited = set()
      islands = 0
      
      def bfs(r, c):
          q = collections.deque()
          visited.add((r, c))
          q.append((r, c))
          
          while q:
            row, col = q.popleft()
            directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

            for dr, dc in directions:
              r = row + dr
              c = col + dc
              if(r in range(rows) and
                 c in range(columns) and
                 grid[r][c] == "1" and
                 (r, c) not in visited):
                q.append((r, c))
                visited.add ((r, c))
                
      for r in range(rows):
        for c in range(columns):
          if grid[r][c] == "1" and (r, c) not in visited:
            bfs(r, c)
            islands += 1
      return islands      

grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]

soln = Solution()
soln.numIslands(grid)

