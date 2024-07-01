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
    
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        st = [root] if root is not None else []
        while st:
            node = st.pop()
            if node.val == subRoot.val:
                if self.isSameTree(node, subRoot):
                    return True
            if node.left:
                st.append(node.left)
            if node.right:
                st.append(node.right)
        return False


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

soln = Solution()
# Example 1
root1 = build_tree([3,4,5,1,2])
subRoot1 = build_tree([4,1,2])
print("Example 1:", soln.isSubtree(root1, subRoot1))  # Expected: True

# Example 2
root2 = build_tree([3,4,5,1,2,None,None,None,None,0])
subRoot2 = build_tree([4,1,2])
print("Example 2:", soln.isSubtree(root2, subRoot2))  # Expected: False

