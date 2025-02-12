from typing import List


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]):
        ROWS, COLS = len(grid), len(grid[0])
        visited = set()

        def dfs(i, j):
            # Handle the base case. Handle all base case. Base case means where dfs won't run further
            if (
                i < 0
                or j < 0
                or i >= ROWS
                or j >= COLS
                or grid[i][j] == 0
                or (i, j) in visited
            ):
                return 0

            visited.add((i, j))
            return 1 + dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i, j - 1)

        max_val = 0
        for i in range(ROWS):
            for j in range(COLS):
                max_val = max(dfs(i, j), max_val)
        return max_val
