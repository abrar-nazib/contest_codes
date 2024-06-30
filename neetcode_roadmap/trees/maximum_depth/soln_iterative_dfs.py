from typing import Optional
import collections

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:    
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        st = [[root, 1]]
        maxdepth = 0
        while len(st)>0:
            node, depth = st.pop()
            if node.right:
                st.append([node.right, depth+1])
            if node.left:
                st.append([node.left, depth+1])
            maxdepth = max(maxdepth, depth)    

        return maxdepth
    
root = TreeNode(3)
root.left= TreeNode(9)
root.right= TreeNode(20)
root.right.left = TreeNode(15)
root.right.right = TreeNode(7)
# root.right.right.right = TreeNode(2)

soln = Solution()
print(soln.maxDepth(root))