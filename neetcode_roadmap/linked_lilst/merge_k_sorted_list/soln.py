from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
    def __str__(self):
        return str(self.val)

class Solution:
    def min_node(self, lists: List[Optional[ListNode]]):
        min_value = 10e7
        min_index = 0
        for i in range(len(lists)):
            if lists[i] is not None:
                if lists[i].val < min_value:
                    min_value = lists[i].val
                    min_index = i
        # Remove all None nodes
        
        return min_index
    
    def print_list(self, node):
        while node:
            print(node.val, end=" ")
            node = node.next
        print()
               
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        head = current = ListNode(-1)
        while any(lists):
            idx = self.min_node(lists)
            current.next = lists[idx]
            current = current.next
            lists[idx] = lists[idx].next
            if lists[idx] is None:
                lists.pop(idx)
        return head.next
            

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