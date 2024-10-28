from typing import Optional, List
import collections


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Codec:

    def serialize(self, root: TreeNode):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        serialized_tree = ""
        q = collections.deque([root])
        while q:
            node = q.popleft()
            if node:
                serialized_tree += f"{node.val},"
            else:
                serialized_tree += "None,"
                continue
            if node.left:
                q.append(node.left)
            else:
                q.append(None)
            if node.right:
                q.append(node.right)
            else:
                q.append(None)

        return serialized_tree

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        lst = data.split(",")[:-1]
        if not lst or lst[0] == "None":
            return None
        root = TreeNode(lst[0])
        queue = collections.deque([root])
        i = 1

        while i < len(lst):
            current: TreeNode = queue.popleft()
            if lst[i] != "None" and i < len(lst):
                current.left = TreeNode(int(lst[i]))
                queue.append(current.left)
            i += 1
            if lst[i] != "None" and i < len(lst):
                current.right = TreeNode(int(lst[i]))
                queue.append(current.right)
            i += 1
        return root


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
            node_val = node.val if node else "X"
            print(node_val, end=" ")
            if node:
                queue.append(node.left if node.left else None)
                queue.append(node.right if node.right else None)
        print()  # Newline for new level


null = None
root = build_tree([1, 2, 3, null, null, 4, 5])
codec = Codec()
data = codec.serialize(root)
print(data)
codec.deserialize(data)
