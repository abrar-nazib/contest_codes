from typing import List
from collections import deque
import time


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        ROWS, COLS = len(board), len(board[0])
        visited = set()

        def capture_region(row, col):
            current_indexes = []
            q = deque([(row, col)])
            has_corner_item = False
            while q:
                # time.sleep(1)
                r, c = q.popleft()
                # print(r, c)
                # print(visited)
                visited.add((r, c))
                current_indexes.append([r, c])
                if r == 0 or c == 0 or r == ROWS - 1 or c == COLS - 1:
                    has_corner_item = True
                    # print("Has corner item", r, c)

                # Top
                if (
                    r + 1 < ROWS
                    and (r + 1, c) not in visited
                    and board[r + 1][c] == "O"
                    and (r + 1, c) not in q
                ):
                    q.append((r + 1, c))
                if (
                    r - 1 >= 0
                    and (r - 1, c) not in visited
                    and board[r - 1][c] == "O"
                    and (r - 1, c) not in q
                ):
                    q.append((r - 1, c))
                if (
                    c + 1 < COLS
                    and (r, c + 1) not in visited
                    and board[r][c + 1] == "O"
                    and (r, c + 1) not in q
                ):
                    q.append((r, c + 1))
                if (
                    c - 1 >= 0
                    and (r, c - 1) not in visited
                    and board[r][c - 1] == "O"
                    and (r, c - 1) not in q
                ):
                    q.append((r, c - 1))

            if not has_corner_item:
                for i, j in current_indexes:
                    board[i][j] = "X"

        for i in range(ROWS):
            for j in range(COLS):
                if (i, j) not in visited and board[i][j] == "O":
                    capture_region(i, j)
        print(board)


soln = Solution()
board = [
    ["X", "X", "X", "X"],
    ["X", "O", "O", "X"],
    ["X", "X", "O", "X"],
    ["X", "O", "X", "X"],
]
soln.solve(board)
board = [["X"]]
soln.solve(board)
# fmt: off
board = [
    ["O","O","O","O","O","O","O","O","X","O","O","O","O","O","X","O","O","O","O","O"],
    ["O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O","O"],
    ["X","O","O","X","O","X","O","O","O","O","X","O","O","X","O","O","O","O","O","O"],
    ["O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","X","X","O"],
    ["O","X","X","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O"],
    ["O","O","O","O","X","O","O","O","O","O","O","X","O","O","O","O","O","X","X","O"],
    ["O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O","O"],
    ["O","O","O","O","O","O","O","O","O","O","O","O","O","X","O","O","O","O","O","O"],
    ["O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","X","O"],
    ["O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O","O","O","O"],
    ["O","O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O"],
    ["O","O","O","O","X","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O"],
    ["O","O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O"],
    ["X","O","O","O","O","O","O","O","O","X","X","O","O","O","O","O","O","O","O","O"],
    ["O","O","O","O","O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O"],
    ["O","O","O","O","X","O","O","O","O","O","O","O","O","X","O","O","O","O","O","X"],
    ["O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","X","O","X","O","O"],
    ["O","X","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O"],
    ["O","O","O","O","O","O","O","O","X","X","O","O","O","X","O","O","X","O","O","X"],
    ["O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O"]]
# fmt: on
soln.solve(board)
