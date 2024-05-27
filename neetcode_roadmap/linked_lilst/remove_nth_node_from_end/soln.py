from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        node_list = []
        current = head
        while current:
            node_list.append(current)
            current = current.next
        # Edge Case 1: Node at the beginning
        if n >= len(node_list):
            return head.next
        if n>=1:
            node_list[-n-1].next = node_list[-n].next
        return head
    
def main():
    solution = Solution()

    # Helper function to create linked list from list
    def create_linked_list(lst):
        dummy = ListNode(0)
        ptr = dummy
        for i in lst:
            ptr.next = ListNode(i)
            ptr = ptr.next
        return dummy.next

    # Helper function to create list from linked list
    def create_list(node):
        lst = []
        while node:
            lst.append(node.val)
            node = node.next
        return lst

    # Example 1
    head = create_linked_list([1, 2, 3, 4, 5])
    output = solution.removeNthFromEnd(head, 2)
    print("Output 1: ", create_list(output))  # Should print [1, 2, 3, 5]

    # Example 2
    head = create_linked_list([1])
    output = solution.removeNthFromEnd(head, 1)
    print("Output 2: ", create_list(output))  # Should print []

    # Example 3
    head = create_linked_list([1, 2])
    output = solution.removeNthFromEnd(head, 1)
    print("Output 3: ", create_list(output))  # Should print [1]

if __name__ == "__main__":
    main()