import collections


def edge_to_adj_list(edges):
    adj_list = {}
    for x, y in edges:
        adj_list.setdefault(x, []).append(y)
        adj_list.setdefault(y, []).append(x)
    return adj_list


def find_shortest_path(graph, src, dest):
    queue = collections.deque([(src, 0)])
    results = []
    visited = set()
    shortest_path = float("inf")
    while queue:
        node, pathlen = queue.popleft()
        if node == dest:
            shortest_path = min(shortest_path, pathlen)
        visited.add(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                queue.append((neighbor, pathlen + 1))

    return shortest_path


edges = [["w", "x"], ["x", "y"], ["z", "y"], ["z", "v"], ["w", "v"]]
graph = edge_to_adj_list(edges)
print(find_shortest_path(graph, "w", "z"))
