class Solution:
    ways_dict = {0: 0, 1: 1, 2: 2}

    def climbStairs(self, n: int) -> int:
        one, two = 1, 1
        for i in range(n - 1):
            one, two = one + two, one
        return one


soln = Solution()
n = 2
print(soln.climbStairs(n))
n = 3
print(soln.climbStairs(n))
n = 30
print(soln.climbStairs(n))
