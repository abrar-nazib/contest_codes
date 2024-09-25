from typing import Optional
import collections


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.max_val = float("-inf")

        def dfs(root):
            if root is None:
                return 0
            left_val = dfs(root.left)
            right_val = dfs(root.right)
            left_tree_sum = root.val + left_val
            right_tree_sum = root.val + right_val
            tree_sum = root.val + left_val + right_val
            # print(
            #     f"rv: {root.val} ts: {tree_sum}, ls: {left_tree_sum}, rs: {right_tree_sum}"
            # )
            self.max_val = max(
                [tree_sum, left_tree_sum, right_tree_sum, self.max_val, root.val]
            )
            return max(left_tree_sum, right_tree_sum, root.val)

        dfs(root)

        return self.max_val


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

sol = Solution()


# # Example 1
# root1 = build_tree([1, 2, 3])
# output1 = sol.maxPathSum(root1)
# expected_output1 = 6
# assert output1 == expected_output1, f"Test 1 Failed: {output1} != {expected_output1}"

# # Example 2
# root2 = build_tree([-10, 9, 20, None, None, 15, 7])
# output2 = sol.maxPathSum(root2)
# expected_output2 = 42
# assert output2 == expected_output2, f"Test 2 Failed: {output2} != {expected_output2}"

# Test case: [2, -1, 2]
root = build_tree([2, -1, -2])
output = sol.maxPathSum(root)
expected_output = 2  # The optimal path is 2 -> 2 with a path sum of 2 + 2 = 4
assert output == expected_output, f"Test Failed: {output} != {expected_output}"

root = build_tree([9, 6, -3, null, null, -6, 2, null, null, 2, null, -6, -6, -6])
output = sol.maxPathSum(root)
expected_output = 16  # The optimal path is 2 -> 2 with a path sum of 2 + 2 = 4
assert output == expected_output, f"Test Failed: {output} != {expected_output}"


print("All tests passed.")
