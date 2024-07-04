from typing import Optional, List
import collections

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        output = []
        q = collections.deque()
        q.append(root) if root is not None else q
        while q:
            val = -1
            for i in range(len(q)):
                node = q.popleft()
                val = node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            output.append(val)
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

sol = Solution()
null = None       
# Assuming the TreeNode class, build_tree function, and Solution class with a method rightSideView are defined as shown previously

# Test Example 1
root1 = build_tree([1,2,3,None,5,None,4])
print("Example 1 Output:", sol.rightSideView(root1))  # Expected: [1, 3, 4]

# Test Example 2
root2 = build_tree([1,None,3])
print("Example 2 Output:", sol.rightSideView(root2))  # Expected: [1, 3]

# Test Example 3
root3 = build_tree([1, 2, 3, 4])
print("Example 3 Output:", sol.rightSideView(root3))  # Expected: []