from typing import List


class Solution:
    def print_board(self):
        for i in range(len(self.board)):
            print(self.board[i])
        print()

    def place_queen(self, x, y):
        edges = [(i, y) for i in range(0, x)]
        corners = []
        corners += [
            (x - i, z)
            for i in range(1, x + 1)
            for z in [y - i, y + i]
            if 0 <= z < len(self.board)
        ]
        combined = edges + corners
        for i, j in combined:
            if self.board[i][j] == "Q":
                return False
        return True

    def solveNQueens(self, n: int) -> List[List[str]]:
        self.board = [["." for _ in range(n)] for _ in range(n)]
        results = []
        current_queens = {}

        def dfs(i):
            if i >= n:
                results.append(["".join(elem) for elem in self.board])
            for j in range(n):
                if current_queens.get(j, False):
                    continue
                if self.place_queen(i, j):
                    self.board[i][j] = "Q"
                    current_queens[j] = True
                    # self.print_board()
                    dfs(i + 1)
                    self.board[i][j] = "."
                    current_queens[j] = False

        dfs(0)
        return results


soln = Solution()
print(soln.solveNQueens(4))
