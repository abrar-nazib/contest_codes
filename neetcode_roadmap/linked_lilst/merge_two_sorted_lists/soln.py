from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        

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
    list1 = create_linked_list([1, 2, 4])
    list2 = create_linked_list([1, 3, 4])
    output = solution.mergeTwoLists(list1, list2)
    print("Output 1: ", create_list(output))  # Should print [1, 1, 2, 3, 4, 4]

    # Example 2
    list1 = create_linked_list([])
    list2 = create_linked_list([])
    output = solution.mergeTwoLists(list1, list2)
    print("Output 2: ", create_list(output))  # Should print []

    # Example 3
    list1 = create_linked_list([])
    list2 = create_linked_list([0])
    output = solution.mergeTwoLists(list1, list2)
    print("Output 3: ", create_list(output))  # Should print [0]

if __name__ == "__main__":
    main()