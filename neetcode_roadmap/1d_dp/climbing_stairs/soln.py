# The first code TLEs
# class Solution:
#     def climbStairs(self, n: int) -> int:
#         self.ways = 0

#         def dfs(nn):
#             if nn == 0:
#                 self.ways += 1
#                 return
#             if nn - 1 >= 0:
#                 dfs(nn - 1)
#             if nn - 2 >= 0:
#                 dfs(nn - 2)

#         dfs(n)
#         return self.ways


class Solution:
    ways_dict = {0: 0, 1: 1, 2: 2}

    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return self.ways_dict[n]
        for i in range(3, n + 1):
            self.ways_dict[i] = self.ways_dict[i - 1] + self.ways_dict[i - 2]
        return self.ways_dict[n]


soln = Solution()
n = 2
print(soln.climbStairs(n))
n = 3
print(soln.climbStairs(n))
n = 30
print(soln.climbStairs(n))
