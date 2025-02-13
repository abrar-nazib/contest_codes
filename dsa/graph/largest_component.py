def find_largest_component(graph):
    visited = set()

    def traverse(node):
        # base case
        if node in visited:
            return 0
        visited.add(node)
        count = 1
        for neighbor in graph[node]:
            if neighbor not in visited:
                count += traverse(neighbor)
        return count

    largest_component = 0
    for i, n in enumerate(graph):
        if n not in visited:
            largest_component = max(largest_component, traverse(n))

    return largest_component


graph = {
    "0": ["8", "1", "5"],
    "1": ["0"],
    "5": ["0", "8"],
    "8": ["0", "5"],
    "2": ["3", "4"],
    "3": ["2", "4"],
    "4": ["3", "2"],
}
print(find_largest_component(graph))
