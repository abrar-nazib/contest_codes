from typing import List


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        visited_array = [[0 for _ in grid[0]] for elem in grid]
        current = [0]
        current_max = [0]

        def dfs(i, j):
            if grid[i][j] == 0 or visited_array[i][j] == 1:
                return
            visited_array[i][j] = 1
            current[0] += 1
            current_max[0] = max(current_max[0], current[0])
            # Go left
            if j - 1 >= 0:
                dfs(i, j - 1)
            # Go right
            if j + 1 < len(grid[0]):
                dfs(i, j + 1)
            # Go up
            if i - 1 >= 0:
                dfs(i - 1, j)
            # Go down
            if i + 1 < len(grid):
                dfs(i + 1, j)
            # visited_array[i][j] = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] != 0 and not visited_array[i][j]:
                    current[0] = 0
                    dfs(i, j)

                    # print(i, j, current_max, current)
        return current_max[0]


soln = Solution()
grid = [
    [0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
    [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
    [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
]
print(soln.maxAreaOfIsland(grid))
grid = [[0, 0, 0, 0, 0, 0, 0, 0]]
print(soln.maxAreaOfIsland(grid))
grid = [[1, 1, 0, 0, 0], [1, 1, 0, 0, 0], [0, 0, 0, 1, 1], [0, 0, 0, 1, 1]]
print(soln.maxAreaOfIsland(grid))
grid = [[0, 1], [1, 1]]
print(soln.maxAreaOfIsland(grid))
