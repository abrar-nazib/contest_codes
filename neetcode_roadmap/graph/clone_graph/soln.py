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
        queue = collections.deque([node]) if node else None
        while queue:
            n = queue.popleft()
            visited.add(n)
            adj_list.setdefault(f"{n.val}", [])
            for neighbor in n.neighbors:

                if neighbor not in visited:
                    queue.append(neighbor)
                    adj_list[f"{n.val}"].append(neighbor.val)
                    adj_list.setdefault(f"{neighbor.val}", []).append(n.val)
        nodes = [Node(i + 1, []) for i in range(len(adj_list))]
        if not nodes:
            return None
        for key, values in enumerate(adj_list):
            n = nodes[int(key) - 1]
            for val in values:
                n.neighbors.append(nodes[int(val) - 1])
        return nodes[0]


def build_graph(adjList):
    if not adjList:
        return None

    nodes = [Node(i + 1) for i in range(len(adjList))]

    for i, neighbors in enumerate(adjList):
        nodes[i].neighbors = [nodes[j - 1] for j in neighbors]

    return nodes[0]


def print_graph(node: Optional["Node"]):
    if not node:
        return "[]"

    adjList = {}
    visited = set()

    def dfs(node: Node):
        if node.val in visited:
            return
        visited.add(node.val)
        adjList[node.val] = [n.val for n in node.neighbors]
        for neighbor in node.neighbors:
            dfs(neighbor)

    dfs(node)
    return adjList


soln = Solution()
adjList = [[2, 4], [1, 3], [2, 4], [1, 3]]
node = build_graph(adjList)
cloned_graph = soln.cloneGraph(node)
print_graph(cloned_graph)
print(soln.cloneGraph(Node(1)))
print(soln.cloneGraph(None))
