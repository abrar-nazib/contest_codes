# Assuming there's no cycle in the graph
def edge_list_to_adjacency_list(edges):
    adj_list = {}
    for edge in edges:
        adj_list.setdefault(edge[0], []).append(edge[1])
        adj_list.setdefault(edge[1], []).append(edge[0])
    return adj_list


visited = set()


def has_path(graph, src, dst) -> bool:
    # Base case 1
    if src == dst:
        return True
    # Base case 2
    if src in visited:
        return False
    visited.add(src)
    for neighbor in graph[src]:
        if has_path(graph, neighbor, dst=dst):
            return True
    return False


edges = [["i", "j"], ["k", "i"], ["m", "k"], ["k", "l"], ["o", "n"]]
graph = edge_list_to_adjacency_list(edges)
print(graph)
print(has_path(graph, "i", "k"))
