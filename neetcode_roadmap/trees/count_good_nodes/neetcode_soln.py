from typing import Optional, List
import collections

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        res = [0]
        def dfs(root, max_val):
            if root is None:
                return
            if root.val >= max_val:
                res[0]+=1
            dfs(root.left, max(root.val, max_val))
            dfs(root.right, max(root.val, max_val))
            
        dfs(root, root.val)
        return res[0]
    
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
            node_val = node.val if node else 'None'
            print(node_val, end=' ')
            if node:
                queue.append(node.left if node.left else None)
                queue.append(node.right if node.right else None)
        print()  # Newline for new level

sol = Solution()
null = None       

# Assuming the TreeNode class, build_tree function, and Solution class with a method goodNodes are defined as shown previously

# Test Example 1
root1 = build_tree([3,1,4,3,None,1,5])
print("Example 1 Output:", sol.goodNodes(root1))  # Expected: 4

# Test Example 2
root2 = build_tree([3,3,None,4,2])
print("Example 2 Output:", sol.goodNodes(root2))  # Expected: 3

# Test Example 3
root3 = build_tree([1])
print("Example 3 Output:", sol.goodNodes(root3))  # Expected: 1