from typing import Optional
import collections

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    
    def isBalanced(self, root: Optional[TreeNode]) -> int:
        res = [True]
        def dfs(root):
            if root == None:
                return -1
            left = dfs(root.left)
            right = dfs(root.right)
            if abs(left - right) > 1:
                res[0] = False
            return 1+max(left, right)
        dfs(root)
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
            # print(node_val, end=' ')
            if node:
                queue.append(node.left if node.left else None)
                queue.append(node.right if node.right else None)
        print()  # Newline for new level

soln = Solution()
null=None
# Test case
lst = [1,2,2,3,3,null,null,4,4]
root = build_tree(lst)
# print_tree(root)
print(soln.isBalanced(root))