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


graph = {"a": ["c", "b"], "b": ["d"], "c": ["e"], "d": ["f"], "e": [], "f": []}
print(dfs_stack(graph, "a"))
print(dfs_recurse(graph, "a"))
