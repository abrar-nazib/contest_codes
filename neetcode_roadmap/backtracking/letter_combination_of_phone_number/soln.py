from typing import List


class Solution:
    letter_dict = {
        "2": ["a", "b", "c"],
        "3": ["d", "e", "f"],
        "4": ["g", "h", "i"],
        "5": ["j", "k", "l"],
        "6": ["m", "n", "o"],
        "7": ["p", "q", "r", "s"],
        "8": ["t", "u", "v"],
        "9": ["w", "x", "y", "z"],
    }

    def letterCombinations(self, digits: str) -> List[str]:
        current = []
        results = []

        def dfs(i):
            if i == len(digits):
                results.append("".join(current)) if len(current) > 0 else results
                return
            for j in range(len(self.letter_dict[digits[i]])):
                current.append(self.letter_dict[digits[i]][j])
                dfs(i + 1)
                current.pop()

        dfs(0)
        return results


soln = Solution()
digits = "23"
print(soln.letterCombinations(digits))
digits = ""
print(soln.letterCombinations(digits))
digits = "2"
print(soln.letterCombinations(digits))
