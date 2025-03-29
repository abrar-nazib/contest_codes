from typing import List


class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adj_list = {i: [] for i in range(n)}
        for a, b in edges:
            adj_list[a].append(b)
            adj_list[b].append(a)
        visited = set()

        def dfs(i):
            if i in visited:
                return
            visited.add(i)
            for j in adj_list[i]:
                dfs(j)

        component_count = 0
        for i in range(n):
            if i not in visited:
                component_count += 1
                dfs(i)
        return component_count


soln = Solution()

n = 3
edges = [[0, 1], [0, 2]]
print(soln.countComponents(n, edges))
n = 6
edges = [[0, 1], [1, 2], [2, 3], [4, 5]]
print(soln.countComponents(n, edges))
