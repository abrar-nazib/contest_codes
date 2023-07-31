from typing import List

class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
      ROWS, COLS = len(matrix), len(matrix[0])
      dp = {}
      
      def dfs(r, c, prevVal):
        # First base case: check for valid row-col and if the present element is less than from where it's coming
        if(r < 0 or r==ROWS or c < 0 or c == COLS or matrix[r][c] <= prevVal):
          return 0
        # Check whether LIP is already measured at this position. If measured, return the measured value
        if(r, c) in dp:
          return dp[(r, c)]
        
        # Set the minimum value
        res = 1
        res = max(res, 1 + (dfs(r+1, c, matrix[r][c])))
        res = max(res, 1 + (dfs(r-1, c, matrix[r][c])))
        res = max(res, 1 + (dfs(r, c+1, matrix[r][c])))
        res = max(res, 1 + (dfs(r, c-1, matrix[r][c])))
        
        dp[(r, c)] = res
        return res

      for r in range(ROWS):
        for c in range(COLS):
          dfs(r, c, -1)
      return max(dp.values())


matrix = [[9,9,4],[6,6,8],[2,1,1]]
soln = Solution()
print(soln.longestIncreasingPath(matrix))