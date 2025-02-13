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

            for neighbor in node_.neighbors:
                print(adj_list)
                adj_list.setdefault(str(node_.val), []).append(str(neighbor.val))
                # adj_list.setdefault(str(neighbor.val), []).append(str(node_.val))
                build_adj_list(neighbor)

        build_adj_list(node)
        nodes = [Node(int(k), []) for i, k in enumerate(adj_list)]
        for i, k in enumerate(adj_list):
            for elem in adj_list[k]:
                nodes[int(k)].append(nodes[int(elem) - 1])

        if len(nodes > 0):
            return nodes[0]
        else:
            return None