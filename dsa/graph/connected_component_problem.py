def count_connected_components(graph):
    visited = set()

    def traverse(node):
        if node in visited:
            return
        visited.add(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                traverse(neighbor)

    count = 0
    for i, n in enumerate(graph):
        if n not in visited:
            traverse(n)
            count += 1
    return count


graph = {
    "0": ["8", "1", "5"],
    "1": ["0"],
    "5": ["0", "8"],
    "8": ["0", "5"],
    "2": ["3", "4"],
    "3": ["2", "4"],
    "4": ["3", "2"],
}
print(count_connected_components(graph))
