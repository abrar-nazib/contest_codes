from typing import Optional

# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: Optional[Node]) -> Optional[Node]:
        out_dict = {None: None} # This is the clever optimization!
        current = head
        if not current:
            return None
        while(current):
            out_node = Node(current.val)
            out_dict[current] = out_node
            current = current.next
        current = head
        while(current):
            current_out_node = out_dict[current]
            current_out_node.next = out_dict[current.next]
            current_out_node.random = out_dict[current.random]
            current = current.next
        return out_dict[head]
            
        
def main():
    solution = Solution()

    # Helper function to create linked list from list
    def create_linked_list(lst):
        nodes = [Node(x[0]) for x in lst]
        for i, node in enumerate(nodes):
            if i < len(nodes) - 1:
                node.next = nodes[i + 1]
            if lst[i][1] is not None:
                node.random = nodes[lst[i][1]]
        return nodes[0] if nodes else None

    # Example 1
    head = create_linked_list([[7, None], [13, 0], [11, 4], [10, 2], [1, 0]])
    output = solution.copyRandomList(head)
    # Print or assert output here

    # Example 2
    head = create_linked_list([[1, 1], [2, 1]])
    output = solution.copyRandomList(head)
    # Print or assert output here

    head = create_linked_list([])
    output = solution.copyRandomList(head)

if __name__ == "__main__":
    main()