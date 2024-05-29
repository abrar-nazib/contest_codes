from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
        
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        current1, current2 = l1, l2
        nodes = []
        carry = 0
        while(current1 or current2 or carry):
            val1 = current1.val if current1 else 0
            val2 = current2.val if current2 else 0
            val = (val1 + val2 + carry)
            # print(val, end=" ")
            carry = (val) // 10
            # print(carry)
            nodes.append(ListNode(val%10))
            if current1:
                current1 = current1.next
            if current2:
                current2 = current2.next
                
        for i in range(len(nodes)-1):
            nodes[i].next = nodes[i+1]
        return nodes[0]
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
    l1 = create_linked_list([2, 4, 3])
    l2 = create_linked_list([5, 6, 4])
    output = solution.addTwoNumbers(l1, l2)
    print("Output 1: ", create_list(output))  # Should print [7, 0, 8]

    # Example 2
    l1 = create_linked_list([0])
    l2 = create_linked_list([0])
    output = solution.addTwoNumbers(l1, l2)
    print("Output 2: ", create_list(output))  # Should print [0]

    # Example 3
    l1 = create_linked_list([9, 9, 9, 9, 9, 9, 9])
    l2 = create_linked_list([9, 9, 9, 9])
    output = solution.addTwoNumbers(l1, l2)
    print("Output 3: ", create_list(output))  # Should print [8, 9, 9, 9, 0, 0, 0, 1]

if __name__ == "__main__":
    main()