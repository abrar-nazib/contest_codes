from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        results = set()

        def dfs(i, subset: List[int]):
            # Edge Case
            if i >= len(nums):
                results.add(tuple(sorted(subset.copy())))
                return
            subset.append(nums[i])
            dfs(i + 1, subset)
            subset.pop()
            dfs(i + 1, subset)

        dfs(0, [])
        return [list(elem) for elem in results]


if __name__ == "__main__":
    sol = Solution()
    print(
        sol.subsetWithDup([1, 2, 2])
    )  # Expected: [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]
    print(sol.subsetWithDup([0]))  # Expected: [[], [0]]
