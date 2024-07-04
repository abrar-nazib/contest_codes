from typing import Optional, List
import collections

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        arr = []
        def post_traverse(root):
            if root is None:
                return
            post_traverse(root.left)
            arr.append(root.val)
            post_traverse(root.right)
            
        post_traverse(root)
        for i in range(len(arr)-1):
            if arr[i] >= arr[i+1]:
                return False
        return True
        
        
def build_tree(lst):
    if not lst:
        return None
    root = TreeNode(lst[0])
    queue = collections.deque([root])
    i = 1
    while queue and i < len(lst):
        current = queue.popleft()
        if lst[i] is not None:
            current.left = TreeNode(lst[i])
            queue.append(current.left)
        i += 1
        if i < len(lst) and lst[i] is not None:
            current.right = TreeNode(lst[i])
            queue.append(current.right)
        i += 1
    return root

def print_tree(root):
    if not root:
        print("Empty Tree")
        return
    queue = collections.deque([root])
    while queue:
        level_size = len(queue)
        for _ in range(level_size):
            node = queue.popleft()
            node_val = node.val if node else 'X'
            print(node_val, end=' ')
            if node:
                queue.append(node.left if node.left else None)
                queue.append(node.right if node.right else None)
        print()  # Newline for new level

sol = Solution()
null = None       

# Assuming the TreeNode class, build_tree function, and Solution class with a method isValidBST are defined as shown previously

# Test Example 1
root1 = build_tree([2,1,3])
print("Example 1 Output:", sol.isValidBST(root1))  # Expected: True

# Test Example 2
root2 = build_tree([5,1,4,None,None,3,6])
print("Example 2 Output:", sol.isValidBST(root2))  # Expected: False

# Test Example 3
root3 = build_tree([5,4,6,null,null,3,7])
print("Example 3 Output:", sol.isValidBST(root3))
print_tree(root3)