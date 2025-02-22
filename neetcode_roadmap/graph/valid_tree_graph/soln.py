# Initial thought: Whether there's a loop??

from typing import List


class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False
        # Check for loops
        adj_list = {i: [] for i in range(n)}
        for node, neighbor in edges:
            adj_list[node].append(neighbor)
            adj_list[neighbor].append(node)

        visiting = set()

        def dfs(node):
            if node in visiting:
                return False
            visiting.add(node)
            for neighbor in adj_list[node]:
                adj_list[neighbor].remove(node)
                if dfs(neighbor) != True:
                    return False
                adj_list[neighbor].append(node)
            visiting.remove(node)
            return True

        for i in range(len(adj_list)):
            if dfs(i) != True:
                return False
        return True
