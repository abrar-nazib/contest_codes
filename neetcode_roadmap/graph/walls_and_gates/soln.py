from typing import List
import collections


class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        ROWS, COLS = len(grid), len(grid[0])  # There could be edge cases

        def traverse(r, c):
            q = collections.deque([(r, c, 0)])
            visited = set()
            while q:
                x, y, d = q.popleft()
                visited.add((x, y))
                grid[x][y] = min(d, grid[x][y])
                if x + 1 < ROWS and (x + 1, y) not in visited and grid[x + 1][y] != -1:
                    q.append((x + 1, y, d + 1))
                if x - 1 >= 0 and (x - 1, y) not in visited and grid[x - 1][y] != -1:
                    q.append((x - 1, y, d + 1))
                if y + 1 < COLS and (x, y + 1) not in visited and grid[x][y + 1] != -1:
                    q.append((x, y + 1, d + 1))
                if y - 1 >= 0 and (x, y - 1) not in visited and grid[x][y - 1] != -1:
                    q.append((x, y - 1, d + 1))

        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 0:
                    traverse(i, j)
                    print(i, j)
        return grid


soln = Solution()

grid = [
    [2147483647, -1, 0, 2147483647],
    [2147483647, 2147483647, 2147483647, -1],
    [2147483647, -1, 2147483647, -1],
    [0, -1, 2147483647, 2147483647],
]
print(soln.islandsAndTreasure(grid))
grid = [[0, -1], [2147483647, 2147483647]]
print(soln.islandsAndTreasure(grid))
