from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        visited_dict = {}
        while head:
            if visited_dict.get(head):
                return True
            visited_dict[head] = 1
            head = head.next 
        return False
    
def main():
    solution = Solution()

    # Helper function to create linked list from list
    def create_linked_list(lst, index):
        dummy = ListNode(0)
        ptr = dummy
        nodes = []
        for i in lst:
            node = ListNode(i)
            nodes.append(node)
            ptr.next = node
            ptr = ptr.next
        if index != -1:
            ptr.next = nodes[index]
        return dummy.next

    # Example 1
    head = create_linked_list([1, 2, 3, 4], 1)
    output = solution.hasCycle(head)
    print("Output 1: ", output)  # Should print True

    # Example 2
    head = create_linked_list([1, 2], -1)
    output = solution.hasCycle(head)
    print("Output 2: ", output)  # Should print False

if __name__ == "__main__":
    main()
        
    