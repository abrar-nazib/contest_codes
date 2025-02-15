from typing import List
from collections import deque
import time as t


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        visited = set()

        def bfs(r_os):
            q = deque([r_os])
            count = 0
            queued = set()
            while q:
                rotten_oranges = q.popleft()
                arr = []
                for rotten_orange in rotten_oranges:
                    i, j = rotten_orange
                    visited.add((i, j))
                    if grid[i][j] == 1:
                        grid[i][j] = 2
                    if (
                        i + 1 < ROWS
                        and (i + 1, j) not in visited
                        and grid[i + 1][j] == 1
                        and (i + 1, j) not in queued
                    ):
                        arr.append((i + 1, j))
                        queued.add((i + 1, j))
                    if (
                        i - 1 >= 0
                        and (i - 1, j) not in visited
                        and grid[i - 1][j] == 1
                        and (i - 1, j) not in queued
                    ):
                        arr.append((i - 1, j))
                        queued.add((i - 1, j))
                    if (
                        j + 1 < COLS
                        and (i, j + 1) not in visited
                        and grid[i][j + 1] == 1
                        and (i, j + 1) not in queued
                    ):
                        arr.append((i, j + 1))
                        queued.add((i, j + 1))
                    if (
                        j - 1 >= 0
                        and (i, j - 1) not in visited
                        and grid[i][j - 1] == 1
                        and (i, j - 1) not in queued
                    ):
                        arr.append((i, j - 1))
                        queued.add((i, j - 1))
                if arr:
                    count += 1
                    q.append(tuple(arr))
                    print(arr)
            return count

        time = 0
        r_os = []
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 2 and (i, j) not in visited:
                    r_os.append((i, j))
        time = bfs(tuple(r_os))
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 1:
                    return -1
        return time


# fmt: off
soln = Solution()
grid = [[2, 1, 1], [1, 1, 0], [0, 1, 1]]
print(soln.orangesRotting(grid))
grid = [[2, 1, 1], [0, 1, 1], [1, 0, 1]]
print(soln.orangesRotting(grid))
grid = [[0, 2]]
print(soln.orangesRotting(grid))
grid = [[2, 1, 1],
        [1, 1, 1], 
        [0, 1, 2]]
print(soln.orangesRotting(grid))
grid=[[2,2],
      [1,1],
      [0,0],
      [2,0]]
print(soln.orangesRotting(grid))
# fmt: on
