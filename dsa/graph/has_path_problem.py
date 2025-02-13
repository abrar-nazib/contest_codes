import collections


def has_path_dfs(graph, src, dst):
    # Base case
    if src == dst:
        return True
    for neighbor in graph[src]:
        if has_path_dfs(graph, neighbor, dst):
            return True
    return False


def has_path_bfs(graph, src, dst):
    queue = collections.deque([src])
    while len(queue) > 0:
        node = queue.popleft()
        if node == dst:
            return True
        for neighbor in graph[node]:
            queue.append(neighbor)
    return False


graph = {"f": ["g", "i"], "g": ["h"], "h": [], "i": ["g", "k"], "j": ["i"], "k": []}

print(has_path_dfs(graph=graph, src="f", dst="k"))
print(has_path_dfs(graph, "j", "f"))
print(has_path_bfs(graph=graph, src="f", dst="k"))
print(has_path_bfs(graph, "j", "f"))
