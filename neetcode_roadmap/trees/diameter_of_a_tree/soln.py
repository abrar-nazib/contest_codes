from typing import Optional
import collections

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    
    def determine_depth(self, root:Optional[TreeNode]):
        if root==None:
            return 0
        return 1+ max(self.determine_depth(root.left),self.determine_depth(root.right))
    
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if root== None:
            return 0
        st = [root]
        max_diameter = 0
        while st:
            node = st.pop()
            max_diameter = max(max_diameter, (self.determine_depth(node.left) + self.determine_depth(node.right)))
            if node.right:
                st.append(node.right)
            if node.left:
                st.append(node.left)
        return max_diameter
            
    
root = TreeNode(1)
root.left= TreeNode(3)
root.right= TreeNode(2)
root.right.left = TreeNode(4)
root.right.right = TreeNode(5)
# root.right.right.right = TreeNode(2)

soln = Solution()
print(soln.diameterOfBinaryTree(root))


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
        
# Test case
lst = [4,-7,-3,None,None,-9,-3,9,-7,-4,None,6,None,-6,-6,None,None,0,6,5,None,9,None,None,-1,-4,None,None,None,-2]
root = build_tree(lst)
# print_tree(root)
print(soln.diameterOfBinaryTree(root))