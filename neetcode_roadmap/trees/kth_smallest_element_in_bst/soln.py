from typing import Optional, List
import collections

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        arr = []
        def dfs(root):
            if root is None:
                return
            left = dfs(root.left)
            arr.append(root.val)
            right = dfs(root.right)
        dfs(root)
        return arr[k-1]
        
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

# Assuming the TreeNode class, build_tree function, and Solution class with a method kthSmallest are defined as shown previously

# Test Example 1
root1 = build_tree([3,1,4,None,2])
k1 = 1
print("Example 1 Output:", sol.kthSmallest(root1, k1))  # Expected: 1

# Test Example 2
root2 = build_tree([5,3,6,2,4,None,None,1])
k2 = 3
print("Example 2 Output:", sol.kthSmallest(root2, k2))  # Expected: 3
