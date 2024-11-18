from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        results = set()
        soln = []

        def dfs():
            # Write the base case first
            if sum(soln) == target:
                results.add(tuple(sorted(soln.copy())))
            for candidate in candidates:
                if sum(soln) + candidate <= target:
                    soln.append(candidate)
                    dfs()
                    soln.pop()

        dfs()

        return [list(comb) for comb in results]


if __name__ == "__main__":
    solution = Solution()

    candidates1 = [2, 3, 6, 7]
    target1 = 7
    print(solution.combinationSum(candidates1, target1))  # Expected: [[2, 2, 3], [7]]

    candidates2 = [2, 3, 5]
    target2 = 8
    print(
        solution.combinationSum(candidates2, target2)
    )  # Expected: [[2, 2, 2, 2], [2, 3, 3], [3, 5]]

    candidates3 = [2]
    target3 = 1
    print(solution.combinationSum(candidates3, target3))  # Expected: []
