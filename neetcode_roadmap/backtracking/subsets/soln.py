from typing import List
import unittest


class Node:
    def __init__(self):
        self.value = []
        self.left = None
        self.right = None


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        subset = []

        def dfs(i):
            # Define the base case first
            if i >= len(nums):
                result.append(subset.copy())
                return
            # Add the element
            subset.append(nums[i])
            dfs(i + 1)

            # Remove the element
            subset.pop()
            dfs(i + 1)

        dfs(0)

        return result


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_subsets_example1(self):
        nums = [1, 2, 3]
        expected_output = [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
        result = self.solution.subsets(nums)
        self.assertEqual(sorted(result), sorted(expected_output))

    def test_subsets_example2(self):
        nums = [0]
        expected_output = [[], [0]]
        result = self.solution.subsets(nums)
        self.assertEqual(sorted(result), sorted(expected_output))


if __name__ == "__main__":
    unittest.main()
