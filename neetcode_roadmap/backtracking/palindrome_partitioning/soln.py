from typing import List


class Solution:
    def check_palindrome(self, s, l, r):
        front = s[l:r]
        back = front[::-1]
        return front == back

    def partition(self, s: str) -> List[List[str]]:
        res = []
        cur = []

        def dfs(i):
            if i >= len(s):
                res.append(cur.copy())
            for j in range(i, len(s)):
                if self.check_palindrome(s, i, j + 1):
                    cur.append(s[i : j + 1])
                    dfs(j + 1)
                    cur.pop()

        dfs(0)
        return res


print(Solution().partition("aab"))