from typing import List, Dict


class Solution:

    def exist(self, board: List[List[str]], word):
        ROW, COL = len(board), len(board[0])
        path = set()

        def dfs(r, c, i):
            # Base case: All cases passed and now came to the end of word
            if i == len(word):
                return True
            # Elimination case
            if (
                r < 0
                or c < 0
                or r >= ROW
                or c >= COL
                or word[i] != board[r][c]
                or (r, c) in path
            ):
                # print(r, c)
                return False

            path.add((r, c))
            res = (
                dfs(r, c + 1, i + 1)
                or dfs(r, c - 1, i + 1)
                or dfs(r - 1, c, i + 1)
                or dfs(r + 1, c, i + 1)
            )
            path.remove((r, c))
            return res

        for r in range(ROW):
            for c in range(COL):
                if dfs(r, c, 0):
                    return True
        return False


soln = Solution()
board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
word = "ABCCED"
print(soln.exist(board, word))
board = [["C", "A", "A"], ["A", "A", "A"], ["B", "C", "D"]]
word = "AAB"
print(soln.exist(board, word))
