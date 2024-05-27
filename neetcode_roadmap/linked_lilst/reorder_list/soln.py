# Definition for singly-linked list.
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
    def __str__(self) -> str:
        return self.val

class Solution:
    def print_ll(self,head):
        while head:
            print(head.val, end=" ")
            head = head.next
        print()
        
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # Put the whole linked list in an array
        list_arr = []
        h = head
        while head:
            list_arr.append(head)
            head = head.next
        # print(list_arr)
        b_range = range(len(list_arr)//2) if len(list_arr)%2 else range(len(list_arr)//2-1)
        for i in b_range:
            # self.print_ll(list_arr[0])
            list_arr[i].next = list_arr[len(list_arr)-i-1]
            list_arr[len(list_arr)-i-2].next = None
            list_arr[len(list_arr)-i-1].next = list_arr[i+1]
            
        return list_arr[i]    
        
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
    head = create_linked_list([1, 2, 3, 4])
    solution.reorderList(head)
    print("Output 1: ", create_list(head))  # Should print [1, 4, 2, 3]

    # Example 2
    head = create_linked_list([1, 2, 3, 4, 5])
    solution.reorderList(head)
    print("Output 2: ", create_list(head))  # Should print [1, 5, 2, 4, 3]

if __name__ == "__main__":
    main()