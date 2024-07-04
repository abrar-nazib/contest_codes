from typing import Optional, List
import collections

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        q = collections.deque()
        output = []
        q.append(root) if root is not None else q
        while q:
            elems = []
            for i in range(len(q)):
                node = q.popleft()
                elems.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            output.append(elems)              
        return output

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
null = None       
root = build_tree([3,9,20,null,null,15,7])
print(soln.levelOrder(root))

# Test Example 2
root1 = build_tree([1])
sol = Solution()
print(sol.levelOrder(root1))

# Test Example 3
root2 = build_tree([])
print(sol.levelOrder(root2))