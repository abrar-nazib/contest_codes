from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates = sorted(candidates)
        results = []

        def backtrack(i, current_combination: List[int]):
            if sum(current_combination) == target:
                results.append(current_combination.copy())
                return
            if i >= len(candidates) or sum(current_combination) > target:
                return
            current_combination.append(candidates[i])
            backtrack(i + 1, current_combination)
            current_combination.pop()
            backtrack(i + 1, current_combination)
            while i + 1 < len(candidates) and candidates[i] == candidates[i + 1]:
                i += 1

        backtrack(0, [])
        return results


if __name__ == "__main__":
    solution = Solution()
    candidates1 = [10, 1, 2, 7, 6, 1, 5]
    target1 = 8
    print("Example 1:")
    print(solution.combinationSum2(candidates1, target1))

    candidates2 = [2, 5, 2, 1, 2]
    target2 = 5
    print("Example 2:")
    print(solution.combinationSum2(candidates2, target2))
