from typing import Optional
import collections

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

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

def build_tree(nodes):
    if not nodes:
        return None
    root = TreeNode(nodes[0])
    queue = collections.deque([root])
    i = 1
    while queue and i < len(nodes):
        node = queue.popleft()
        if i < len(nodes) and nodes[i] is not None:
            node.left = TreeNode(nodes[i])
            queue.append(node.left)
        i += 1
        if i < len(nodes) and nodes[i] is not None:
            node.right = TreeNode(nodes[i])
            queue.append(node.right)
        i += 1
    return root


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p:"TreeNode", q:"TreeNode") -> 'TreeNode':
        current = root
        while current:
            if current.val > p.val and current.val > q.val:
                current = current.left
            elif current.val < p.val and current.val < q.val:
                current = current.right
            else:
                return current
            
soln = Solution()

null = None
root = build_tree([6,2,8,0,4,7,9,null,null,3,5])
p = build_tree([2])
q = build_tree([8])
print(soln.lowestCommonAncestor(root, p, q).val)

# Assuming the TreeNode class, build_tree function, and Solution class are defined as shown previously

# Adjust the input values for p and q
p = build_tree([2])
q = build_tree([4])

# Build the tree from the given input
root = build_tree([6,2,8,0,4,7,9,None,None,3,5])

# Create an instance of the Solution class

# Call the lowestCommonAncestor method and print the result
print(soln.lowestCommonAncestor(root, p, q).val)