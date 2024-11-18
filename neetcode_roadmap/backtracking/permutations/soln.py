from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        results = []

        def dfs(permutation: List[int], current_input: List[int]):
            # Define the base case
            if len(current_input) < 1:
                results.append(permutation.copy())
                return
            for i, elem in enumerate(current_input):
                permutation.append(elem)
                current_input.remove(elem)
                dfs(permutation, current_input)
                permutation.pop()
                current_input.insert(i, elem)

        dfs([], nums)

        return results
