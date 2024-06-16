from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:

    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        temp = root.left
        root.left = root.right
        root.right = temp

        self.invertTree(root.left)
        self.invertTree(root.right)
        return root
            

def main():
    solution = Solution()

    # Helper function to create binary tree from list
    def create_binary_tree(lst):
        if not lst:
            return None
        root = TreeNode(lst[0])
        queue = [root]
        i = 1
        while queue and i < len(lst):
            node = queue.pop(0)
            if lst[i] is not None:
                node.left = TreeNode(lst[i])
                queue.append(node.left)
            i += 1
            if i < len(lst) and lst[i] is not None:
                node.right = TreeNode(lst[i])
                queue.append(node.right)
            i += 1
        return root

    # Helper function to create list from binary tree
    def create_list(root):
        if not root:
            return []
        queue = [root]
        lst = []
        while queue:
            node = queue.pop(0)
            lst.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        return lst

    # Example 1
    root = create_binary_tree([4, 2, 7, 1, 3, 6, 9])
    output = solution.invertTree(root)
    print("Output 1: ", create_list(output))  # Should print [4, 7, 2, 9, 6, 3, 1]

    # Example 2
    root = create_binary_tree([2, 1, 3])
    output = solution.invertTree(root)
    print("Output 2: ", create_list(output))  # Should print [2, 3, 1]

    # Example 3
    root = create_binary_tree([])
    output = solution.invertTree(root)
    print("Output 3: ", create_list(output))  # Should print []

if __name__ == "__main__":
    main()