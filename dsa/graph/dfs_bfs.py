import collections


def dfs_stack(graph, node):
    # This dfs utilizes stack. Visualize:
    st = [node]
    while len(st) > 0:
        n = st.pop()
        print(n)
        for neighbor in graph[n]:
            st.append(neighbor)  # [c b] a, [c d] b, [c f] d, [c] f, [e] c, [] e


def dfs_recurse(graph, node):
    print(node)
    for n in graph[node][::-1]:
        dfs_recurse(graph, n)


def bfs(graph, node):
    queue = collections.deque([node])
    while queue:
        n = queue.popleft()
        print(n)
        for neighbor in graph[n]:
            queue.append(neighbor)


graph = {"a": ["c", "b"], "b": ["d"], "c": ["e"], "d": ["f"], "e": [], "f": []}
dfs_stack(graph, "a")
dfs_recurse(graph, "a")
bfs(graph, "a")
