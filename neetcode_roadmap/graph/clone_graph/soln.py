# Definition for a Node.
class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

    def __repr__(self):
        return f"{self.val}"


import collections
from typing import Optional


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        # Build adjacency graph first, then build the actual graph
        adj_list = {}
        visited = set()

        def build_adj_list(node_):
            # Base case
            if not node_ or node_.val in visited:
                return
            visited.add(node_.val)
            adj_list.setdefault(str(node_.val), set())

            for neighbor in node_.neighbors:
                adj_list[str(node_.val)].add(str(neighbor.val))
                adj_list.setdefault(str(neighbor.val), set()).add(str(node_.val))
                build_adj_list(neighbor)

        build_adj_list(node)
        adj_list = dict(sorted(adj_list.items(), key=lambda item: int(item[0])))
        print(adj_list)
        nodes = [Node(int(k), []) for i, k in enumerate(adj_list)]
        for i, k in enumerate(adj_list):
            for elem in adj_list[k]:
                nodes[int(k) - 1].neighbors.append(nodes[int(elem) - 1])

        if len(nodes) > 0:
            return nodes[0]
        else:
            return None


def build_graph(adjList):
    if not adjList:
        return None

    nodes = [Node(i + 1) for i in range(len(adjList))]

    for i, neighbors in enumerate(adjList):
        nodes[i].neighbors = [nodes[j - 1] for j in neighbors]

    return nodes[0]


def prepare_adj_list(node: Optional["Node"]):
    if not node:
        return "[]"

    adjList = {}
    visited = set()

    def dfs(node: Node):
        if node.val in visited:
            return
        visited.add(node.val)
        adjList[node.val] = sorted([n.val for n in node.neighbors])
        for neighbor in node.neighbors:
            dfs(neighbor)

    dfs(node)
    return dict(sorted(adjList.items()))


soln = Solution()
adjList = [[2, 4], [1, 3], [2, 4], [1, 3]]
node = build_graph(adjList)
cloned_graph = soln.cloneGraph(node)
# print(prepare_adj_list(cloned_graph))
# print(soln.cloneGraph(Node(1)))
# print(soln.cloneGraph(None))
adjList = [[2, 3, 4], [1, 7], [1], [1, 5, 6, 8], [4], [4], [2], [4]]
node = build_graph(adjList)
cloned_graph = soln.cloneGraph(node)
print(prepare_adj_list(cloned_graph))
print()
adjList = [
    [2, 3, 4, 14],
    [1, 7, 11],
    [1],
    [1, 5, 6, 8],
    [4, 9],
    [4],
    [2, 10],
    [4, 13],
    [5, 12, 16],
    [7],
    [2],
    [9, 15],
    [8],
    [1],
    [12],
    [9],
]
node = build_graph(adjList)
cloned_graph = soln.cloneGraph(node)
print(prepare_adj_list(cloned_graph))
