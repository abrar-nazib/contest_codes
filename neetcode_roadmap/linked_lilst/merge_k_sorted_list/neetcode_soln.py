from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
    def __str__(self):
        return str(self.val)

class Solution:

    def print_list(self, node):
        while node:
            print(node.val, end=" ")
            node = node.next
        print()

    def merge_two_lists(self, list1, list2):
        current = head = ListNode(0)
        while list1 and list2:
            if list1.val < list2.val:
                current.next = list1
                list1=list1.next
            else:
                current.next = list2
                list2 = list2.next
            current = current.next
        current.next = list1 or list2
        return head.next
               
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        merged_list = None
        for i in range( len(lists)):
            merged_list = self.merge_two_lists(merged_list,lists[i])
        return merged_list
            

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
    lists = [create_linked_list(lst) for lst in [[1, 4, 5], [1, 3, 4], [2, 6]]]
    output = solution.mergeKLists(lists)
    print("Output 1: ", create_list(output))  # Should print [1, 1, 2, 3, 4, 4, 5, 6]

    # Example 2
    lists = []
    output = solution.mergeKLists(lists)
    print("Output 2: ", create_list(output))  # Should print []

    # Example 3
    lists = [create_linked_list(lst) for lst in [[]]]
    output = solution.mergeKLists(lists)
    print("Output 3: ", create_list(output))  # Should print []
    
    # Example 4
    lists = [create_linked_list(lst) for lst in [[2],[],[-1]]]
    output = solution.mergeKLists(lists)
    print("Output 4: ", create_list(output))  # Should print [1]
    
    # Example 5
    lists = [create_linked_list(lst) for lst in [[1]]]
    output = solution.mergeKLists(lists)
    print("Output 5: ", create_list(output))  # Should print [1]

if __name__ == "__main__":
    main()