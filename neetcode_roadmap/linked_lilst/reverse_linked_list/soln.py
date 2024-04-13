# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val=val
        self.next = next
        
    def __str__(self):
        return str(self.val) + " " + str(self.next.val) if self.next != None else str(None)

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        previous = None
        while head != None:
            next_ = head.next
            head.next = previous
            previous = head
            head = next_
        return previous
        
            
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
    head1 = create_linked_list([1, 2, 3, 4, 5])
    output1 = solution.reverseList(head1)
    print("Output 1: ", create_list(output1))  # Should print [5, 4, 3, 2, 1]

    # Example 2
    head2 = create_linked_list([1, 2])
    output2 = solution.reverseList(head2)
    print("Output 2: ", create_list(output2))  # Should print [2, 1]

    # Example 3
    head3 = create_linked_list([])
    output3 = solution.reverseList(head3)
    print("Output 3: ", create_list(output3))  # Should print []

if __name__ == "__main__":
    main()