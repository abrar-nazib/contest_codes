from typing import List


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        adj_lists: List[dict] = []
        for i in range(len(edges) - 1, -1, -1):
            adj_list = {k: [] for k in range(1, len(edges) + 1)}
            for j, edge in enumerate(edges, start=1):
                if j - 1 == i:
                    continue
                adj_list[edge[0]].append(edge[1])
                adj_list[edge[1]].append(edge[0])
            adj_lists.append(adj_list.copy())

        visiting = set()
        adj_list = adj_lists[0].copy()

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

        for i, adj_list in enumerate(adj_lists):
            visiting = set()
            adj_list = adj_lists[i].copy()
            if all([dfs(x) for x in range(1, len(edges) + 1)]):
                return edges[len(edges) - i - 1]
        return []


soln = Solution()
edges = [[1, 2], [1, 3], [2, 3]]
print(soln.findRedundantConnection(edges))
edges = [[1, 2], [2, 3], [3, 4], [1, 4], [1, 5]]
print(soln.findRedundantConnection(edges))
edges = [
    [2, 7],
    [7, 8],
    [3, 6],
    [2, 5],
    [6, 8],
    [4, 8],
    [2, 8],
    [1, 8],
    [7, 10],
    [3, 9],
]
print(soln.findRedundantConnection(edges))
edges = [
    [20, 24],
    [3, 17],
    [17, 20],
    [8, 15],
    [14, 17],
    [6, 17],
    [15, 23],
    [6, 8],
    [15, 19],
    [16, 22],
    [7, 9],
    [8, 22],
    [2, 4],
    [4, 11],
    [22, 25],
    [6, 24],
    [13, 19],
    [15, 18],
    [1, 9],
    [4, 9],
    [4, 19],
    [5, 10],
    [4, 21],
    [4, 12],
    [5, 6],
]
print(soln.findRedundantConnection(edges))
