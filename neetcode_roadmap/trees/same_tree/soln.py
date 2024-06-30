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
        p_st = [p] if p is not None else []
        q_st = [q] if q is not None else []
        while p_st and q_st:
            p_node = p_st.pop()
            q_node = q_st.pop()
            if p_node.val != q_node.val:
                return False
            if p_node.left or q_node.left:
                if not (p_node.left and q_node.left):
                    return False
                p_st.append(p_node.left)
                q_st.append(q_node.left)
            if p_node.right or q_node.right:
                if not (p_node.right and q_node.right):
                    return False
                p_st.append(p_node.right)
                q_st.append(q_node.right)
        if len(p_st) != len(q_st):
            return False
        return True

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