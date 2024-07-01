from typing import Optional
import collections

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True
        if not p or not q:
            return False
        if p.val != q.val:
            return False
        left = self.isSameTree(p.left, q.left)
        right= self.isSameTree(p.right, q.right)
        return (left and right)

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

soln = Solution()

# Example 1
p1 = build_tree([1, 2, 3])
q1 = build_tree([1, 2,3])
print(soln.isSameTree(p1, q1))

# Example 2
p2 = build_tree([1, 2])
q2 = build_tree([1, None, 2])
print(soln.isSameTree(p2, q2))

# Example 3
p3 = build_tree([1, 2, 1])
q3 = build_tree([1, 1, 2])
print(soln.isSameTree(p3,q3))

print(soln.isSameTree(None, None))

p4 = build_tree([10, 5, 15])
q4 = build_tree([10, 5, None, None, 15])
print(soln.isSameTree(p4, q4))