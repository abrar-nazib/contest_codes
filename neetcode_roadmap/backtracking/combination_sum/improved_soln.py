from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        results = []

        def dfs(i: int, temp_target: int, members: List[int]):

            # The Base case: Failure
            if i >= len(candidates):
                return
            # The base case: Success
            if temp_target == 0:
                results.append(members.copy())
                return

            if candidates[i] <= temp_target:
                members.append(candidates[i])
                dfs(i, target - sum(members), members)
                members.pop()
            dfs(i + 1, target - sum(members), members)

        dfs(0, target, [])

        return results


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
