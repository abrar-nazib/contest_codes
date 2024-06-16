from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def determineDepth(self, root):
        if root == None:
            return 0


        return 1+ max(self.determineDepth(root.left) , self.determineDepth(root.right))    
    
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.determineDepth(root)
        
root = TreeNode(3)
root.left= TreeNode(9)
root.right= TreeNode(20)
root.right.left = TreeNode(15)
root.right.right = TreeNode(7)
# root.right.right.right = TreeNode(2)

soln = Solution()
print(soln.maxDepth(root))