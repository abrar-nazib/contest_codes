from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    

    
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(-1, head)
        groupPrev = dummy # Securing the previous node
        while True:
            kth_node = self.get_kth_node(groupPrev, k)
            if not kth_node:
                break
            groupNext = kth_node.next # Securing the next node
            
            # Reverse Group
            prev, curr = kth_node.next, groupPrev.next
            
            while curr != groupNext:
                temp = curr.next
                curr.next = prev
                prev = curr
                curr = temp
                
            temp = groupPrev.next
            groupPrev.next= kth_node
            groupPrev = temp
        return dummy.next
    def get_kth_node(self, current_node, k):
        while current_node and k>0:
            current_node = current_node.next
            k -=1
        return current_node
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
    head = create_linked_list([1, 2, 3, 4, 5, 6])
    output = solution.reverseKGroup(head, 2)
    print("Output 1: ", create_list(output))  # Should print [2, 1, 4, 3, 5]

    # Example 2
    head = create_linked_list([1, 2, 3, 4, 5])
    output = solution.reverseKGroup(head, 3)
    print("Output 2: ", create_list(output))  # Should print [3, 2, 1, 4, 5]

if __name__ == "__main__":
    main()