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
        
        level = 0
        q = collections.deque([root])
        while q:
            for i in range(len(q)):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            level +=1
        return level

        
root = TreeNode(3)
root.left= TreeNode(9)
root.right= TreeNode(20)
root.right.left = TreeNode(15)
root.right.right = TreeNode(7)
# root.right.right.right = TreeNode(2)

soln = Solution()
print(soln.maxDepth(root))